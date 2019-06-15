#include <EEPROM.h>
#define MAIN_MENU_ITEMS 5 // @@@ some are modified tmp
#define TEST_EEPROM_ADDR 60
#define TEST_EEPROM_VALUE 194 // @@@ verify at three different addresses?

const bool submenu_float[MAIN_MENU_ITEMS] = { 1, 1, 1, 1, 0 };
const uint8_t submenu_eeprom_addr[MAIN_MENU_ITEMS] PROGMEM = { 52, 4, 8, 12, 16}; // @@@ addresses
const float submenu_fl_defaults[MAIN_MENU_ITEMS] PROGMEM = { 120, 60, 60, 60, 1 }; // @@@ fix, set to 0 non appl. ones
const uint8_t submenu_int_defaults[MAIN_MENU_ITEMS] PROGMEM = { 120, 60, 60, 60, 1 };

void setup() {
    uint8_t iterator = 0; // @@@ consistency in declaring iterators
    for(iterator = 0; iterator < MAIN_MENU_ITEMS; iterator++) { // @@@ 13
      if(submenu_float[iterator]) {
          EEPROM.put(pgm_read_byte(&submenu_eeprom_addr[iterator]), pgm_read_float(&submenu_fl_defaults[iterator])); // @@@ do we need to declare float variable with f?
      } else {
          EEPROM.write(pgm_read_byte(&submenu_eeprom_addr[iterator]), pgm_read_byte(&submenu_int_defaults[iterator])); // @@@ first check if value changed
      }
    }

    EEPROM.write(TEST_EEPROM_ADDR, TEST_EEPROM_VALUE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
