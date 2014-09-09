/*
 * Control of stepper driver for the motor on Z-axis
 *
 *
 */

#include "config.h"

bool moveZ(int steps, bool dir, int speed);

// move stepper motor up
void moveUp(unsigned int stepsUp);

// move stepper motor down
void moveDown(unsigned int stepsDown);
