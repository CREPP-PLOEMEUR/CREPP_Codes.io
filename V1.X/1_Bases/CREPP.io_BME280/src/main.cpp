/*
 * This program is free software; you can redistribute it and/or
 * modify without any restriction
 */

/*
 *   Libraries
 */
#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include "Adafruit_BME280.h"

//
#include "CREPP_BME280.h"
#include "CREPP_I2C_Scanner.h"

/*
 *   Macros
 */

Adafruit_BME280 bme; 


#define SEALEVELPRESSURE_HPA (1023.25)  //Pression au niveau de la mer  

float temperature = 0.0;
float humidity = 0.0;
float pressure = 0.0;
float altitude = 0.0;

void setup() 
{
  
  Serial.begin(9600);       //Baudrate 
  I2C_Scan();

  bool status_BME = bme.begin(0x76);  

  if (!status_BME) 
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  }



 
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



  delay(2000);

  //BME280_Init();
  //Serial.println(BME280_Get_Temperature());
  //Serial.println(BME280_Get_Humidity());
  //Serial.println(BME280_Get_Pressure());
  //Serial.println(BME280_Get_Altitude(SEALEVELPRESSURE_HPA));

}
