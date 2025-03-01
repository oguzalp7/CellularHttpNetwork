#include <CellularHttpLib.h>
#include <GPRS.h>
#include <creds.h>
#include <CellularHttp.h>

bool server_connected = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Waking up GPRS...");
  GPRS_wake_up();
  server_connected = server_connect();
  if (server_connected) {
    Serial.println("Server connected!");
  } else {
    Serial.println("Server not connected!");
  }
}

void loop() {
  if (GPRS_connectivity_status() && server_connected) {
    String response = HttpGET(resource);
    Serial.println(response);
    delay(2000);
  } else {
    Serial.println("Connection lost...");
  }
}