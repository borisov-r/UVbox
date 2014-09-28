/*

  UVbox firmware

  ============================================================================================
  Version: 0.01
  Authors: Radoslav Borisov

  Explanation: Firmware uses Steven Cogswell's ArduinoSerialCommand library for communication.
               Simple commands will be added later to process data from PC.

  References:
		https://github.com/kroimon/Arduino-SerialCommand

  License: Beerware (http://en.wikipedia.org/wiki/Beerware)
  ============================================================================================
*/

// Demo Code for SerialCommand Library
// Steven Cogswell
// May 2011

#include <SerialCommand.h>

#include "config.h"
//
#include "lamps.h"
//
#include "zaxis.h"

// this pins control the Relays that switch on the UV lamps
// tested with pins 22, 23, 24, 25
// #define arduinoLED 22   // Arduino LED on board

SerialCommand sCmd;     // The demo SerialCommand object

void setup() {
  // pinMode(arduinoLED, OUTPUT);      // Configure the onboard LED for output
  // digitalWrite(arduinoLED, LOW);    // default to LED off

  pinMode(UVlamp1, OUTPUT);      // Configure the onboard LED for output
  digitalWrite(UVlamp1, LOW);    // default to LED off

  pinMode(UVlamp2, OUTPUT);      // Configure the onboard LED for output
  digitalWrite(UVlamp2, LOW);    // default to LED off

  pinMode(UVlamp3, OUTPUT);      // Configure the onboard LED for output
  digitalWrite(UVlamp3, LOW);    // default to LED off

  pinMode(UVlamp4, OUTPUT);      // Configure the onboard LED for output
  digitalWrite(UVlamp4, LOW);    // default to LED off


  pinMode(STEPPER_STEP, OUTPUT);
  pinMode(STEPPER_DIR, OUTPUT);
  pinMode(STEPPER_EN, OUTPUT);

  Serial.begin(9600);

  // Setup callbacks for SerialCommand commands
  //sCmd.addCommand("ON",    LED_on);          // Turns LED on
  //sCmd.addCommand("OFF",   LED_off);         // Turns LED off
  sCmd.addCommand("HELLO", sayHello);          // Echos the string argument back
  //sCmd.addCommand("P",     processCommand);  // Converts two arguments to integers and echos them back
  sCmd.addCommand("L",     lampOnOff);         // Turn on or off lamp 
  sCmd.addCommand("M",     moveZaxis);         // Converts two arguments to integers and echos them back
  sCmd.setDefaultHandler(unrecognized);        // Handler for command that isn't matched  (says "What?")
  Serial.println("Ready");
}

void loop() {
  sCmd.readSerial();     // We don't do much, just process serial commands
}

/*
void LED_on() {
  Serial.println("LED on");
  digitalWrite(UVlamp1, HIGH);
}

void LED_off() {
  Serial.println("LED off");
  digitalWrite(UVlamp1, LOW);
}
*/

void sayHello() {
  char *arg;
  arg = sCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL) {    // As long as it existed, take it
    Serial.print("Hello ");
    Serial.println(arg);
  }
  else {
    Serial.println("Hello, whoever you are");
  }
}

/*
void processCommand() {
  int aNumber;
  char *arg;

  Serial.println("We're in processCommand");
  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atol(arg);
    Serial.print("Second argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No second argument");
  }
}
*/


void lampOnOff() {
  int aNumber, lamps, onOff;
  char *arg;

  Serial.println("We're in lampOnOff function.");
  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
    if ( (aNumber > 0) && (aNumber < 5) ) { 
      lamps = aNumber;
    }
    else { Serial.println("Please enter value between 1 and 4"); }
  }
  else {
    Serial.println("No arguments");
  }

  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);
    Serial.print("Second argument was: ");
    Serial.println(aNumber);
    if ( (aNumber == 0) || (aNumber == 1) ) { onOff = aNumber; }
    else { Serial.println("Please enter 0 / off or 1 / on"); }
  }
  else {
    Serial.println("No second argument");
  }
  
 if ( (lamps > 0) && (lamps < 5) && ( (onOff == 0) || (onOff == 1) ) )
 {
    if (onOff == 0) { turnOffLamp(lamps); }
    else if (onOff == 1) { turnOnLamp(lamps); }
    else { Serial.println("Please enter reasonable value"); } 
 }
 else { Serial.println("Can't turn ON or OFF lamp"); }
  
}




void moveZaxis() {
  
  int aNumber = 0;
  boolean bNumber = 0;
  int cNumber = 0;
  bool res = false;
  char *arg;

  Serial.println("We're in moveZaxis");
  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);   // convert a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else { Serial.println("No arguments"); }
  
  arg = sCmd.next();
  if (arg != NULL) {
    bNumber = atoi(arg);
    Serial.print("Second argument was: ");
    Serial.println(bNumber);
  }
  else { Serial.println("No second argument"); }
  
  arg = sCmd.next();
  if (arg != NULL) {
    cNumber = atoi(arg);
    Serial.print("Third argument was: ");
    Serial.println(cNumber);
  }
  else { Serial.println("No third argument"); }
  
  if( aNumber == 0 & bNumber == 0 & cNumber == 0 ) {
      res = moveZ(0, 0, 0);
      Serial.print("Res : ");
      Serial.println(res);
  }
  else { 
      res = moveZ( aNumber, bNumber, cNumber); 
      Serial.print("Res : ");
      Serial.println(res);  
  }
  
  if (res) { Serial.println("Movement finished"); } 

}


// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}


