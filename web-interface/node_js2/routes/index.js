var express = require('express');
var router = express.Router();
var connection = require('../config/connection');

/* Основная страница (вывод всех слов) */
router.get('/', function(req, res) {
  connection.query('SELECT * FROM keyword', function(err, rows) {
    if (err) throw err;
    res.render('index', { words: rows });
  });
});


// Добавление слова
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

// Удаление слова
router.get('/deleteWord/:idWord', function(req, res) {
  var wordid = req.params.idWord;
  connection.query('DELETE FROM keyword WHERE idKeyword = ?', [wordid], function(err, rows){
    if (err) throw err;
    res.redirect('/');
  } )
})

// Переход на страницу редактирвоания слова
router.get('/edit/:idWord' , function(req, res) {
  var wordid = req.params.idWord;
  connection.query('SELECT * FROM keyword WHERE idKeyword = ?', [wordid], function(err, rows){
    if (err) throw err;
    res.render('edit', {wordData: rows});
  } )
})

// Редактирование слова
router.post('/updateWord/:idWord', function(req, res) {
  var description = req.body.descriptionKeyword;
  var updateId = req.params.idWord;
  connection.query('UPDATE keyword SET descriptionKeyword=? WHERE idKeyword = ?', [description, updateId], function(err, result){
    if (err) throw err;
    res.redirect('/');
  } )
});

// Переход на страницу регистрации
router.get('/registration', function(req, res) {
    res.render('registration');
});

// Переход на страницу регистрации
router.get('/authorization', function(req, res) {
    res.render('authorization');
});

module.exports = router;
