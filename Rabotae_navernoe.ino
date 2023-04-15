#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD
#include <RemoteXY.h>
#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
int a, mode;

#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "MegaFon_2.4G_DA56DD"
#define REMOTEXY_WIFI_PASSWORD "XT3LGAMW"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "d27926c30543c0b640c29cdce89db1c3"

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 35 bytes
  { 255,1,0,15,0,28,0,16,25,1,68,17,0,0,64,50,25,30,3,132,
  3,53,58,16,29,26,67,4,3,72,21,8,29,25,11 };
struct {

  uint8_t mode;

  float lux;
  char text_1[11];  

  uint8_t connect_flag;

} RemoteXY;
#pragma pack(pop)

void setup() 
{
  Wire.begin();
  lightMeter.begin();
  RemoteXY_Init (); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, INPUT);
  a=0;
  
}

void loop() 
{ 
  float ux = lightMeter.readLightLevel();
  RemoteXY.lux = ux; 
  RemoteXY_Handler ();
 
  if (RemoteXY.mode==0) {
  strcpy  (RemoteXY.text_1, "Для тонких работ"); // не точно
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);  
  analogWrite(2, a);
  if(ux>500 && a!=0){
    a-=1;} 
  if(ux<500 && a!=255){
    a+=1;}
  }
  else if (RemoteXY.mode==1) {
  strcpy  (RemoteXY.text_1, "Для офиса"); // не точно
  analogWrite(2, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);  
  analogWrite(3, a);
  if(ux>400 && a!=0){
    a-=1;} 
  if(ux<400 && a!=255){
    a+=1;}
  }
  
  else if (RemoteXY.mode==2) {
  strcpy  (RemoteXY.text_1, "Для Гостинной"); // не точно
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(5, 0);  
  analogWrite(4, a);
  if(ux>150 && a!=0){
    a-=1;} 
  if(ux<150 && a!=255){
    a+=1;}
  }
  
  else if (RemoteXY.mode==3) {
  strcpy  (RemoteXY.text_1, "Для детской"); // не точно
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);  
  analogWrite(5, a);
  if(ux>200 && a!=0){
    a-=1;} 
  if(ux<200 && a!=255){
    a+=1;}
  }
}
