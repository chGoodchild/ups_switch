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


#define DEB_DELAY    2       // Debounce delay
#define TIMER_SNAPSHOT_MS() ((ticks << 8) | TCNT0)
volatile uint32_t ticks;
volatile uint32_t DebounceSnapshot;


#define maxItemSize 9
const int itemsPerScreen = 2;
int cnt = 0; 
const int fontSize = 15;
static int enSW = 9;

volatile int fn_run = 0;
volatile int mode = 0;
volatile bool in_submenu = 0;
volatile int main_menu_item = 0;
volatile int mode_menu_item = 0;
volatile int cur_menu = 0;
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
  Serial.println("ISR");
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

}


void loop() {
  // @@@ is it interesting to understand why it didn't work calling the functions straight from
  // the ISR while using hardware I2C?
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
      delay(100); // @@@ required? 
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
            askConfirm(main_menu[main_menu_item]);
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
        
          break;
          case 4 :
        
          break;
          case 5 :
        
          break;
          case 6 :
          
          break;
          case 7 :
        
          break;
          case 8 :
        
          break;
          case 9 :
        
          break;
          case 10 :
        
          break;
        }
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
    }

    delay(100); // @@@ required?
    DebounceSnapshot = ticks;
  }
  return;
}

bool askConfirm(char title[9]) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" ");
  display.println(title);
  display.println(" Confirm?");
  display.display();
}

