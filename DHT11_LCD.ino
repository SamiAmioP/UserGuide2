/* DHT 11 sensor on the LCD: This program shows how we can put dht 11 sensor's value on the LCD
 *  We need a LCD, and the DHT11 sensor.


*/


#include <DHT.h>  //Include the DHT11 sensor library
#define DHTPIN 7 //Attribute a pin for the sensor
#define DHTTYPE DHT11     //Since there are two different sensors, the DHT22 and DHT11, we define the one we need to have the proper settings.
DHT dht(DHTPIN, DHTTYPE); // Attribute a name for DHT and attribute his pin and type.

#include <LiquidCrystal.h>//Include the LCD library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


float Temp = 0; // Set a float for temperature
float Hum = 0;  // Set a float for humidity



void setup(){
  lcd.begin(16, 2);
}

void loop(){

Temp = dht. readTemperature(); //Store the dht temperature into Temp
Hum =  dht. readHumidity();    //Store the dht humidity into Hum


  lcd.setCursor(0,0);     //Go to the top line of the lcd
  lcd.print("Temp: ");    //Print the variable
  lcd.print(Temp);        //Print the temperature
  lcd.print((char)223);
  lcd.print("C");         //Print the variable
  lcd.setCursor(0,1);     //Go to the bottom line of the lcd
  lcd.print("Humidity: ");//Print the variable
  lcd.print(Hum);         //Print the humidity
  lcd.print("%");         //Print the variable
  delay(1000);            //Delay of 1 second
}
