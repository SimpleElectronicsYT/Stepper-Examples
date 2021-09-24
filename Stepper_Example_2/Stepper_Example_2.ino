/* This program has been written (poorly) by Dan of the Simple Electronics Youtube channel
 * (www.SimpleElectronics.ca) and is available for you to do whatever you want with it as
 * long as you don't hold me responsible. But if you want to send me money for my terrible
 * coding, feel free! (www.patreon.com/SimpleElectronics)
 */

//Include the Arduino stepper library
#include <Stepper.h>

//Define an input pin
int buttonPressPin = 7;

//Define a Boolean to track a button press
bool buttonPressed;

//Set how many steps it takes to make a full revolution. Divide the degrees per step by 360 to get the steps
const int stepsPerRevolution = 2048;

//Use pin 8-11 on the arduino to IN1-IN4 on the stepper board
//Setting up the stepper
Stepper stepperName = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {

  //Set the RPM of the stepper motor
  stepperName.setSpeed(5);

  //Set the pinMode of our button pin
  pinMode(buttonPressPin, INPUT_PULLUP);

  //Set our button press Boolean to a known value
  buttonPressed = true;
}

void loop() {
    //Checking the state of the button pin and saving it in our Boolean
    buttonPressed = digitalRead(buttonPressPin);
    //If the button is pressed (grounded), step to 90* and reset the button pressing state
    if (buttonPressed == false) {
      stepperName.step(stepsPerRevolution / 4);
      delay(50);
      buttonPressed = true;
    }
    
}
