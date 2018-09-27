
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(4);
bool cont = HIGH;
bool cont2 = LOW;
int tacos = 0;
int OV = 0;
int UV = 0;
int pantalla = 0;
int osc = 0;

int aov = 0;
int auv = 0;
int aalt = 0;
int lectura = 0;
int first = HIGH;
int posx[63];
int alt = 0;

bool m_t_h = LOW;

bool m_t_l = LOW;

void setup() {
  // put your setup code here, to run once:
  for (int y = 0; y < 63; y++) {
    posx[y] = 0;
  }
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(3, OUTPUT);
      pinMode(4, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setCursor(10, 5);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("TEMPERATURE SENSOR");
  display.drawLine(0, 0, 127, 0, WHITE);
  display.drawLine(0, 15, 127, 15, WHITE);
  display.drawLine(0, 1, 0, 14, WHITE);
  display.drawLine(127, 1, 127, 14, WHITE);
  display.drawPixel(2, 2, WHITE);
  display.drawPixel(2, 13, WHITE);
  display.drawPixel(125, 2, WHITE);
  display.drawPixel(125, 13, WHITE);
  display.drawLine(0, 16, 127, 16, WHITE);
  display.drawLine(0, 63, 127, 63, WHITE);
  display.drawLine(0, 17, 0, 62, WHITE);
  display.drawLine(127, 17, 127, 62, WHITE);
  display.drawPixel(2, 19, WHITE);
  display.drawPixel(2, 61, WHITE);
  display.drawPixel(3, 61, WHITE);
  display.drawPixel(2, 60, WHITE);
  display.drawPixel(3, 60, WHITE);
  display.drawPixel(125, 19, WHITE);
  display.drawPixel(124, 19, WHITE);
  display.drawPixel(125, 20, WHITE);
  display.drawPixel(124, 20, WHITE);
  display.drawPixel(125, 61, WHITE);
  display.drawPixel(125, 60, WHITE);
  display.drawPixel(124, 61, WHITE);
  display.drawPixel(124, 60, WHITE);
  display.drawLine(63, 16, 63, 63, WHITE);
  display.setCursor(13, 21);
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.println("OT: ");
  display.setCursor(13, 31);
  display.println("UT: ");
  display.setCursor(13, 41);
  display.println("AT: ");
  display.setCursor(13, 53);
  display.println("V");
  display.setCursor(35, 53);
  display.println("C");
  display.setCursor(35, 53);
  display.drawCircle(7, 24, 2, WHITE);
  display.display();
 alt = map(analogRead(3), 0, 1000, 0, 44);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if (osc > 500) {
    for (int y = 64; y < 127; y++) {
      display.drawPixel(y, 62 - posx[(y - 64)], BLACK);
    }

    posx[62] = map(constrain(alt,15,55), 15, 55,0, 47); ;
    for (int y = 0; y < 62; y++) {
      posx[y] = posx[y + 1];
    }
    for (int y = 64; y < 127; y++) {
      display.drawPixel(y, 62 - posx[(y - 64)], WHITE);
    }

    osc = 0;
  }

  if (!digitalRead(2)) {
    if (cont) {
      cont2 = !cont2;
      Serial.println(cont2);
      cont = LOW;
      if (!cont2) {
        display.drawCircle(7, 24, 2, WHITE);
        display.drawCircle(7, 34, 2, BLACK);
        display.display();
      }
      if (cont2) {
        display.drawCircle(7, 24, 2, BLACK);
        display.drawCircle(7, 34, 2, WHITE);
        display.display();
      }
    }


  }
  if (digitalRead(2)) {
    cont = HIGH;
  }

  if ((pantalla > 200) || first) {
    lectura = map(analogRead(6), 0, 1000, 15, 55);
    alt = map(analogRead(3), 0, 388, 0, 150);

    if (!cont2 || first) {
      OV  = lectura;
      if (OV <= (UV + 5)) {
        OV = UV + 5;
      }
      
      display.setCursor(32, 21);
      display.setTextSize(0);
      display.setTextColor(BLACK);
      display.println(aov);
      display.setCursor(32, 21);
      display.setTextColor(WHITE);
      display.println(OV);
      display.display();
      
      aov = OV;
    }


    if (cont2 || first) {
      UV = lectura;
      if (UV >= OV) {
        UV = OV - 5;
      }
      display.setCursor(32, 31);
      display.setTextSize(0);
      display.setTextColor(BLACK);
      display.println(auv);
      display.setCursor(32, 31);
      display.setTextSize(0);
      display.setTextColor(WHITE);
      display.println(UV);
      display.display();
      auv = UV;
    }


      display.setCursor(32, 41);
      display.setTextSize(0);
      display.setTextColor(BLACK);
      display.println(aalt);
      display.setCursor(32, 41);
      display.setTextSize(0);
      display.setTextColor(WHITE);
      display.println(alt);
      display.display();
      aalt = alt;

    pantalla = 0;
    first = 0;
  }

if(m_t_h){
if(alt<=OV-2){
  digitalWrite(8, HIGH);
   digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    m_t_h = LOW;
}}

if(m_t_l){
if(alt>=UV+2){
  digitalWrite(8, HIGH);
   digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    m_t_l = LOW;
}}

if(!m_t_l){
if(!m_t_h){
if(alt<=OV&&alt>=UV){
  digitalWrite(8, HIGH);
   digitalWrite(7, LOW);
    digitalWrite(9, LOW);
}}}

if(alt>OV){
  digitalWrite(8, LOW);
   digitalWrite(7, LOW);
    digitalWrite(9, HIGH);
       digitalWrite(3, HIGH);
              digitalWrite(4, LOW);
    m_t_h = HIGH;
}
if(alt<UV){
  digitalWrite(8, LOW);
   digitalWrite(7, HIGH);
    digitalWrite(9, LOW);
           digitalWrite(3, LOW);
              digitalWrite(4, HIGH);
    m_t_l = HIGH;
}


  osc++;
  pantalla++;
  tacos++;
  delay(1);
}
