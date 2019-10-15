var http = require('http');
var fs = require('fs');
var socketio = require('socket.io');
// var apn = require('apn');

var apns = require('./apns');



var count = 0;
var sockets = [];

var server = http.createServer(function(req, res) {
    fs.readFile('./index.html', function(err, data){
        res.writeHead(200, {'Content-Type':'text/html'});
        res.end(data, 'utf-8');
    });
}).listen(3000);//, '127.0.0.1'


console.log('server running at http://127.0.0.1:3000');

// SocketIO监听Server
var io = socketio.listen(server);

io.on('connection', function(socket) {//在启动了服务器的Socket.io之后，用于初始化，需要一些代码来让Socket.io对特定事件作出响应，Socket.io侦听许多事件，这里只是示例

    count++;
    console.log('user connected, ' + count + ' users present');

    // 注册
    socket.on('regist', function(data, callback) {
        console.log("regist");
        console.log(data);

        console.log("user id:" + data.userID);
        console.log("ip address:", socket.handshake.address);
        
        
        var bRegistered = false;
        // 先判断是否已注册
        for (var i = 0; i < sockets.length; i++) {
            var element = sockets[i];
            
            if (element.socket == socket) {
                console.log('soccket exists, ip address:', element.socket.handshake.address);
                
                bRegistered = true;

                break;
            }
        }
        
        if (bRegistered) {
            var response = {
                'code':999,
                'msg':"has registered, do not register once more"
            }
            callback(response);
            console.log("服务器端判断 - 已注册");
        } else {
            var response = {
                'code':0,
                'msg':"register success"
            }
            callback(response);
            console.log("服务器端判断 - 未注册");

            // 没有注册，则加入sokcets数组
            var dic = {
                uid:data.userID,
                socket:socket,
                token:data.token
            }
    
            sockets.push(dic);
        }

        console.log("sockets array:", sockets.length);
        
    });

    socket.on('addUser', function(data, callback) {
        console.log('add user');
        console.log(data);

        var response = {
            'code':0,
            'msg':"add user success"
        }

        callback(response);
    })

    // 消息
    socket.on('message', function(data, callback) {//侦听客户端的message事件

        console.log('message: ' );
        console.log(data);

        var response = {
            'code':0,
            'msg':"server has received the message"
        }

        callback(response);

        for (var i = 0; i < sockets.length; i++) {
            var element = sockets[i];
            
            if (element.uid == data.receiverID) {
                console.log('receiver ip address:', element.socket.handshake.address);
                element.socket.emit('message', data);

                var token = element.token;//长度为64的设备Token，去除空格
                console.log("receiver token:", token);

                // var param = {
                //     token: token,
                //     title: "你的好友给你发来一条消息",
                //     content: data
                // }
                
                apns.send(token, data);

                break;
            }
        }
    });

    // 断开socket
    socket.on('disconnect', function() {
        count--;
        console.log('user disconnected, ' + count + ' users present');

        socket.broadcast.emit('users', {number:count});

        // for (var i = 0; i < sockets.length; i++) {
        //     var element = sockets[i];
            
        //     if (element.socket == socket) {
        //         console.log('ip address:', element.socket.handshake.address);
        //         sockets.splice(i, 1);
        //         console.log("socket number is:", sockets.length);
        //         break;
        //     }
        // }
    });
});