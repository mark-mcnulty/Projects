// AUTHOR: Mark McNulty
#include "stepper.h"

#define BAUD (9600)
#define ENABLE 6
#define stepPin 5
#define dirPin 4

// define the stepper motor
stepper motor(stepPin, dirPin, ENABLE, 1000);

// defines pins
void setup() {
  Serial.begin(9600);
}

/*
 * NOTES
 *  The motor takes 200 steps to go 360 degrees
 *  each step is 1.8 degrees
 *  
 *  There are 9 degrees per number 
 */
void loop() {
  // move the motor to the zero position
  motor.move(200);
  delay(2000);

  motor.move(-200);
  delay(2000);
}
