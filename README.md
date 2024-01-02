## riksnu{forked}

`cpptoml` library github installer:
```bash
$ git clone https://github.com/skystrife/cpptoml.git
```

# ESP8266 Web Server/Site
## Setup arduino ide for esp8266
- Go to File > Preferences
- Enter Enter `http://arduino.esp8266.com/stable/package_esp8266com_index.json` into the “Additional Boards Manager URLs” field as shown in the figure below. Then, click the “OK” button

* Note: if you already have the ESP32 boards URL, you can separate the URLs with a comma as follows: `https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json`

-  Go to Tools > Board > Boards Manager
- Search for ESP8266 and press install button for the “ESP8266 by ESP8266 Community“

## Setup project
- Create `Config.h` in `/` directory of project
- Define `SSID` and `PASSWORD` for wifi in `Config.h`: `#define SSID "my_network"` , `#define PASSWORD "securepassword123"`
- Define `PORT` for webserver in `Config.h`: `#define PORT 1000`

## Upload sketch
- Tools > Board > Generic ESP8266 Module (Or other your board)
- Tools > Port > Select COM port of your board
- And click on upload button(second button with arrow in left upper side)

![image](https://github.com/razenxc/ESP8266_WEBSITE/assets/84779107/a687fae7-b7cc-4b81-9a47-cdc0fb5ff09a)

## Net
### For hosting to internet you need:
- Public(also known as "White ip") ip address: For example `10.0.0.0/24`, `10.172.0.0/24`(and other local ips) is not public ip; You can check this ip in your router, just find `Default gateway` line
- If your ip is public - just open ports on your router
## Now if you did everything correctly and checked the web server should be accessible at your public IP address
### If not:
- You haven't powered your board
- Your ip is gray(not pubic)
- If 100% ip is public - the ports were not opened correctly
- Check the logs in the serial monitor - whether the board was connected to wifi
## For hiding your origin ip you can use cloudflare and your domain, I won’t write about it here, go on yourself if you need to, I don’t even think this will be useful to anyone, I like writing readme
