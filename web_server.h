/*
 * @Author: aditya om 
 * @Date: 2022-02-06 22:11:23 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2022-02-06 22:12:20
 * Description: basic declaration of web server
 */

#ifndef _WEB_SERVER_H
    #define _WEB_SERVER_H

    #include <Arduino.h>
    #include <ESPAsyncTCP.h>
    #include <ESPAsyncWebServer.h>

    extern AsyncWebServer server;

    extern void web_server_setup();

 #endif // _WEB_SERVER_H