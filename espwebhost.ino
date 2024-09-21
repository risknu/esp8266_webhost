#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "variables.hpp"

#ifndef ew_cssid
#define ew_cssid "..."
#endif

#ifndef ew_cpassword 
#define ew_cpassword "..."
#endif

#ifndef _kw 
#define _kw "hello_world"
#endif

#ifndef request_string_buffer
#define request_string_buffer 2048
#endif

#ifndef all_page_buffer 
#define all_page_buffer 4096
#endif

// define the web server port using ew_port, fallback to 80 if not defined
#ifdef ew_port
ESP8266WebServer server(ew_port);
#else
ESP8266WebServer server(80);
#endif

static char* request_json_stats(void) {
    static char json_string_content[request_string_buffer];

    uint32_t chip_id = ESP.getChipId(); uint32_t flash_size = ESP.getFlashChipSize() / 1024;
    uint32_t free_heap = ESP.getFreeHeap();
    int32_t wifi_signal = WiFi.RSSI(); uint32_t uptime = millis() / 1000;

    snprintf(json_string_content, sizeof(json_string_content),
        "{\"chip_id\": \"%u\",\"flash_size\": \"%u KB\",\"free_heap\": \"%u bytes\","
        "\"wifi_signal\": \"%d dBm\",\"uptime\": \"%u seconds\"}",
        chip_id, flash_size, free_heap, wifi_signal, uptime);

    return json_string_content;
}

static void handle_root(void) {
    static char page_string_content[all_page_buffer] = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>esp8266 hosted by risknu</title><script>function _update_esp_stats() {var xhr = new XMLHttpRequest();xhr.onreadystatechange = function () {if (this.readyState == 4 && this.status == 200) {var esp_json_stats = JSON.parse(this.responseText);document.getElementById('chip_id').innerHTML = esp_json_stats.chip_id; document.getElementById('flash_size').innerHTML = esp_json_stats.flash_size;document.getElementById('free_heap').innerHTML = esp_json_stats.free_heap; document.getElementById('wifi_signal').innerHTML = esp_json_stats.wifi_signal;document.getElementById('uptime').innerHTML = esp_json_stats.uptime;} else {document.getElementById('chip_id').innerHTML = '~'; document.getElementById('flash_size').innerHTML = '~';document.getElementById('free_heap').innerHTML = '~'; document.getElementById('wifi_signal').innerHTML = '~';document.getElementById('uptime').innerHTML = '~'; }};xhr.open('GET', '/request_stats', true); xhr.send();} setInterval(_update_esp_stats, 1000);</script></head><body><style>:root {--color-white: #ffffff; --color-gray: #757575;--color-black: #000000; --color-link: #ff55ff;}* {font-family: monospace; font-size: 11pt;font-weight: 400; font-style: normal;padding: 0px; margin: 0px;box-sizing: border-box;color: var(--color-white);}html, body {background-color: var(--color-gray);width: 100%; height: 100%;overflow-y: hidden; overflow-x: hidden;}.container {position: absolute; top: 50%; left: 50%;transform: translate(-50%, -50%);background-color: var(--color-black);width: 344px; padding: 12px;box-shadow: 12px 13px 0px 0px #0000004f;}.container-content {outline: 2px solid var(--color-white); padding: 18px;}.container-header {position: absolute;background-color: var(--color-black);padding: 0px 12px; left: 50%; top: 1px;transform: translate(-50%, 0px);}.link {color: var(--color-link); text-decoration: none;-webkit-touch-callout: none; -webkit-user-select: none;-khtml-user-select: none; -moz-user-select: none;-ms-user-select: none; user-select: none;}.copyright {color: var(--color-gray);}</style><div class='container'><h1 class='container-header'>esp8266 header</h1><div class='container-content'><p>Chip ID -> <span class='link' id='chip_id'></span></p><p>Flash Chip Size -> <span class='link' id='flash_size'></span></p><p>Free Heap -> <span class='link' id='free_heap'></span></p><p>WiFi Signal (RSSI) -> <span class='link' id='wifi_signal'></span></p><p>Uptime -> <span class='link' id='uptime'></span></p><span class='copyright'>copyright (c) risknu 2023-2024</span></div></div><script>_update_esp_stats();</script></body></html>";
    server.send(200, "text/html", page_string_content);
}

static void handle_stats(void) {
    char* json_string_content = request_json_stats();
    server.send(200, "application/json", json_string_content);
}

static void handle_not_found(void) {
    // if you want to add more features to 404 error page:
    // (server.method() == HTTP_GET) ? F("GET") : F("POST");
    // F("\nArguments: ") + String(server.args()) + F("\n");
    // F("URI: ") + server.uri() + F("\nMethod: ");
    // for (uint8_t i = 0; i < server.args(); i++) {
    //     message += F(" ") + server.argName(i) + F(": ") + server.arg(i) + F("\n");
    // }
    static char error_page_content[all_page_buffer] = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>oops -> page not found error; code 404</title></head><body><style>:root {--color-white: #ffffff; --color-gray: #757575;--color-black: #000000; --color-link: #ff55ff;}* {font-family: monospace; font-size: 11pt;font-weight: 400; font-style: normal;padding: 0px; margin: 0px;box-sizing: border-box;color: var(--color-white);}html, body {background-color: var(--color-gray);width: 100%; height: 100%;overflow-y: hidden; overflow-x: hidden;}.container {position: absolute; top: 50%; left: 50%;transform: translate(-50%, -50%);background-color: var(--color-black);width: 344px; padding: 12px;box-shadow: 12px 13px 0px 0px #0000004f;}.container-content {outline: 2px solid var(--color-white); padding: 18px;}.container-header {position: absolute;background-color: var(--color-black);padding: 0px 12px; left: 50%; top: 1px;transform: translate(-50%, 0px);}.link {color: var(--color-link); text-decoration: none;-webkit-touch-callout: none; -webkit-user-select: none;-khtml-user-select: none; -moz-user-select: none;-ms-user-select: none; user-select: none;}.copyright {color: var(--color-gray);}</style><div class='container'><h1 class='container-header'>oops bruh</h1><div class='container-content'><p>oops page not found error <span class='link'>404</span></p><span class='copyright'>copyright (c) risknu 2023-2024</span></div></div></body></html>";
    server.send(404, "text/html", error_page_content);
}

void setup(void) {
    #ifdef ser_
    Serial.begin(ser_);
    #else
    Serial.begin(115200);
    #endif
    
    delay(10); WiFi.begin(ew_cssid, ew_cpassword);
    Serial.print(F("[*] connecting to WiFi"));
    while (WiFi.status() != WL_CONNECTED) {
        delay(500); Serial.print(F("."));
    }

    Serial.println("\n[*] WiFi connected\nip address ->");
    Serial.println(WiFi.localIP());

    server.on("/", handle_root); Serial.println(F("[*] root(index) page started"));
    server.on("/request_stats", handle_stats); Serial.println(F("[*] ajax json stats started"));
    server.onNotFound(handle_not_found); Serial.println(F("[*] 404 page not found page started"));

    server.begin(); Serial.println(F("[*] HTTP server started"));
}

void loop(void) {
    server.handleClient();
}
