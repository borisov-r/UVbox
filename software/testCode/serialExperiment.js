var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/ttyUSB0", {
      baudrate: 9600
}, false); // this is the openImmediately flag [default is true]

serialPort.open(function () {
      console.log('open');
      serialPort.on('data', function(data) {
            console.log('data received: ' + data);
      });
      serialPort.write("OFF\r\n", function(err, results) {
            console.log('err ' + err);
            console.log('results ' + results);
      });
});
