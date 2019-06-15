#ifndef MULT
#define MULT
     
#include <Arduino.h>
     
class MULTIMETER {

// Global variables
float measurements[4]; // @@@ maybe variables should be initialized to 0?
float capacity;
float calib;
int error;

 public:
  MULTIMETER(float capacity);
  ~MULTIMETER();
  void calibration();
  void reCalibrate();
  float batteryVoltage();
  void measure();
  float currentInAmps();
  float getPercentage();
  float getV();
  float getI();
  float getMeasuredV();
  float getError();
  float percentage (float U, float I, float C);
};

#endif
