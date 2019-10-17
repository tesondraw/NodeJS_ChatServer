var express = require('express');
var async = require('async')
var app = express();
var bodyParser = require('body-parser');
// var io = require('socket.io')(app);
// var io = require('ws');

var urlEncodeParser = bodyParser.urlencoded({ extended: false });

var query = require('./mysql_pool');


app.post('/regist', urlEncodeParser, function (req, res) {

    async.waterfall(
        [
            function (done) {
                var sql = 'select * from users where account = ?';

                console.log("account is:", req.body.account);
                query(sql, [req.body.account], function (err, results, fields) {
                    console.log("length ", results.length);

                    if (results.length > 0) {
                        var response = {
                            "code": 100,
                            "msg": "账号已存在"
                        };
                        res.end(JSON.stringify(response));
                        // console.log("account exists");
                        done("check account", "account exists");
                        // return;
                    } else {
                        done(null, "account not exists");
                    }

                });
            },
            function (preValue, done) {
                var sql = 'insert into users(account, pwd) values(?, ?)';
                var param = [req.body.account, req.body.pwd];

                query(sql, param, function (err, results, fields) {
                    if (err) {
                        // console.log("insert failed");

                        var response = {
                            "code": 200,
                            "msg": "服务器错误"
                        };
                        res.end(JSON.stringify(response));

                        done("insert error", preValue + ", insert fail");
                    } else {
                        // console.log("insert success");
                        var response = {
                            "code": 0,
                            "msg": "注册成功"
                        };
                        res.end(JSON.stringify(response));

                        done(null, preValue + ", insert success");
                    }
                });
            }
        ], function (error, results) {
            console.log(error);
            console.log(results);
        }
    )
});

app.post('/login', urlEncodeParser, function (req, res) {
    console.log("client account:%s, pwd is:%s", req.body.account, req.body.pwd);

    var sql = 'select pwd from users where account = ?';
    query(sql, [req.body.account], function (err, results, fields) {
        console.log("login result length:" + results.length);
        // console.log("server account is:%s, pwd is:%s", results[0].account, results[0].pwd);
        if (results.length > 0) {
            if (req.body.pwd != results[0].pwd) {
                var response = {
                    "code": 400,
                    "msg": "账号或密码错误"
                };
                res.end(JSON.stringify(response));
                console.log("pwd is not right");
            } else {
                var response = {
                    "code": 0,
                    "msg": "登录成功"
                };
                res.end(JSON.stringify(response));
                console.log("login success");
            }
        } else {
            var response = {
                "code": 300,
                "msg": "账号不存在"
            };
            res.end(JSON.stringify(response));
            console.log("account not exists");
        }
    });
});

var server = app.listen(8080, function () {
    var host = server.address().address;
    var port = server.address().port;

    console.log("server running at http://%s:%s", host, port);
});

// var ws = io.listen(server);


// ws.on('connection', function (client) {
//     console.log('033[96msomeone is connect');
//     var address = WebSocket.handshake.address;
//     console.log(Date() + " New connection from " + address.address + ":" + address.port);
// }) 