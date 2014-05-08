// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _FreeIMU_heading_H_
#define _FreeIMU_heading_H_
#include "Arduino.h"
//add your includes for the project FreeIMU_heading here

#include <ADXL345.h>
#include <bma180.h>
#include <HMC58X3.h>
#include <ITG3200.h>
#include <MS561101BA.h>
#include <I2Cdev.h>
#include <MPU60X0.h>
#include <EEPROM.h>
#include "FreeIMU.h"
#include <Wire.h>
#include <SPI.h>

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project FreeIMU_heading here




//Do not add code below this line
#endif /* _FreeIMU_heading_H_ */
