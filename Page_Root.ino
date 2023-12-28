void handle_root()
{
  String html = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta name="description" content="Wi-Fi module ESP8266 version ESP-01S based on the ESP8266EX chip with built-in TCP/IP protocol stack and AT command control">
        <link rel="icon" type="image/x-icon" href="https://iot-guider.com/wp-content/uploads/2017/08/Hardware-Information-ESP-01.png">
        <link rel="stylesheet" href="/styles">
        <title>ESP01S WEB SERVER</title>
    </head>
    <body>
        <div class="header">
            <img style="width:10%;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/Flag_of_Ukraine.svg/800px-Flag_of_Ukraine.svg.png">
            <div>
              <a href="/esp8266ex">ESP8266EX</a>
            </div>
            <img style="width:10%;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Flag_of_Kharkiv_Oblast.svg/1200px-Flag_of_Kharkiv_Oblast.svg.png">
        </div>

        <div class="content">
            <h1>This site hosted from ESP01S</h1>
            <img src="https://arduino.ua/products_pictures/medium_aoc631_4.jpg">
            <br>
            <div class="cleanslate w24tz-current-time w24tz-middle" style="display: inline-block !important; visibility: hidden !important; min-width:300px !important; min-height:145px !important;"><p><a href="//24timezones.com/Kyiv/time" style="text-decoration: none" class="clock24" id="tz24-1703714886-c1367-eyJob3VydHlwZSI6IjEyIiwic2hvd2RhdGUiOiIxIiwic2hvd3NlY29uZHMiOiIxIiwiY29udGFpbmVyX2lkIjoiY2xvY2tfYmxvY2tfY2I2NThjYTA0NmVhNTg5IiwidHlwZSI6ImRiIiwibGFuZyI6ImVuIn0=" title="Kyiv local time" target="_blank" rel="nofollow">Current time in Kyiv</a></p><div id="clock_block_cb658ca046ea589"></div></div>
            <script type="text/javascript" src="//w.24timezones.com/l.js" async></script>
            <br>
            <iframe
              title="Board performance"
              width="308px"
              height="200px"
              src="/performance"></iframe>

            <h2>ESP01S Board Specifications</h2>

            <table>
            <tr>
                <th>Parameter</th>
                <th>Description</th>
            </tr>
            <tr>
                <td>Microcontroller</td>
                <td>ESP8266</td>
            </tr>
            <tr>
                <td>Flash Memory</td>
                <td>1MB</td>
            </tr>
            <tr>
                <td>Operating Voltage</td>
                <td>3.3V</td>
            </tr>
            <tr>
                <td>GPIO Pins</td>
                <td>2</td>
            </tr>
            <tr>
                <td>Wi-Fi Standard</td>
                <td>802.11 b/g/n</td>
            </tr>
            <tr>
                <td>Antenna</td>
                <td>Onboard PCB Antenna</td>
            </tr>
            <tr>
                <td>Dimensions</td>
                <td>14.3mm x 24.8mm</td>
            </tr>
            <tr>
                <td>Operating Temperature</td>
                <td>-40°C to 125°C</td>
            </tr>
            </table>        
        </div>
        <footer>
            <hr>
            <p>Copyright ©️ Razenxc Software 2023</p>
            <hr>
        </footer>
    </body>
    </html>
  )";
  Serial.println("Received request for /, 200");
  server.send(200, "text/html", html);
}