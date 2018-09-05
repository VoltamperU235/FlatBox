#include <Servo.h>

#define GREEN pixels.Color(0,255,0)
#define ORANGE pixels.Color(255,98,0)
#define YELLOW pixels.Color(255,255,0)
#define RED pixels.Color(255,0,0)
#define BLUE pixels.Color(0,0,255)
#define WHITE pixels.Color(155,155,155)
#define NONE pixels.Color(0,0,0)

Servo myservo;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void SET_ALARM() {
  pixels.begin();
  myservo.attach(SERVO_PIN);
  myservo.write(91);
  delay(333);
}

void Start_Ring() {

  for (int pos = 65; pos <= 115; pos += 1) {
    myservo.write(pos);
    delay(15);
  }

  for (int pos = 115; pos >= 65; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

void SET_GREEN() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, GREEN);
    pixels.show();   
    delay(111);
  }
   delay(333);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, NONE);
    pixels.show();
  }
  delay(111);
}

void SET_RED() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, RED);
    pixels.show();
    delay(155);
  }
  Start_Ring();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, NONE);
    pixels.show();
  }
  delay(111);
}

void SET_ORANGE() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, ORANGE);
    pixels.show();
    delay(155);
  }
   Start_Ring();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, NONE);
    pixels.show();
  }
 delay(111);
}

void SET_YELLOW() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, YELLOW);
    pixels.show();
    delay(111);
  }
   delay(333);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, NONE);
    pixels.show();
  }
  delay(111);
}

void SET_DEFAULT() {
  for (int i = 0; i < NUMPIXELS / 3; i++) {
    pixels.setPixelColor(i, BLUE);
    pixels.show();
    delay(111);
  }
  for (int i = NUMPIXELS / 3; i < (NUMPIXELS / 3) * 2; i++) {
    pixels.setPixelColor(i, WHITE);
    pixels.show();
    delay(111);
  }
  for (int i = (NUMPIXELS / 3) * 2; i <= (NUMPIXELS / 3) * 3; i++) {
    pixels.setPixelColor(i, BLUE);
    pixels.show(); 
    delay(111);
  }
  
}



void ALARM_ESTATE(int ESTATE){
  switch (ESTATE){
    case 0:
    SET_DEFAULT();
    break;
    case 1:
    SET_GREEN();
    break;
    case 2:
    SET_YELLOW();
    break;
    case 3:
    SET_ORANGE();
    break;
    case 4:
    SET_RED();
    break;
  }
  
}


