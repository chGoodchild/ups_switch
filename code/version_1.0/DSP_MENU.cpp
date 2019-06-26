#include "DSP_MENU.h"
#include "dsp_menu_menu_defs.h"
#include <EEPROM.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1015.h>
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

// 2019-06-02 last version of sketch_load_shed_switch code before split of menu code
// @@@ fine tune all values, settings, constants, and make constants (#define) for all applicable things
  
// Runtime config mode
uint8_t cur_menu = 0;
float submenu_fl_cur_setting[MAIN_MENU_ITEMS] = { 0, 0, 0, 0, 0 }; // @@@ or -1 init?
uint8_t submenu_int_cur_setting[MAIN_MENU_ITEMS] = { 0, 0, 0, 0, 1 }; // @@@ or -1 init? @@@ menu definition in separate file, make this universal!!! @@@ change order of btns in other sketch
float pres_sett_orig_val_fl = 0;
uint8_t pres_sett_orig_val_int = 0;

void set_display_menu() { // @@@ declare non-public functions in .h file?
  
  display.clearDisplay();
  menu_write_display(0,0,2,false,0,0,mainmenu[cur_menu]);
  //Serial.println(mainmenu[0]);
  if(submenu_float[cur_menu]) {  
    menu_write_display(0,18,2,true,2,submenu_fl_cur_setting[cur_menu],suffixmenu[cur_menu]);
  } else {
    menu_write_display(0,18,2,false,0,0,submenu[cur_menu][submenu_int_cur_setting[cur_menu]]);
  }
  display.display();
}

// TMP
void set_change_value(bool increase) {
  if(submenu_float[cur_menu]) { 
    if(increase) {
      if(submenu_fl_cur_setting[cur_menu] < pgm_read_float(&submenu_fl_max_vals[cur_menu])) {
        submenu_fl_cur_setting[cur_menu] += pgm_read_float(&submenu_fl_step[cur_menu]);
      } else {
        submenu_fl_cur_setting[cur_menu] = pgm_read_float(&submenu_fl_min_vals[cur_menu]);    
      }
    } else {
      if(submenu_fl_cur_setting[cur_menu] > pgm_read_float(&submenu_fl_min_vals[cur_menu])) {
        submenu_fl_cur_setting[cur_menu] -= pgm_read_float(&submenu_fl_step[cur_menu]);
      } else {
        submenu_fl_cur_setting[cur_menu] = pgm_read_float(&submenu_fl_max_vals[cur_menu]);    // @@@ using & good? @@@ make sure it is done everywhere
      }
    } // @@@ bug with est. cur going down to negative number @@@ should have four max currents
  } else {
    if(increase) {
      if(submenu_int_cur_setting[cur_menu] < pgm_read_byte(&submenu_int_max_vals[cur_menu])) {
        submenu_int_cur_setting[cur_menu] += pgm_read_byte(&submenu_int_step[cur_menu]);
      } else {
        submenu_int_cur_setting[cur_menu] = pgm_read_byte(&submenu_int_min_vals[cur_menu]);    
      }
    } else {
      if(submenu_int_cur_setting[cur_menu] > pgm_read_byte(&submenu_int_min_vals[cur_menu])) {
        submenu_int_cur_setting[cur_menu] -= pgm_read_byte(&submenu_int_step[cur_menu]);
      } else {
        submenu_int_cur_setting[cur_menu] = pgm_read_byte(&submenu_int_max_vals[cur_menu]); // @@@ 'word' correct in pgm_read_word? // @@@ doing the reading and passing to function, etc. PROGMEM vars correctly? @@@ using &var[index] rather than var + index or &var + index, ok? @@@ check that option numbers correspond to actual settings, are displayed in correct order, and correct default is chosen.    
      }
    }
  }

  set_display_menu();
}

void set_next_menu() {
  // check if value changed and write to EEPROM
  if(submenu_float[cur_menu]) { 
    if(pres_sett_orig_val_fl != submenu_fl_cur_setting[cur_menu]) {
      EEPROM.put(pgm_read_byte(&submenu_eeprom_addr[cur_menu]), submenu_fl_cur_setting[cur_menu]); // @@@ do we need to declare float variable with f?
    }
  } else {
    if(pres_sett_orig_val_int != submenu_int_cur_setting[cur_menu]) {
      EEPROM.write(pgm_read_byte(&submenu_eeprom_addr[cur_menu]), submenu_int_cur_setting[cur_menu]); // @@@ first check if value changed
    }
  }
  
  if (cur_menu < (MAIN_MENU_ITEMS - 1)) {
    cur_menu++;
    // read value from EEPROM
    if(submenu_float[cur_menu]) { // @@@ convert 'byte' from EEPROM.read to 'int' or 'float' @@@ what if EEPROM address not written yet or out of length!
      EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[cur_menu]), submenu_fl_cur_setting[cur_menu]); // @@@ do we need to declare float variable with f?
      pres_sett_orig_val_fl = submenu_fl_cur_setting[cur_menu];
    } else {
      submenu_int_cur_setting[cur_menu] = EEPROM.read(pgm_read_byte(&submenu_eeprom_addr[cur_menu]));
      pres_sett_orig_val_int = submenu_int_cur_setting[cur_menu]; // @@@ verify that the checking for changes before writing to EEPROM works
    }
  
    set_display_menu();
  } else {
    display.clearDisplay();
    menu_write_display(0,18,2,false,0,0,ad);
    display.display();
    cur_menu = 0;
  }
}



void menu_display_display() {
  display.display();
}

void menu_display_clearDisplay() { // @@@ use these two functions also from within this file instead of directly calling display library
  display.clearDisplay();
}

void menu_write_display(int x, int y, int s, bool display_number, int dec, float number, const char text[]) { // @@@ are the passed text[]s null terminated? @@@ String type good? @@@ need to set type String also elsewhere? e.g. arrays containing menu info
  display.setCursor(x,y);
  display.setTextSize(s);
  if(display_number) {
    display.print(number,dec);
  }

  char myChar;
  for (byte k = 0; k < strlen_P(text); k++) {
    myChar = pgm_read_byte_near(text + k);
    display.print(myChar); // @@@@@@!!!! newline @@@ sanity/robustness/correctness of this solution, incl. passing text[], etc. @@@ why newline was coming in serial?
  }
    /*
  lcd.setCursor(0,0);
  lcd.print(to_print[0]);
  lcd.print(" A");
  lcd.setCursor(8,0);
  lcd.print(to_print[1]);
  lcd.print(" A");
  lcd.setCursor(0,1);
  lcd.print(to_print[2]);
  lcd.print(" A");
  lcd.setCursor(8,1);
  lcd.print(to_print[3]);
  lcd.print(" A");
*/
//  lcd.clear(); lcd.begin(16, 2); // MAYBE
}

void init_display() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // @@@ why bulb on/off repeatedly when disabling display?
  display.clearDisplay();
  display.setTextSize(5); // @@@ use #define for pin numbers, font sizes, cursor positions?, etc.
  display.setTextColor(WHITE); // 'inverted' text
  display.setCursor(32,0); // @@@ use #define for pin numbers, font sizes, cursor positions?, etc.
  display.println("./"); // @@@ make #define or display string
  display.display();
  // @@@ Why does compile fail if display.set* is entered a second time here?

  //delay(700);
  //display.clearDisplay();
  
}
// @@@ rename suffixes to dsp_menu?
void menu_setup(int sel_btn, int up_btn, int dwn_btn) {
  pinMode(dwn_btn, INPUT);    // sets the digital pin 7 as input
  digitalWrite(dwn_btn, 1);
  pinMode(up_btn, INPUT);    // sets the digital pin 7 as input
  digitalWrite(up_btn, 1);
  pinMode(sel_btn, INPUT);    // sets the digital pin 7 as input
  digitalWrite(sel_btn, 1);
  
  delay(100); // @@@ delay before reading A3 after setting to INPUT? @@@ delay being used also by digitalRead A3 in loop!
  bool reset_mode = (!digitalRead(sel_btn));
  
  init_display();
  if (EEPROM.read(TEST_EEPROM_ADDR) != TEST_EEPROM_VALUE) {
    delay(200);
    display.clearDisplay();
    menu_write_display(0,0,2,false,0,0,eeprom_err_msg_1); // @@@ add indication of shed status
    display.display();
    while(1);
  }
  if (reset_mode) { 
    delay(200);
    display.clearDisplay();
    menu_write_display(0,0,1,false,0,0,reset_defaults_1);
    display.display();
    while(!digitalRead(sel_btn));
    delay(800); // @@@ review and make defines for all delay times or other values, etc.
    while(!digitalRead(sel_btn)); // @@@ do this?
    while(digitalRead(sel_btn));
    // do the reset
    uint8_t iterator = 0; // @@@ consistency in declaring iterators
    for(iterator = 0; iterator < MAIN_MENU_ITEMS; iterator++) { // @@@ 13
      if(submenu_float[iterator]) {
        float pres_val = 0;
        EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[iterator]), pres_val); // @@@ also here, do we need to declare float variable with f?
        if(pres_val != pgm_read_float(&submenu_fl_defaults[iterator])) { // @@@ test this (and below int), that doesn't write when already equal, but that writes reliably when necessary
          EEPROM.put(pgm_read_byte(&submenu_eeprom_addr[iterator]), pgm_read_float(&submenu_fl_defaults[iterator])); // @@@ do we need to declare float variable with f?
        }
      } else {
        if(EEPROM.read(pgm_read_byte(&submenu_eeprom_addr[iterator])) != pgm_read_byte(&submenu_int_defaults[iterator])) {
          EEPROM.write(pgm_read_byte(&submenu_eeprom_addr[iterator]), pgm_read_byte(&submenu_int_defaults[iterator])); // @@@ first check if value changed
        }
      }
    }

    // display confirmation
    display.clearDisplay();
    menu_write_display(0,0,1,false,0,0,reset_defaults_2); // @@@ put char sizes in #defines also?
    display.display();
    while (1);
  }
}

bool menu_loop(int sel_btn, int up_btn, int dwn_btn) {
  bool config_mode = (!digitalRead(sel_btn)); // @@@ make define of all pins
  if (config_mode) {
    delay(800);
    // read value from EEPROM
    cur_menu = 0; // start from first menu item
    if(submenu_float[cur_menu]) { // @@@ convert 'byte' from EEPROM.read to 'int' or 'float' @@@ what if EEPROM address not written yet or out of length!
      EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[cur_menu]), submenu_fl_cur_setting[cur_menu]); // @@@ do we need to declare float variable with f?
      pres_sett_orig_val_fl = submenu_fl_cur_setting[cur_menu];
    } else {
      submenu_int_cur_setting[cur_menu] = EEPROM.read(pgm_read_byte(&submenu_eeprom_addr[cur_menu]));
      pres_sett_orig_val_int = submenu_int_cur_setting[cur_menu]; // @@@ verify that the checking for changes before writing to EEPROM works
    }
    set_display_menu();
    while(!digitalRead(sel_btn));
    while (config_mode) {
      if(!digitalRead(dwn_btn)) {
        set_change_value(false);
        delay(300);
      } else if(!digitalRead(up_btn)) {
        set_change_value(true);
        delay(300);
      } else if(!digitalRead(sel_btn)) {
        while(!digitalRead(sel_btn));
        set_next_menu();
        if (cur_menu < 1) {
          config_mode = false;
        }
        //delay(300); // @@@ unite? at least #define common delay @@@ verify that all is ok with changing settings while running @@@ and why is this delay commented out?
      }
    }
    return true;
  } else {
    return false;
  }
}
