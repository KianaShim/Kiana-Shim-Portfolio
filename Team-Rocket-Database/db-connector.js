let mysql = require('mysql2')

const pool = mysql.createPool({
    waitForConnections: true,
    connectionLimit   : 10,
    host              : 'classmysql.engr.oregonstate.edu',
    user              : 'cs340_sheparry',
    password          : '6771',
    database          : 'cs340_sheparry'
}).promise();

module.exports = pool;