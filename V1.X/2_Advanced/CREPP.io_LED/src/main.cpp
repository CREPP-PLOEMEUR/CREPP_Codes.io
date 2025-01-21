/*!
CREPP.io code
Ce code permet de faire clignoter les LEDs reliées aux sorties D0, D3 et D4
Ne pas oublier de mettre les jumpers associés (D0, D3 et D4)
*/
#include <Arduino.h> 

#define RED_LED D0
#define ORANGE_LED D3
#define GREEN_LED D4


int delayGreen = 1000; //Temps d'allumage/Extinction
int delayOrange = 1000; //Temps d'allumage/Extinction
int delayRed = 1000; //Temps d'allumage/Extinction

void setup() 
{
    Serial.begin(9600);         //Initialise la communication série
    pinMode(RED_LED, OUTPUT);     //Broche en sortie
    pinMode(ORANGE_LED, OUTPUT);  //Broche en sortie
    pinMode(GREEN_LED, OUTPUT);   //Broche en sortie
    Serial.println("INIT : OK");
}



void loop() 
{ 
  
  Serial.println("GREEN ON");
  digitalWrite(GREEN_LED, HIGH);
  delay(delayGreen);
  digitalWrite(GREEN_LED, LOW);
  delay(delayGreen);
  Serial.println("GREEN OFF");

  Serial.println("ORANGE ON");
  digitalWrite(ORANGE_LED, HIGH);
  delay(delayOrange);
  digitalWrite(ORANGE_LED, LOW);
  delay(delayOrange);
  Serial.println("ORANGE OFF");

  Serial.println("RED ON");
  digitalWrite(RED, HIGH);
  delay(delayRed);
  digitalWrite(RED, LOW);
  delay(delayRed);
  Serial.println("RED OFF");

}

