/*
 * @Author: aditya om 
 * @Date: 2022-02-06 22:15:39 
 * @Last Modified by: aditya om
 * @Last Modified time: 2022-02-06 22:46:22
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
    AsyncResponseStream *response;
    if(false == requestPreProcess(request, response)){
        return;
    }

    //Form JSON String to respond to the status AJAX requests from App client
    String s = "{";
    s += "\"relay_1_state\":" + String(relay_1_state ? "false":"true") + ",";
    s += "\"relay_2_state\":" + String(relay_2_state ? "false":"true") + ",";
    s += "\"relay_3_state\":" + String(relay_3_state ? "false":"true") + ",";

    //temperature settings in console
    s += "\"dallas_temperature\":\"" + String(dallas_temperature) + "\",";
    s += "\"dht_temperature\":\"" + String(dht_temperature) + "\",";
    s += "\"dht_humidity\":\"" + String(dht_humidity) + "\"";
    s += "}";

    //output to console
    DBUG("[web_server] '/status' response");
    DBUGLN(s);

    response->setCode(200);
    response->print(s);
    request->send(response);
}

