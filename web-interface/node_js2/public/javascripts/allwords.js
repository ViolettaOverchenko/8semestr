$("#analyses").on('click', function(e){
  //console.log("test my button");
  $.ajax({
  url: '/testajax',
  success: function(data){
    var str = '';
    if( data instanceof Array) str = JSON.stringify(data);
    console.log("загружены данные " + str);
    console.log("тип данных " + typeof data);
    var htmlstr= '<table>';
    //try{
      if (typeof data == 'object') {
        console.log("ошибка");
        data_ = Object.entries(data);
        //var data_ = JSON.parse(data);
        for (var i = 0; i < data_.length; i++) {
          htmlstr += '<tr>';
          for(var j = 0; j < data_.length; j++)
            htmlstr += '<td>' + data_[i][j] + '</td>';
          htmlstr += '</tr>'
        }
        htmlstr += '<table>';
        console.log("это массив" + htmlstr);
        $("#mytable").html(htmlstr);
      }
    //} catch(e){console.log("ошибка");}

  }
});
})
