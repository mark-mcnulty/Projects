#define DATA_PIN 2
volatile int count = 0;


void setup(void) {
    // baud rate for serial monitor
    Serial.begin(9600);
    
    attachInterrupt(digitalPinToInterrupt(DATA_PIN), interruptRoutine, FALLING);
    
}

void loop(void) {

}

void interruptRoutine() {
    Serial.print("Interrupt");
    Serial.println(count);
    count += 1;
}