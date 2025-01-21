/*!
CREPP.io
Ce code permet de tester le bon fonctionnement des boutons RIGHT, UP et DOWN
Ne pas oublier de mettre les jumpers D5, D6 et D7
NE PAS UTILISER LE BOUTON LEFT et ne pas oublier de retirer son jumper D8 !
*/
#include <Arduino.h> //For Platform.io

const uint8_t buttonUpPin = D6; //Button UP
const uint8_t buttonDownPin = D7; //Button DOWN
const uint8_t buttonRightPin = D5; //Button RIGHT

void setup() 
{
  pinMode(buttonUpPin, INPUT); //Input
  pinMode(buttonDownPin, INPUT); //Input
  pinMode(buttonRightPin, INPUT); //Input

  Serial.begin(MONITOR_SPEED); //Communication with computer
}
      
void loop() 
{
  //Read button state
  bool stateButtonUp = digitalRead(buttonUpPin);
  bool stateButtonDown = digitalRead(buttonDownPin);
  bool stateButtonRight = digitalRead(buttonRightPin);

  //Analysis

  if(stateButtonUp == LOW)
  {
    Serial.println("UP Pressed");
  }
  if(stateButtonDown == LOW)
  {
    Serial.println("DOWN Pressed");
  }
  if(stateButtonRight == LOW)
  {
    Serial.println("RIGHT Pressed");
  }

  delay(10);

}