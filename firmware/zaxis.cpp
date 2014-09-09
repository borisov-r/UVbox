/*
 * Control of stepper driver for the motor on Z-axis
 *
 *
 */

#include "config.h"

// move
bool moveZ( int steps,   // move steps times
            bool dir,    // set direction
            int speed )  // set speed of the movement
{
    digitalWrite(STEPPER_DIR, dir);  // set direction
    digitalWrite(STEPPER_EN, HIGH);  // enable motor power
    
    Serial.print("All steps: ");
    Serial.println(steps);
    for ( int i = 0; i < steps; i++)
    {
        digitalWrite(STEPPER_STEP, HIGH);
        delay(speed);
        digitalWrite(STEPPER_STEP, LOW);
        delay(speed);
        Serial.print("Step: ");
        Serial.println(i);
    }
  
    digitalWrite(STEPPER_EN, LOW);  // disable motor power
    return true;
}

// move stepper motor up
void moveUp(unsigned char stepsUp){
  //

}

// move stepper motor down
void moveDown(unsigned int stepsDown){
  //
}

