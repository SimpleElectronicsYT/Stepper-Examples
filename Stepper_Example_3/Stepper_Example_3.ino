/* This program has been written (poorly) by Dan of the Simple Electronics Youtube channel
 * (www.SimpleElectronics.ca) and is available for you to do whatever you want with it as
 * long as you don't hold me responsible. But if you want to send me money for my terrible
 * coding, feel free! (www.patreon.com/SimpleElectronics)
 */

//Include the Arduino stepper library
#include <Stepper.h>

//Define some limit pins
int firstLimit = 7;
int secondLimit = 6;

//Define some Booleans to track the limit switch statuses
bool e1State = true;
bool e2State = false;
//Define a variable to flip around the rotation
int revolutionVal = 0;

//Use pin 8-11 on the arduino to IN1-IN4 on the stepper board
//Setting up the stepper
Stepper stepperName = Stepper(2048, 8, 10, 9, 11);

void setup() {

  //Set the RPM of the stepper motor
  stepperName.setSpeed(5);

  //Set the pinMode of our limit switches
  pinMode(firstLimit, INPUT_PULLUP);
  pinMode(secondLimit, INPUT_PULLUP);

  //Initialize the rotation variable
  revolutionVal = 100;
}

void loop() {
    //Checking the state of the button pin and saving it in our Booleans
    e1State = digitalRead(firstLimit);
    e2State = digitalRead(secondLimit);
    //Make the stepper spin in one direction
    stepperName.step(revolutionVal);
    //If any limit switch is pressed (grounded), reverse the direction of the motor
    if (e1State == false) {
      revolutionVal = revolutionVal * -1;
      stepperName.step(revolutionVal);
      e1State = true;
      delay(500);
      
    }
    if (e2State == false) {
      revolutionVal = revolutionVal * -1;
      stepperName.step(revolutionVal);
      e2State = true;
      delay(500);
    }
}
