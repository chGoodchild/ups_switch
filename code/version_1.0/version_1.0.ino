// Include files
#include <EEPROM.h>
#include "MULTIMETER.h"
#include "PINDEFINITIONS.h"
#include "CODEDEFINITIONS.h"
#include "DSP_MENU.h"
#include "dsp_menu_menu_defs.h"

// Compile time settings
#define RELAY_PIN 6
#define BTN_1_PIN 8
#define BTN_2_PIN 9
#define BTN_3_PIN 10

// Variables for storing in memory during runtime menu setting values read from EEPROM
float battery_ah = 0;
float topup_high_bound = 0;
float user_high_bound = 0;
float user_low_bound = 0;
uint8_t mode = 0;

// Runtime variables
uint8_t topup_wants_charge = 0;
uint8_t user_bound_wants_charge = 0;

MULTIMETER *mult = new MULTIMETER(120); // @@@ update ah

void update_display(uint8_t message) {
  menu_display_clearDisplay();
  menu_write_display(0, 0, 2, true, 1, "");
  menu_display_display();
}

void read_settings_from_eeprom() {
  // @@@ here read EEPROM and put values into above variables, e.g. battery_ah
}

void setup() {
  // put your setup code here, to run once:
  menu_setup(BTN_1_PIN, BTN_2_PIN, BTN_3_PIN);
  mult->reCalibrate(); // @@@ tmp because mult constructor runs before
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, 0);
  read_settings_from_eeprom();
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
  } else if(mult->getError() == V_LB_Error) {
    // switch to TNEB
    digitalWrite(RELAY_PIN, 1);
    //write_display("Error 1");
  } else if(mult->getError() == V_UB_Error) {
    // switch off TNEB
    digitalWrite(RELAY_PIN, 0);
  } else if(mult->getError() == perc_LB_Error) {
    // switch to TNEB
    digitalWrite(RELAY_PIN, 1);
  } else if(mult->getError() == perc_UB_Error) {
    // switch off TNEB
    digitalWrite(RELAY_PIN, 0);
  } else if(mult->getError() == no_error) {
    // check the user bound
    if (false) {
      topup_wants_charge = 1;
    }
    if (mult->getPercentage() > topup_high_bound) {
      topup_wants_charge = -1;
    }
    if (mult->getPercentage() > user_high_bound) {
      user_bound_wants_charge = -1;
    }
    if (mult->getPercentage() < user_low_bound) {
      user_bound_wants_charge = 1;
    }
    if ((topup_wants_charge == 1) || (user_bound_wants_charge == 1)) {
      // switch on relay
      digitalWrite(RELAY_PIN, 1);
    } else if ((topup_wants_charge == -1) || (user_bound_wants_charge == -1)) {
      // switch off relay
      digitalWrite(RELAY_PIN, 0);
      topup_wants_charge = 0;
      user_bound_wants_charge = 0;
    }
  }
}
