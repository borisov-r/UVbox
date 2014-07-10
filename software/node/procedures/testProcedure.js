(function() {
    var someThings = 'test';

    var fs = require('fs');
    var testView = fs.readFileSync('./index.html');

    module.exports.execute = function(context) {
        return someThings;
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
