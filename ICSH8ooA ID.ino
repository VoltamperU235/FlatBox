#include <SoftwareSerial.h>

String Analisis = "";
String CARD_ID = "";
String LAST_ID = "";


bool RECORD=LOW;


SoftwareSerial DEBUG(2,3); // RX, TX


void setup(){
pinMode(13, OUTPUT);
digitalWrite(13, HIGH);
delay(333);

   DEBUG.begin(115200);
  delay(522);
  DEBUG.println("INICIANDO TEST");
 

  Serial.begin(115200);
  delay(555);
  
 
  Serial.write(0x02);
  }

  
void loop(){

  
  if( Serial.available()){
    char T = Serial.read();

 if ((T != '\n') && (RECORD)) {
      CARD_ID += T;
    }
    if ((T == '\n') && (RECORD)) {
      RECORD = LOW;
      if(LAST_ID!=CARD_ID){
      DEBUG.println(CARD_ID);}
      
      LAST_ID = CARD_ID;
      CARD_ID = "";
 Serial.write(0x7f);
 delay(111);
  Serial.write(0x0c);
  delay(111);
   Serial.write(0xf7);
   delay(2222);
Serial.write(0x02);
}

    
   Analisis += T;
    int ID = Analisis.lastIndexOf("Series Number:");
  if(ID!=-1){
    Analisis = "";
    RECORD = HIGH;
  }


  }
}



