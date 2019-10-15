/*
var fs = require('fs')
, http = require('http')
, socketio = require('socket.io');

var server = http.createServer(function(req, res) {
    
    fs.readFile(__dirname + '/index.html', function (err, data) {
        if (err) {
            return console.error(err);
        }
        console.log("异步读取: " + data.toString());
        
        // res.writeHead(200, { 'Content-type': 'text/html'});
        // res.end(fs.readFileSync(__dirname + '/index.html'));

        res.writeHead(200, { 'Content-type': 'text/html'});
        res.end(data);

     });

}).listen(8080, function() {
    console.log('Listening at: http://localhost:8080');
});

socketio.listen(server).on('connection', function (socket) {
    socket.on('message', function (msg) {
        console.log('Message Received: ', msg);
        socket.broadcast.emit('message', msg);
    });
});
*/

var app = require('http').createServer(handler), 
io = require('socket.io').listen(app), 
fs = require('fs')

app.listen(8080);
io.set('log level', 1);//将socket.io中的debug信息关闭

function handler (req, res) {
    fs.readFile(__dirname + '/index.html',function (err, data) {  
        if (err) {
            res.writeHead(500);
            return res.end('Error loading index.html');
        }    
        res.writeHead(200, {'Content-Type': 'text/html'});    
        res.end(data);
    });
}

io.sockets.on('connection', function (socket) {
    socket.emit('news', { hello: 'world' });
    socket.on('my other event', function (data) {
        console.log(data);
    });
});