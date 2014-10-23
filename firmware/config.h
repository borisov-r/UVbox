/*
 * UVbox configuration file
 *
 *
 */

// include standart int types
#include <stdint.h>
#include <Arduino.h>

// define byte type
typedef uint8_t byte;

// stepper definition
#define STEPPER_EN 12
#define STEPPER_DIR 14
#define STEPPER_STEP 13

// define stepper motor speed
extern unsigned char STEPPER_SPEED;  

// define output pins of the arduino that control the relays
// for turning on and off the UV lamps
#define UVlamp1 22
#define UVlamp2 23
#define UVlamp3 24
#define UVlamp4 25

// esc control of bldc hdd motor
#define ESC_PIN 9

/*
// Interface table row struct
struct ioRow
{
    String name;   // description of the device connected to the pin
    byte type;     // bool, int, char, float
    byte pinNo;    // number of physical pin on arduino
};

typedef struct ioRow IOrow;
*/
//typedef struct ioRow inputRow;   
// describes one row of input / output pins
//typedef struct ioRow outputRow;  
// describes one row of input / output pins
