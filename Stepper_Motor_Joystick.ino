/*Stepper Motor: This program is to show how to control a stepper motor with a joystick.
 * We need a stepper motor, an external 5v battery, and your arduino uno.
 * You can't connect directly the motor from the arduino or it will burn. 
 * That's the reason why we use an an external battery, to power up the motor.
*/




#include <Stepper.h> //Include stepper motor library
#define stepper 32   //Define number of steps per revolution

#define IN1  11        
#define IN2  10      // define stepper motor control pins
#define IN3   9
#define IN4   8


Stepper steps(stepper, IN4, IN3, IN2, IN1);   //Initialize stepper library
int Ypin = A0;   //Set the analog pin A0 for the Yaxis
int val;         //Set a memory where you can store values


void setup()
{
  Serial.begin(9600); //Set a serial communication
}

void loop()
{

  val = analogRead(Ypin);// Store the joystick bit value into the memory
  Serial.print(val);     // Print the bit value in the serial monitor

  if (  (val > 500) && (val < 523) ) //if the value is in between those two value, nothing move
  {                                        //neutral position
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

  }

  else
  {
    
    while (val >= 523)
    {
      int speed_ = map(JoyVal, 550, 1023, 5, 500); //Scale the speed
      steps.setSpeed(speed_);                      //Set the speed
      steps.step(1);                               //Start the steps in the positive direction(Clockwise)
        val = analogRead(Ypin);                    //Store the joystick bit value into the memory
    }

   
    while (val <= 500)
    {
      int speed_ = map(val, 500, 0, 5, 500);        //Scale the speed
      steps.setSpeed(speed_);                       //Set the speed
      steps.step(-1);                               //Start the steps in the opposite direction(CounterClockwise)
      val = analogRead(Ypin);                       //Store the joystick bit value into the memory
    }

  }

}
