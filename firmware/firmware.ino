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

// include Servo library to contrl HDD motor
#include <Servo.h>

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
  // pinMode(arduinoLED, OUTPUT);     
  // Configure the onboard LED for output
  // digitalWrite(arduinoLED, LOW);   
  // default to LED off

  
  pinMode(UVlamp1, OUTPUT);   // Configure the onboard LED for output
  digitalWrite(UVlamp1, LOW); // default to LED off

  pinMode(UVlamp2, OUTPUT);   // Configure the onboard LED for output
  digitalWrite(UVlamp2, LOW); // default to LED off

  pinMode(UVlamp3, OUTPUT);   // Configure the onboard LED for output
  digitalWrite(UVlamp3, LOW); // default to LED off

  pinMode(UVlamp4, OUTPUT);   // Configure the onboard LED for output
  digitalWrite(UVlamp4, LOW); // default to LED off

  // stepper motor pins
  pinMode(STEPPER_STEP, OUTPUT);
  pinMode(STEPPER_DIR, OUTPUT);
  pinMode(STEPPER_EN, OUTPUT);

  Serial.begin(9600);

  // Setup callbacks for SerialCommand commands

  // Turns LED on
  //sCmd.addCommand("ON",LED_on);

  // Turns LED off
  //sCmd.addCommand("OFF",LED_off); // Turns LED off

  // Echos the string argument back
  sCmd.addCommand("HELLO",sayHello);

  // Converts two arguments to integers and echos them back
  //sCmd.addCommand("P",processCommand); 

  // Turn on or off lamp
  sCmd.addCommand("L",lampOnOff);

  // Converts two arguments to integers and echos them back
  sCmd.addCommand("M",moveZaxis); 

  // Control speed of the HDD BLDC motor using ESC
  sCmd.addCommand("HDD",hddSpeedControl);

  // Control speed of the HDD BLDC motor using ESC
  sCmd.addCommand("D",turnOnOffDigitalPin);

  // Handler for command that isn't matched  (says "What?")
  sCmd.setDefaultHandler(unrecognized);
  
  Serial.println("Ready");
}

void loop() {
  sCmd.readSerial();  // We don't do much, just process serial commands
}


void turnOnOffDigitalPin()
{
  int digitalPin, onOff;
  char *arg;

  Serial.println("We are in turnOnOffDigitalPin() function.");
  arg = sCmd.next();
  if (arg != NULL) {
     digitalPin = atoi(arg);   // Converts a char string to an integera
     Serial.print("First argument was: ");
     Serial.println(digitalPin);

     if ( (digitalPin > 1) && (digitalPin < 31) ) { 
     // all availabe pins in rfAtmega128 
	pinMode(digitalPin, OUTPUT);
     }
     else{
	Serial.println("Please enter pin number between 1 - 31");
     }
  }

  arg = sCmd.next();
  if (arg != NULL) {
     onOff = atoi(arg);   // Converts a char string to an integera
     Serial.print("Second argument was: ");
     Serial.println(onOff);

     if ( onOff == 1 ) { 
     // all availabe pins in rfAtmega128 
	digitalWrite(digitalPin, HIGH);
     }
     else if( onOff == 0) {
	Serial.println("Enter pin number between 1 - 31");
	digitalWrite(digitalPin, LOW);
     }
     else {
	Serial.println("Enter as second argument 0 (off) or 1 (on)");
     }
  }
  Serial.println("End of turnOnOffDigitalPin() function");
}


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

// 
void hddSpeedControl()
{
  /*
	CONTROL SPEED OF HDD USING ESC
	DIAGRAMM
	      
		      int 45        int 100
	  ----------------
	  |              |  variable   |
	  |              |  <------->  |
	  |              --------------
			 
	 0 ms           1ms        up to 1ms
	 
	       frequency = 50 Hz
  */
  Servo esc;

  int zero = 45;        // 1 ms offset
  int speed_max = 100;  // 1 ms max control speed
  int stepSpeed = 1000; // delay between pulses
  boolean startHDD = true; // spin HDD till get FALSE 

  Serial.println("HDD start");
  esc.attach(ESC_PIN);       // use pin DIO9 as PWM
  
  esc.write(zero);     // set frequency at 50 Hz and wait for beep 
                       // ESC detects this signal actually
  delay(5000);         // wait for beep signal

  while(startHDD)
  {
	// start HDD to spin	
	esc.write(zero);
	delay(stepSpeed);
	Serial.println("DBG:spin");
        Serial.flush();
        // delay(10);
        
        // if stop command received stop spinning
        if(Serial.available())
	{
		Serial.read();
                Serial.println("DBG: hddSpeedControl()...stop");
                delay(1);
                esc.detach();
		startHDD = false;
	}
	
  }
  
  Serial.println("HDD stop");

}


// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}


// *************** OBSOLETE FUNCTIONS ********

/* OBSOLETE FUNCTIONS
void LED_on() {
  Serial.println("LED on");
  digitalWrite(UVlamp1, HIGH);
}

void LED_off() {
  Serial.println("LED off");
  digitalWrite(UVlamp1, LOW);
}
*/

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


