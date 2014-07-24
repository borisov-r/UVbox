(function() {

    var communicator = require('./serialComunicator');


    var testProcedureImpl = require('./procedures/testProcedure');
    var procedures = {
        'start' : testProcedureImpl,
        'test'  : testProcedureImpl,
        'end'   : testProcedureImpl
      }; 

    var currentProcedure = 'start';

    module.exports.scheduler = function(context) {
  
        context.comunicator = communicator;
        if (procedures[currentProcedure].initialized() != 'true') {
            procedures[currentProcedure].init(context);
        }

        nextProc = procedures[currentProcedure].execute(context);
        currentProcedure = nextProc;


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
