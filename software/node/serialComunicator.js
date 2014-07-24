(function() {

//    var communicator = 
    // export send data
    // export readyToSend
    // set callback on receive




    var responseProcessor;

    module.exports.sendData = function(message) {
        sp.write(message);
    }

    module.exports.readyToSend = function() {
        return true;
    }

    module.exports.setResponseProcessor = function(responseProc) {
        responseProcessor = responseProc;
    }



    var SerialPort  = require('serialport2').SerialPort;
    var portName = '/dev/tty0';//'/dev/ttyACM0';

    var sp = new SerialPort(); // instantiate the serial port.
    sp.open(portName, { // portName is instatiated to be COM3, replace as necessary
        baudRate: 9600, // this is synced to what was set for the Arduino Code
        dataBits: 8, // this is the default for Arduino serial communication
        parity: 'none', // this is the default for Arduino serial communication
        stopBits: 1, // this is the default for Arduino serial communication
        flowControl: false // this is the default for Arduino serial communication
    });

    var cleanData = ''; // this stores the clean data
    var readData = '';  // this stores the buffer
    sp.on('data', function (data) { // call back when data is received
        readData += data.toString(); // append data to buffer
        responseProcessor(readData);
        readData = '';

        // if the letters 'A' and 'B' are found on the buffer then isolate what's in the middle
        // as clean data. Then clear the buffer. 
        //if (readData.indexOf('B') >= 0 && readData.indexOf('A') >= 0) {
        //    cleanData = readData.substring(readData.indexOf('A') + 1, readData.indexOf('B'));
        //    readData = '';
        //    systemResponse['inp5_out'] = cleanData;
        //   // io.sockets.emit('message', cleanData);
        //
        //}
    });
}());



