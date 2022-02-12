/*
 * @Author: aditya om 
 * @Date: 2022-02-11 23:28:20 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-11 23:36:48
 */
#include "wifi.h"
#include "debug.h"

#include <ESP8266WiFi.h> //connect to WiFi

String ipaddress = "";

//WiFi Network Settings
String esid = "My WiFi SSID"; //Enter WiFi Access point ID
String epass = "mywifipassword"; // Enter the WiFi access point password

#ifdef WIFI_LED
    int wifiledState = !WIFI_LED_ON_STATE;
    unsigned long wifiledTimeout = millis();
#endif

//get IP address function
void get_ip(){
    //get local
    
    //add logging

    //add connection status log

    //blink the LED if connection SUCCESS
}

void start_client(){
    
    //convert it to C string to take input from console
   
    //Convert to C STring to execute

    //execute the WiFi begin function that takes WiFi username and Password

    //add delay to allow ESP8266 some time to configure its internal WiFi antenna and make it ready for functioning

    //add reconnection and retry logic in case Connection is UNSUCCESFUL
        //CONSOLE output if connection failed
        
        //restart the reconnection
        
}

void wifi_start(){
    //set mode

    //call begin client
}

void wifi_setup(){
   //standad setup stuff
}

//Task Execution Handler 
/*
* To compare a statically coded Timeout value against the time value that has elapsed since the
* Arduino started code execution. This is done using the Arduino Millis Function. 
* If the LED Timeout hasn't happend then, Execution would go on as in void loop
* Else, in case of timeout, Toggle the LED STATE, next, Check the current PIN state. 
* If the current PIN STATE is ON then assign "ON_TIME (= 50 ms)" to "LED TIMEOUT ", 
* else if the current PIN STATE is OFF, then assign the "OFF_TIME (= 4 s)" to "LED TIMEOUT".
*/
void wifi_loop(){
 //flip the LED state
 
 //toggle the LED accordingly

        //check PIN STATE 
           
               //IF ON
              
               //IF OFF 
}