#include <Arduino.h> // Include the Arduino Framework


// This version of the code include an LCDdisplay to print the
#include<main.h>

DHTesp dht;             // create a DHT object
LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);  // Define the lcd object from the liduidCrystal class


String staticMessage = "DHT Tutorial";
String scrollingMessage = "Welcome to ESP32 with DHT11 !";

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}


void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  dht.setup(DHT_Pin, DHTesp::DHT11);   // If you are using the DHT22, you just need to change the value 11 to 22
  delay(dht.getMinimumSamplingPeriod());
  Serial.println(dht.getStatusString());
  lcd.init();                    
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(staticMessage);
  scrollMessage(1, scrollingMessage, 250, totalColumns);
}


void loop() {
  float temperature = dht.getTemperature();       // To store the values of tempreature
  float humidity = dht.getHumidity();            // To store the values of Humidity
  lcd.clear();
  lcd.print("Data: "+ String(counter));   // Print the data index
  // Print the values of Humidity 
  lcd.setCursor(0,1);
  String scrollingMessageHumidity = "Humidity: "+String(humidity);
  scrollMessage(1, scrollingMessageHumidity, 250, totalColumns);

  // Print he values of Temperature in Celsus
  String scrollingMessageTemperature = "Temperature: "+String(temperature) +"C";
  scrollMessage(1, scrollingMessageTemperature, 250, totalColumns);
  // Print the values of temperature in Fahrenheit
  String scrollingMessageTemperatureFahrenheit = "Temperature: "+String(dht.toFahrenheit(temperature)) +"F";
  scrollMessage(1, scrollingMessageTemperatureFahrenheit, 250, totalColumns);
  // Print the values of the heat Index for both Units
  String scrollingMessageHeatIndexCelsus = "Heat Index In Celsus: "+String(dht.computeHeatIndex(temperature, humidity, false)) +"%";
  scrollMessage(1, scrollingMessageHeatIndexCelsus, 250, totalColumns);
  String scrollingMessageHeatIndexFahrenheit = "Heat Index In Fahrenheit: "+String(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true)) +"%";
  scrollMessage(1, scrollingMessageHeatIndexFahrenheit, 250, totalColumns);
  delay(delayTime);
  counter++;  // update the counbter

}