// Include files
#include <EEPROM.h>
#include "MULTIMETER.h"
#include "PINDEFINITIONS.h"
#include "CODEDEFINITIONS.h"
#include "DSP_MENU.h"
#include "dsp_menu_menu_defs.h"

// Compile time settings and constant variables
#define RELAY_PIN 6
#define BTN_1_PIN 8
#define BTN_2_PIN 9
#define BTN_3_PIN 10
#define MODE_AUTO 1
#define CMD_RUN_CHARGE 1
#define CMD_STOP_CHARGE 2
#define CMD_NEUTRAL 0
const char symbols[8][2] PROGMEM = { "%", "V", "A", "C", "", "", "T", "M" }; // @@@ just not show anything instead of chrg. off
const char messages[5][31] PROGMEM = { "Scaling error", "Battery voltage\ncritically low", "Battery voltage very\nhigh", "perc_LB_error", "perc_UB_error" };
const char recalib_1[77] PROGMEM = "Recalibrate current\nsensor, ensure\ncurrent is zero and\npress X to confirm..."; // @@@ make sure \n and \0 count as single character and are understood
const char recalib_2[41] PROGMEM = "Current sensor\nrecalibrated, press\nReset";
const char topup_1[40] PROGMEM = "Start battery topup?\nPress X to confirm"; // @@@ make sure \n and \0 count as single character and are understood
const char topup_2[22] PROGMEM = "Battery topup started";
const char topup_3[41] PROGMEM = "Cancel battery topup?\nPress X to confirm"; // @@@ make sure \n and \0 count as single character and are understood
const char topup_4[24] PROGMEM = "Battery topup\ncancelled"; // @@@ re-count number of chars in each var and update constructor

// Variables for storing in memory during runtime menu setting values read from EEPROM
float battery_ah = 0;
float topup_high_bound = 0;
float user_high_bound = 0;
float user_low_bound = 0;
uint8_t mode = 0;

// Runtime variables
uint8_t topup_wants_charge = 0;
uint8_t user_bound_wants_charge = 0;

MULTIMETER *mult = new MULTIMETER(); // @@@ update ah

void update_display(int message) { // @@@ uint8_t didn't work
  int state_1_symbol_number = 0; // @@@ init other than 0?
  if (digitalRead(RELAY_PIN)) {
    state_1_symbol_number = 3;
  } else {
    state_1_symbol_number = 4;
  }
  int state_2_symbol_number = 0; // @@@ init other than 0?
  if (mode == MODE_AUTO) {
    if (topup_wants_charge == CMD_RUN_CHARGE) {
      state_2_symbol_number = 6;
    } else {
      state_2_symbol_number = 5;
    }
  } else {
    state_2_symbol_number = 7;
  }
  menu_display_clearDisplay();
  if (message > -1) { // @@@ sane (-1) ?
    menu_write_display(0, 0, 1, false, 0, 0, messages[message]);
    // @@@ compare with coordinate values used in other implementation @@@ alignment of symbol
    menu_write_display(0, 16, 1, true, 0, mult->getPercentage(), symbols[0]); // @@@ or get percent, relay state, etc. passed to this function?
    menu_write_display(64, 16, 1, true, 1, mult->getMeasuredV(), symbols[1]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(0, 24, 1, false, 0, 0, symbols[state_1_symbol_number]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(7, 24, 1, false, 0, 0, symbols[state_2_symbol_number]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(64, 24, 1, true, 1, mult->getI(), symbols[2]); // @@@ or get percent, etc. passed to this function?
  } else { // @@@ have calls only once and use multiplier? @@@ better arrangement on display
    // @@@ compare with coordinate values used in other implementation @@@ alignment of symbol
    menu_write_display(0, 0, 2, true, 0, mult->getPercentage(), symbols[0]); // @@@ or get percent, relay state, etc. passed to this function?
    menu_write_display(51, 0, 2, true, 1, mult->getMeasuredV(), symbols[1]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(0, 16, 2, false, 0, 0, symbols[state_1_symbol_number]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(13, 16, 2, false, 0, 0, symbols[state_2_symbol_number]); // @@@ or get percent, etc. passed to this function?
    menu_write_display(51, 16, 2, true, 1, mult->getI(), symbols[2]); // @@@ or get percent, etc. passed to this function?    
  }
  menu_display_display();
  Serial.print(message);
  Serial.print(" ");
  Serial.print(mult->getPercentage());
  Serial.print(" ");
  Serial.print(mult->getMeasuredV());
  Serial.print(" ");
  Serial.print(state_1_symbol_number * 10);
  Serial.print(" ");
  Serial.print(state_2_symbol_number * 10);
  Serial.print(" ");
  Serial.print(mult->getI());
  Serial.print(" ");
  Serial.print(mult->getV());
  Serial.println("");
}

void read_settings_from_eeprom() {
  // Read settings from EEPROM and put them into variables making them available to the program
  EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[0]), battery_ah); // @@@ do we need to declare float variable with f?
  EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[1]), topup_high_bound); // @@@ do we need to declare float variable with f?
  EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[2]), user_low_bound); // @@@ do we need to declare float variable with f?
  EEPROM.get(pgm_read_byte(&submenu_eeprom_addr[3]), user_high_bound); // @@@ do we need to declare float variable with f?
  mode = EEPROM.read(pgm_read_byte(&submenu_eeprom_addr[4])); // @@@ make all settings variable names with prefix
}

void setup() {
  Serial.begin(9600); // @@@ tmp
  // put your setup code here, to run once:
  menu_setup(BTN_1_PIN, BTN_2_PIN, BTN_3_PIN);
  read_settings_from_eeprom();
  mult->initialize(battery_ah); // @@@ tmp because mult constructor runs before
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, 0);

  delay(100); // @@@ delay before reading A3 after setting to INPUT? @@@ delay being used also by digitalRead A3 in loop!
  bool recalib_mode = (!digitalRead(BTN_2_PIN));
  if ((recalib_mode) || (mult->getError() == calibration_not_done_Error)) {
    // ask confirmation
    delay(200);
    menu_display_clearDisplay();
    menu_write_display(0,0,1,false,0,0,recalib_1);
    menu_display_display();
    while(!digitalRead(BTN_2_PIN));
    delay(800); // @@@ review and make defines for all delay times or other values, etc.
    while(!digitalRead(BTN_2_PIN)); // @@@ do this?
    while(digitalRead(BTN_2_PIN));
    menu_display_clearDisplay();
    menu_display_display();
    
    // do the re-calibration
    mult->reCalibrate();
    
    // display confirmation
    menu_display_clearDisplay();
    menu_write_display(0,0,1,false,0,0,recalib_2); // @@@ put char sizes in #defines also?
    menu_display_display();
    while (1);
  }
    
}

void loop() {
  // put your main code here, to run repeatedly:
  if(menu_loop(BTN_1_PIN, BTN_2_PIN, BTN_3_PIN)) {
    read_settings_from_eeprom();
  }

  //cleardisplay();
  mult->measure();

  if(mult->getError() == scaling_error) {
    // this is a fatal error, switch to TNEB, inform the user and do nothing
    digitalWrite(RELAY_PIN, 1);
    update_display(0);
  } else if(mult->getError() == V_LB_Error) {
    // switch to TNEB
    digitalWrite(RELAY_PIN, 1);
    update_display(1);
    //write_display("Error 1");
  } else if(mult->getError() == V_UB_Error) {
    // switch off TNEB
    digitalWrite(RELAY_PIN, 0);
    update_display(2);
  } else if(mult->getError() == perc_LB_Error) {
    // switch to TNEB
    digitalWrite(RELAY_PIN, 1);
    update_display(3);
  } else if(mult->getError() == perc_UB_Error) {
    // switch off TNEB
    digitalWrite(RELAY_PIN, 0);
    update_display(4);
  } else if(mult->getError() == no_error) {
    // check the user bound

    bool topup_mode = (!digitalRead(BTN_2_PIN)); // @@@ rename this var
    if (topup_mode) { // @@@ make it possible to cancel topup
      if (topup_wants_charge == CMD_RUN_CHARGE) {
        int delay_counter = 0;
        delay(800);
        menu_display_clearDisplay();
        menu_write_display(0,0,1,false,0,0,topup_3);
        menu_display_display();
        while(!digitalRead(BTN_2_PIN));
        delay(800); // @@@ review and make defines for all delay times or other values, etc.
        while(!digitalRead(BTN_2_PIN)); // @@@ do this?
        while(digitalRead(BTN_2_PIN) && (delay_counter < 3000)) { // @@@ make #define for delay, also below
          delay(1);
          delay_counter++;
        }
        if (delay_counter < 3000) { // @@@ is this too dirty? @@@ see above
          topup_wants_charge = CMD_STOP_CHARGE;
          // display confirmation
          menu_display_clearDisplay();
          menu_write_display(0,0,1,false,0,0,topup_4); // @@@ put char sizes in #defines also?
          menu_display_display();
          delay(800); // @@@ review all delay values
        }
      } else {
        int delay_counter = 0; // @@@ make into separate function in menu class
        delay(800);
        menu_display_clearDisplay();
        menu_write_display(0,0,1,false,0,0,topup_1);
        menu_display_display();
        while(!digitalRead(BTN_2_PIN));
        delay(800); // @@@ review and make defines for all delay times or other values, etc.
        while(!digitalRead(BTN_2_PIN)); // @@@ do this?
        while(digitalRead(BTN_2_PIN) && (delay_counter < 3000)) { // @@@ make #define for delay, also below
          delay(1);
          delay_counter++;
        }
        if (delay_counter < 3000) { // @@@ is this too dirty? @@@ see above
          topup_wants_charge = CMD_RUN_CHARGE;
          // display confirmation
          menu_display_clearDisplay();
          menu_write_display(0,0,1,false,0,0,topup_2); // @@@ put char sizes in #defines also?
          menu_display_display();
          delay(800); // @@@ review all delay values
        }
      }
    }
    if (mult->getPercentage() > topup_high_bound) {
      topup_wants_charge = CMD_STOP_CHARGE;
    }
    if (mult->getPercentage() > user_high_bound) {
      user_bound_wants_charge = CMD_STOP_CHARGE;
    }
    if (mult->getPercentage() < user_low_bound) {
      user_bound_wants_charge = CMD_RUN_CHARGE;
    }
      Serial.println(topup_wants_charge);
    if ((topup_wants_charge == CMD_RUN_CHARGE) || (user_bound_wants_charge == CMD_RUN_CHARGE)) {
      // switch on relay
      Serial.println("on");
      digitalWrite(RELAY_PIN, 1);
    } else if ((topup_wants_charge == CMD_STOP_CHARGE) || (user_bound_wants_charge == CMD_STOP_CHARGE)) {
      // switch off relay
      Serial.println("off");
      digitalWrite(RELAY_PIN, 0);
      topup_wants_charge = CMD_NEUTRAL;
      user_bound_wants_charge = CMD_NEUTRAL;
    }
    update_display(-1);
  }
}
