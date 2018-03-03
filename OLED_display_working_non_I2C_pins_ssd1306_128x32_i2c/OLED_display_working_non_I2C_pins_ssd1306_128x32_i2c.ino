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
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define maxItemSize 9
const int itemsPerScreen = 2;
int cnt = 0; 
const int fontSize = 15;
static int enSW = 9;

volatile int menu_item = 0;

const byte interruptPin = 3;

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

void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(500);

  // Clear the buffer.
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Chandran Dyuman!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(500);
  display.clearDisplay();

  // Normally, it seems there is a better way of doing interrupts, according to https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);

  // draw a bitmap icon and 'animate' movement
  //testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
}


void loop() {
  char menu[][maxItemSize] ={"Battery","Time","Alarm","Format","Zone","Daylight","BACK"};
  displayMenu(menu,sizeof(menu)/maxItemSize, menu_item);
}

int displayMenu(char menuInput[][maxItemSize], int menuLength, int startPos){
    
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

void blink() {
  menu_item += 1;
  menu_item = menu_item % 6;
  delay(100);
}
