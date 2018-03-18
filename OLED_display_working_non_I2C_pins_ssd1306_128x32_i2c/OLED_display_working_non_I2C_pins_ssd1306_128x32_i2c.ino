//#include <TimerHelpers.h>

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98
dis
This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <Adafruit_GFX.h>
// @@@ This library is currently a modified version! Keep modified?
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define DEB_DELAY    2       // Debounce delay @@@ to be fine tuned
#define TIMER_SNAPSHOT_MS() ((ticks << 8) | TCNT0)
volatile uint32_t ticks;
volatile uint32_t DebounceSnapshot;


// Refference voltage
// static float Vref = 5;

// MCP1702 in grace
static float Vref = 4.99;

// On USB in last school
// static float Vref = 4.64;
  
#define maxItemSize 9
const int itemsPerScreen = 2;
int cnt = 0; 
const int fontSize = 15;
static int enSW = 9;

// @@@ most of the following don't actually need to be volatile
// @@@ following three/four variables will need to be set when defining the battery voltage scale
// Beware the combinations of values entered in the four variables, to avoid problems when "overflowing"
// i.e. don't set min to 15 if step is 10 and val is 20 @@@ to be better phrased
float fltPrmpt_max[] = {15,100,15,100,3,12};
float fltPrmpt_min[] = {10,10,10,10,0.5,3};
float fltPrmpt_step[] = {0.10,10,0.10,10,0.25,0.25};
// @@@ change 12.5?
volatile float fltPrmpt_val[] = {11,30,13.5,70,1,12};
volatile int fn_run = 0;
volatile int mode = 0;
volatile bool topup = false;
volatile bool need_to_calibrate = false;
volatile int main_menu_item = 0;
volatile int mode_menu_item = 0;
volatile int cur_menu = -1;
volatile char main_menu[][10] ={"Run topup\0","Mode\0","Bat. size\0","Ch. on V\0","Ch. on %\0","Ch. off V\0","Ch. off %\0","Min time\0","Max time\0","Calibrate\0","Exit\0"};
// @@@ is it necessary for the following to be volatile and/or global?
volatile char mode_menu[][10] ={"Automatic\0","Off\0","On\0","Back\0"};


const byte interruptPinScr = 8;
const byte interruptPinSel = 9;

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

/* Interrupt service routine to keep track of time
 */
ISR(TIMER1_OVF_vect)
{
  // @@@
  TCNT1 = 34286;
  ticks++;
  return;
}

void setup()   {                
  // @@@ Rename sketch as we are now using the actual hardware I2C pins
  
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done

  // Clear the buffer.
  display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(0,0);
  display.println("Chandran\nDyuman");
  //display.setTextColor(WHITE);
  display.display();
  // @@@ Why does compile fail if display.set* is entered a second time here?

  delay(500);
  display.clearDisplay();
  cli();
  // @@@ Normally, it seems there is a better way of doing interrupts, according to https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  // @@@ Verify that INPUT_PULLUP is equivalent to HIGH (https://playground.arduino.cc/Main/PinChangeInterrupt)
  pinMode(interruptPinScr, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPinScr), scroll, FALLING);
  pinMode(interruptPinSel, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPinSel), select, FALLING);

    *digitalPinToPCMSK(interruptPinScr) |= bit (digitalPinToPCMSKbit(interruptPinScr));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(interruptPinScr)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(interruptPinScr)); // enable interrupt for the group 
    *digitalPinToPCMSK(interruptPinSel) |= bit (digitalPinToPCMSKbit(interruptPinSel));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(interruptPinSel)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(interruptPinSel)); // enable interrupt for the group 
  sei();
  // draw a bitmap icon and 'animate' movement
  //testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);

  // @@@ review code. See http://www.hobbytronics.co.uk/arduino-timer-interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCNT1 = 34286;
  TCCR1B |= (1 << CS12);
  TIMSK1  = _BV(TOIE1);   /* enable the overflow interrupt */

  // @@@ replace the '11' and menu values
  displayMenu(main_menu,11, main_menu_item);
//  ticks = 0;
  cur_menu = -1;
  meas_setup();
  // @@@ remove????
  pinMode(6,OUTPUT);
}


void loop() {
  // @@@ is it interesting to understand why it didn't work calling the functions straight from
  // the ISR while using hardware I2C?

  // @@@ verify the sanity of the order of things being done/checked in this main loop
  switch(fn_run) {
          case 1 :
            fn_run=0;
            scroll();
          break;
          case 2 :
            fn_run=0;
            select();
          break;
        }
  if (cur_menu == -1) {
   meas_loop();
  }
  if (topup) {
    digitalWrite(6, HIGH);
    // @@@ Take care of the topup over here
    // @@@ Do we need to restore the relay to its previous state
    // upon completion of the topup as well as upon cancellation?
  } else {
    // Do whatever has been set in the Mode menu
    if (mode == 2) {
      digitalWrite(6, HIGH);
    } else if (mode == 1) {
      digitalWrite(6, LOW);
    } else if (mode == 0) {
      // @@@ Check here for voltages/percentages/timings having reached thresholds/etc.
    }
  }
  if (need_to_calibrate) {
    // @@@ Write to EEPROM bit and reset the MCU
    // @@@ There is a cleaner way to reset, I am sure
    digitalWrite(12, LOW);
  }
}

int displayMenu(char menuInput[][10], int menuLength, int startPos){
    
    int curPos, endPos;
// do{ 
            Serial.println("startPos:");
            Serial.println(startPos);
            display.clearDisplay();
      
            endPos = itemsPerScreen;
            
            if(menuLength < itemsPerScreen)
            {
                 endPos = menuLength -startPos;  
            }
      
            if((menuLength-startPos)<itemsPerScreen)
            {
                endPos = menuLength -startPos;
            }

            Serial.print("endPos:");
            Serial.println(endPos);
      
            for(cnt = 0; cnt<=(endPos-1); cnt++){
                if(cnt == 0)
                {
                  display.setCursor(0,0);
                  display.print(">");
                }
               
                display.setCursor(16, cnt*fontSize);
                display.println(menuInput[cnt+startPos]);
                Serial.println(menuInput[cnt+startPos]);   
            }

            display.display();
            cnt = 0;

          /*if(oldEncPos != encoderPos) {
            oldEncPos = encoderPos;   
          } */ 
 /*} while(digitalRead(enSW));
 
 while(digitalRead(enSW)==0); //wait till switch is reseleased 
 return startPos;*/
}

ISR (PCINT0_vect) 
 {
  // @@@ verify if this is a dependable way of checking which button triggered the interrupt, and what about the FALLING?
  // @@@ It might be better to use the library mentioned at http://playground.arduino.cc//Main/PinChangeIntExample
  if (!digitalRead(interruptPinScr)) {
    fn_run=1;
  }
  if (!digitalRead(interruptPinSel)) {
    fn_run=2;
  }
 }

void scroll() {
  // Potential bug with ticks overflowing!!! @@@
  // @@@ No need to debounce twice. Can put this in the ISR, and serve both buttons.
  if ((ticks - DebounceSnapshot) >= DEB_DELAY) {
      DebounceSnapshot = ticks; // @@@ better at beginning of ISR?
      // @@@ replace all the following 'if' statements with a 'switch'/'case'
      if (cur_menu == -1) {
        cur_menu = 0;
        main_menu_item = -1; /// @@@ is this too dirty a hack? And, does it work with checking for 11 below?
      }
      if ((cur_menu == 1) || (cur_menu == 10)) {
        cur_menu = 0;
        main_menu_item -= 1; /// @@@ is this too dirty a hack? And, does it work with checking for 11 below?
      }
      if (cur_menu == 0) {
        main_menu_item += 1;
        // @@@ replace the '11'
        if (main_menu_item == 11) {
          main_menu_item = 0;
        }
        // @@@ replace the '11' and menu values
        displayMenu(main_menu,11, main_menu_item);
      }
      if (cur_menu == 2) {
        mode_menu_item += 1;
        // @@@ replace the '4'
        if (mode_menu_item == 4) {
          mode_menu_item = 0;
        }
        // @@@ replace the '4'
        displayMenu(mode_menu,4, mode_menu_item);
      }
      if ((cur_menu >= 4) && (cur_menu <= 9)) {
        int arr_i = cur_menu - 4;
        fltPrmpt_val[arr_i] += fltPrmpt_step[arr_i];
        // @@@ at the moment, if variable happens to contain out of bounds value as in too low, it does not get corrected. Ok?
        if (fltPrmpt_val[arr_i] > fltPrmpt_max[arr_i]) {
          fltPrmpt_val[arr_i] = fltPrmpt_min[arr_i];
        }
        fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[arr_i]);
      }
  }
  return;
}

void select() {
  Serial.println("Button sel pressed");
  // Potential bug with ticks overflowing!!! @@@
  if ((ticks - DebounceSnapshot) >= DEB_DELAY) {
    switch(cur_menu) {
      case 0 :
        switch(main_menu_item) {
          case 0 :
            cur_menu = 1;
            if (topup) {
              askCancel(main_menu[main_menu_item]);              
            } else {
              askConfirm(main_menu[main_menu_item]);              
            }
          break;
          case 1 :
            cur_menu = 2;
            mode_menu_item = 0;
            // @@@ replace the '4'
            displayMenu(mode_menu,4, mode_menu_item);
          break;
          case 2 :
        
          break;
          case 3 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[0]);
            cur_menu = 4;
          break;
          case 4 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[1]);
            cur_menu = 5;        
          break;
          case 5 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[2]);
            cur_menu = 6;        
          break;
          case 6 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[3]);
            cur_menu = 7;          
          break;
          case 7 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[4]);
            cur_menu = 8;        
          break;
          case 8 :
            fltPrmpt(main_menu[main_menu_item], fltPrmpt_val[5]);
            cur_menu = 9;        
          break;
          case 9 :
            cur_menu = 10;
            askConfirm(main_menu[main_menu_item]);              
          break;
          case 10 :
            cur_menu = -1;
          break;
        }
      break;
      case 1 :
        // @@@ Confirm that the next line is sufficient/appropriate. Does this apply also to calibrate option?
        // @@@ Also verify that this is the behavior we want, i.e. running topup at
        // the moment overrides settings in "Mode". This might or might not be intuitive.
        // @@@ Once topup has started, there needs to be a way to cancel it.
        topup = !topup;
        disMessage(main_menu[main_menu_item], " OK");
        cur_menu = 0;
        // @@@ replace the '11' and menu values
        displayMenu(main_menu,11, main_menu_item);
      break;
      case 2 :
        if (mode_menu_item < 3)
          {
            mode = mode_menu_item;
          }
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);
      break;
      case 4 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 5 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 6 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 7 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 8 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 9 :
          // @@@ put the following two lines in a function, they get used often
          cur_menu = 0;
          // @@@ replace the '11'
          displayMenu(main_menu,11, main_menu_item);          
      break;
      case 10 :
        disMessage(main_menu[main_menu_item], " OK");
        need_to_calibrate = true;
        // @@@ should we bother to return to main menu or not since we probably anyway will reset here?
      break;
    }

    DebounceSnapshot = ticks;
  }
  return;
}

void askConfirm(char title[9]) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" ");
  display.println(title);
  display.println(" Confirm?");
  display.display();
}

void askCancel(char title[9]) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" ");
  display.println(title);
  display.println(" Cancel?");
  display.display();
}

void disMessage(char title[9], char message[9]) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" ");
  display.println(title);
  display.println(message);
  display.display();
  delay(500);
}

void fltPrmpt(char title[9], float curValue) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" ");
  display.println(title);
  display.print(" ");
  display.println(curValue);
  display.display();
}

// Measurement code as of 17/03/2018, tmp, to be removed @@@
float calibration = 0;
// Capacity in AH
float C = 26;

void meas_setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  // Voltage measurement
  pinMode(A0, INPUT);
  // Current measurement
  pinMode(A7, INPUT);
  calibration = analogRead(A7);
}


void meas_loop() {

  static float measurements[3];
  measure(&measurements[0]);

  display.clearDisplay();
  display.setCursor(0,0);
  display.println(measurements[0]);
  display.print(measurements[1]);
  display.print(" ");
  display.println(measurements[2]);
  display.display();
  Serial.print("Percentage: ");
  Serial.print(measurements[0]);
  Serial.print("\t");
  Serial.print("Voltage: ");
  Serial.print(measurements[1]);
  Serial.print("\t");
  Serial.print("Current: ");
  Serial.print(measurements[2]);
  Serial.println("\t");
  
  // testPercentage();
}

void testPercentage (float Uin) {
    // put your main code here, to run repeatedly:
  static float C = 100;
  static float I = 0; // C5 only
  static float U = Uin;

  Serial.println("");

  //Serial.print(U);
  Serial.print("\t");

  I = 20;
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 10;  // C10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 5; // C20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 2.5; // C40
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 0; // rest
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -1; // D100
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -5; // D20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -10; // D10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -20; // D5
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -33.3; // D3
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -50; // D2
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  U = U + 0.01;
  
  testPercentage(U);
}

/**
 * Return the battery voltage.
 */
float batteryVoltage() {
  // Small resistor
  static int sR = 317;
  // Big resistor
  static int bR = 4590;

  return ((analogRead(A0) * Vref) / 1023) * (sR + bR) / sR;
}



/**
 * Return the current in Amps.
 */
float currentInAmps() {
  return ((calibration - analogRead(A7)) / 1023 * Vref) * 1000 / 33;
}



/**
 * Scale the battery voltage down to 12 Volts and return a 
 * standardized Array with percentage, voltage and current.
 */
float measure(float *measurements) {
    // Return [percentage, voltage, current]
    // Battery voltage pin: A0
    // Current: A7
    float percent;
    
    // Voltage measurement and scaling
    float measuredVoltage = batteryVoltage();
    int divisor = (int) (measuredVoltage / 9.5);
    if (divisor < 1) {
      divisor = 1;
    }
    // Scaled voltage:
    float V = measuredVoltage / divisor;

    // Current measurement - no scaling
    float I = currentInAmps();

    // Can't be right: scaling error
    if (V < 8.5 || V > 15.5) {
      percent = -3;
    } else {
      percent = percentage(V, I, C);
    }

    measurements[0] = (199 * measurements[0] + percent) / 200;
    //measurements[0] = percent;
    measurements[1] = (19 * measurements[1] + V) / 20;
    measurements[2] = (19 * measurements[2] + I) / 20;
    //measurements[1] = V;
    //measurements[2] = I;
}


/**
 * Return the percentage charge of a battery, given the 
 * voltage, current and capacity of the battery...
 */
float percentage (float U, float I, float C) {
  // I = Q / t, [I] = C / s = .... Ah / 3600 s = ... Ah / 1 h

    if (I > 0 && I < 0.00001) {
      I = 0.00001;
    }

    if (I <= 0 && I > -0.00001) {
      I = -0.00001;
    }

    // T in hours:
    float T = C / I;

    if (T < 0) {
      T = -T;
    }

  
  if (I > 0) {
    // CHARGING

    if (T <= 5) {
      // 5 Formula: (x - 17.481) * (x - 14.408) * (x - 14.202) * (x - 12.168) * (x - 17.452) * (x - 14.783) + 78.465
      // Serial.print("< 5 ");

      if (12.64 < U && U < 15.77) {
        float result = (U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if (5 < T && T <= 10) {
      // 10 Formula: (x - 11.992) * (x - 14.325) * (x - 17.428) * (x - 14.420) * (x - 14.353) * (x - 17.227) + 88.222)      
      // return ((T - 5) * (10 formula)  + (10 - T) * (5 formula) / 5
      // Serial.print("5 < T && T < 10 ");

      if (12.49 < U && U < 15.77) {

        float result = ((T - 5) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222) 
                + (10 - T) * ((U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465)) / 5;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }

    } else if (10 < T && T <= 20) {
      // 20 Formula: (x - 17.190) * (x - 14.171) * (x - 14.205) * (x - 11.740) * (x - 17.159) * (x - 14.222) + 94.499)
      // return ((T - 10) * (20 formula) ) + (20 - T) * (10 formula) / 10
      // Serial.print("10 < T && T < 20 ");

      if (12.25 < U && U < 15.33) {
        float result = (((T - 10) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499))
                + (20 - T) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222)) / 10;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if (20 < T && T <= 40) {
      // 40 Formula: (x - 14.6659) * (x - 14.8680) * (x - 9.8940) * (x - 9.9535) * (x - 13.3392) * (x - 9.9839) + 100.1695
      // return: ((T - 20) * (40 formula) ) + (40 - T) * (20 formula) / 20
      // Serial.print("20 < T && T < 40 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 20) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)
                  + (40 - T) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499)) / 20;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if(40 < T && T <= 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 40) * (rest formula) ) + (200 - T) * (40 formula) / 160
      // Serial.print("40 < T && T < 200 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 40) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                + (200 - T) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)) / 160;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
    } else {
      // Rest
      // Serial.print("Rest ");
      // Serial.print(T);

      if (12.69 > U && U > 11.77) {
        float result = (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }

    }
  } else if (I < 0) {
    // DISCHARGING
    
    if (T >= 200) {
      // Rest

      if (12.69 > U && U > 11.77) {
        float result = (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }


    } else if (T >= 100 && T < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 100) * (rest formula) + (200 - T) * (100 formula)) / 100

      if (12.67 > U && U > 11.67) {
        float result = ((T - 100) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                  + (200 - T) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185)) / 100;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (20 <= T && T < 100) {
      // 100 formula: (x - 10.8400) * (x - 10.8709) * (x - 10.8594) * (x - 7.9782) * (x - 10.9025) * (x - 10.8718) + 13.3185
      // return ((T - 20) * (100 formula) + (100 - T) * (20 formula)) / 80

      if (12.59 > U && U > 11.56) {
        float result = ((T - 20) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185) 
                    + (100 - T) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746)) / 80;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (10 <= T && T < 20) {
      // 20 formula: (x - 9.7996) * (x - 15.1168) * (x - 12.4056) * (x - 15.2981) * (x - 9.8815) * (x - 9.7797) + 73.6746
      // return ((T - 10) * (20 formula) + (20 - T) * (10 formula)) / 10

      if (12.45 > U && U > 11.10) {
        float result = ((T - 10) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746) 
                    + (20 - T) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754)) / 10;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (5 <= T && T < 10) {
      // 10 formula: (x - 13.3140) * (x - 8.8627) * (x - 13.2982) * (x - 13.3087) * (x - 8.9231) * (x - 8.9352) + 128.2754
      // return ((T - 5) * (10 formula) + (10 - T) * (5 formula)) / 5

      if (12.06 > U && U > 10.52) {
          float result = ((T - 5) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754) 
                      + (10 - T) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786)) / 5;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (3 <= T && T < 5) {
      // 5 formula: (x - 13.0987) * (x - 11.8714) * (x - 8.5070) * (x - 13.2636) * (x - 8.5267) * (x - 8.5385) + 89.6786
      // return ((T - 3) * (5 formula) + (5 - T) * (3 formula)) / 2

      if (11.71 > U && U > 9.34) {
          float result = ((T - 3) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786) 
                      + (5 - T) * ((U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198)) / 2;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (T < 3) {
      // 3 formula: (x - 10.1354) * (x - 10.1681) * (x - 10.1423) * (x - 6.4437) * (x - 13.7005) * (x - 13.5256) + 27.9198
      // return 3 formula;

      if (11.71> U && U > 9.35) {
          float result = (U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
    }

    return -1.0;
  }
}


