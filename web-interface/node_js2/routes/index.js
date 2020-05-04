var express = require('express');
var router = express.Router();
var connection = require('../config/connection');

/* GET home page. */
router.get('/', function(req, res) {

  connection.query('SELECT * FROM keyword', function(err, rows) {
    if (err) throw err;
    console.log(rows);
    res.render('index', { words: rows });
  });
});

router.post('/addWord', function(req, res) {

  const wordData = {
    descriptionKeyword: req.body.descriptionKeyword,
    periodicityKeyword: 0
  }
  connection.query('INSERT INTO keyword SET ?', wordData, function(err, result){
    if (err) throw err;
    res.redirect('/');
  } )
});

router.get('/deleteWord/:idWord', function(req, res) {
  var wordid = req.params.idWord;
  connection.query('DELETE FROM keyword WHERE idKeyword = ?', [wordid], function(err, rows){
    if (err) throw err;
    res.redirect('/');
  } )
})

router.get('/edit/:idWord' , function(req, res) {
  var wordid = req.params.idWord;
  connection.query('SELECT * FROM keyword WHERE idKeyword = ?', [wordid], function(err, rows){
    if (err) throw err;
    res.render('edit', {wordData: rows});
  } )
})

router.post('/updateWord/:idWord', function(req, res) {

  var description = req.body.descriptionKeyword;
  var updateId = req.params.idWord;

  connection.query('UPDATE keyword SET descriptionKeyword=? WHERE idKeyword = ?', [description, updateId], function(err, result){
    if (err) throw err;
    res.redirect('/');
  } )
});

module.exports = router;
