/* DC motor with IC chip: This program shows how to control the spining direction of the motor. 
 *  We need a DC MOTOR, a RELAY, the ARDUINO, and an external battery.
 *  We can not directly connect the DC motor to the arduino or it will cook(burn). 
 *  The power used by the motor to spin is get it by an external battery.
 *  The LOW and HIGH state will allow the DC motor go either left or right (Direction)
 
*/

int MotorPin1 = 5; //Set the MotorPin1 variable to pin 5
int MotorPin2 = 6; //Set the MotorPin2 variable to pin 6



void setup() {
  // put your setup code here, to run once:
pinMode(MotorPin1, OUTPUT); //Set the pin of the MotorPin1(5) as an OUTPUT
pinMode(MotorPin2, OUTPUT); //Set the pin of the MotorPin2(6) as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(MotorPin1, HIGH); //Set the MotorPin1 to HIGH
digitalWrite(MotorPin2, LOW);  //Set the MotorPin2 to LOW
delay(2000);                   //Will let the instructions above for the 2 seconds

digitalWrite(MotorPin1, LOW);  //Set the MotorPin1 to LOW
digitalWrite(MotorPin2, HIGH); //Set the MotorPin2 to HIGH
delay(2000);                   //Will let the instructions above for the 2 seconds

}
