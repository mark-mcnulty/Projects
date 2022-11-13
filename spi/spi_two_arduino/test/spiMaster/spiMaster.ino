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

  // The slave select pin is active low so we need to set it high to disable the slave
  digitalWrite(CS_PIN, HIGH);

  // setup SPI master
  SPI.begin();

  // // sets the clk to a division of the system cloc 
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

char c;

void loop(void) {
  // activate the slave
  digitalWrite(CS_PIN, LOW);

  // send a string 
  for(constant char* p = "Hello World"; *p; p++) {
    SPI.transfer(p);
    Serial.print(p);
  }

  // disable the slave
  digitalWrite(CS_PIN, HIGH);
  delay(3000);
}