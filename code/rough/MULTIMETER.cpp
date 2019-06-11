#include "MULTIMETER.h"
#include "PINDEFINITIONS.h"
#include "CODEDEFINITIONS.h"
#include <EEPROM.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads;

// Global variables
float measurements[4];
float capacity;
float calib;
int error;

// Constructor
MULTIMETER::MULTIMETER(float C){

  // @@@ We have to shift all the pin initializations into a 
  // single setup function in order to ensure that we don't 
  // use the same pin for two different things...
  // Voltage measurement
  //pinMode(voltage_pin, INPUT);

  // Current measurement
  // @@@ Set EEEProm and only initialize if it is not yet initialized
  // @@@ List the EEEProm addresses that are already in use (0, 1, 2) ---> Use #define / const
  //pinMode(current_pin, INPUT);

  // @@@ tmp stuffed ads begin in reCalibrate function, needs to be fixed!!

  this->capacity = capacity;
  calibration();
}


// Destructor
MULTIMETER::~MULTIMETER(){/*nothing to destruct*/}


/**
 * Return the battery voltage.
 */
float MULTIMETER::batteryVoltage() {
  // Small resistor
  static int sR = 1200;
  // Big resistor
  static int bR = 10000;

  //return ((analogRead(voltage_pin) * Vref) / 1023) * (sR + bR) / sR;
  return(ads.readADC_SingleEnded(voltage_pin) * adcRatio / 1000 * ((sR + bR) / sR)); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?
}


/**
 * Triggered whenever the device is powered on and calibrates when
 * necessary...
 *
 * For determining the initial zero value of the current sensor when
 * the electrician has confirmed that the current is zero. This is
 * only done once since the electrician needs to be present.
 */
void MULTIMETER::calibration() {
  if (!((EEPROM.read(0) == 56) && (EEPROM.read(1) == 194) && (EEPROM.read(2) == 42))) {

    // The EEPROM probably isn't configured yet.
    reCalibrate();
  }
}

/**
 * Called from the UI or from calibration();
 *
 * For determining the zero value of the current sensor when the
 * electrician has confirmed that the current is zero. This is only
 * done rarely since the electrician needs to be present.
 */
void MULTIMETER::reCalibrate() {
  // @@@ tmp abusing this function 
  ads.begin();
  ads.setGain(GAIN_ONE); // @@@ which gain to use / are we using? @@@ do we need to wait before running setGain and/or is it right to run it after ads.begin?
  capacity = 240; // @@@ tmp

  delay(2000);
  ads.readADC_SingleEnded(cur_ref_pin);
  ads.readADC_SingleEnded(cur_sen_pin);
  ads.readADC_SingleEnded(cur_ref_pin);
  ads.readADC_SingleEnded(cur_sen_pin);
  delay(2000);
  
  // @@@ re-use code. code here for calib is same as in measure current function
  float v_cur_ref = 0;
  float v_cur_sen = 0;
   
  v_cur_ref = ((ads.readADC_SingleEnded(cur_ref_pin) * adcRatio)); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?
  v_cur_sen = ((ads.readADC_SingleEnded(cur_sen_pin) * adcRatio)); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?
 
  this->calib = (v_cur_sen - (v_cur_ref / 2));

  EEPROM.write(0, 56);
  EEPROM.write(1, 194);
  EEPROM.write(2, 42);

}
  
 
/**
 * Scale the battery voltage down to 12 Volts and return a 
 * standardized Array with percentage, voltage and current.
 * 
 * // Error messages
 *    const float no_error = 1;
 *    const float scaling_error = -1;
 *    const float V_LB_Error = -2;
 *    const float V_UB_Error = -3;
 *    const float perc_LB_Error = -4;
 *    const float perc_UB_Error = -5;
 *    
 */
void MULTIMETER::measure(){
    int error;
  
    // Return [percentage, scaled_voltage, current, measured_voltage]
    // Battery voltage pin: voltage_pin
    // Current: current_pin
    float percent;
    
    // Voltage measurement and scaling.
    float measuredVoltage = batteryVoltage();
    int divisor = (int) (measuredVoltage / scaling_boundary);

    // This should never be needed.
    if (divisor < 1) {
      // We will probably get a scaling error below.
      divisor = 1;
    } if (divisor > 4) { // @@@ should this be else if?
      // We will probably get a scaling error below.
      divisor = 4;
    }
    
    // Scaled voltage:
    float V = measuredVoltage / divisor;

    // Current measurement - no scaling
    float I = currentInAmps();

    percent = percentage(V, I, capacity);

    // @@@ Make sure all states are accounted for!
    if ((V < scaling_boundary) || (V < scaling_err_LB) || (V > scaling_err_UB)) {
      // This voltage doesn't make sense for any kind of battery, it's
      // neither a dead 12V/24V/36V/48V battery, nor a flat
      // 12V/24V/36V/48V battery => scaling error
      error = scaling_error;
      // @@@ Switch to TNEB and don't do anything.
    } else if (V < V_LB_Const) {
      // The voltage should never be this low! This boundary stays out of the way.
      error = V_LB_Error;      
    } else if (V > V_UB_Const) {
      // The voltage should never be this high! This boundary stays out of the way.
      error = V_UB_Error;
    } else if (percent < perc_LB_Cons) {
      // The percentage should never be this low! This boundary also stays out of the way.
      error = perc_LB_Error;
    } else if (percent > perc_UB_Cons) {
      // The percentage should never be this high! This boundary stays out of the way.
      error = perc_UB_Error;
    } else {
      // Everything is fine, let the user defined boundaries decide if the UPS gets charged or not.
      error = no_error;
    }

    // Averaging (digital capacitors / filters)...
    // @@@ Don't include error values in the average!
    this->measurements[0] = (0 * measurements[0] + percent) / 1; // @@@ tmp changed average weights
    this->measurements[1] = (0 * measurements[1] + V) / 1;
    this->measurements[2] = (0 * measurements[2] + I) / 1; // @@@ we have ovfs when averaging
    
    // Give the main function access to the unscaled voltage.
    // Don't show this to the user because the unscaled error might alarm them unnecessarily.
    this->measurements[3] = measuredVoltage;

    this->error = error;
}


float MULTIMETER::getPercentage() {
  return this->measurements[0];
}

float MULTIMETER::getV() {
  return this->measurements[1];
}

float MULTIMETER::getI() {
  return this->measurements[2];
}

float MULTIMETER::getMeasuredV() {
  return this->measurements[3];
}

float MULTIMETER::getError() {
  return this->error;
}




/**
 * Return the current in Amps.
 */
float MULTIMETER::currentInAmps() {
  float v_cur_ref = 0;
  float v_cur_sen = 0;
  float v_cur_dif = 0;
  
  v_cur_ref = ((ads.readADC_SingleEnded(cur_ref_pin) * adcRatio)); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?
  v_cur_sen = ((ads.readADC_SingleEnded(cur_sen_pin) * adcRatio)); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?

  v_cur_dif = (v_cur_sen - (v_cur_ref / 2) - calib);
 
  return (v_cur_dif / cur_sen_mv_ratio); // @@@ or should we keep it in millivolts for more precision and divide it after converting it to battery voltage range? / is it being treated as int or float?

  //return ((calib - analogRead(current_pin)) / 1023 * Vref) * 1000 / 33;
}


/**
 * Return the percentage charge of a battery, given the 
 * voltage, current and capacity of the battery...
 *
 * @@@ Use matrices of function coefficients.
 * @@@ Document it and discuss it with Dyuman.
 *
 */
float MULTIMETER::percentage (float U, float I, float C) {
  // I = Q / t, [I] = C / s = .... Ah / 3600 s = ... Ah / 1 h

    if (I > 0 && I < 0.00001) {
      I = 0.00001;
    }

    if (I <= 0 && I > -0.00001) {
      I = -0.00001;
    }

    // T in hours:
    float T = C / I;

    if (T < 0) {
      T = -T;
    }

  
  if (I > 0) { // @@@ what about when we are at or very close to 0 and value keeps fluctuating between -0.0xx and +0.0xx amps?
    // CHARGING

    if (T <= 5) {
      // 5 Formula: (x - 17.481) * (x - 14.408) * (x - 14.202) * (x -
      // 12.168) * (x - 17.452) * (x - 14.783) + 78.465

      // Serial.print("< 5 ");

      if (12.64 < U && U < 15.77) {
        float result = (U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return percent_function_percent_Error;
        }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (5 < T && T <= 10) {
      // 10 Formula: (x - 11.992) * (x - 14.325) * (x - 17.428) * (x -
      // 14.420) * (x - 14.353) * (x - 17.227) + 88.222)

      // return ((T - 5) * (10 formula)  + (10 - T) * (5 formula) / 5
      // Serial.print("5 < T && T < 10 ");

      if (12.49 < U && U < 15.77) {

        float result = ((T - 5) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222) 
                + (10 - T) * ((U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465)) / 5;

        if (0 <= result && result <= 100) {
          return result;
        } else {
          return percent_function_percent_Error;
        }
      } else {
        return percent_function_V_Error;
      }

    } else if (10 < T && T <= 20) {
      // 20 Formula: (x - 17.190) * (x - 14.171) * (x - 14.205) * (x -
      // 11.740) * (x - 17.159) * (x - 14.222) + 94.499)

      // return ((T - 10) * (20 formula) ) + (20 - T) * (10 formula) / 10
      // Serial.print("10 < T && T < 20 ");

      if (12.25 < U && U < 15.33) {
        float result = (((T - 10) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499))
                + (20 - T) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222)) / 10;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return percent_function_percent_Error;
        }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (20 < T && T <= 40) {
      // 40 Formula: (x - 14.6659) * (x - 14.8680) * (x - 9.8940) * (x
      // - 9.9535) * (x - 13.3392) * (x - 9.9839) + 100.1695

      // return: ((T - 20) * (40 formula) ) + (40 - T) * (20 formula) / 20
      // Serial.print("20 < T && T < 40 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 20) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)
                  + (40 - T) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499)) / 20;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return percent_function_percent_Error;
        }
      } else {
        return percent_function_V_Error;
      }
      
    } else if(40 < T && T <= 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) *
      // (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968

      // return ((T - 40) * (rest formula) ) + (200 - T) * (40 formula) / 160
      // Serial.print("40 < T && T < 200 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 40) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                + (200 - T) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)) / 160;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return percent_function_percent_Error;
        }
      } else {
        return percent_function_V_Error;
      }
    } else {
      // Rest
      // Serial.print("Rest ");
      // Serial.print(T);

      if (12.69 > U && U > 11.77) {
        float result = (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }

    }
  } else if (I < 0) {
    // DISCHARGING
    
    if (T >= 200) {
      // Rest

      if (12.69 > U && U > 11.77) {
        float result = (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }


    } else if (T >= 100 && T < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) *
      // (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968

      // return ((T - 100) * (rest formula) + (200 - T) * (100 formula)) / 100

      if (12.67 > U && U > 11.67) {
        float result = ((T - 100) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                  + (200 - T) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185)) / 100;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (20 <= T && T < 100) {
      // 100 formula: (x - 10.8400) * (x - 10.8709) * (x - 10.8594) *
      // (x - 7.9782) * (x - 10.9025) * (x - 10.8718) + 13.3185

      // return ((T - 20) * (100 formula) + (100 - T) * (20 formula)) / 80

      if (12.59 > U && U > 11.56) {
        float result = ((T - 20) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185) 
                    + (100 - T) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746)) / 80;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (10 <= T && T < 20) {
      // 20 formula: (x - 9.7996) * (x - 15.1168) * (x - 12.4056) * (x
      // - 15.2981) * (x - 9.8815) * (x - 9.7797) + 73.6746

      // return ((T - 10) * (20 formula) + (20 - T) * (10 formula)) / 10

      if (12.45 > U && U > 11.10) {
        float result = ((T - 10) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746) 
                    + (20 - T) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754)) / 10;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (5 <= T && T < 10) {
      // 10 formula: (x - 13.3140) * (x - 8.8627) * (x - 13.2982) * (x
      // - 13.3087) * (x - 8.9231) * (x - 8.9352) + 128.2754

      // return ((T - 5) * (10 formula) + (10 - T) * (5 formula)) / 5

      if (12.06 > U && U > 10.52) {
          float result = ((T - 5) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754) 
                      + (10 - T) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786)) / 5;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (3 <= T && T < 5) {
      // 5 formula: (x - 13.0987) * (x - 11.8714) * (x - 8.5070) * (x
      // - 13.2636) * (x - 8.5267) * (x - 8.5385) + 89.6786

      // return ((T - 3) * (5 formula) + (5 - T) * (3 formula)) / 2

      if (11.71 > U && U > 9.34) {
          float result = ((T - 3) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786) 
                      + (5 - T) * ((U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198)) / 2;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
      
    } else if (T < 3) {
      // 3 formula: (x - 10.1354) * (x - 10.1681) * (x - 10.1423) * (x
      // - 6.4437) * (x - 13.7005) * (x - 13.5256) + 27.9198

      // return 3 formula;

      if (11.71> U && U > 9.35) {
          float result = (U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return percent_function_percent_Error;
          }
      } else {
        return percent_function_V_Error;
      }
    }

    return -1.0;
  }
}
