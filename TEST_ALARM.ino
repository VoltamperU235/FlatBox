#define PIN            19
#define NUMPIXELS      16
#define SERVO_PIN      6

#include "ALARM.h"

volatile int ESTADO=0;

void setup() {
  // put your setup code here, to run once:
  SET_ALARM();
  attachInterrupt(0, BUTTON, RISING );
}

void loop() {
ALARM_ESTATE(ESTADO);
}


void BUTTON(){
ESTADO++;
  
}

