#ifndef CELLULARHTTP_H
#define CELLULARHTTP_H

#include <Arduino.h>
#include <ArduinoHttpClient.h>
#include "GPRS.h"

bool server_connect() {
    if (!modem.isGprsConnected()) {
        return false;
    }

    if (!client.connect(server, port)) {
        return false;
    }

    return true;
}

String HttpGET(const String& resource) {
    HttpClient http(client, server, port);
    http.beginRequest();
    http.get(resource);
    http.sendHeader("Content-Type", "application/json");
    http.sendHeader("Accept", "application/json");
    http.endRequest();

    int statusCode = http.responseStatusCode();
    String response = http.responseBody();

    http.stop();

    return response;
}

String HttpPost(const String& resource) {
    HttpClient http(client, server, port);
    http.beginRequest();
    http.post(resource);
    http.sendHeader("Content-Type", "application/json");
    http.sendHeader("Accept", "application/json");
    http.endRequest();

    int statusCode = http.responseStatusCode();
    String response = http.responseBody();

    http.stop();

    return response;
}

#endif // CELLULARHTTP_H