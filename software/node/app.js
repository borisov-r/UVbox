
var context = require('./context');

var objectController = require('./objectController');

var httpServer = require('./httpServer');

httpServer.startServer(objectController);
console.log('testtesttest');

//var f = objectController.scheduler(context);
setInterval(function() {objectController.scheduler(context);}, 1000);

//init function

//object controller init

//http server init

//ajax server init


