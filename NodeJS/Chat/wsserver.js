var WebSocketServer = require('ws').Server,
wss = new WebSocketServer({ port: 8181 });

wss.on('connection', function (ws) {
    console.log('client connected');
    // console.log(ws);

    ws.on('message', function (message) {

        if ((typeof message) == 'object') {

            // console.log(message);
            // console.log("二进制数据：%s", message);

            var messageObj = JSON.parse(message);

            console.log(messageObj);
            console.log(messageObj.receiverID);
            console.log(messageObj.object.type);
        }
    });
});