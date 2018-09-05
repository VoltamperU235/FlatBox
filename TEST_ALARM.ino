#define PIN            17
#define NUMPIXELS      3
#define SERVO_PIN      6

#include "ALARM.h"

void setup() {
  // put your setup code here, to run once:
  SET_ALARM();

}

void loop() {
ALARM_ESTATE(3);
}




