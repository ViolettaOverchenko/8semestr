const bcrypt = require('bcrypt');
var express=require("express");
var connection = require('../config/connection');
var router = express.Router();

router.post('/authorization', function(req, res){
    var email = req.body.email;
    var password = req.body.password;


    connection.query('SELECT * FROM user WHERE emailUser = ?',[email], function (err, results, fields) {
      if (err) throw err;
      else{
        console.log(results);
        if(results.length >0){
            passwordHash = results[0].passwordUser;
            if(password == passwordHash){
                res.json({
                    status:true,
                    message:'successfully authenticated'
                })
            }else{
                res.json({
                  status:false,
                  message:"Email and password does not match"
                 });
            }

        }
        else{
          res.json({
              status:false,
            message:"Email does not exits"
          });
        }
      }
    });
});
module.exports = router;
