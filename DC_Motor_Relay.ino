/* DC motor with RELAY: This program shows how to turn ON and OFF a DC motor by using arduino.
 *  We need a DC MOTOR, a RELAY, the ARDUINO. 
 *  We can not directly connect the DC motor to the arduino or it will cook(burn). 
 *  The power used by the motor to spin is get it by an external battery.
*/




void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);     //Set the pin 11 as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(11, HIGH); //Turn ON the pin 11
delay(2000);            //Set a delay of 2 seconds
digitalWrite(11, LOW);  //Turn OFF the pin 11
delay(2000):            //Set a delay of 2 seconds
}
