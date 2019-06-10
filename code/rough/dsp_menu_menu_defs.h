#ifndef DSP_MENU_MENU_DEFS
#define DSP_MENU_MENU_DEFS

// @@@ fine tune all values, settings, constants, and make constants (#define) for all applicable things

#define TEST_EEPROM_ADDR 60
#define TEST_EEPROM_VALUE 194 // @@@ verify at three different addresses?

// Menu
#define MAIN_MENU_ITEMS 13 // @@@ some are modified tmp
#define SUB_MENU_ITEMS 3
#define MENU_MAX_CHAR_COUNT 12
#define SUFFIX_MENU_MAX_CHAR_COUNT 4
const char mainmenu[MAIN_MENU_ITEMS][MENU_MAX_CHAR_COUNT] PROGMEM = {"Max tot. 1", "Max tot. 2", "Max tot. 3", "Max tot. 4", "Priority 1", "Priority 2", "Priority 3", "Priority 4", "Est. cur 1", "Est. cur 2", "Est. cur 3", "Est. cur 4", "Extra shed"}; // @@@ use char or string? @@@ need the \0 ?
const char submenu[MAIN_MENU_ITEMS][SUB_MENU_ITEMS][MENU_MAX_CHAR_COUNT] PROGMEM = { { "", "", "" }, { "", "", "" }, { "", "", "" }, { "", "", "" }, { "Low", "Normal", "High" }, { "Low", "Normal", "High" }, { "Low", "Normal", "High" }, { "Low", "Normal", "High" }, { "", "", "" }, { "", "", "" }, { "", "", "" }, { "", "", "" }, { "Disabled", "Enabled", "" } };
const char suffixmenu[MAIN_MENU_ITEMS][SUFFIX_MENU_MAX_CHAR_COUNT] PROGMEM = { " A", " A", " A", " A", "", "", "", "", " A", " A", " A", " A", "" };
const float submenu_fl_defaults[MAIN_MENU_ITEMS] PROGMEM = { 60, 60, 60, 60, 1, 1, 1, 1, 0, 0, 0, 0, 1 }; // @@@ fix, set to 0 non appl. ones
const float submenu_fl_max_vals[MAIN_MENU_ITEMS] PROGMEM = { 60, 60, 60, 60, 2, 2, 2, 2, 15, 15, 15, 15, 1 }; // @@@ fix, set to 0 non appl. ones
const float submenu_fl_min_vals[MAIN_MENU_ITEMS] PROGMEM = { 0.5, 0.5, 0.5, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const float submenu_fl_step[MAIN_MENU_ITEMS] PROGMEM = { 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 0.20, 0.20, 0.20, 0.20, 1 };
const uint8_t submenu_int_defaults[MAIN_MENU_ITEMS] PROGMEM = { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1 };
const uint8_t submenu_int_max_vals[MAIN_MENU_ITEMS] PROGMEM = { 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1 };
const uint8_t submenu_int_min_vals[MAIN_MENU_ITEMS] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const uint8_t submenu_int_step[MAIN_MENU_ITEMS] PROGMEM = { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1 };
const uint8_t submenu_eeprom_addr[MAIN_MENU_ITEMS] PROGMEM = { 52, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48 }; // @@@ addresses
const bool submenu_float[MAIN_MENU_ITEMS] = { 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0 };

// Display strings @@@ better names and comment
const char ad[3] PROGMEM = "..";
const char eeprom_err_msg_1[16] PROGMEM = "EEPROM not init";
const char reset_defaults_1[45] PROGMEM = "Restore default\nsettings, press X to confirm"; // @@@ make sure \n and \0 count as single character and are understood
const char reset_defaults_2[39] PROGMEM = "Default settings\nrestored, press Reset";

#endif
