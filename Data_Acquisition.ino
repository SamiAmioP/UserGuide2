/* Data Acquisition: In this program, we are ask to take information from the sensor and store it into an SD card to display them in an EXCEL sheet.  
 *  This will allow us to make a graph on Excel. 
 *  To proceed, We need a temperature sensor(DHT11) and an SD card with his module.

*/


#include <SPI.h> //Include the SPI library 
#include <SD.h>  //Include the SD card library

#include <DHT.h> //Include the DHT11 sensor library

int CSpin = 4; //Attribute a pin for the CS port of SD card's module
File myDHT11Data; //Create a file

#define DHTPIN 7 //Attribute a pin for the sensor
#define DHTTYPE DHT11 //Since there are two different sensors, the DHT22 and DHT11, we define the one we need to have the proper settings.

DHT dht(DHTPIN, DHTTYPE); // Attribute a name for DHT and attribute his pin and type
float Tempvalue = 0; // Set a float for temperature
float Humvalue = 0;  // Set a float for humidity

void setup() {
  // put your setup code here, to run once:
SD.begin(CSpin); //Set the communication of the SD card
dht.begin();     //Set the DHT sensor communication (since dht is the name we gave)
}

void loop() {
// put your main code here, to run repeatedly:
Tempvalue = dht. readTemperature(); //Store the dht temperature into Tempvalue 
Humvalue = dht. readHumidity();     //Store the dht humidity into Humvalue

myDHT11Data = SD.open("Graphs.txt", FILE_WRITE); //Open the file and start saving the values

myDHT11Data.print(Tempvalue); //print the temperature value into the SD card
myDHT11Data.print(",");       //This a gap to separe the different value
myDHT11Data.print(Humvalue);  //print the humidity value into the SD card
myDHT11Data.println();        //This will stop the printing
delay(1000);                  //Delay of 1 second
myDHT11Data.close();          //Close the file

}
