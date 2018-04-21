// Refference voltage
static float Vref = 5;

float calibration = 0;
// Capacity in AH
float C = 26;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  // Voltage measurement
  pinMode(A0, INPUT);
  // Current measurement
  pinMode(A7, INPUT);
  calibration = analogRead(A7);
}


void loop() {

  static float measurements[3];
  measure(&measurements[0]);

  Serial.print("Percentage: ");
  Serial.print(measurements[0]);
  Serial.print("\t");
  Serial.print("Voltage: ");
  Serial.print(measurements[1]);
  Serial.print("\t");
  Serial.print("Current: ");
  Serial.print(measurements[2]);
  Serial.println("\t");
  
  // testPercentage();
}

void testPercentage (float Uin) {
    // put your main code here, to run repeatedly:
  static float C = 100;
  static float I = 0; // C5 only
  static float U = Uin;

  Serial.println("");

  //Serial.print(U);
  Serial.print("\t");

  I = 20;
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 10;  // C10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 5; // C20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 2.5; // C40
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 0; // rest
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -1; // D100
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -5; // D20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -10; // D10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -20; // D5
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -33.3; // D3
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -50; // D2
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  U = U + 0.01;
  
  testPercentage(U);
}

/**
 * Return the battery voltage.
 */
float batteryVoltage() {
  // Small resistor
  static int sR = 317;
  // Big resistor
  static int bR = 4590;

  return ((analogRead(A0) * Vref) / 1023) * (sR + bR) / sR;
}



/**
 * Return the current in Amps.
 */
float currentInAmps() {
  return ((calibration - analogRead(A7)) / 1023 * Vref) * 1000 / 33;
}



/**
 * Scale the battery voltage down to 12 Volts and return a 
 * standardized Array with percentage, voltage and current.
 */
float measure(float *measurements) {
    // Return [percentage, voltage, current]
    // Battery voltage pin: A0
    // Current: A7
    float percent;
    
    // Voltage measurement and scaling
    float measuredVoltage = batteryVoltage();
    int divisor = (int) (measuredVoltage / 9.5);
    if (divisor < 1) {
      divisor = 1;
    }
    // Scaled voltage:
    float V = measuredVoltage / divisor;

    // Current measurement - no scaling
    float I = currentInAmps();

    // Can't be right: scaling error
    if (V < 8.5 || V > 15.5) {
      percent = -3;
    } else {
      percent = percentage(V, I, C);
    }

    // measurements[0] = (199 * measurements[0] + percent) / 200;
    measurements[0] = percent;
    // measurements[1] = (19 * measurements[1] + V) / 20;
    // measurements[2] = (19 * measurements[2] + I) / 20;
    measurements[1] = V;
    measurements[2] = I;
}


/**
 * Return the percentage charge of a battery, given the 
 * voltage, current and capacity of the battery...
 */
float percentage (float U, float I, float C) {
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

  
  if (I > 0) {
    // CHARGING

    if (T <= 5) {
      // 5 Formula: (x - 17.481) * (x - 14.408) * (x - 14.202) * (x - 12.168) * (x - 17.452) * (x - 14.783) + 78.465
      // Serial.print("< 5 ");

      if (12.64 < U && U < 15.77) {
        float result = (U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if (5 < T && T <= 10) {
      // 10 Formula: (x - 11.992) * (x - 14.325) * (x - 17.428) * (x - 14.420) * (x - 14.353) * (x - 17.227) + 88.222)      
      // return ((T - 5) * (10 formula)  + (10 - T) * (5 formula) / 5
      // Serial.print("5 < T && T < 10 ");

      if (12.49 < U && U < 15.77) {

        float result = ((T - 5) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222) 
                + (10 - T) * ((U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465)) / 5;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }

    } else if (10 < T && T <= 20) {
      // 20 Formula: (x - 17.190) * (x - 14.171) * (x - 14.205) * (x - 11.740) * (x - 17.159) * (x - 14.222) + 94.499)
      // return ((T - 10) * (20 formula) ) + (20 - T) * (10 formula) / 10
      // Serial.print("10 < T && T < 20 ");

      if (12.25 < U && U < 15.33) {
        float result = (((T - 10) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499))
                + (20 - T) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222)) / 10;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if (20 < T && T <= 40) {
      // 40 Formula: (x - 14.6659) * (x - 14.8680) * (x - 9.8940) * (x - 9.9535) * (x - 13.3392) * (x - 9.9839) + 100.1695
      // return: ((T - 20) * (40 formula) ) + (40 - T) * (20 formula) / 20
      // Serial.print("20 < T && T < 40 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 20) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)
                  + (40 - T) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499)) / 20;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if(40 < T && T <= 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 40) * (rest formula) ) + (200 - T) * (40 formula) / 160
      // Serial.print("40 < T && T < 200 ");

      if (11.99 < U && U < 13.34) {
        float result = ((T - 40) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                + (200 - T) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)) / 160;

        if (0 <= result && result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
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
            return -2;
          }
      } else {
        return -1;
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
            return -2;
          }
      } else {
        return -1;
      }


    } else if (T >= 100 && T < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 100) * (rest formula) + (200 - T) * (100 formula)) / 100

      if (12.67 > U && U > 11.67) {
        float result = ((T - 100) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                  + (200 - T) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185)) / 100;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (20 <= T && T < 100) {
      // 100 formula: (x - 10.8400) * (x - 10.8709) * (x - 10.8594) * (x - 7.9782) * (x - 10.9025) * (x - 10.8718) + 13.3185
      // return ((T - 20) * (100 formula) + (100 - T) * (20 formula)) / 80

      if (12.59 > U && U > 11.56) {
        float result = ((T - 20) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185) 
                    + (100 - T) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746)) / 80;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (10 <= T && T < 20) {
      // 20 formula: (x - 9.7996) * (x - 15.1168) * (x - 12.4056) * (x - 15.2981) * (x - 9.8815) * (x - 9.7797) + 73.6746
      // return ((T - 10) * (20 formula) + (20 - T) * (10 formula)) / 10

      if (12.45 > U && U > 11.10) {
        float result = ((T - 10) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746) 
                    + (20 - T) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754)) / 10;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (5 <= T && T < 10) {
      // 10 formula: (x - 13.3140) * (x - 8.8627) * (x - 13.2982) * (x - 13.3087) * (x - 8.9231) * (x - 8.9352) + 128.2754
      // return ((T - 5) * (10 formula) + (10 - T) * (5 formula)) / 5

      if (12.06 > U && U > 10.52) {
          float result = ((T - 5) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754) 
                      + (10 - T) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786)) / 5;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (3 <= T && T < 5) {
      // 5 formula: (x - 13.0987) * (x - 11.8714) * (x - 8.5070) * (x - 13.2636) * (x - 8.5267) * (x - 8.5385) + 89.6786
      // return ((T - 3) * (5 formula) + (5 - T) * (3 formula)) / 2

      if (11.71 > U && U > 9.34) {
          float result = ((T - 3) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786) 
                      + (5 - T) * ((U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198)) / 2;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (T < 3) {
      // 3 formula: (x - 10.1354) * (x - 10.1681) * (x - 10.1423) * (x - 6.4437) * (x - 13.7005) * (x - 13.5256) + 27.9198
      // return 3 formula;

      if (11.71> U && U > 9.35) {
          float result = (U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198;

          if (0 <= result && result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
    }

    return -1.0;
  }
}


