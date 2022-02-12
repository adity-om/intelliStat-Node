/*
 * @Author: aditya om 
 * @Date: 2022-02-11 23:28:20 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-11 23:53:54
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
    IPAddress myAddress = WiFi.localIP();
    char tmpStr[40];
    
    //add logging
    sprintf(tmpStr, "%d.%d.%d.%d", myAddress[0], myAddress[1], myAddress[2], myAddress[3]);
    ipaddress = tmpStr;

    //add connection status log
    DBUG("[WiFi] Connected, IP: ");
    DBUGLN(tmpStr);

    //blink the LED if connection SUCCESS
    #ifdef WIFI_LED
        wifiledState = WIFI_LED_ON_STATE;
        digitalWrite(WIFI_LED, wifiledState);
    #endif
}

void start_client(){
  
    DBUG("[WiFi]Connecting to SSID: ");
    DBUGLN(esid.c_str()); //convert it to C string to take input from console
    DBUG("Pass: ");
    DBUGLN(epass.c_str()); //Convert to C STring to execute

    //execute the WiFi begin function that takes WiFi username and Password
    WiFi.begin(esid.c_str(), epass.c_str());

    //add delay to allow ESP8266 some time to configure its internal WiFi antenna and make it ready for functioning
    delay(50);

    //add reconnection and retry logic in case Connection is UNSUCCESFUL
    if(WiFi.waitForConnectResult() != WL_CONNECTED){
        //CONSOLE output if connection failed
        DBUGLN("[WiFi] WiFi connect failed! Rebooting...");
        delay(1000);
        //restart the reconnection
        ESP.restart();
    }
    get_ip();        
}

void wifi_start(){
    //set mode
    #ifdef WIFI_LED
      pinMode(WIFI_LED, OUTPUT);
      digitalWrite(WIFI_LED, wifiledState);
    #endif

    //call begin client
    wifi_start();
}

void wifi_setup(){
   //blink LED for WiFi state
   #ifdef WIFI_LED
        pinMode(WIFI_LED, OUTPUT);
        digitalWrite(WIFI_LED, wifiledState);
    #endif
    
    //call wifi start
    wifi_start();
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
 #ifdef WIFI_LED
       if(millis() > wifiledTimeout){
           wifiledTimeout = !wifiledState; //flip the LED state
           digitalWrite(WIFI_LED, wifiledState); //toggle the LED accordingly

        //check PIN STATE 
           if(wifiledState == WIFI_LED_ON_STATE){
               //IF ON
               wifiledTimeout = millis() + WIFI_LED_ON_TIME;
           }
           else {
               //IF OFF
               wifiledTimeout = millis() + WIFI_LED_OFF_TIME;
           }
       }
 #endif
}