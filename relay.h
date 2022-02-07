/*
 * @Author: aditya om 
 * @Date: 2022-02-05 02:20:39 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-05 09:29:18
 */

//Add relay guards
#ifndef _RELAY_H
    #define _RELAY_H

    #include <Arduino.h>

    //Define the Relay pins
    #define RELAY_1 1 //GPIO12 -> D6 on NodeMCU ESP8266
    #define RELAY_2 2 //GPIO13 -> D7 on NodeMCU ESP8266
    #define RELAY_3 3 //GPIO14 -> D5 on NodeMCU ESP8266

    //Macro definitions for PIN invocations
    #define RELAY_1_PIN 12
    #define RELAY_2_PIN 13
    #define RELAY_3_PIN 14

    #define ON 0 //active low
    #define OFF 1 //inactive high

    extern String relay_1_name;
    extern String relay_2_name;
    extern String relay_3_name;

    extern bool relay_latch_enabled;

    extern bool relay_1_state;
    extern bool relay_2_state;
    extern bool relay_3_state;

    //----------------------------------------------------------------
    // RELAY INITIALIZATION
    //----------------------------------------------------------------
    extern void relay_setup();

    //----------------------------------------------------------------
    // SET RELAY STATE
    //----------------------------------------------------------------
    extern void relay_set_state(uint8_t id, bool state);

#endif //_RELAY_H
