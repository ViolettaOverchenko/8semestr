const bcrypt = require('bcrypt');
var express=require("express");
var connection = require('../config/connection');
var router = express.Router();

router.post('/addUser', function(req, res) {
  const passwordHash = bcrypt.hashSync(req.body.password,10);
  var userData={
      "emailUser":req.body.email,
      "loginUser":req.body.email,
      "passwordUser":passwordHash
  }
  connection.query('INSERT INTO user SET ?', userData, function(err, result){
    if (err) throw err;
    res.redirect('/');
  } )
});

module.exports = router;
