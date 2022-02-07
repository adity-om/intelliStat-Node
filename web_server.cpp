/*
 * @Author: aditya om 
 * @Date: 2022-02-06 22:15:39 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2022-02-06 22:28:53
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
}

void handleHome(AsyncWebServerRequest *request){
   //handler the default home page
}

void handleStatus(AsyncWebServerRequest * request){
  

    //Form JSON String to respond to the status AJAX requests from App client
   

    //output to console
    
}


