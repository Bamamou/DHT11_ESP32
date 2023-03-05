#include <Arduino.h> // Include the Arduino Framework
#include "DHTesp.h" // Include the DHT librairy for the ESPx

DHTesp dht;             // create a DHT object
int delayTime =1000;   // Set the delay time between each values 
int counter;          // data counter  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  dht.setup(4, DHTesp::DHT11);   // If you are using the DHT11, you just need to change the value 22 to 11
  delay(dht.getMinimumSamplingPeriod());
  Serial.println(dht.getStatusString());
}

void loop() {
  float temperature = dht.getTemperature();       // To store the values of tempreature
  float humidity = dht.getHumidity();            // To store the values of Humidity
   Serial.println("Data: "+ String(counter));   // Print the data index
  // Print the values of Humidity 
  Serial.print("Humidity:\t");
  Serial.println(humidity);
    // Print he values of Temperature in Celsus
  Serial.print("Temperatue:\t");
  Serial.print(temperature);
  Serial.println("C");
  // Print the values of temperature in Fahrenheit
  Serial.print("Temperatue:\t");
  Serial.print(dht.toFahrenheit(temperature));
  Serial.println("F");
  // Print the values of the heat Index for both Units
  Serial.print("Heat Index In Celsus: ");
  Serial.println(dht.computeHeatIndex(temperature, humidity, false));
  Serial.print("Heat Index In Fahrenheit: ");
  Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true));
  delay(delayTime);
  counter++;  // update the counbter
}