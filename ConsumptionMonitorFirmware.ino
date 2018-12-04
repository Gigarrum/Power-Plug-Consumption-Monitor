/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  NOTE:
  BlynkTimer provides SimpleTimer functionality:
    http://playground.arduino.cc/Code/SimpleTimer

  App project setup:
    Value Display widget attached to Virtual Pin V5
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define PIN_A0 0

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "EmonLib.h" 

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "<your Blynk auth token here>";
EnergyMonitor emon1;

// Your WiFi credentials.
// Set password to "" for open networks.
const char ssid[] = "<network ID>";
const char pass[] = "<network password>";

//Tensao da rede eletrica
int rede = 120.0;
 
//Pino do sensor SCT
int pino_sct = PIN_A0;

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void SendMeasurement()
{
  double Irms = emon1.calcIrms(1480);
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Serial.printf("%lf",Irms*rede);
  Blynk.virtualWrite(V6, Irms*rede);
  ;
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth,ssid,pass);
  
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 1800/62 = 29. 
   emon1.current(pino_sct, 29);
  // Setup a function to be called every second
  timer.setInterval(1000L, SendMeasurement);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

