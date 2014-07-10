(function() {

//    var communicator = 


    var testProcedureImpl = require('./procedures/testProcedure');
    var procedures = {
        'start' : testProcedureImpl,
        'test'  : testProcedureImpl,
        'end'   : testProcedureImpl
      }; 

    var currentProcedure = 'start';

    module.exports.start = function(context) {
        return procedures[currentProcedure].execute(context);
    }

    module.exports.processHttpReq = function() {
        return procedures[currentProcedure].processHttpReq();
    }

    module.exports.processAjaxReq = function() {
        return procedures[currentProcedure].processAjaxReq();
    }

    module.exports.getView = function() {
        return procedures[currentProcedure].getView();
    }

}());



// init
// communicator init

// initial procedure
// procedure table

// callbacks
//   procedureExecute
//   httpReq
//   ajaxReq
//   getView
