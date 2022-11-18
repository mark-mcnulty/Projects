#ifdef stepper_h
#define stepper_h

#include <Arduino.h>

class stepper {
    private:
    // private variables
    // define  
        int stepPin;
        int dirPin;
        float angle;
        int steps;
        int delayVelocity;

    public:
    // define the constructor
        stepper(int stepPinIn, int dirPin);

    // control the stepper motor
        void move(int stepsIn);
        void moveRelSteps(int stepsIn);
        void moveAbsSteps(int stepsIn);
        void moveRelAngle(float angleIn);
        void moveAbsAngle(float angleIn);

    // general functions
        void fullTurn(int direction);
        void resetLock();

    // get the private variables
        float getAngle();
        int getSteps();
        int getDelayVelocity();

    // set the private variables
        void setAngle(float angleIn);
        void setSteps(int stepsIn);
        void setDelayVelocity(int delayVelocityIn);

}