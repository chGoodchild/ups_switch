void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:
  static float C = 100;
  static float I = 180; // C5 only
  static float U = 9.4;

  Serial.println(percentage(U, I, C));
  Serial.print("\t");

  I = 360;  // C10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 720; // C20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 720; // C40
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = 0; // rest
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -3600; // D100
  Serial.print(percentage(U, I, C));
  Serial.print("\t");

  I = -720; // D20
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -360; // D10
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -180; // D5
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  I = -108; // D3
  Serial.print(percentage(U, I, C));
  Serial.print("\t");
  
  delay(20);
  U = U + 0.1;

}

float percentage (float U, float I, float C) {
  // I = Q / t, [I] = C / s = .... Ah / 3600 s = ... Ah / 1 h
  
  // Time in hours:
  float time = C / (I * 3600);

  if (I > 0) {
    // Charging
    if (time < 5) {
      // 5 Formula: (x - 17.481) * (x - 14.408) * (x - 14.202) * (x - 12.168) * (x - 17.452) * (x - 14.783) + 78.465
      
      return (U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465;
      
    } else if (time < 10) {
      // 10 Formula: (x - 11.992) * (x - 14.325) * (x - 17.428) * (x - 14.420) * (x - 14.353) * (x - 17.227) + 88.222)      
      // return ((time - 5) * (10 formula)  + (10 - time) * (5 formula) / 5
      return ((time - 5) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222) 
              + (10 - time) * ((U - 17.481) * (U - 14.408) * (U - 14.202) * (U - 12.168) * (U - 17.452) * (U - 14.783) + 78.465)) / 5;
      
    } else if (time < 20) {
      // 20 Formula: (x - 17.190) * (x - 14.171) * (x - 14.205) * (x - 11.740) * (x - 17.159) * (x - 14.222) + 94.499)
      // return ((time - 10) * (20 formula) ) + (20 - time) * (10 formula) / 10

      return (((time - 10) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499))
              + (20 - time) * ((U - 11.992) * (U - 14.325) * (U - 17.428) * (U - 14.420) * (U - 14.353) * (U - 17.227) + 88.222)) / 10;
      
    } else if (time < 40) {
      // 40 Formula: (x - 14.6659) * (x - 14.8680) * (x - 9.8940) * (x - 9.9535) * (x - 13.3392) * (x - 9.9839) + 100.1695
      // return: ((time - 20) * (40 formula) ) + (40 - time) * (20 formula) / 20

      return ((time - 20) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)
              + (40 - time) * ((U - 17.190) * (U - 14.171) * (U - 14.205) * (U - 11.740) * (U - 17.159) * (U - 14.222) + 94.499)) / 20;
      
    } else if(time < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((time - 40) * (200 formula) ) + (200 - time) * (40 formula) / 160

      return ((time - 40) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
              + (200 - time) * ((U - 14.6659) * (U - 14.8680) * (U - 9.8940) * (U - 9.9535) * (U - 13.3392) * (U - 9.9839) + 100.1695)) / 160;
    } else {
      // Rest
      return (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;
    }
    
  } else if (I < 0) {
    // Discharging
    if (time > 200) {
      // Rest
      return (U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968;
      
    } else if (time < 200) {
      // Rest formula: (x - 11.4656) * (x - 14.9852) * (x + 6.5100) * (x - 11.1390) * (x - 14.1120) * (x - 12.0202) + 20.7968
      // return ((time - 100) * (200 formula) + (200 - time) * (100 formula)) / 100

      return ((time - 100) * ((U - 11.4656) * (U - 14.9852) * (U + 6.5100) * (U - 11.1390) * (U - 14.1120) * (U - 12.0202) + 20.7968) 
              + (200 - time) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185)) / 100;
      
    } else if (time < 100) {
      // 100 formula: (x - 10.8400) * (x - 10.8709) * (x - 10.8594) * (x - 7.9782) * (x - 10.9025) * (x - 10.8718) + 13.3185
      // return ((time - 20) * (100 formula) + (100 - time) * (20 formula)) / 80

      return ((time - 20) * ((U - 10.8400) * (U - 10.8709) * (U - 10.8594) * (U - 7.9782) * (U - 10.9025) * (U - 10.8718) + 13.3185) 
              + (100 - time) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746)) / 80;

      
    } else if (time < 20) {
      // 20 formula: (x - 9.7996) * (x - 15.1168) * (x - 12.4056) * (x - 15.2981) * (x - 9.8815) * (x - 9.7797) + 73.6746
      // return ((time - 10) * (20 formula) + (20 - time) * (10 formula)) / 10

      return ((time - 10) * ((U - 9.7996) * (U - 15.1168) * (U - 12.4056) * (U - 15.2981) * (U - 9.8815) * (U - 9.7797) + 73.6746) 
              + (20 - time) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754)) / 10;

      
    } else if (time < 10) {
      // 10 formula: (x - 13.3140) * (x - 8.8627) * (x - 13.2982) * (x - 13.3087) * (x - 8.9231) * (x - 8.9352) + 128.2754
      // return ((time - 5) * (10 formula) + (10 - time) * (5 formula)) / 5

      return ((time - 5) * ((U - 13.3140) * (U - 8.8627) * (U - 13.2982) * (U - 13.3087) * (U - 8.9231) * (U - 8.9352) + 128.2754) 
              + (10 - time) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786)) / 5;

      
    } else if (time < 5) {
      // 5 formula: (x - 13.0987) * (x - 11.8714) * (x - 8.5070) * (x - 13.2636) * (x - 8.5267) * (x - 8.5385) + 89.6786
      // return ((time - 3) * (5 formula) + (5 - time) * (3 formula)) / 2

      return ((time - 3) * ((U - 13.0987) * (U - 11.8714) * (U - 8.5070) * (U - 13.2636) * (U - 8.5267) * (U - 8.5385) + 89.6786) 
              + (5 - time) * ((U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198)) / 2;

    } else if (time < 3) {
      // 3 formula: (x - 10.1354) * (x - 10.1681) * (x - 10.1423) * (x - 6.4437) * (x - 13.7005) * (x - 13.5256) + 27.9198
      // return 3 formula;

      return (U - 10.1354) * (U - 10.1681) * (U - 10.1423) * (U - 6.4437) * (U - 13.7005) * (U - 13.5256) + 27.9198;

    }

    return -1.0;
  }
}

