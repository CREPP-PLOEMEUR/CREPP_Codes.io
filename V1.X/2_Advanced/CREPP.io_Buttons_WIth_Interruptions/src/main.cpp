
#include <Arduino.h>


const int buttonUpPin = D6;    
const int buttonDownPin = D7; 
const int buttonRightPin = D5;  
const int buttonLeftPin = D8;   
/*!
 ATTENTION : LORS DE L'ENVOI DU PROGRAMME, SI LE JUMPER D8 EST MIS, IL FAUT APPUYER SUR LE BOUTON 
 INDIQUÉ "LEFT" LORS DES PREMIÈRES SECONDES D'ENVOI DU PROGRAMME, SOUS PEINE D'ERREUR LE CAS ÉCHÉANT
*/

//Variable commune entre les interruptions et le code principal
volatile bool buttonUpPressed = false;
volatile bool buttonDownPressed = false;
volatile bool buttonRightPressed = false;
volatile bool buttonLeftPressed = false;

//Anti-rebond
const unsigned long debounceTime = 50;
unsigned long lastButtonPressTime = 0;



void IRAM_ATTR buttonUpISR() 
{
    if (millis() - lastButtonPressTime > debounceTime) {
        buttonUpPressed = true;
        lastButtonPressTime = millis();
    }
}

void IRAM_ATTR buttonDownISR() 
{
    if (millis() - lastButtonPressTime > debounceTime) {
        buttonDownPressed = true;
        lastButtonPressTime = millis();
    }
}

void IRAM_ATTR buttonRightISR() 
{
    if (millis() - lastButtonPressTime > debounceTime) {
        buttonRightPressed = true;
        lastButtonPressTime = millis();
    }
}

void IRAM_ATTR buttonLeftISR() 
{
    if (millis() - lastButtonPressTime > debounceTime) {
        buttonLeftPressed = true;
        lastButtonPressTime = millis();
    }
}

void setup() 
{
    Serial.begin(115200);
    
    //Configuration des broches
    pinMode(buttonUpPin, INPUT);
    pinMode(buttonDownPin, INPUT);
    pinMode(buttonRightPin, INPUT);
    pinMode(buttonLeftPin, INPUT);

    //Définitions des callbacks
    attachInterrupt(digitalPinToInterrupt(buttonUpPin), buttonUpISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonDownPin), buttonDownISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonRightPin), buttonRightISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonLeftPin), buttonLeftISR, FALLING);
}

void loop() 
{
    
    if (buttonUpPressed) {
        buttonUpPressed = false;
        Serial.println("Button UP pressed");
    }
    if (buttonDownPressed) {
        buttonDownPressed = false;
        Serial.println("Button DOWN pressed");
    }
    if (buttonRightPressed) {
        buttonRightPressed = false;
        Serial.println("Button RIGHT pressed");
    }
    if (buttonLeftPressed) {
        buttonLeftPressed = false;
        Serial.println("Button LEFT pressed");
    }
}
