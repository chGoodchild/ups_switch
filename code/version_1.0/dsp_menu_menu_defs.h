#ifndef DSP_MENU_MENU_DEFS
#define DSP_MENU_MENU_DEFS

// @@@ fine tune all values, settings, constants, and make constants (#define) for all applicable things

#define TEST_EEPROM_ADDR 60
#define TEST_EEPROM_VALUE 194 // @@@ verify at three different addresses?

// Menu
#define MAIN_MENU_ITEMS 5 // @@@ some are modified tmp
#define SUB_MENU_ITEMS 3
#define MENU_MAX_CHAR_COUNT 12
#define SUFFIX_MENU_MAX_CHAR_COUNT 4
const char mainmenu[MAIN_MENU_ITEMS][MENU_MAX_CHAR_COUNT] PROGMEM = {"Battery Ah", "Topup %", "Low bound", "High bound", "Mode"}; // @@@ use char or string? @@@ need the \0 ?
const char submenu[MAIN_MENU_ITEMS][SUB_MENU_ITEMS][MENU_MAX_CHAR_COUNT] PROGMEM = { { "", "", "" }, { "", "", "" }, { "", "", "" }, { "", "", "" }, { "Off", "Auto", "On" } };
const char suffixmenu[MAIN_MENU_ITEMS][SUFFIX_MENU_MAX_CHAR_COUNT] PROGMEM = { " Ah", " %", " %", " %", "" };
const float submenu_fl_defaults[MAIN_MENU_ITEMS] PROGMEM = { 120, 60, 60, 60, 1 }; // @@@ fix, set to 0 non appl. ones
const float submenu_fl_max_vals[MAIN_MENU_ITEMS] PROGMEM = { 500, 100, 100, 100, 2 }; // @@@ fix, set to 0 non appl. ones
const float submenu_fl_min_vals[MAIN_MENU_ITEMS] PROGMEM = { 10, 0, 0, 0, 0 }; // @@@ what happens when step is different multiple than min/max?
const float submenu_fl_step[MAIN_MENU_ITEMS] PROGMEM = { 10, 5, 5, 5, 1 };
const uint8_t submenu_int_defaults[MAIN_MENU_ITEMS] PROGMEM = { 120, 60, 60, 60, 1 };
const uint8_t submenu_int_max_vals[MAIN_MENU_ITEMS] PROGMEM = { 500, 100, 100, 100, 2 };
const uint8_t submenu_int_min_vals[MAIN_MENU_ITEMS] PROGMEM = { 10, 0, 0, 0, 0 };
const uint8_t submenu_int_step[MAIN_MENU_ITEMS] PROGMEM = { 10, 5, 5, 5, 1 };
const uint8_t submenu_eeprom_addr[MAIN_MENU_ITEMS] PROGMEM = { 52, 4, 8, 12, 16 }; // @@@ addresses
const bool submenu_float[MAIN_MENU_ITEMS] = { 1, 1, 1, 1, 0 };

// Display strings @@@ better names and comment
#define ad_x 90
#define ad_y 18
#define ad_s 2
const char ad[4] PROGMEM = "...";
const char eeprom_err_msg_1[16] PROGMEM = "EEPROM not init";
const char prmpt_message[8][77] PROGMEM = { "Restore default\nsettings, press X to confirm", "Default settings\nrestored, press Reset" ,"Recalibrate current\nsensor, ensure\ncurrent is zero and\npress X to confirm...", "Current sensor\nrecalibrated, press\nReset", "Start battery topup?\nPress X to confirm" , "Battery topup started" , "Cancel battery topup?\nPress X to confirm" , "Battery topup\ncancelled" }; // @@@ make sure \n and \0 count as single character and are understood // @@@ re-count number of chars in each var and update constructor

#endif
