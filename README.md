# DHT11_ESP32
The project is mainly about reading the ambient temperature and humidity using a DHT11 sensor and an ESP32
# Pin Configuration:

+ The + or VCC is connected to the 3V3 or 3.3V pin of the ESP32
- The - or ground is connected to the GND pin of the ESP32
+ The midle pin or data pin is connected the GPIO4 of the ESP32
+ Connect the I2C LCD acordingly (SDA to 21 and CLK to 22 of ESP32)
+ Don't forget to connect the VCC of the LCD to 5V or VIN of the ESP32
+ The DHT sensor library for ESPx by Bernd Giesecke is required 
+ The simualtion of version 1.0 is avaliable on Wokwi.com at 
+ https://wokwi.com/projects/355569587735816193
+ The simualtion of version 1.0.1 is available at 
+ https://wokwi.com/projects/358989916399451137
+ The simulation of version 1.0.2 has WIFI feature and data plotting feature using ThingSpeak
+ https://wokwi.com/projects/365254628263680001
