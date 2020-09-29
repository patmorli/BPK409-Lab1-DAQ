/*
 * This code measures 200Hz data with 2G from the Sparkfun Accelerometer
 * It is based on the Library for the MMA8452Q
 * Modified by Patrick Mayerhofer July 2020
 */


/*
  Library for the MMA8452Q
  By: Jim Lindblom and Andrea DeVore
  SparkFun Electronics

  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/14587

  This sketch uses the SparkFun_MMA8452Q library to initialize
  the accelerometer and stream raw x, y, z, acceleration
  values from it.

  Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

  The MMA8452Q is a 3.3V max sensor, so you'll need to do some
  level-shifting between the Arduino and the breakout. Series
  resistors on the SDA and SCL lines should do the trick.

  License: This code is public domain, but if you see me
  (or any other SparkFun employee) at the local, and you've
  found our code helpful, please buy us a round (Beerware
  license).

  Distributed as is; no warrenty given.

*/

// To do: change Serial monitor baud rate to 56700

#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    // Click here to get the library: http://librarymanager/All#SparkFun_MMA8452Q

MMA8452Q accel;                   // create instance of the MMA8452 class

void setup() {
  Serial.begin(57600);
  Wire.begin();

  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }
  accel.setScale(SCALE_2G);
  accel.setDataRate(ODR_200);
  
}

void loop() {
  if (accel.available()) {      // Wait for new data from accelerometer
    // Raw of acceleration of x, y, and z directions
    Serial.print(double(accel.getX())/1024);
    Serial.print("\t");
    Serial.print(double(accel.getY())/1024);
    Serial.print("\t");
    Serial.print(double(accel.getZ())/1024);
    Serial.print("\t");
    Serial.print(millis()); // uncomment this if you want to try the experiment in the serial plotter
    Serial.println(); 
  }
}
