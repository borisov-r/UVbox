/*
 * Control of stepper driver for the motor on Z-axis
 *
 *
 */

#include "config.h"

// move
bool moveZ( int steps,   // move steps times
            boolean dir,    // set direction
            int speed_ )  // set speed of the movement
{
    digitalWrite(STEPPER_DIR, dir);  // set direction
    digitalWrite(STEPPER_EN, LOW);  // enable motor power
    
    Serial.print("All steps: ");
    Serial.println(steps);
    for ( int i = 0; i < steps; i++)
    {
        digitalWrite(STEPPER_STEP, HIGH);
        delay(speed_);
        digitalWrite(STEPPER_STEP, LOW);
        delay(speed_);
        Serial.print("Step: ");
        Serial.println(i);
        Serial.print("Speed: ");
        Serial.println(speed_);
    }
  
    digitalWrite(STEPPER_EN, HIGH);  // disable motor power
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

