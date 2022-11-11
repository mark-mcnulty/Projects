// AUTHOR: Mark McNulty
#define BAUD (9600)
#define ENABLE 6
#define stepPin 5
#define dirPin 4

int numberStep = 9;

enum number{zero=0, one=1*numberStep, two=2*numberStep, three=3*numberStep, four=4*numberStep, five=5*numberStep,
            six=6*numberStep, seven=7*numberStep, eight=8*numberStep, nine=9*numberStep, ten=10*numberStep,
            eleven=11*numberStep, twelve=12*numberStep, thirteen=13*numberStep, fourteen=14*numberStep, fifteen=15*numberStep,
            sixteen=16*numberStep, seventeen=17*numberStep, eighteen=18*numberStep, nineteen=19*numberStep, twenty=20*numberStep,
            twentyone=21*numberStep, twentytwo=22*numberStep, twentythree=23*numberStep, twentyfour=24*numberStep, twentyfive=25*numberStep,
            twentysix=26*numberStep, twentyseven=27*numberStep, twentyeight=28*numberStep, twentynine=29*numberStep, thirty=30*numberStep,
            thirtyone=31*numberStep, thirtytwo=32*numberStep, thirtythree=33*numberStep, thirtyfour=34*numberStep, thirtyfive=35*numberStep,
            thirtysix=36*numberStep, thirtyseven=37*numberStep, thirtyeight=38*numberStep, thirtynine=39*numberStep
            };


// defines pins
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

/*
 * NOTES
 *  The motor takes 200 steps to go 360 degrees
 *  each step is 1.8 degrees
 *  
 *  There are 9 degrees per number 
 */
void loop() {
  // lets define some variables
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(700); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 1600; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
