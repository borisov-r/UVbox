## Description

Firmware is installed on Arduino to controll all the processes and
collect real time information from sensors.

  * firmware.ino        - project's main file

## Dependencies

 * [A Minimal Arduino Library for Processing Serial Commands](https://github.com/scogswell/ArduinoSerialCommand)

## Installation

Clone Arduino Serial Command repository to get latest version

```
git clone https://github.com/scogswell/ArduinoSerialCommand.git
```

Copy library to Arduino IDE

```
cp ./ArduinoSerialCommand path-to/arduino/libraries/
```

Edit *'path-to/arduino/libraries/ArduinoSerialCommand/SerialCommand.h'* as
described in file to remove SoftwareSerial dependencies.

At the end file should look like this:

```
// If you want to use SerialCommand with the hardware serial port only, and want to disable
// SoftwareSerial support, and thus don't have to use "#include <SoftwareSerial.h>" in your
// sketches, then uncomment this define for SERIALCOMMAND_HARDWAREONLY, and comment out the
// corresponding #undef line.
//
// You don't have to use SoftwareSerial features if this is not defined, you can still only use
// the Hardware serial port, just that this way lets you get out of having to include
// the SoftwareSerial.h header.
#define SERIALCOMMAND_HARDWAREONLY 1
//#undef SERIALCOMMAND_HARDWAREONLY
```

