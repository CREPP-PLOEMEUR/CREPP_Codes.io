/*
 * This program is free software; you can redistribute it and/or
 * modify without any restriction
 * 
 * This file create a web server based on ESP12 NodeMCU.
 * You can load a page and turn-on and turn off the internal LED
 * Major informations about connection are displayed on OLED screen
 */

/*
 *   Libraries
 */
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_Sensor.h>
#include "Adafruit_BME280.h"

/*
 *   Macros
 */
#define LED D4  //LED Pin

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 //reset pin
#define SCREEN_ADDRESS 0x3C ///Sometimes 0x3D ou 0x3F


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme; 


#define SEALEVELPRESSURE_HPA (1023.25)  //Pression au niveau de la mer  

float temperature = 0.0;
float humidity = 0.0;
float pressure = 0.0;
float altitude = 0.0;

void setup() 
{
  
  Serial.begin(115200);       //Baudrate 

  bool status_BME = bme.begin(0x76);  

  if (!status_BME) 
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  }

  bool status_OLED = display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
   if (!status_OLED) 
  {
    Serial.println("Could not find a valid OLED sensor, check wiring!");
  }
  delay(100);
  display.setRotation(2);
  display.setTextSize(1);               //Size factor
  display.setCursor(0, 0);              //Set cursor to (0,0)
  display.setTextColor(SSD1306_WHITE);  //White text
}

void loop() 
{
  temperature = bme.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  pressure = bme.readPressure() / 100.0F;
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");

  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print("Approx. Altitude = ");
  Serial.print(altitude);
  Serial.println(" m");

  humidity = bme.readHumidity();
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  display.clearDisplay();
  display.setCursor(0, 0); 
  display.println("Temperature:"+String(temperature)+" C");
  display.println("Humidity:"+String(humidity)+ " %");
  display.println("Pressure:"+String(pressure)+" hPa");
  display.println("Altitude"+String(altitude)+" m");
  display.display();
  delay(1000);

}
