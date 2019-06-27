#ifndef DSP_MENU // @@@ do we need this?
#define DSP_MENU // @@@ do we need this?
     
#include <Arduino.h> // @@@ do we need this?
     
void menu_write_display(int x, int y, int s, bool display_number, int dec, float number, const char text[]);
void menu_setup(int dwn_btn, int up_btn, int sel_btn);
bool menu_loop(int dwn_btn, int up_btn, int sel_btn);
void menu_display_display();
void menu_display_clearDisplay();
bool menu_show_prompt(int init_delay, int message1, int message2, int timeout, int btn_pin);
#endif // @@@ do we need this?
