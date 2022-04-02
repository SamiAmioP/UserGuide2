/* DHT 11 sensor on serial monitor: This program shows how we can put dht 11 sensor's value on the serial monitor
 * We need the DHT11 sensor.

*/
#include <DHT.h>  //Include the DHT11 sensor library
#define DHTPIN 7 //Attribute a pin for the sensor
#define DHTTYPE DHT11     //Since there are two different sensors, the DHT22 and DHT11, we define the one we need to have the proper settings.
DHT dht(DHTPIN, DHTTYPE); // Attribute a name for DHT and attribute his pin and type.


float Temp = 0; // Set a float for temperature
float Hum = 0;  // Set a float for humidity

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //Set a serial communication 
}

void loop() {
  // put your main code here, to run repeatedly:

Temp = dht. readTemperature(); //Store the dht temperature into Temp
Hum =  dht. readHumidity();    //Store the dht humidity into Hum


 
  Serial.print("Temperature = "); //Print the variable
  Serial.print(Temp);             //Print the temperature
  Serial.print("\t");             //Print a gap
  Serial.print("Humidity = ");    //Print the variable
  Serial.println(Hum);            //Print the humidity
  delay(1000);                    //Delay of 1 second
}
