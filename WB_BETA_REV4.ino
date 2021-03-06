
#include <ArduinoJson.h>
#include "LowPower.h"                                 //Fue nesesaria para Reudcir el consumo de energia mientras la arduino no se esta utilizando (que es aproximadamente un 95% del tiempo :v )
#include <SoftwareSerial.h>                           //Se utilizo SoftwareSerial para el Debuging (En el terminal) debido a que el SIM utiliza el UART0 .
#define TINY_GSM_MODEM_SIM800                         //Como la libreria tinyGSM es generica hay que especificar que Chip se utiliza para la conexion a la red GSM.
#include <TinyGsmCommon.h>
#include <PubSubClient.h>                             //Librerias nesesarias para el correcto funcionamiento del SIM800.
#include <TinyGsmClient.h>
SoftwareSerial mySerial(11, 12);                      //Declaramos los pines por los cuales se comunicara el Arduino con el PC (utilizar conversor USB - TTL)
TinyGsm modem(Serial);                                //Creamos un objeto del tipo modem en el cual indicaremos el UART que se comunicara con el SIM800 en este caso UART0 (Serial) si fuera otra arduino mas poderosa podria ser Serial1, Serial2, etc. :v
TinyGsmClient client(modem);
PubSubClient mqtt(client);
#include "RTClib.h"
#include <DS3232RTC.h>



char JSON_SMS[125];

RTC_DS3231 rtc;


#define NO_CONECTION_LED 14                           //Definimos el pin que nos mostrara en una LED la ausencia de conexion.
#define ACTIVE_LED 15                                //Definimos el pin que nos mostrara en una LED que el sistema esta busy.
#define LOW_POWER_LED 16
#define LOW_PIN 17
#define OPEN_COLECTOR_CAPACITIVE_SENSOR 3
#define RTC_ALARM 2
#define LOCATION "TEC"
#define RST 9



volatile int ESTATE = 2;
const char* apn   = "Internet.tuenti.gt";
const char* user = "";
const char* pass = "";
const char*  broker = "klimato.tk";

const char* topic1 = "/WaterSense/M";
const char* topic2 = "/WaterSense/D";
const char* topic3 = "/WaterSense/T";

const char* username = "DENNIS";
const char* password = "FBx_admin2012";
//const char* device = "Water_Sense_V1";

long lastReconnectAttempt = 0;
volatile bool LOW_LEVEL = LOW;
int Y;
int M;
int D;
int H;
int MM;

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 5000;
unsigned long currentMillis = 0;

char ID[16];
String IMEI = "";

bool ALARM_FLAG = LOW;
bool LOW_FLAG = LOW;
bool SLEEP_LOCK = LOW;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                  //Establecemos la conexion con el SIM800 utilizando el UART0 (Lo utilizamos porque existe la Interupcion Serial nesesaria para sacar a la arduino del modo sleep en el momento que el SIM800 reciba la indicacion de alarma);
  mySerial.begin(115200);
  delay(555);

  if (! rtc.begin()) {
    mySerial.println("Couldn't find RTC");
    while (1);
  }

  pinMode(OPEN_COLECTOR_CAPACITIVE_SENSOR, INPUT_PULLUP);
  pinMode(RTC_ALARM, INPUT_PULLUP);
  pinMode(LOW_PIN, OUTPUT);
  digitalWrite(LOW_PIN, LOW);
  pinMode(NO_CONECTION_LED, OUTPUT);                   //El LED permanecera encendido mientras carga el setup y detecta conexion;

  pinMode(ACTIVE_LED, OUTPUT);
  pinMode(RST, OUTPUT);
  digitalWrite(RST, LOW);
  delay(555);
  digitalWrite(RST, HIGH);
  pinMode(LOW_POWER_LED, OUTPUT);
  flash_init();
  mySerial.println(F("WB_BETA__REV4"));
  IMEI = modem.getIMEI();
  ENABLE_COMUNICATION();
  mqtt.subscribe("/NTP");
  JSON();
  publish_management();
  mySerial.println("-->");
  //mySerial.println(ok);
  //digitalWrite(ACTIVE_LED, HIGH);
  mqtt.publish(topic2, "ND");
  mySerial.println(F("SE"));

}

void loop() {
  // put your main code here, to run repeatedly:
  switch (ESTATE)
  {
    case 0:
      if (ALARM_FLAG)
      {
        mySerial.println(F("A_F"));
        ALARM_FLAG = LOW;
        SLEEP_LOCK = HIGH;
        ESTATE = 3;
      }
      if (LOW_FLAG)
      {
        mySerial.println(F("L_F"));
        LOW_FLAG = LOW;
        SLEEP_LOCK = HIGH;
        ESTATE = 1;
      }
      if (!SLEEP_LOCK)
      {
        attachInterrupt(1, WATER_DETECT, FALLING);
        attachInterrupt(0, ALARM, FALLING);
        mqtt.disconnect();
        while (!modem.gprsDisconnect())
        {
          delay(55);
        }
        mqtt.disconnect();

        sendData("AT+CFUN=0", 7555, 1);
        sendData("AT+CSCLK=2", 7555, 1);
        delay(555);
        //sendData("AT+CPOWD=1", 1111, 1);
        mySerial.println(F("2G OUT"));
        mySerial.println(F("ZZz"));
        delay(1111);
        Serial.flush();
        mySerial.flush();
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_ON);
      }
      break;
    case 1:
      flash();
      digitalWrite(RST, LOW);
      delay(111);
      digitalWrite(RST, HIGH);
      /*sendData("AT", 1111, 1);
        sendData("AT+CSCLK=0", 5999, 1);
        sendData("AT+CFUN=1", 5999, 1);*/
      ENABLE_COMUNICATION();
      LOW_SIGNAL();
      SLEEP_LOCK = LOW;
      ESTATE = 0;
      break;
    case 2:
      mqtt.loop();
      break;
    case 3:
      if (check())
      {
        flash();
        digitalWrite(RST, LOW);
        delay(111);
        digitalWrite(RST, HIGH);
        SET_ALARM();
        ENABLE_COMUNICATION();
        JSON();
        publish_management();
        SLEEP_LOCK = LOW;

        mySerial.println(F("A!!"));
      } else
      {
        mySerial.println(("NA, GTS"));
        SLEEP_LOCK = LOW;
        SET_ALARM();
      }
      ESTATE = 0;
      break;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                         mqttCallback
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mqttCallback(char* topic, byte* payload, unsigned int len) {
  mySerial.print("SMS [");
  mySerial.print(topic);
  mySerial.print("]: ");
  mySerial.write(payload, len);
  mySerial.println();

  String Data;
  for (int y = 0; y < len; y ++)
  {
    Data += char(payload[y]);
  }


  if (String(topic) == "/NTP")
  {
    int pos1;
    int pos2;
    String Build;
    pos2 = Data.indexOf("-");
    for (int j = 0; j < pos2; j++)
    {
      Build += Data[j];

      Y = Build.toInt();

    }
    //mySerial.println(Y);
    Build = "";
    pos1 = pos2;
    pos2 = Data.indexOf("-", pos1 + 1);
    for (int j = pos1 + 1; j < pos2; j++)
    {
      Build += Data[j];

      M = Build.toInt();

    }
    //mySerial.println(M);
    Build = "";
    pos1 = pos2;
    pos2 = Data.indexOf("T");
    for (int j = pos1 + 1; j < pos2; j++)
    {
      Build += Data[j];

      D = Build.toInt();

    }
    //mySerial.println(D);
    Build = "";
    pos1 = pos2;
    pos2 = Data.indexOf(":");
    for (int j = pos1 + 1; j < pos2; j++)
    {
      Build += Data[j];

      H = Build.toInt();

    }
    //mySerial.println(H);

    Build = "";
    pos1 = pos2;
    pos2 = Data.indexOf(":", pos1 + 1);
    for (int j = pos1 + 1; j < pos2; j++)
    {
      Build += Data[j];

      MM = Build.toInt();

    }
    // mySerial.println(MM);

    if (! rtc.begin())
    {
      while (1);
    }

    H = H - 6;
    if (H < 0) {
      H = 24 + H;
    }

    rtc.adjust(DateTime(Y, M, D, H, MM, 0));
    DateTime now = rtc.now();
    mySerial.println(F("TimeNode ok"));
    ESTATE = 0;
    flash_long();
    //bool ok = mqtt.publish(topic1, "TIME SETTED");
    // mySerial.println(ok);
    ALARMS();
    mySerial.println(now.minute());
    mySerial.println(now.hour());
    mySerial.println(now.day());
    mySerial.println(now.month());
    mySerial.println(now.year());
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   7                                                       sendData
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

String sendData(String command, const int timeout, boolean debug) {     //Funcion que permite enviar comandos AT y esperar su respuesta por determinado tiempo (si Debug esta en HIGH)
  String response = "";                                                 //Reiniciamos nuestra variable.
  mySerial.println(command);
  Serial.println(command);                                              //Mostramos en la PC el comando que enviamos.
  modem.getGSMDateTime(DATE_TIME);
  long int time = millis();                                             //Tomamos el valor acutal de millis();
  while ( (time + timeout) > millis()) {                                //Miestras no se sobrepase el timeout esperamos datos y los mostramos en el PC
    while (Serial.available()) {
      char c = Serial.read();
      response += c;
    }
  }
  if (debug) {
    mySerial.print(response);
  }
  return response;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                          mqttConnect
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


boolean mqttConnect()
{
  mySerial.print(F("Connecting to "));
  mySerial.print(broker);

  IMEI = modem.getIMEI();
  IMEI.toCharArray(ID, sizeof(IMEI));


  boolean status = mqtt.connect(ID, username, password);

  if (status == false)
  {
    mySerial.println(F(" fail"));
    return false;
  }
  mySerial.println(F(" OK"));
  //mqtt.publish("/WaterSense/Management/", "G");
  //mqtt.subscribe(topicLed);
  return mqtt.connected();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           WATER_DETECT
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WATER_DETECT()
{
  if (ESTATE == 0)
  {
    ESTATE = 1;
  } else
  {
    if (!ESTATE == 1)
    {
      LOW_FLAG = HIGH;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           WENABLE_COMUNICATION
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ENABLE_COMUNICATION()
{


  mySerial.println(F("W ON"));
  digitalWrite(NO_CONECTION_LED, HIGH);
  if (!GSM_CONECTION())
  {
    mySerial.println(F("SR"));
    software_Reset();
  }
  ///////////////////////////////////////////////////
  for (int h = 0; h < 8; h++)
  {
    digitalWrite(NO_CONECTION_LED, HIGH);
    delay(155);
    digitalWrite(NO_CONECTION_LED, LOW);
    delay(155);
  }
  if (!GPRS_CONECTION())
  {
    mySerial.println(F("SR"));
    software_Reset();
  }
  /////////////////////////////////////////////////////////

  digitalWrite(NO_CONECTION_LED, LOW);

  for (int h = 0; h < 8; h++)
  {
    digitalWrite(ACTIVE_LED, HIGH);
    delay(155);
    digitalWrite(ACTIVE_LED, LOW);
    delay(155);
  }
  if (!MQTT_CONECTION())
  {
    mySerial.println(F("SR"));
    software_Reset();
  }
  /////////////////////////////////////////////
  for (int h = 0; h < 8; h++)
  {
    digitalWrite(LOW_POWER_LED, HIGH);
    delay(155);
    digitalWrite(LOW_POWER_LED, LOW);
    delay(155);
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           flash
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void flash()
{
  digitalWrite(NO_CONECTION_LED, HIGH);
  delay(155);
  digitalWrite(NO_CONECTION_LED, LOW);
  digitalWrite(ACTIVE_LED, HIGH);
  delay(155);
  digitalWrite(ACTIVE_LED, LOW);
  digitalWrite(LOW_POWER_LED, HIGH);
  delay(155);
  digitalWrite(LOW_POWER_LED, LOW);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           flash_init
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void flash_init()
{
  for (int g = 0; g < 10; g++)
  {
    digitalWrite(NO_CONECTION_LED, HIGH);
    delay(55);
    digitalWrite(NO_CONECTION_LED, LOW);
    digitalWrite(ACTIVE_LED, HIGH);
    delay(55);
    digitalWrite(ACTIVE_LED, LOW);
    digitalWrite(LOW_POWER_LED, HIGH);
    delay(55);
    digitalWrite(LOW_POWER_LED, LOW);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           flash_long
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void flash_long()
{
  digitalWrite(NO_CONECTION_LED, HIGH);
  delay(355);
  digitalWrite(NO_CONECTION_LED, LOW);
  digitalWrite(ACTIVE_LED, HIGH);
  delay(355);
  digitalWrite(ACTIVE_LED, LOW);
  digitalWrite(LOW_POWER_LED, HIGH);
  delay(355);
  digitalWrite(LOW_POWER_LED, LOW);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           LOW_SIGNAL
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LOW_SIGNAL()
{

  StaticJsonBuffer<40> jsonBuffer;                           //Generar un buffer para la String Json que contrendra los datos.
  JsonObject& root = jsonBuffer.createObject();               //Se crea un Objeto del tipo JsomObjet para ingresar los datos.

  root["LE"] = "0";                  //Obtenemos la localización (Se nesecita conexion GPRS :'v).
  root["IM"] = modem.getIMEI();;

  root.printTo(JSON_SMS, sizeof(JSON_SMS));                   //Ingresamos en un array de Char nuestro JSON con los datos ya ingresados.
  mySerial.println("J");
  mySerial.println(String(JSON_SMS));
  mySerial.println("F");

  bool ok = mqtt.publish(topic3, JSON_SMS);
  mySerial.println(ok);
  delay(555);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           ALARMS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ALARMS()
{
  mySerial.println(F("StA"));
  RTC.alarmInterrupt(ALARM_1, true);
  RTC.alarmInterrupt(ALARM_2, false);
  RTC.squareWave(SQWAVE_NONE);
  RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 0, 0, 1);
  RTC.alarm(ALARM_1);
  mySerial.println(F("AS"));
  ESTATE = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           ALARM
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ALARM()
{
  if (ESTATE == 0)
  {
    ESTATE = 3;
  } else
  { if (!ESTATE == 3)
    {
      ALARM_FLAG = HIGH;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           SET_ALARM
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SET_ALARM()
{
  mySerial.println(F("AWU"));
  if ( RTC.alarm(ALARM_1) )
  {
    RTC.setAlarm(ALM1_MATCH_MINUTES, 0, 0, 0, 1);
    mySerial.println(F("AS"));
  }
  //ESTATE = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                           JSON
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void JSON()
{
  StaticJsonBuffer<125> jsonBuffer;                           //Generar un buffer para la String Json que contrendra los datos.
  JsonObject& root = jsonBuffer.createObject();               //Se crea un Objeto del tipo JsomObjet para ingresar los datos.

  root["P"] = modem.getGsmLocation();                  //Obtenemos la localización (Se nesecita conexion GPRS :'v).
  root["L"] = LOCATION;
  root["B"] = modem.getBattPercent();
  root["I"] = modem.getIMEI();

  root.printTo(JSON_SMS, sizeof(JSON_SMS));                   //Ingresamos en un array de Char nuestro JSON con los datos ya ingresados.
  mySerial.println("J");
  mySerial.println(String(JSON_SMS));
  mySerial.println("F");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     publish_management
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void publish_management()
{
  bool ok = mqtt.publish(topic1, JSON_SMS);
  if (!ok)
  {
    mySerial.println(F("SR"));
    software_Reset();
  }
  mySerial.println(ok);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                   check new management publish
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool check()
{
  DateTime now = rtc.now();
  int hora = now.hour();
  if ((hora == 0) || (hora == 6) || (hora == 12) || (hora == 18))
  {
    return true;
  } else
  {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////7
bool GSM_CONECTION()
{
  if (!modem.waitForNetwork())
  {
    mySerial.println(F("..."));
    return false;
  }

  if (modem.isNetworkConnected())
  {
    mySerial.println(F("GSM"));      //Mostrara un mensaje cuando de haya conectado a la red.
    return true;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
bool GPRS_CONECTION()
{
  if (!modem.gprsConnect(apn, user, pass))
  {
    mySerial.println(" fail");
    return false;
  } else
  {
    mySerial.println(F("2G OK"));
    return true;

  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool MQTT_CONECTION()
{
  mqtt.setServer(broker, 1883);
  mqtt.setCallback(mqttCallback);

  long int time = millis();
  int reset_time = 30000;

  while ( ((time + reset_time) > millis()) && (!mqtt.connected())) {
    if (!mqtt.connected())
    {

      // Reconnect every 10 seconds
      unsigned long t = millis();
      if (t - lastReconnectAttempt > 2000L)
      {
        lastReconnectAttempt = t;
        if (mqttConnect())
        {

          lastReconnectAttempt = 0;
        }
      }
      delay(100);

    }
  }
  if (!mqtt.connected()) {
    return false;
  } else
  {
    return true;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  asm volatile ("  jmp 0");
}
