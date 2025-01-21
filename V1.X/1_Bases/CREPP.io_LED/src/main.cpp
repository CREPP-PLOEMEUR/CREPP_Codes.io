/*!
CREPP.io code
Ce code permet de tester le bon fonctionnement des LEDs intégrés à la carte.
Ne pas oublier de mettre les jumpers associés (D0, D3 et D4)
*/
#include <Arduino.h> 

#define RED_LED D0

#define ORANGE_LED D3
#define GREEN_LED D4

/*
Fonction qui ne retourne aucun élément et qui prend en paramètre : 
- Une broche de LED
- Une durée de clignotement (en millisecondes)
*/
void blinkLed(uint8_t led, uint16_t time)
{
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
  delay(time);
}

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
  Serial.println("LED RED ON");
  blinkLed(RED_LED, 100);  // Allume la LED rouge pendant 1 seconde
  Serial.println("LED RED OFF");
  Serial.println("LED ORANGE ON");
  blinkLed(ORANGE_LED, 150); // Allume la LED orange pendant 0.5 seconde
  Serial.println("LED ORANGE OFF");
  Serial.println("LED GREEN ON");  // Allume la LED verte pendant 0.5 seconde
  blinkLed(GREEN_LED, 200); // Allume la LED verte pendant 0.25 seconde
  Serial.println("LED GREEN OFF");

}

