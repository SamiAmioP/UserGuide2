/* Servo Motor: This program show how to control a servo motor with a joystick.
 *  We need a servo motor, a Joystick and the module of the Joystick

*/





#include <Servo.h> //Include the servo motor library
Servo SRV;         //Set a name to the servo motor
int Ypin = A1;     //Set an analog pin to the axis needed
int val;           //Set a memory where value can be store

void setup() {
  // put your setup code here, to run once:
SRV.attach(9);       //Attach the Output signal of the motor at the pin 9
Serial.begin(9600);  //Set a serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(Xpin);          //Store the bit number get by the joystick into the val
val = map(val, 0, 1023, 0, 180); //Scale the bit value of a range of 0-1023 to the range of the servo motor 0-180
SRV.write(val);                  //It will convert the value given in rotation, if you get 70 degrees, the servo motor will turn to 70 degrees.

Serial.println(Ypin);            //Print the analog value to help troobleshooting in case.

}
