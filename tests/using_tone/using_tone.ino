#include "Tone.h"

#define PIN_1 10
#define PIN_2 9

Tone tone1;
Tone tone2;

void setup() {
  tone1.begin(PIN_1);
  tone2.begin(PIN_2);
  tone1.play(NOTE_A4);
  tone2.play(NOTE_A4);
}

void loop() {
}
