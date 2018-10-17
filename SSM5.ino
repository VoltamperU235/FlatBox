
/* Sistema de Transmisión de audio utilizando el SIM800.
   Desarrollado en FlatBox.
   Se utilizo una Arduino Ultra_mini, siendo compatible el sketch con una Arduino Pro mini.
   Created August 2018
   Developed and designed by Dennis Revolorio (Kestler Disciple)
*/
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT11
//#include <TimerOne.h>
#include "LowPower.h"                                 //Fue nesesaria para Reudcir el consumo de energia mientras la arduino no se esta utilizando (que es aproximadamente un 95% del tiempo :v )
#include <SoftwareSerial.h>                           //Se utilizo SoftwareSerial para el Debuging (En el terminal) debido a que el SIM utiliza el UART0 .
#include <ArduinoJson.h>                              //Se utilizo para generar una String Json para transmision de los datos a Internet.
#define TINY_GSM_MODEM_SIM800                         //Como la libreria tinyGSM es generica hay que especificar que Chip se utiliza para la conexion a la red GSM.
#include <TinyGsmCommon.h>                            //Librerias nesesarias para el correcto funcionamiento del SIM800.
#include <TinyGsmClient.h>
SoftwareSerial mySerial(8, 9);                        //Declaramos los pines por los cuales se comunicara el Arduino con el PC (utilizar conversor USB - TTL)
TinyGsm modem(Serial);                                //Creamos un objeto del tipo modem en el cual indicaremos el UART que se comunicara con el SIM800 en este caso UART0 (Serial) si fuera otra arduino mas poderosa podria ser Serial1, Serial2, etc. :v

#include <BMA220.h>

BMA220 bma;
#define SLEEP 17//Definimos el pin de la Arduino que va a estar conectado al pin DTR del SIM800. (Se utiliza para ponerlo en modo Sleep).
#define MIC   12
#define NO_CONECTION_LED 7                           //Definimos el pin que nos mostrara en una LED la ausencia de conexion.
#define ACTIVE_LED 6                                //Definimos el pin que nos mostrara en una LED que el sistema esta busy.
#define LOW_POWER_LED 5                             //Definimos el pin que nos mostrara en una LED que el sistema entro en modo power-save.

#define LLAMADA 1                                     //Estado de la maquina de estados finitos en el cual se ejecutara la llamada.
#define TEXT 8                                        //Estado de la maquina de estados finitos en el cual se enviaran los mensajes de estado.
#define ALARMS 21                                   //Estado de la maquina de estados finitos en el cual se programaran las alarmas.
#define NOISE 24                                     //Estado de la maquina de estados finitos en el cual se ejecutara el analisis de pulsos.
#define READ_TEXT 55
#define PROGRAM_READ 56
#define READ_GROUP 58

#define DELETE_SMS 57
#define MIC_PIN A0                                    //Definimos el pin analogo al cual estara conectado nuestro Sensor microfono
#define LECTURAS 1023

//Definimos el numero de lecturas para leamos el pin Analogo al cual esta conectado nuestro microfono.
long PROMEDIO;                                        //Variable que almacenara ek promedio de las lecturas realizadas
//int ANALOGIC = 0;                                   //Variable que almacenara el valor actual del pin analogico que utilicemos para el microfono.
int ADC_TOTAL;                                        //Varialble en la que se almacenara el valor del promedio del ADC medido.
String DETECCION_ALARMA = "";                         //String en la cual ingresaran caracteres provenientes del SIM800 en busca del texto que indica activacion de alarma.
String HORA_ACTUAL;                                   //String en la cual de almacenaran los caracteres decodificados de la String que genera el SIM800 al solicitar hora de red.
int HORA_ACTUAL_INT;                                  //Entero que guardara la hora actual.
int CHECK;                                            //Entero que nos indicara en el momento que DETECCION_ALARMA contenga la frase de indica activacion de alarma.
String STRING_HORA_SIM800;                            //String que almacenara la String de hora actual proveniente del SIM800.
char ARRAY_DE_ANALISIS[12];                           //Array de caracteres en el cual se desarmara la String de hora proveniente del SIM800. (Esto de hace para poder analizar la String caracter por caracter y determinar que porcion de la String contiene el numero actual de la hora),
char C;                                               //Caracter que almacenara el dato recibido por el SIM800 y lo concatenara al ARRAY_DE_ANALISIS.
int HORA_DE_ENVIO;                                    //Entero que contendra la hora en la cual se realizara el siguinte envio (Es nesesario ingresarla a un comando AT).
unsigned long MILLIS_NOW;                             //Entero que contendra el valor de millis() en ese momento.
bool LOCK_MILLIS = HIGH;                              //Booleano que nos bloqueara que la variable MILLIS_NOW este tomando valores nuevos cada vez, sino solamente una vez al inicio de la funcion.
bool ENABLE_SCAN;

//Para establecer una alarma en el SIM800 se utiliza el siguiente comando AT: AT+CALA=<Parametros> (verificarlos en el Datasheet) :v
//La idea es que Arduino cree la instruccion de manera automatica en relacion a la hora, por lo que se utilizaran porciones constantes de la instruccion y se le contatenara la informacion extra.
const String Comando1_1 = "AT+CALA=\"0";              //Porcion inicial para cuando la hora es menor a las 10 AM.
const String Comando1_2 = "AT+CALA=\"";               //Porcion inicial para cuando la hora es superior o igual a las 10 AM.
const String Comando2 = ":00:00\",2,0";               //Porcion final luego de haber concatenado los datos anterios (La funcion que realiza eso se encuentra mas abajo)
String CONSTRUCTOR_AT;                                //String en la cual se generara el comando AT para programar la siguiente alarma.
int i;                                                //Nos servira para el bucle for del promediado de medidas.
bool INDICADOR_DE_ENVIO;                              //Booleano que nos indicara si nuestro comando tinyGMS fue realizado exitosamente
volatile int ESTADO = 0;                              //Entero que almacenara el estado de la maquina de estados finitos.
bool SENDER = LOW;
uint16_t BATT_PERCENT;                                //Servira para guardar el valor del porcentaje de la bateria.
String BATTERY_TO_SMS;                                //String para guardar el BATT_PERCENT concatenado con %.
char JSON_SMS[99];                                   //Array de Caracteres donde se guardara la String JSON para enviar;
String JSON_STRING;                                   //String donde se concaternara nustro array de JSON y que este listo para enviar por GSM.
volatile int PULSES;                                 //Servira para llevar control del numero de interrupciones generadas en un momento dado de tiempo.
int TOTAL_SMS = 0;

unsigned long MILLLIS_NOW;                            //Entero que almacenara el valor de millis() para calcular diferencias de tiempo.
bool ENABLE_ANALISIS = HIGH;                          //Bool que nos permitira el acceso a una rutina de analisis de pulsos para determinar si es un sonido fuerte o sos falsos positivos.
long PULSES_BEFORE;                                   //Enetero que almacenara la ultima cantidad de pulsos registrada para determinar la diferencia de pulsos entre lecturas.
unsigned long PULSES_DIFERENCE;                       //Entero en el cual se almacena la diferencia de pulsos entre lecturas.

const String ALARM_RESET = "AT+CALA=\"00:00:00\",1,0";
const String ALARM_RESET_DELETE = "AT+CALD=1";
char ALARM_FLAG[8];
char SMS_DETECT[8];
//+CMTI: "SM",1
bool RECORD;
String SMS_DATA;

bool ENABLE_READ = HIGH;;
volatile int  SMS_COUNT = 3;
volatile bool SMS_DETECTED;
int HUMITY;
int TEMP;
int SECURE_COUNTER;
volatile int SMS_ESTATE = 0;
String TELEPHONE = "50257276772";
bool SETT;
volatile bool MOVEMENT = 0;
bool SMS_E = LOW;
String ALARM_SETED="";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);                                  //Establecemos la conexion con el SIM800 utilizando el UART0 (Lo utilizamos porque existe la Interupcion Serial nesesaria para sacar a la arduino del modo sleep en el momento que el SIM800 reciba la indicacion de alarma);
  mySerial.begin(115200);                              //Lo utilizamos para el debuging y visualizar los datos en el PC (es mas rapida para que no retrase mucho la programacion).
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  dht.begin();
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(MIC, OUTPUT);
  pinMode(SLEEP, OUTPUT);                              //Inicializamos el pin SLEEP como salida.
  digitalWrite(SLEEP, LOW);                            //Colocamos el pin SLLEP en estado bajo (El SIM800 se despierta).
  pinMode(NO_CONECTION_LED, OUTPUT);                   //El LED permanecera encendido mientras carga el setup y detecta conexion;
  digitalWrite(NO_CONECTION_LED, HIGH);

  mySerial.println(F("1"));        //Mensajes para determinar correcto funcionamiento en el PC

  for (int h = 0; h < 12; h++) {
    ARRAY_DE_ANALISIS[h] = ' ';
  }
  for (int h = 0; h < 8; h++) {
    ALARM_FLAG[h] = ' ';
  }
  for (int h = 0; h < 8; h++) {
    SMS_DETECT[h] = ' ';
  }


  pinMode(ACTIVE_LED, OUTPUT);
  pinMode(LOW_POWER_LED, OUTPUT);

  while (!modem.waitForNetwork()) {                          //Esperamos en un bucle infinito la conexion de red.
    mySerial.println(F("2"));
  }
  if (modem.isNetworkConnected()) {
    mySerial.println(F("3"));      //Mostrara un mensaje cuando de haya conectado a la red.
  }
  Serial.println(F("AT+CLTS=1"));
  delay(111);
  Serial.println(F("AT&W"));
  digitalWrite(NO_CONECTION_LED, LOW);

  digitalWrite(ACTIVE_LED, HIGH);

 // Timer1.initialize(4000000);
 // Timer1.attachInterrupt(SMS_INTERRUPT);
  bma.begin();
  delay(555);
  bma.setRegister(SENSITIVITY_REG, SENS_16g);
  bma.setRegister(INTRP_MODE_REG, SLOPEDETECT);
  bma.setRegister(SLOPE_REG, SLOPEPAR1); // threshold 0b0011, duration 0b01
  bma.setRegister(INTRP_RES_REG, LATCH_1s);


  //SET ALARM TO RESET
  sendData(ALARM_RESET_DELETE, 1111, 1);                                         //Enviamos el comando que borra cualquier alarma en la posicion 2 (Yo urilize esa arbitrariamente :v ).
  sendData(ALARM_RESET, 1111, 1);                                      //Enviamos nuestro constructor AT con nuestra alarma ya programada.




  ESTADO = TEXT;
  //ESTADO = 0;
}

void loop() {
  switch (ESTADO) {
    case 0:
      SMS_ESTATE = 0;
      digitalWrite(ACTIVE_LED, LOW);                                                                       //Colocamos en LOW el LED de ACTIVE (Busy).
      digitalWrite(LOW_POWER_LED, HIGH);                                                                   //Colocamos en HIGH el LED de Power Save
      PULSES_DIFERENCE = 0; PULSES_BEFORE = 0; PULSES = 0;                                                 //Borramos nuestra variables de analisis porque se sobrepaso el tiempo maximo de muestreo estando PULSES_FIFERENCE en 0 (Ver Case: Noise para comprender mejor.)
      attachInterrupt(0, DETECTION, FALLING);                                                              //Activamos la interrupcion INT0.
      attachInterrupt(1, HIGH_G, RISING);                                                                  //Activamos la interrupcion INT0.
      //Mostrara un mensaje cuando de haya conectado a la red.
      mySerial.flush();
      ENABLE_SCAN = HIGH;
      LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, SPI_OFF, USART0_ON, TWI_OFF); //Se coloca la Arduino en modo LowPower IDLE (Ver Datasheet.) podemos desactivar todo lo que no estemos utilizando, apagar los clock internos y permanecer atentos al UART0 (Se hace porque se programar alarmas periodicas al SIM y las envia por UART )

      break;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BIENVENIDOS AL ESTADO "LLAMADA"//

    case LLAMADA:
      digitalWrite(MIC, HIGH);
      detachInterrupt(0);                                 //Desactivamos la interrupcion (Para evitar falsos positivos generados por los picos de energia que consumen el SIM800.
      detachInterrupt(1);                                        //Desactivamos la interrupcion (Para evitar falsos positivos generados por los picos de energia que consumen el SIM800.

      digitalWrite(LOW_POWER_LED, LOW);

      digitalWrite(ACTIVE_LED, HIGH);                     //Colocamos en HIGH el LED de busy y desactivamos los demas.
      digitalWrite(NO_CONECTION_LED, LOW);
      //  mySerial.println(F("INTERRUPCION ACIVADA"));        //Mostramos un mensaje en el momento que la interrupcion por sonido se active ;v
      digitalWrite(SLEEP, LOW);                           //Colocamos el pin SLLEP en estado bajo (El SIM800 se despierta).
      ESTADO += 1;                                        //Pasamos al siguiente estado de la llamda. :v
      break;
    case 2:
      Smart_Delay(111);                                   //Esperamos 111ms para pasar al siguiente estado (uso numeros asi porque el numero 0 de mi teclado no funciona y tengo que copiarlo y pegarlo cada vez que lo utilizo XD ).
      break;
    case 3:
      // mySerial.println(F("-----------------"));              //Desplegamos información en la terminal para saber en que momento se realiza la llamada.
      // mySerial.println(F("REALIZANDO LLAMADA"));
      INDICADOR_DE_ENVIO = modem.callNumber("0017867084206");  //Este comando esta disponible en la libreria tinyGSM y sirve para ejecutar una llamada,
      //INDICADOR_DE_ENVIO = modem.callNumber(TELEPHONE);  //Este comando esta disponible en la libreria tinyGSM y sirve para ejecutar una llamada,

      mySerial.println(INDICADOR_DE_ENVIO);                  //Mostramos el resultado de la llamada (Normalmente si se tarda es porque ocurrió algún error :'v ).
      // mySerial.println(F(""));
      ESTADO += 1;                                           //Pasamos al siguiente estado de la llamda. :v
      break;
    case 4:
      Smart_Delay(48000);                                     //Esperamos 8s. para pasar al siguiente estado
      break;
    case 5:
      mySerial.flush();                                    //Vaciamos el buffer de nuestro UART virtual.
      digitalWrite(SLEEP, HIGH);                             //Mandamos a dormir el SIMSIM800.
      ESTADO += 1;                                           //Pasamos al siguiente estado de la llamda. :v
      break;
    case 6:
      Smart_Delay(5555);                                             //Esperamos 5s. para pasar al siguiente estado (Se hace porque al finalizar la llamada todavia esta enviando cosas y generando falsos positivos)
      break;
    case 7:
      ESTADO = 0;                                                  //Desactivamos la maquina de estados finitos colocando Case 0.
      digitalWrite(MIC, LOW);
      break;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BIENVENIDOS AL ESTADO "TEXT"//
    case TEXT:
      digitalWrite(LOW_POWER_LED, LOW);
      digitalWrite(ACTIVE_LED, HIGH);                            //Activa el LED busy mientras envia un mensaje informativo al celular en formato JSON y coloca la alarmas para los mensajes periodicos.
      detachInterrupt(digitalPinToInterrupt(0));                                        //Desactivamos la interrupcion (Para evitar falsos positivos generados por los picos de energia que consumen el SIM800.
      detachInterrupt(digitalPinToInterrupt(1));                                        //Desactivamos la interrupcion (Para evitar falsos positivos generados por los picos de energia que consumen el SIM800.

      digitalWrite(SLEEP, LOW);                                  //Colocamos el pin SLLEP en estado bajo (El SIM800 se despierta).


      mySerial.println(F("SMS"));

      if (SMS_ESTATE == 0) {
        DTH();

        SECURE_COUNTER = 0;
        mySerial.println(HUMITY);
        mySerial.println(TEMP);
        BATT_PERCENT = modem.getBattPercent();                     //Solicitamos al SIM800 el valor del porcentaje de la bateria.
        BATTERY_TO_SMS = String(BATT_PERCENT) += '%';              //Lo concatenamos con % (solo para que se mire bonito :v)
        STRING_HORA_SIM800  = modem.getGSMDateTime(DATE_TIME);     //Solicitamos la hora de la red.
        JSON();
      }
      mySerial.println(F("P-E"));
      ESTADO += 1;                                               //Pasamos al siguiente estado de los mensajes. :v
      break;
    case 9:
      Smart_Delay(111);
      break;
    case 10:
      mySerial.println(F("E"));
      Serial.println(F("AT+CMGF=1"));                            //Los siguientes comandos hasta el case 18, son utilizados para enviar una mensaje de texto, los Smart_Delay son algo tediosos porque generan mas codigo pero hace mas aficiente la programacion para el compilador.
      ESTADO += 1;
      break;
    case 11:
      Smart_Delay(111);
      break;
    case 12:
      mySerial.print(F("Estado Sender: "));
      mySerial.println(SENDER);
      if (!SENDER)
      {
        Serial.println(F("AT+CMGS=\"0017867084206\""));
      }
      if (SENDER)
      {
        Serial.println("AT+CMGS=\"" + TELEPHONE + "\"");
      }
      ESTADO += 1;
      break;
    case 13:
      Smart_Delay(111);
      break;
    case 14:
      mySerial.println(SMS_ESTATE);
      if (SMS_ESTATE == 0) {
        Serial.print(JSON_STRING);
      }
      if (SMS_ESTATE == 1) {
        Serial.print(F("MOVEMENT DETECTED"));
      }
      if (SMS_ESTATE == 2) {
        Serial.print(F("OK"));
      }
      ESTADO += 1;
      break;
    case 15:
      Smart_Delay(555);
      break;
    case 16:
      Serial.print(char(26));
      ESTADO += 1;
      break;
    case 17:
      Smart_Delay(111);
      break;
    case 18:
      Serial.print("");
      Serial.flush();
      mySerial.print(F(""));
      mySerial.print(F("E2"));
      mySerial.print(F(""));
      ESTADO += 1;
      break;
    case 19:
      Smart_Delay(5555);                                                      //Esperamos esta cantidad de tiempo para evitar los falsos positivos generados por los picos de corriente que exije el  SIM800.
      break;
    case 20:
      if (SMS_ESTATE == 0)
      {

        switch (SENDER) {
          case 0:
            ESTADO = TEXT;
            SENDER = HIGH;
            break;
          case 1:
            ESTADO += 1;
            SENDER = LOW;
            break;
        }

      }

      if (!SMS_ESTATE == 0) {

        ESTADO = 0;
      }

      SETT = 0;                                                     //Esperamos esta cantidad de tiempo para evitar los falsos positivos generados por los picos de corriente que exije el  SIM800.
      break;


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BIENVENIDOS AL ESTADO "ALARMAS"//
    case ALARMS:
     ALARM_SETED="";
      CONSTRUCTOR_AT = "";                                                    //Borramos cualquier String que tenga almacena nuestro constructor (Si no lo hacemos empieza a concatenar instrucciones a lo cerdo :v )
      mySerial.println(STRING_HORA_SIM800);
      HORA_ACTUAL_INT = decodeHour(STRING_HORA_SIM800);                       //Utilizamos la funcion decodeHour() para determinar el valor (Entero) de la hora actual.
      HORA_DE_ENVIO = HORA_ACTUAL_INT + 6;                                    //Le sumamos uno para determinar de envio del siguiente mensaje, en este caso una hora despues. (Falta construir el comando para programarlo)
      mySerial.println(HORA_DE_ENVIO);
      if(HORA_DE_ENVIO != 0)
      {
      if (HORA_DE_ENVIO > 23) {
        HORA_DE_ENVIO = 24 - HORA_DE_ENVIO;
      }
      if (HORA_DE_ENVIO < 10) {                                               //Empezamos a construir nuestro comando AT para programarle la hora del siguiente envio SMS
        CONSTRUCTOR_AT += Comando1_1;
        CONSTRUCTOR_AT += String(HORA_DE_ENVIO);
        CONSTRUCTOR_AT += Comando2;
      }
      if (HORA_DE_ENVIO >= 10) {
        CONSTRUCTOR_AT += Comando1_2;
        CONSTRUCTOR_AT += String(HORA_DE_ENVIO);
        CONSTRUCTOR_AT += Comando2;
      }
      mySerial.println(F("A-P"));                               //Mostranos el comando AT construido en elPC
      mySerial.println(CONSTRUCTOR_AT);
      mySerial.println(F(""));
      sendData("AT+CALD=2", 1111, 1);                                         //Enviamos el comando que borra cualquier alarma en la posicion 2 (Yo urilize esa arbitrariamente :v ).
      ALARM_SETED = sendData(CONSTRUCTOR_AT, 1111, 1);                                      //Enviamos nuestro constructor AT con nuestra alarma ya programada.
      int SETED = ALARM_SETED.indexOf("ERROR");
      if(SETED != -1)
      {
         RETRY_SETED();
      }
      }else
      {
      mySerial.println(F("II"));
      }

      
      //sendData("AT+CALA=\"21:11:00\",2,0", 1111, 1);
      Serial.flush();                                                         //Despejamos la cola de bytes :v
      ESTADO += 1;
      break;
    case 22:
      Smart_Delay(4333);                                                      //Esperamos esta cantidad de tiempo para evitar los falsos positivos generados por los picos de corriente que exije el  SIM800.
      break;
    case 23:
      mySerial.println(F("S"));                      //Mandamos a dormir el SIM800.
      digitalWrite(SLEEP, HIGH);
      ESTADO = 0;                                                             //Vamos al Estado O donde se coloca a dormir tambien el arduino.
      // ESTADO += 1;
      break;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BIENVENIDOS AL ESTADO "NOISE"//  (Basicamente calcula la tasa de cambio producida por las interrupciones de nuestro sensor de sonido).

    case NOISE:

      digitalWrite(ACTIVE_LED, HIGH);
      delay(11);
      digitalWrite(ACTIVE_LED, LOW);
      if (ENABLE_ANALISIS) {                                                                  //Verificamos si es nesesario realizar un nuevo calculo o si ya hay uno en proceso.
        MILLIS_NOW = millis();                                                                //Verificamos el estado actual de millis() para empezar a calcular la tasa de cambio de los pulsos.
        ENABLE_ANALISIS = LOW;
      }
      if (millis() > (MILLIS_NOW + 333)) {                                                    //El tiempo de muestreo es aproximadamente 333ms despues de haber detectado un pulso
        PULSES_DIFERENCE = PULSES - PULSES_BEFORE;                                            //Se calcula la difencia de pulsos entre nuestra tasa de tiempo
        mySerial.println(PULSES_DIFERENCE);
        mySerial.println(PULSES);
        PULSES_BEFORE = PULSES;                                                               //Se guarda nuestra ultima lectura de pulsos
        ENABLE_ANALISIS = HIGH;                                                               //Se habilita la posibilidad de nuevo analisis.

        if (PULSES_DIFERENCE == 0) {
          ESTADO = 0;                                                                           //Si el resultado del analisis fue cero es porque ya no se esta produciendo ningun sonido constate ni fuerte.
        }
        if (PULSES_DIFERENCE > 22) {
          ESTADO = LLAMADA;                                                                     //Se puede modificar el 22 para tasas de cambio mas fuertes (Sonidos bastante fuertes);
          PULSES_DIFERENCE = 0;
          PULSES_BEFORE = 0;
        }

      }

      break;
   /* case READ_TEXT:
      digitalWrite(LOW_POWER_LED, LOW);
      digitalWrite(ACTIVE_LED, HIGH);                            //Activa el LED busy mientras envia un mensaje informativo al celular en formato JSON y coloca la alarmas para los mensajes periodicos.

      mySerial.println("L-A");
      READ_SMS(TOTAL_SMS);
      mySerial.flush();

      if (!SETT) {
        ESTADO = 0;
        TOTAL_SMS = 0;
      }

      break;


    case READ_GROUP:
      digitalWrite(LOW_POWER_LED, LOW);
      digitalWrite(ACTIVE_LED, HIGH);                            //Activa el LED busy mientras envia un mensaje informativo al celular en formato JSON y coloca la alarmas para los mensajes periodicos.

      for (int j = TOTAL_SMS; j > 0; j--) {
        ERASE_SMS(j);
      }

      ESTADO = 0;
      mySerial.println("E-R");
      break;*/
  }

  if (ENABLE_SCAN) {
    SIM_SCAN();
  }                                                     //ALARM es una funcion independiente de la maquina de estados finitos que siempre esta analizando los datos del UART0 en busca de alarmas.

  ESLOPE();
  CHECK_OUT();
}

void Smart_Delay(long duration) {                       //Funcion parecida a delay() pero no para la ejecucion del sketch, siempre esta atento a datos provenientes del UART0. (Funciona unicamente con maquinas de estados finitos :'v ).

  if (LOCK_MILLIS) {
    MILLIS_NOW = millis();
    LOCK_MILLIS = LOW;
    mySerial.println(F(""));
  }
  if ( millis() >= (MILLIS_NOW + duration)) {           //Se calcula la diferencia de tiempos para saber si ya transcurrio el tiempo nesesario y pasar al siguiente estado.
    LOCK_MILLIS = HIGH;
    ESTADO += 1;
  }
}

void DETECTION() {                                      //Funcion un la cual entra la interrupción 0 he inicializa la maquina de estados finitos.
  ESTADO = NOISE;                                       //Vamos al Estado Noise para analizar los pulsos (No se hace directamente aca porque al ser una interrupcion eso retrasaria cualquier proceso que se este realizando (Como recibir datos por el UART)).
  PULSES++;
}


int decodeHour(String time) {                           //La String que devuelve esta funcion: modem.getGSMDateTime(DATE_TIME); es constante y se puede desarmar XD
  time.toCharArray(ARRAY_DE_ANALISIS, sizeof(time));    //Descomponemos en un array de caracteres nuestra String con la hora
  HORA_ACTUAL += ARRAY_DE_ANALISIS[0];                  //El primer digito del entero de la hora se encuentra en la posicion 0 de la String descompuesta
  HORA_ACTUAL += ARRAY_DE_ANALISIS[1];                  //El segundo digito del entero de la hora se encuentra en la posicion 1 de la String descompuesta
  int HORA_INT =  HORA_ACTUAL.toInt();                  //Convertimos a entero la  ya decodificada.
  HORA_ACTUAL = "";                                     //Reiniciamos la variable.
  for (int h = 0; h < 12; h++) {
    ARRAY_DE_ANALISIS[12] = ' ';
  }
  return HORA_INT;
}


///////////////// Coamndo AT /////// Espera /////// Respesusta ///
String sendData(String command, const int timeout, boolean debug) {     //Funcion que permite enviar comandos AT y esperar su respuesta por determinado tiempo (si Debug esta en HIGH)
  String response = "";                                                 //Reiniciamos nuestra variable.
  Serial.println(command);                                              //Mostramos en la PC el comando que enviamos.
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

void JSON() {
  StaticJsonBuffer<99> jsonBuffer;                           //Generar un buffer para la String Json que contrendra los datos.
  JsonObject& root = jsonBuffer.createObject();               //Se crea un Objeto del tipo JsomObjet para ingresar los datos.
  root["S"] = "SIM800L";                                      //Añadimos los valores de los sensores a nuestro JSON.
  root["B"] = BATTERY_TO_SMS;
  root["dB"] = ADC_TOTAL;
  root["P"] = modem.getGsmLocation();                         //Obtenemos la localización (Se nesecita conexion GPRS :'v).
  root["D"] = STRING_HORA_SIM800;
  root["T"] = TEMP;
  root["H"] = HUMITY;
  root.printTo(JSON_SMS, sizeof(JSON_SMS));                   //Ingresamos en un array de Char nuestro JSON con los datos ya ingresados.
  //mySerial.println(JSON_SMS);
  JSON_STRING = String(JSON_SMS);                             //Convertimos a String nuestro JSON.
  /*mySerial.println("J_AC/////////////");
    mySerial.println(JSON_STRING);
    mySerial.println("JS/////////////");*/
}

void SIM_SCAN() {


  while (Serial.available()) {                          //Verificamos si hay nuevos datos disponibles en el UART0.

    C = Serial.read();                                  //Lo almacenamos en nuestra variable C.
    mySerial.write(C);

    ALARM_FLAG[7] = C;
    SMS_DETECT[7] = C;

    if ((C != '\n') && (RECORD)) {
      SMS_DATA += C;
    }
    if ((C == '\n') && (RECORD)) {
      RECORD = LOW;
      //   mySerial.println("////////////////////////");

      TOTAL_SMS  = IMBOX(SMS_DATA);
      for (int j = TOTAL_SMS; j > 0; j--) {
        ERASE_SMS(j);
      }
      SMS_DATA  = "";
      //   mySerial.println("/////////////////////////");
      SMS_DATA = "";
    }
    // && (ENABLE_READ)
    if (TOTAL_SMS > 0) {
      // mySerial.println("PROGM");
      ENABLE_READ = LOW;
      SMS_DETECTED = HIGH;

      SMS_COUNT = 3;
    }



    String A_F;
    String S_D;


    // mySerial.println("///////////////////////");
    // mySerial.print("Constructor A_F: ");
    for (int h = 0; h < 8; h++) {
      // mySerial.print(ALARM_FLAG[h]);
      A_F += ALARM_FLAG[h];
    }
    // mySerial.println(";");

    //mySerial.println("");
    //mySerial.print("Constructor S_D: ");
    for (int h = 0; h < 8; h++) {
      // mySerial.print(SMS_DETECT[h]);
      S_D += SMS_DETECT[h];
    }
    // mySerial.println(";");
    // mySerial.println("///////////////////////");


    if (A_F == "+CALV: 2") {
      // ESTADO = TEXT;
      SMS_E =  HIGH;
      mySerial.println(F("AD"));

    }
    if (A_F == "+CALV: 1")
    {

      mySerial.println(F("R"));
      mySerial.flush();
      software_Reset() ;
    }
    if (S_D == "+CMTI: \"") {
      SMS_DATA += S_D;
      RECORD =  HIGH;
    }

    for (int x = 0; x < 7; x++) {
      ALARM_FLAG[x] =  ALARM_FLAG[x + 1];
    }
    for (int x = 0; x < 7; x++) {
      SMS_DETECT[x] =  SMS_DETECT[x + 1];
    }
  }


}

int IMBOX(String SMS_STRING) {
  String TOTAL_MENSSAGES = "";
  //SMS_STRING.toCharArray( ARRAY_DE_ANALISIS_SMS, sizeof(SMS_STRING));
  int DATA_LONG = SMS_STRING.length();
  int DATA_POS = SMS_STRING.indexOf(",");
  DATA_POS++;
  for (int x = DATA_POS; x <= DATA_LONG; x++) {
    TOTAL_MENSSAGES += SMS_STRING[x];
  }
  int TOTAL_SMS =  TOTAL_MENSSAGES.toInt();
  return (TOTAL_SMS);
}

/*void READ_SMS(int SMS_NUMBER)
{
  String NEW_AT = "";
  NEW_AT = "AT+CMGR=";
  NEW_AT += SMS_NUMBER;
  // sendData(NEW_AT, 555, 1);

  String SMS_STRING = sendData(NEW_AT, 777, 1);

  ANALIZE_SMS(SMS_STRING, SMS_NUMBER);
}*/

/*void SMS_INTERRUPT() {

  if (SMS_DETECTED) {
    if (SMS_COUNT > 0) {
      SMS_COUNT--;
    }
    if (SMS_COUNT == 0) {
      if (TOTAL_SMS == 1) {
        ESTADO = READ_TEXT;
      }
      if (TOTAL_SMS > 1) {
        ESTADO = READ_GROUP;
      }

      SMS_DETECTED =  LOW;

    }

  }
}*/


/*void ANALIZE_SMS(String sms_to_analize, int SMS_NUMBER) {
  String number = "";
  String sms_menssage = "";
  int PRIMER_COMA = sms_to_analize.indexOf(',');

  int NEXT_POS = PRIMER_COMA += 2;
  int SEGUNDA_COMA = sms_to_analize.indexOf(',', NEXT_POS);
  // mySerial.println("Segunda Coma: ");
  // mySerial.println(SEGUNDA_COMA);
  // mySerial.println("////////////////////////////////");
  int FINAL_POS = SEGUNDA_COMA -= 2;



  for (int h = NEXT_POS; h <= FINAL_POS; h++) {
    number += sms_to_analize[h];
  }


  int PRIMER_SL = sms_to_analize.indexOf('\n');
  PRIMER_SL += 1;
  int SGUNDO_SL = sms_to_analize.indexOf('\n', PRIMER_SL);

  SGUNDO_SL++;
  int TERCER_SL = sms_to_analize.indexOf('\n', SGUNDO_SL);
  TERCER_SL--;

  for (int h = SGUNDO_SL; h <= TERCER_SL; h++)
  {
    sms_menssage += sms_to_analize[h];
  }

  if (sms_menssage.startsWith("{"))
  {

    ESTADO = 0;
    //mySerial.println(F("INFO"));
    //mySerial.print(F("number: "));
    mySerial.println(number);
    //mySerial.print(F("text: "));
    mySerial.println(sms_menssage);

  }
  if (sms_menssage.startsWith("{{N"))
  {
    TELEPHONE = "";
    int L = sms_menssage.length();
    for (int y = 3; y < (L - 1); y++)
    {
      TELEPHONE += sms_menssage[y];
    }
    mySerial.println("TELEPHONE:" + TELEPHONE + ".");
    ESTADO = TEXT;
    SMS_ESTATE = 2;
    SETT = HIGH;
  }


  ERASE_SMS(SMS_NUMBER);
}*/

void ERASE_SMS(int SMS_SIM_NUMBER)
{
  String AT = "AT+CMGD=";
  AT += SMS_SIM_NUMBER;
  sendData(AT, 888, 1);
}

void DTH()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f))
  {
    //  mySerial.println("Failed to read from DHT sensor!");

    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  HUMITY = int(h);
  TEMP = int(t);

}
void ESLOPE()
{
  digitalWrite(ACTIVE_LED, HIGH);
  delay(11);
  digitalWrite(ACTIVE_LED, LOW);

  if (ESTADO == 0 && !SENDER && MOVEMENT)
  {
    delay(55);
    if (digitalRead(3))
    {
      ESTADO = TEXT;
      SMS_ESTATE = 1;
      MOVEMENT = LOW;
    }
  }
}
void HIGH_G()
{
  MOVEMENT = HIGH;


}

void CHECK_OUT() {
  if (SMS_E && ESTADO == 0 && !SENDER)
  {
    SMS_E = LOW;
    ESTADO = TEXT;
  }
}

void RETRY_SETED()
{
 delay(555);
 mySerial.println(F("R-S"));
 sendData("AT+CALD=2", 1111, 1);                                                       //Enviamos el comando que borra cualquier alarma en la posicion 2 (Yo urilize esa arbitrariamente :v ).
 ALARM_SETED = sendData(CONSTRUCTOR_AT, 1111, 1);                                      //Enviamos nuestro constructor AT con nuestra alarma ya programada.
}

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  asm volatile ("  jmp 0");
}
