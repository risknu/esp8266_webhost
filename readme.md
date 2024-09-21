## Simple Website Hosting with ESP8266
This code works on ESP8266 boards, in my case, I'm using the `ESP8266 NodeMCU v3`

## Setup
To run the code, create a file in the directory named `variables.hpp` (I’ll change it to a proper `.ini` file later, but I’m too lazy for that right now XD).

```hpp
#ifndef ESP_VARIABLES_HPP
#define ESP_VARIABLES_HPP

// just because
#define _kw "hello_world"

// optional
#define request_string_buffer 2048
#define all_page_buffer 4096

// optional
#define ew_port 80u
#define ser_ 115200u

// secure defines
#define ew_cssid your_wifi_ssid
#define ew_cpassword your_wifi_password

#endif
```

That's it! You can now run the code :)

## License
...