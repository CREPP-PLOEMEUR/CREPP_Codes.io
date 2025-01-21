#ifndef ANALOG_H
#define ANALOG_H

#include <Arduino.h"

class Analog 
{

typedef enum
{
        Channel_1,
        Channel_2,
        Channel_3,
        Channel_4

} AnalogChannel;
   

public:
    Analog();  

    void begin(uint8_t adress);
    void analogRead(AnalogChannel channel); 
    

private:
    
    

    ESP8266WebServer server;  // Serveur web intégré
    void (*htmlContentGenerator)();  // Pointeur de fonction pour générer le contenu HTML

    // Méthode privée pour gérer les requêtes HTTP
    void handleClientRequest();
};

#endif
