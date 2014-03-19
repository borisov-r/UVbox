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

