var mysql = require('mysql');

function OptPool() {
    this.flag = true;// 是否连接过

    this.pool = mysql.createPool({
        host:'localhost',
        user:'root',
        password:'123456',
        database:'mydb'
    });

    this.getPool = function() {
        if(this.flag) {
            // 监听connection事件
            this.pool.on('connection', function(connection) {
                connection.query('SET SESSION auto_increment');
                this.flag = false;
            });
        }

        return this.pool;
    }
};

module.exports = OptPool;