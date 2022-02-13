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
   
   //enable debugging: initialize Debug Port
   
   //Debug messages upon first start to Console Output
   
   
   //display version of server firmware 

   
   //display the unique ESP Chip ID


   //Load Config: Read saved settings from the config
   
   
   //WiFi Setup: Initialize the WiFi


   //Sensors Setup: Initialize Sensors


   //Relay Setup: Initialize relays(Actuation modules)
 
   //Web Server Setup: Bring up the Web server


   //Display mesage to console that : SERVER IS UP !! :)


   //before prog entry to loop, give a delay of 100 milliseconds

}

// -------------------------------------------------------------------
// MAIN LOOP 
// -------------------------------------------------------------------
void loop () {

    //wifi loop
    /*
    * This loop will handle the toggling of an LED to indicate the STATE of the WiFi connection
    */  

    
    //sensors loop
    /*
    * This loop will periodically poll the sensors and retrieve the data. 
    * Task execution loop impentation is done using the Arduino Miller's function
    */

}