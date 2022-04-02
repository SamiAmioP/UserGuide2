/* LCD with push button: This program shows how to display the temperature on the LCD and change the value from celsius to fahrenheit with the push button.
 *  We need the lcd, a push button, 220 ohm resistor, dht11 sensor
*/


#include <DHT.h> //Include the DHT11 sensor library
#define DHTPIN 7 //Attribute a pin for the sensor
#define DHTTYPE DHT11     //Since there are two different sensors, the DHT22 and DHT11, we define the one we need to have the proper settings.
DHT dht(DHTPIN, DHTTYPE); // Attribute a name for DHT and attribute his pin and type.



#include <LiquidCrystal.h> //Include the LCD library
LiquidCrystal lcd(12, 5, 4, 3, 2); //


int PushB = 8; //Set an input
float C = 0;   //Set a float for Celsius temperature



void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
pinMode(PushB, INPUT); //Set the push button as an Input
}

void loop() {
  // put your main code here, to run repeatedly:
 C = dht. readTemperature(); //Store the dht temperature into C 
  if (PusB == LOW) {               //If the push button state is low, then the Celsius temperature will be print

  lcd.setCursor(0,0);              //Go to the top line of the lcd
  lcd.print("Temperature in C: "); //Print the variable
  lcd.setCursor(0,1);              //Go to the bottom line of the lcd
  lcd.print(C);                    //Print in Celsius
  lcd.print("C");                  //Print the variable

  }

  else if (PusB == HIGH){          //If the push button state is High, then the fahrenheit temperature will be print

    float F = (C*1.8)+32;          //The math to convert celsius to fahrenheit
  lcd.setCursor(0,0);              //Go to the top line of the lcd
  lcd.print("Temperature in F: "); //Print the variable
  lcd.setCursor(0,1);              //Go to the bottom line of the lcd
  lcd.print(F);                    //Print in fahrenheit
  lcd.print("F");                  //Print the variable
    
    
    
    
    
    }



}
