#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
SoftwareSerial mySerial2(4, 5); // RX, TX

#define SerialMon mySerial2

#define SerialAT mySerial

const char apn[]  = "internet.tuenti.gt";
const char user[] = "";
const char pass[] = "";

// MQTT details
const char* broker = "klimato.tk";
bool LOOK = HIGH;
String Analisis = "";
String CARD_ID = "";
String LAST_ID = "";
int ESTADO = 0;


bool RECORD = LOW;

TinyGsm modem(SerialAT);
TinyGsmClient client(modem);
PubSubClient mqtt(client);

#define LED_PIN 13
int ledStatus = LOW;

long lastReconnectAttempt = 0;
uint32_t timerEnvioDatos;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    
  digitalWrite(10, HIGH);
  pinMode(LED_PIN, OUTPUT);
  // Set console baud rate
  SerialMon.begin(115200);
  delay(10);
  Serial.begin(115200);
  delay(10);
  // Set GSM module baud rate
  SerialAT.begin(9600);
  delay(3000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  SerialMon.println("Initializing modem...");
  modem.restart();

  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem: ");
  SerialMon.println(modemInfo);

  // Unlock your SIM card with a PIN
  //modem.simUnlock("1234");

  SerialMon.print("Waiting for network...");
  if (!modem.waitForNetwork()) {
    SerialMon.println(" fail");
    while (true);
  }
  SerialMon.println(" OK");

  SerialMon.print("Connecting to ");
  SerialMon.print(apn);
  if (!modem.gprsConnect(apn, user, pass)) {
    SerialMon.println(" fail");
    while (true);
  }
  SerialMon.println(" OK");

  // MQTT Broker setup
  mqtt.setServer(broker, 1883);
  mqtt.setCallback(mqttCallback);

}

boolean mqttConnect() {
  SerialMon.print("Connecting to ");
  SerialMon.print(broker);

  // Connect to MQTT Broker
  boolean status = mqtt.connect("GsmClientTest", "admin", "admin");

  if (status == false) {
    SerialMon.println(" fail");
    return false;
  }
  SerialMon.println(" OK");
  mqtt.publish("/conexion", "GsmClientTest started");
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(55);
  digitalWrite(11, LOW);
  delay(55);
  digitalWrite(11, HIGH);
  delay(55);
  digitalWrite(11, LOW);
  delay(55);
  return mqtt.connected();
}

void loop() {

  if (!mqtt.connected()) {
    digitalWrite(10, HIGH);
    SerialMon.println("=== MQTT NOT CONNECTED ===");
    // Reconnect every 10 seconds
    unsigned long t = millis();
    if (t - lastReconnectAttempt > 10000L) {
      lastReconnectAttempt = t;
      if (mqttConnect()) {
        lastReconnectAttempt = 0;
      }
    }
    delay(100);
    return;
  }

  if (mqtt.connected() && LOOK) {
   // Serial.write(0x02);
    LOOK = LOW;
  }
  /*else {
        //cliente conectado
        if (millis() - timerEnvioDatos > 5000) {
          timerEnvioDatos = millis();
          //a falta de sensores enviamos valores aleatorios
          char msg[4];
          snprintf (msg, 3, "%ld", random(35));
           mqtt.publish("SIM8", msg);
           SerialMon.print("Sended");

        }
      }*/

  mqtt.loop();
  CHECH_TAG();
  RESET();
}

void mqttCallback(char* topic, byte* payload, unsigned int len) {
  SerialMon.print("Message arrived [");
  SerialMon.print(topic);
  SerialMon.print("]: ");
  SerialMon.write(payload, len);
  SerialMon.println();

}

void CHECH_TAG() {
  while ( Serial.available()) {
    char T = Serial.read();

    if ((T != '\n') && (RECORD)) {
      CARD_ID += T;
    }
    if ((T == '\n') && (RECORD)) {
      RECORD = LOW;
      if (LAST_ID != CARD_ID) {
        int LONG = CARD_ID.length();
        if (LONG == 8) {
           timerEnvioDatos=millis();
          digitalWrite(LED_PIN, HIGH);
          delay(55);
          digitalWrite(LED_PIN, LOW);
            delay(55);
          digitalWrite(11, HIGH);
          delay(55);
          digitalWrite(11, LOW);
          delay(55);
          SerialMon.println(CARD_ID);
          //DECODE_ID(CARD_ID);
          // ESTADO = 1;
          if (mqtt.connected()) {

            char msg[9];
            CARD_ID.toCharArray(msg, 9);
            mqtt.publish("SIM8", msg);
            SerialMon.println("SENDED");
            SerialMon.println(msg);
          } 


        }
      }

      LAST_ID = CARD_ID;
      CARD_ID = "";
    /*  Serial.write(0x7f);
      delay(111);
      Serial.write(0x0c);
      delay(111);
      Serial.write(0xf7);
      delay(1111);*/
      Serial.write(0x02);
      timerEnvioDatos=millis();
    }


    Analisis += T;
    int ID = Analisis.lastIndexOf("Series Number:");
    if (ID != -1) {
      Analisis = "";
      RECORD = HIGH;
    }


  }
}
void RESET(){
  if (millis() - timerEnvioDatos > 9000) {
 timerEnvioDatos=millis();
    /*  Serial.write(0x7f);
      delay(111);
      Serial.write(0x0c);
      delay(111);
      Serial.write(0xf7);
      delay(1111);*/
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
 
      
     
        
      Serial.write(0x02);
      delay(55);
        SerialMon.println("RESETED");
         digitalWrite(11, LOW);
      digitalWrite(10, LOW);
 }
 
}

