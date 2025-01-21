/*
NE PAS OUBLIER LE JUMPER JP1
*/
#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>

// Créer une instance de l'objet RTC
RTC_DS1307 rtc;

void setup() 

{
  Serial.begin(115200);

  // Initialiser le RTC
  if (!rtc.begin()) 
  {
    Serial.println("RTC non trouvé !");
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC n'est pas en marche, réinitialisation !");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Ajuster à la date et l'heure de compilation
  }

  // Configurer le signal SQW pour faire clignoter la LED
  rtc.writeSqwPinMode(Ds1307SqwPinMode::DS1307_SquareWave1HZ); // Configurer pour une sortie 4kHz

 
}

void loop() {
  
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
}