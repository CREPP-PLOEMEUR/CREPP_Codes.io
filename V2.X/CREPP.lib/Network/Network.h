 #ifndef NETWORK_H
#define NETWORK_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

class Network 
{

    enum NetMode {
        WIFI_OFF,
        WIFI_ON
    };
    enum AccessMode {
        WIFI_ROUTER,
        WIFI_ACCESS_POINT
    };

public:
    Network();  

    void setMode(NetMode mode);

    void init(const char* ssid, const char* password);
    void setCallback(void (*htmlCallback);

    IPAddress getIPAddress();

    void startWebServer();
    void stopWebServer();

    

    // Méthode pour configurer un serveur web et enregistrer une fonction de gestion HTML
    

private:
    void printWiFiStatus(); // Méthode privée pour afficher l'état du Wi-Fi

    ESP8266WebServer server;  // Serveur web intégré
    void (*htmlContentHandler)();  // Pointeur de fonction pour générer le contenu HTML

    // Méthode privée pour gérer les requêtes HTTP
    void handleClientRequest();
};

#endif

