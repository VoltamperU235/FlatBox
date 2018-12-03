//El archivo config.h contiene las variables que podrian ser modificadas en base a las nesecidades del usuario

//Variables para la conexion de los pines
#define NO_CONECTION_LED 14                           
#define ACTIVE_LED 15                                
#define LOW_POWER_LED 16
#define LOW_PIN 17
#define OPEN_COLECTOR_CAPACITIVE_SENSOR 3         //Nesecita ser un pin con interrupcion externa
#define RTC_ALARM 2                               //Nesecita ser un pin con interrupcion externa
#define LOCATION "TEC"
#define RST 9

//Variables de la conexion GPRS que realiza el modem que se este utilizando
const char* apn   = "Internet.tuenti.gt";
const char* user = "";
const char* pass = "";
const char*  broker = "klimato.tk";

//Variables del Broker al cual se esta conectando
const char* username = "DENNIS";
const char* password = "FBx_admin2012";
const char* device = "Water_Sense_V1";

//Variables de los topicos a los que publica
const char* topic1 = "/WaterSense/M";
const char* topic2 = "/WaterSense/D";
const char* topic3 = "/WaterSense/T";
