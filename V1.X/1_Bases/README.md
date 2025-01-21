## Description des codes

- **CREPP.io_Buttons** :

Programme qui affiche un message sur le moniteur série en cas d'appui sur un des boutons.
**Ne pas utiliser le bouton LEFT, il faut retirer le jumper D8**

- **CREPP.io_LED** : 

Programme qui fait clignoter les 3 LEDS

- **CREPP.ui_OLED** :

Programme qui affiche du texte ("OLED : OK") sur l'écran OLED

- **CREPP.io_Potentiometre**

Programme qui affiche sur le moniteur série la tension aux bornes du potentiomètre

- **CREPP.io_RTC** : 

Programme qui configure le moduel Real Time Clock à l'heure de la compilation. La LED du module RTC doit clignoter à 1 Hz.

- **I2C_Scanner** : 

Programme qui vient scanner le bus I2C pour détecter les différents périphériques reliés à la carte.

On doit trouver le module OLED, le module pour lire les tension analogiques (ADS1115) et le capteur de température BME280.
