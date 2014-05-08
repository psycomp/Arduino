// Do not remove the include below
#include "FreeIMU_heading.h"

FreeIMU my3IMU = FreeIMU();
float ypr[3]; // yaw pitch roll

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(500);
  my3IMU.init(false);
  delay(500);
}

void loop() {
  my3IMU.getYawPitchRoll(ypr);
  Serial.println(ypr[0] + 180);
  delay(500);
}
