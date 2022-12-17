#include <Servo.h>

Servo myservo;


void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

int pos = 0;

void loop(void) {
  // put your main code here, to run repeatedly:
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
    }
}