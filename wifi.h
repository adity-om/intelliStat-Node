/*
 * @Author: aditya om 
 * @Date: 2022-02-11 23:27:11 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-11 23:27:37
 */

//Write header guard to avoid double exclusion issue
#ifndef _WIFI_H
    #define _WIFI_H

    #include <Arduino.h>

    #ifndef WIFI_LED
        #define WIFI_LED 16
    #endif

    #ifdef WIFI_LED
        
        #ifndef WIFI_LED_ON_STATE
            #define WIFI_LED_ON_STATE LOW
        #endif

        #ifndef WIFI_LED_ON_TIME
            #define WIFI_LED_ON_TIME 50
        #endif

        #ifndef WIFI_LED_OFF_TIME
            #define WIFI_LED_OFF_TIME 4000
        #endif
        
    #endif

    // ipaddress variable defn
    extern String ipaddress;

    extern const char *esp_hostname;

    //add function definitions for WiFi setup and WiFi Loop
    extern void wifi_setup();
    extern void wifi_loop();
    
#endif