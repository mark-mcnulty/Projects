/*
  MASTER CODE
*/

#include <SPI.h>

#define CS_PIN 10


// COPI - Controller Out Peripherial In == MOSI
// CIPO - Controller In Peripherial Out == MISO
// SCK - Serial Clk                     == clk
// SS - Slave Select                    == CS

void setup(void) {
  Serial.begin(115200);

  // setup SPI master
  SPI.begin();

  // The slave select pin is active low so we need to set it high to disable the slave
  digitalWrite(CS_PIN, HIGH);

  // // sets the clk to a division of the system cloc 
  // SPI.setClockDivider()
}


// set the master receive and transmit bytes
byte masterSend;
byte masterReceive;

void loop(void) {

}