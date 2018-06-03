#include <EEPROM.h>
#include "MULTIMETER.h"
#include "PINDEFINITIONS.h"
#include "CODEDEFINITIONS.h"

//#include <TimerHelpers.h>


// Display: Battery size settings Dyuman

// EEPROM --> Calibration Ch
// TNEB sensing Dy

// Main logic (switching) - Later
//  Time delay
//  Percentage
//  Bat voltage
//  TNEB presence
// Topup

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


// @@@ Measure the measure time uppon the first measure...
// @@@ Define the sleep time as 100 ms - measure time.
// @@@ Is 100 ms reasonable??
// @@@ Or update the sleep time dynamically. Every time we 
//     go to sleep at the end of loop() we can subtract the 
//     time that loop took from the sleep time (100 ms).

// => Sleep for 100 ms (sleep_time) - loop_time.


#define DEB_DELAY    2       // Debounce delay @@@ to be fine tuned
#define TIMER_SNAPSHOT_MS() ((ticks << 8) | TCNT0)
volatile uint32_t ticks;  // ###
volatile uint32_t DebounceSnapshot;  // ###


// On USB in last school
// static float Vref = 4.64;
  
#define maxItemSize 9  // ###
const int itemsPerScreen = 2;  // ###
int cnt = 0;  // ###
const int fontSize = 15;  // ###
static int enSW = 9;  // ###

// @@@ most of the following don't actually need to be volatile
// @@@ following three/four variables will need to be set when defining the battery voltage scale
// Beware the combinations of values entered in the four variables, to avoid problems when "overflowing"
// i.e. don't set min to 15 if step is 10 and val is 20 @@@ to be better phrased

// @@@ We can make a 2 dimensional array (an array of arrays) to list these values.
// We can use # defin max = 0, min = 1, step = 2 etc...
float fltPrmpt_max[] = {15,100,15,100,3,12};
float fltPrmpt_min[] = {10,10,10,10,0.5,3};
float fltPrmpt_step[] = {0.10,10,0.10,10,0.25,0.25};
// @@@ change 12.5?
volatile float fltPrmpt_val[] = {11,30,13.5,70,1,12};

volatile int btn_number = 0; // ###
volatile int mode = 0;
volatile bool topup = false;
volatile bool need_to_calibrate = false;
volatile int main_menu_item = 0;
volatile int mode_menu_item = 0;
volatile int cur_menu = -1;
volatile char main_menu[][10] ={"Run topup\0","Mode\0","Bat. size\0","Ch. on V\0","Ch. on %\0","Ch. off V\0","Ch. off %\0","Min time\0","Max time\0","Calibrate\0","Exit\0"};
// @@@ is it necessary for the following to be volatile and/or global?
volatile char mode_menu[][10] ={"Automatic\0","Off\0","On\0","Back\0"};

// Pin number of the buttons
const byte interruptPinScr = 8;
const byte interruptPinSel = 9;

MULTIMETER *mult = new MULTIMETER(26);

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

  // BEGIN: Setup Buttons

  // Disable interrupts and setup the button interrupts.
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

  // Re-enable interrupts
  sei();

  // END: Setup Buttons


  // BEGIN: Timer interrupts
  
  // @@@ review code. See http://www.hobbytronics.co.uk/arduino-timer-interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCNT1 = 34286;
  TCCR1B |= (1 << CS12);
  TIMSK1  = _BV(TOIE1);   /* enable the overflow interrupt */

  // END: Timer interrupts.

  

  // @@@ replace the '11' and menu values
  //displayMenu(main_menu,11, main_menu_item);
//  ticks = 0;


  // Which page of the Menu is currently being displayed?
  // -1 --> home screen with status information
  // 
  cur_menu = -1;

  
  // This is the relay pin. ---> Use # define / const for all the pins...
  pinMode(6,OUTPUT);
}


void loop() {
  // @@@ we always want to measure. cur_menu checking should only affect displaying the values


  // BEGIN: Measure

  
  mult->measure();

  // Only for debugging
  // @@@ Use ifdef
  Serial.print("Percentage: ");
  Serial.print(mult->getPercentage());
  Serial.print("\t");
  Serial.print("Voltage: ");
  Serial.print(mult->getV());
  Serial.print("\t");
  Serial.print("Current: ");
  Serial.print(mult->getI());
  Serial.println("\t");

  // END: Measure


  // BEGIN: Display

  // @@@ we should also display the current state of the relay
  if (cur_menu == -1) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println(mult->getPercentage());
    display.print(mult->getV());
    display.print(" ");
    display.println(mult->getI());
    display.display();
  }


  // @@@ is it interesting to understand why it didn't work calling the functions straight from
  // the ISR while using hardware I2C?


  // Begin: Menu code

  // @@@ verify the sanity of the order of things being done/checked in this main loop
  switch(btn_number) {
          case 1 :
            btn_number=0;
            scroll();
          break;
          case 2 :
            btn_number=0;
            select();
          break;
        }

  //  END: Display


  //  BEGIN: Action
    
  if (need_to_calibrate) {
    // @@@ Write to EEPROM bit and reset the MCU
    // @@@ There is a cleaner way to reset, I am sure
    digitalWrite(12, LOW);
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
      // @@@ FLOW CHART
    }
  }

  //  END: Action

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
    btn_number=1;
  }
  if (!digitalRead(interruptPinSel)) {
    btn_number=2;
  }
 }

void scroll() {
  // Potential bug with ticks overflowing!!! @@@ ---> Use more variables (https://github.com/chGoodchild/ups_switch/issues/10)
  // @@@ No need to debounce twice. Can put this in the ISR, and serve both buttons.
  if ((ticks - DebounceSnapshot) >= DEB_DELAY) {
      DebounceSnapshot = ticks; // @@@ better at beginning of ISR?
      // @@@ replace all the following 'if' statements with a 'switch'/'case'
      // @@@ Use # define / const again, -1 ---> main screen...
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
        // @@@ 11 ---> main_menu.length(), if that is not possible #define / const main_menu_length = main_menu.length()
        displayMenu(main_menu,11, main_menu_item);
      }
      
      if (cur_menu == 2) {
        mode_menu_item += 1;
        if (mode_menu_item == 4) {
          mode_menu_item = 0;
        }
        // @@@ 4 ---> mode_menu.length(), if that is not possible #define / const mode_menu_length = mode_menu.length()
        displayMenu(mode_menu,4, mode_menu_item);
      }

      // Increment the values being displayed.
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

// @@@ Again define / consts could be used for readability...
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
  delay(275);
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



