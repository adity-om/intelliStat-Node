/**
 * @author: Aditya Om
 * @email: adityaom.code@gmail.com
 * @created on: 2022-02-12 22:15:39
 * @last modified: 2022-02-12 23:31:38
 * @desc: source arduino driver
 */

#include <Arduino.h>
#include "debug.h"
#include "wifi.h"
#include "relay.h"
#include "sensors.h"
#include "web_server.h"
#include "config.h"

// -------------------------------------------------------------------
// INITIAL SETUP : configurations upon start
// -------------------------------------------------------------------
void setup() {

   //add delay
   delay(2000);

   //enable debugging: initialize Debug Port
   DEBUG_BEGIN(115200);

   //Debug messages upon first start to Console Output
   DBUGLN();
   DBUG("Wireless - Intellistat Node Server");
      
   //display version of server firmware 
   DBUG("Version : 1.0.1"); /*Added to keep track of changes to firmware*/
   
   //display the unique ESP Chip ID
   DBUG(ESP.getChipId());

   //Load Config: Read saved settings from the config
   config_load_settings();
   
   //WiFi Setup: Initialize the WiFi
   wifi_setup();

   //Sensors Setup: Initialize Sensors
   sensors_setup();

   //Relay Setup: Initialize relays(Actuation modules)
   relay_setup();

   //Web Server Setup: Bring up the Web server
   web_server_setup();

   //Display mesage to console that : SERVER IS UP !! :)
   DBUG("[src] Server started Successfully!");

   //before prog entry to loop, give a delay of 100 milliseconds
   delay(100);
}

// -------------------------------------------------------------------
// MAIN LOOP 
// -------------------------------------------------------------------
void loop () {

    //wifi loop
    /*
    * This loop will handle the toggling of an LED to indicate the STATE of the WiFi connection
    */
    wifi_loop(); 
    
    //sensors loop
    /*
    * This loop will periodically poll the sensors and retrieve the data. 
    * Task execution loop impentation is done using the Arduino Miller's function
    */
    sensors_loop();
}