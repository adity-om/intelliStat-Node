/*
 * @Author: aditya om 
 * @Date: 2022-02-06 22:15:39 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-06 22:33:52
 */

#include "FS.h"

#include "web_server.h"
#include "config.h"
#include "debug.h"
#include "sensors.h"
#include "relay.h"
#include "ArduinoJson.h"

#define RELAY_STATE_MESSAGE 10
#define RELAY_MESSAGE_MEMORY_POOL 100

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

bool enableCors = true;

bool requestPreProcess(AsyncWebServerRequest *request, AsyncResponseStream *&response, const char *contentType="application/json"){
    //handle request pre processing
    response = request->beginResponseStream(contentType);

    if(enableCors){
        response->addHeader("Access-Control-Allow-Origin","*");
    }
    return true;
}

void handleHome(AsyncWebServerRequest *request){
   //handler the default home 
   if(SPIFFS.exists("/home.html")){
        request->send(SPIFFS, "/home.html"); 
    }
    else {
        request->send(200, "text/plain", "/home.html not found, have you fininshed the SPIFFS?");
    }
}

void handleStatus(AsyncWebServerRequest * request){
  

    //Form JSON String to respond to the status AJAX requests from App client
   

    //output to console
    
}


