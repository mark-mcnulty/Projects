/*
    SLAVE CODE
*/
#include <SPI.h>

// define the pins
#define CS_PIN 10
#define MISO_PIN 12

volatile bool received;
volatile byte Slavereceived;

void setup(void){
    Serial.begin(115200);

    // setup SPI slave
    pinMode(MISO_PIN, OUTPUT);          // set MISO as output
    SPCR |= _BV(SPE);                   // enable SPI

    // interrupt stuff 
    received = false;
    SPI.attachInterrupt();
}


ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR;         
  received = true;                        
}


void loop(void){
    if(received){
        Serial.print("Received: ");
        Serial.println(Slavereceived);
        received = false;
    }
}