// start http server

// when recieve request
//    see if req have parameters
//        parse parameters
//        and do its work -- call object controller - procedure
//    object controller - return get view


(function() {
    var http = require('http');
    var fs = require('fs');
    var index = fs.readFileSync('index.html');


    module.exports.startServer = function(objectController) {
        http.createServer(function (req, res) {
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.end(objectController.processHttpReq());
        }).listen(1337);
    
        console.log('Server running at http://127.0.0.1:1337/');
    }

}());
