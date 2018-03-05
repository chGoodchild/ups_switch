void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:
  static float C = 100;
  static float I = 20; // C5 only
  static float U = 11.8;

  percentage(U, I, C);

  Serial.println("");

  Serial.print(U);
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

  delay(25);
  U = U + 0.01;

}

float percentage (float U, float I, float C) {
  // I = Q / t, [I] = C / s = .... Ah / 3600 s = ... Ah / 1 h
  
  // T in hours:
  float T = C / (I);

  if (I > 0) {
    // CHARGING

    if (T < 5) {
      // 5 Formula: (x - 17.481) * (x - 14.408) * (x - 14.202) * (x - 12.168) * (x - 17.452) * (x - 14.783) + 78.465

      float result = (U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465;

      return result;
      
    } else if (5 < T < 10) {
      // 10 Formula: (x - 11.992) * (x - 14.325) * (x - 17.428) * (x - 14.420) * (x - 14.353) * (x - 17.227) + 88.222)      
      // return ((T - 5) * (10 formula)  + (10 - T) * (5 formula) / 5

      if (12.64 < U < 15.77) {

        float result = ((T - 5) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222) 
                + (10 - T) * ((U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465)) / 5;

        if (0 <= result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }

    } else if (10 < T < 20) {
      // 20 Formula: (x - 17.190) * (x - 14.171) * (x - 14.205) * (x - 11.740) * (x - 17.159) * (x - 14.222) + 94.499)
      // return ((T - 10) * (20 formula) ) + (20 - T) * (10 formula) / 10

      if (12.49 < U < 15.33) {
        float result = (((T - 10) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499))
                + (20 - T) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222)) / 10;

        if (0 <= result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if (20 < T < 40) {
      // 40 Formula: (x - 14.6659) * (x - 14.8680) * (x - 9.8940) * (x - 9.9535) * (x - 13.3392) * (x - 9.9839) + 100.1695
      // return: ((T - 20) * (40 formula) ) + (40 - T) * (20 formula) / 20

      if (12.25 < U < 14.90) {
        float result = ((T - 20) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)
                  + (40 - T) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499)) / 20;

        if (0 <= result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
      
    } else if(40 < T < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 40) * (200 formula) ) + (200 - T) * (40 formula) / 160
      
      if (11.99 < U < 13.34) {
        float result = ((T - 40) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                + (200 - T) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)) / 160;

        if (0 <= result <= 100) {
          return result;          
        } else {
          return -2;
        }
      } else {
        return -1;
      }
    } else {
      // Rest
      return (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;
    }
  } else if (I < 0) {
    // DISCHARGING
    
    if (T > 200) {
      // Rest
      return (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;

    } else if (T < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((T - 100) * (200 formula) + (200 - T) * (100 formula)) / 100


      if (12.65 > U > 11.47) {
        float result = ((T - 100) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
                  + (200 - T) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185)) / 100;

          if (0 <= result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (20 < T < 100) {
      // 100 formula: (x - 10.8400) * (x - 10.8709) * (x - 10.8594) * (x - 7.9782) * (x - 10.9025) * (x - 10.8718) + 13.3185
      // return ((T - 20) * (100 formula) + (100 - T) * (20 formula)) / 80

      float result = ((T - 20) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185) 
                  + (100 - T) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746)) / 80;

      if (12.65 > U > 11.21) {
          if (0 <= result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (10 < T < 20) {
      // 20 formula: (x - 9.7996) * (x - 15.1168) * (x - 12.4056) * (x - 15.2981) * (x - 9.8815) * (x - 9.7797) + 73.6746
      // return ((T - 10) * (20 formula) + (20 - T) * (10 formula)) / 10

      float result = ((T - 10) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746) 
                  + (20 - T) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754)) / 10;

      if (12.66 > U > 11.27) {
          if (0 <= result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (5 < T < 10) {
      // 10 formula: (x - 13.3140) * (x - 8.8627) * (x - 13.2982) * (x - 13.3087) * (x - 8.9231) * (x - 8.9352) + 128.2754
      // return ((T - 5) * (10 formula) + (10 - T) * (5 formula)) / 5

      float result = ((T - 5) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754) 
                  + (10 - T) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786)) / 5;

      if (12.66 > U > 11.27) {
          if (0 <= result <= 100) {
            return result;          
          } else {
            return -2;
          }
      } else {
        return -1;
      }
      
    } else if (3 < T < 5) {
      // 5 formula: (x - 13.0987) * (x - 11.8714) * (x - 8.5070) * (x - 13.2636) * (x - 8.5267) * (x - 8.5385) + 89.6786
      // return ((T - 3) * (5 formula) + (5 - T) * (3 formula)) / 2

      float result = ((T - 3) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786) 
                  + (5 - T) * ((U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198)) / 2;

      if (12.66 > U > 11.27) {
          if (0 <= result <= 100) {
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

      return (U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198;

    }

    return -1.0;
  }
}

