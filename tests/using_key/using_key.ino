#include <Keyboard.h>

#define A_LOW_PRESS 0x61
#define B_LOW_PRESS 0x62
#define C_LOW_PRESS 0x63
#define D_LOW_PRESS 0x64
#define E_LOW_PRESS 0x65
#define F_LOW_PRESS 0x66
#define G_LOW_PRESS 0x67
#define H_LOW_PRESS 0x68
#define I_LOW_PRESS 0x69
#define J_LOW_PRESS 0x6a
#define K_LOW_PRESS 0x6b
#define L_LOW_PRESS 0x6c
#define M_LOW_PRESS 0x6d
#define N_LOW_PRESS 0x6e
#define O_LOW_PRESS 0x6f
#define P_LOW_PRESS 0x70
#define Q_LOW_PRESS 0x71
#define R_LOW_PRESS 0x72
#define S_LOW_PRESS 0x73
#define T_LOW_PRESS 0x74
#define U_LOW_PRESS 0x75
#define V_LOW_PRESS 0x76
#define W_LOW_PRESS 0x77
#define X_LOW_PRESS 0x78
#define Y_LOW_PRESS 0x79
#define Z_LOW_PRESS 0x7a



void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  delay(1000);

}


void loop() {
  Keyboard.end();
  
}
