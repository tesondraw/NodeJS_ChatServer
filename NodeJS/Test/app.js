var http = require('http');
var fs = require('fs');
http.createServer(function (req, res) {
    
    res.writeHead(200, {'Content-Type': 'image/png'});
    fs.createReadStream('./1.png').pipe(res);
    

    /*
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Hello World\n');
    */
}).listen(3000);

console.log('Server running at http://localhost:3000/');