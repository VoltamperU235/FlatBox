 /////////////////////////////////     WARNING_BOX // WATER_SENSE     ////////////////////////////////////////////
/* 
 *  Es un disposito IoT que permite monitorizar sistemas dinamicos e informar respecto a un cambio pre-programado
 * 
 *  FEATURES:
 *  Algoritmo de Ultra Bajo consumo.
 *  Conexion GPRS.
 *  Ampliable a nivel de hardware.
 *  Sistema de informe continuo de "Im Okey" cada 6 horas. 
 *  Informe constante de porcentaje de bateria.
 *  Network Position para rastreo del dispositivo.
 *  
 */

 /////////////////////////////////     History Changes     //////////////////////////////////////////////////////

//  Diciembre 3, 2018
//
//  Se creo el archivo config.h y history.h
//  
//  Bug encontrado:
//  SendHour = 24 - SendHour;
//  }
//  mySerial.println(SendHour);
//  if ( RTC.alarm(ALARM_1) )
//  {
//    RTC.setAlarm(ALM1_MATCH_HOURS, SendHour, 0, 0, 1);
//    mySerial.println(F("AS"));
//  }
//  ESTATE = 0; primer bug encontrado; Se elimino esta linea de codigo;
//  }
// --------------------------------------------------------------------------------------------------------------
