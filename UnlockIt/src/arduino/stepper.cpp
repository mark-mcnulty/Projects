#include <cmath>
#include "stepper.h"
using namespace std;

/*
NOTES:
    - The motor takes 200 steps to go 360 degrees
    - each step is 1.8 degrees
    - There are 9 degrees per number
    - 5 steps per number for the lock
*/

stepper::stepper(int stepPinIn, int dirPinIn, int delayVelocityIn) {
    // define the pins
    stepPin = stepPinIn;
    dirPin = dirPinIn;
    delayVelocity = delayVelocityIn;
    steps = 0;
    angle = 0;

    // set the pins as outputs
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

/*
void move(int stepsIn)

This function moves the stepper motor a certain number of steps
*/
void stepper::move(int stepsIn){
    // set the direction
    if (stepsIn > 0) {
        digitalWrite(dirPin, HIGH);
    }
    else {
        digitalWrite(dirPin, LOW);
    }

    // rotate the motor
    for(int x = 0; x < stepsIn; x++) {
        digitalWrite(stepPin, HIGH); 
        delayMicroseconds(delayVelocity);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(stepPin, LOW); 
        delayMicroseconds(delayVelocity); 
    }
}

/*
void moveRelSteps(int stepsIn)

INPUT: stepsIn - the number of steps to move the motor rel from the CURRENT position

OUTPUT: none

FUNCTION: moves the motor to the absolute position of stepsIn relative to the CURRENT position
*/
void stepper::moveRelSteps(int stepsIn){
    // redefine the overall variables
    steps += stepsIn;

    move(stepsIn);
}

/*
void moveAbsSteps(int stepsIn)

INPUT: stepsIn - the number of steps to move the motor abs from the zero position

OUTPUT: none

FUNCTION: moves the motor to the absolute position of stepsIn relative to the zero position
*/
void stepper::moveAbsSteps(int stepsIn){
    // calculate the number of steps to move
    int moveSteps = stepsIn - steps;
    steps = stepsIn;

    // move the motor 
    move(moveSteps);
}

/*
void moveRelAngle(float angle)

INPUT: angle - the angle relative to the CURRENT position to move the motor

OUTPUT: none

FUNCTION: moves the motor to the RELATIVE angle relative to the CURRENT position
*/
void stepper::moveRelAngle(float angleIn){
    // redefine the overall variables
    int moveStep = round(angleIn / 1.8);

    // redefine the overall variables
    steps += moveStep;
    angle += round(angleIn / 1.8) * 1.8;

    // move the motor
    move(moveStep);
}

/*
void moveAbsAngle(float angle)

INPUT: angle - the angle absolute to the zero position

OUTPUT: none

FUNCTION: moves the motor to the ABSOLUTE angle relative to the zero position
*/
void stepper::moveAbsAngle(float angleIn){
    // redefine the overall variables
    int moveStep = round(angleIn / 1.8) - steps;

    // redefine the overall variables
    angle = round(angleIn / 1.8) * 1.8;
    steps = round(angleIn / 1.8);

    // move the motor
    move(moveStep);
}

/*
void fullTurn(int direction);

INPUT: angle - the angle absolute to the zero position

OUTPUT: none

FUNCTION: moves the motor to the ABSOLUTE angle relative to the zero position
*/
void stepper::fullTurn(int direction){
    // set the direction
    if (direction == 1) {
        digitalWrite(dirPin, HIGH);
    }
    else {
        digitalWrite(dirPin, LOW);
    }

    move(200);
}

/*
GET FUNCTIONS
*/
int stepper::getSteps(){
    return steps;
}

float stepper::getAngle(){
    return angle;
}

int stepper::getDelayVelocity(){
    return delayVelocity;
}


/*
SET FUNCTIONS
*/
void stepper::setSteps(int stepsIn){
    steps = stepsIn;
}

void stepper::setAngle(float angleIn){
    angle = angleIn;
}

void stepper::setDelayVelocity(int delayVelocityIn){
    delayVelocity = delayVelocityIn;
}



/*
    // define the constructor
        stepper(int stepPin, int dirPin);

    // control the stepper motor
        void moveRelSteps(int steps);
        void moveAbsSteps(int steps);
        void moveRelAngle(int angle);
        void moveAbsAngle(int angle);

    // general functions
        void fullTurn(int direction);
        void resetLock();

    // get the private variables
        int getAngle();
        int getSteps();
        int getDelayVelocity();

    // set the private variables
        void setAngle(int angle);
        void setSteps(int steps);
        void setDelayVelocity(int delayVelocity);
*/