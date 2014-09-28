/*
 * UV lamps control
 *
 */
 
#include "config.h"

//IOrow Inputs;

// turn ON lamp - 0 to 255
bool turnOnLamp ( int lamp ){
  //
  if( lamp == 1 ) { digitalWrite(UVlamp1, HIGH); }
  else if ( lamp == 2 ) { digitalWrite(UVlamp2, HIGH); }
  else if ( lamp == 3 ) { digitalWrite(UVlamp3, HIGH); }
  else if ( lamp == 4 ) { digitalWrite(UVlamp4, HIGH); }
  else {
    Serial.println("Please enter lamp from 1 - 4");
    return false;
  }
  return true;
};

// turn OFF lamp - 0 to 255
bool turnOffLamp ( int lamp ){
  //
  if( lamp == 1 ) { digitalWrite(UVlamp1, LOW); }
  else if ( lamp == 2 ) { digitalWrite(UVlamp2, LOW); }
  else if ( lamp == 3 ) { digitalWrite(UVlamp3, LOW); }
  else if ( lamp == 4 ) { digitalWrite(UVlamp4, LOW); }
  else {
    Serial.println("Please enter lamp from 1 - 4");
    return false;
  }
  return true;
};
