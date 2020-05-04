var mysql      = require('mysql');

var db;
var setting = {
  host     : 'localhost',
  user     : 'root',
  password : '',
  database : 'analysiseducationalmaterial'
};

function connectDatabase() {
    if(!db) {
      db = mysql.createConnection(setting);

      db.connect( function(err) {
        if (!err){
          console.log('Database connection!');
        }
        else {
          console.log('Error connection');
        }
      });
    }
    return db;
}

module.exports = connectDatabase();
