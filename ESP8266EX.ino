void handle_ESP8266EX()
{
  String html = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta charset="UTF-8">
        <meta name="description" content="Espressif’s ESP8266EX delivers highly integrated Wi-Fi SoC solution to meet users’ continuous demands for efficient power usage, compact design and reliable performance in the Internet of Things industry.">
        <link rel="icon" type="image/x-icon" href="https://iot-guider.com/wp-content/uploads/2017/08/Hardware-Information-ESP-01.png">
        <link rel="stylesheet" href="/styles">
        <title>ESP01S WEB SERVER | ESP8266EX SPECS</title>
    </head>
    <body>
        <div class="header">
            <img style="width:10%;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/Flag_of_Ukraine.svg/800px-Flag_of_Ukraine.svg.png">
            <div>
              <a href="/">MAIN</a>
            </div>
            <img style="width:10%;" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Flag_of_Kharkiv_Oblast.svg/1200px-Flag_of_Kharkiv_Oblast.svg.png">
        </div>

        <div class="content">
            <h2>Specifications ESP8266EX</h2>
            <table>
            <tr>
                <th>Categories</th>
                <th>Items</th>
                <th>Parameters</th>
            </tr>
            <tr>
                <td rowspan="11">Wi-Fi</td>
                <td>Certification</td>
                <td>Wi-Fi Alliance</td>
            </tr>
            <tr>
                <td>Protocols</td>
                <td>802.11 b/g/n (HT20)</td>
            </tr>
            <tr>
                <td>Frequency Range</td>
                <td>2.4 GHz ~ 2.5 GHz (2400 MHz ~ 2483.5 MHz)</td>
            </tr>
            <tr>
                <td>TX Power</td>
                <td>802.11 b</td>
                <td>+20 dBm</td>
            </tr>
            <tr>
                <td></td>
                <td>802.11 g</td>
                <td>+17 dBm</td>
            </tr>
            <tr>
                <td></td>
                <td>802.11 n</td>
                <td>+14 dBm</td>
            </tr>
            <tr>
                <td>Rx Sensitivity</td>
                <td>802.11 b</td>
                <td>–91 dBm (11 Mbps)</td>
            </tr>
            <tr>
                <td></td>
                <td>802.11 g</td>
                <td>–75 dBm (54 Mbps)</td>
            </tr>
            <tr>
                <td></td>
                <td>802.11 n</td>
                <td>–72 dBm (MCS7)</td>
            </tr>
            <tr>
                <td>Antenna</td>
                <td>PCB Trace, External, IPEX Connector, Ceramic Chip</td>
            </tr>
            <tr>
                <td rowspan="9">Hardware</td>
                <td>CPU</td>
                <td>Tensilica L106 32-bit processor</td>
            </tr>
            <tr>
                <td>Peripheral Interface</td>
                <td>UART/SDIO/SPI/I2C/I2S/IR Remote Control</td>
            </tr>
            <tr>
                <td>GPIO/ADC/PWM/LED Light & Button</td>
                <td>Operating Voltage</td>
                <td>2.5 V ~ 3.6 V</td>
            </tr>
            <tr>
                <td>Operating Current</td>
                <td>Average value: 80 mA</td>
            </tr>
            <tr>
                <td>Operating Temperature Range</td>
                <td>–40 °C ~ 125 °C</td>
            </tr>
            <tr>
                <td>Package Size</td>
                <td>QFN32-pin (5 mm x 5 mm)</td>
            </tr>
            <tr>
                <td>External Interface</td>
                <td>-</td>
            </tr>
            <tr>
                <td rowspan="6">Software</td>
                <td>Wi-Fi Mode</td>
                <td>Station/SoftAP/SoftAP+Station</td>
            </tr>
            <tr>
                <td>Security</td>
                <td>WPA/WPA2</td>
            </tr>
            <tr>
                <td>Encryption</td>
                <td>WEP/TKIP/AES</td>
            </tr>
            <tr>
                <td>Firmware Upgrade</td>
                <td>UART Download / OTA (via network)</td>
            </tr>
            <tr>
                <td>Software Development</td>
                <td>Supports Cloud Server Development / Firmware and SDK for fast on-chip programming</td>
            </tr>
            <tr>
                <td>Network Protocols</td>
                <td>IPv4, TCP/UDP/HTTP</td>
            </tr>
            <tr>
                <td>User Configuration</td>
                <td>AT Instruction Set, Cloud Server, Android/iOS App</td>
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
  Serial.println("Received request for /esp8266ex, 200");
  server.send(200, "text/html", html);
}