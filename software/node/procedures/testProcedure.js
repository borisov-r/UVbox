(function() {
    var nextProc = 'test';

    var fs = require('fs');
    var testView = fs.readFileSync('./index.html');


    var initialized = {};





    var objectResponseProcessor = function(data) {
        console.log("comunicator response = " + data);
    }

    module.exports.init = function(context) {

        console.log("communicator response processor initialized");
        context.comunicator.setResponseProcessor(objectResponseProcessor);
        initialized = 'true';
    }

    module.exports.initialized = function() {
       return initialized;
    }

    module.exports.execute = function(context) {

        context.comunicator.sendData('ON' + String.fromCharCode(13,10));
        console.log("communicator data send 1");

        return nextProc;
    }

    module.exports.processHttpReq = function() {
        return testView;
    }

    module.exports.processAjaxReq = function() {
        return someThings;
    }

    module.exports.getView = function() {
        return someThings;
    }

}());



// callbacks
//   nextProcedure = Execute(context, communicator)
//   httpReq
//   ajaxReq
//   getView
