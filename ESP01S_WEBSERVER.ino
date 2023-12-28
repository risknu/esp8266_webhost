#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "Config.h"
#include "Pages.h"

ESP8266WebServer server(PORT);

void setup()
{
  Serial.begin(115200);

  WiFi.begin(SSID, PASSWORD);
  Serial.println("");
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, handle_root);
  server.on("/esp8266ex", HTTP_GET, handle_ESP8266EX);
  server.on("/performance", HTTP_GET, handle_performance);
  server.on("/styles", HTTP_GET, handle_css);

  server.begin();
}

void loop()
{
  server.handleClient();
}
