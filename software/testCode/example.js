var http = require('http'),
    fs = require('fs');
 
var app = http.createServer(function (request, response) {
    fs.readFile("client.html", 'utf-8', function (error, data) {
        response.writeHead(200, {'Content-Type': 'text/html'});
        response.write(data);
        response.end();
    });
}).listen(1337);
 

// define system variables
userInputs = {};
systemResponse = {'t':'5'};


var io = require('socket.io').listen(app);
 
io.sockets.on('connection', function(socket) {
    socket.on('message_to_server', function(data) {
        // process the request data
        requestProcess(data["message"]);

        // response update
        responseUpdata();

        // return the response
        io.sockets.emit("message_to_client",{ message: systemResponse });
    });
});




function requestProcess(data) {
    // get inputs delta and update the user input
    userInputs

    var keys = Object.keys(data);
    
    for (var i = 0; i < keys.length; i++) {
        userInputs[keys[i]] = data[keys[i]];
    }
}

function responseUpdata() {

    // update the responses here
    var keys = Object.keys(userInputs);
    for (var i = 0; i < keys.length; i++) {
        systemResponse[keys[i]+'_out'] = userInputs[keys[i]];
    }
}



var SerialPort  = require('serialport2').SerialPort;
var portName = '/dev/ttyACM0';

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
    // if the letters 'A' and 'B' are found on the buffer then isolate what's in the middle
    // as clean data. Then clear the buffer. 
    if (readData.indexOf('B') >= 0 && readData.indexOf('A') >= 0) {
        cleanData = readData.substring(readData.indexOf('A') + 1, readData.indexOf('B'));
        readData = '';
systemResponse['inp5_out'] = cleanData;
       // io.sockets.emit('message', cleanData);
    }
});



