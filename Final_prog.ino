/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD

#include <RemoteXY.h>
#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
// настройки соединения 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "MegaFon_2.4G_DA56DD"
#define REMOTEXY_WIFI_PASSWORD "XT3LGAMW"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "d27926c30543c0b640c29cdce89db1c3"


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 35 bytes
  { 255,1,0,21,0,28,0,16,8,1,68,17,255,1,63,49,8,30,3,132,
  2,54,39,11,0,26,67,4,3,68,31,6,0,26,17 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t select_1; // =0 если переключатель в положении A, =1 если в положении B, =2 если в положении C, ... 

    // output variables
  float lux;
  char text_1[17];  // =строка UTF8 оканчивающаяся нулем 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  Wire.begin();
  lightMeter.begin();
  RemoteXY_Init (); 
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  float ux = lightMeter.readLightLevel();
  RemoteXY.lux = ux; 
  



}
