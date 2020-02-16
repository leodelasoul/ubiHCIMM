

function sumbitLoverNames(){

  var couplesJSONObj = {"coupleNames":[]};

  var nameLover1 = document.getElementById("LoverName1").value;
  var nameLover2 = document.getElementById("LoverName2").value;
  //herz code:0x03
//  var coupleObj = JSON.parse(couplesJSON);
  couplesJSONObj['coupleNames'].push({"name1":nameLover1, "name2":nameLover2});
  couplesJSON = JSON.stringify(couplesJSONObj);
  $.ajax({
    url : "http://localhost:8080/notify",
    type : "POST",
    data : couplesJSON,
    dataType : "json",
    contentType: "application/json",
    success : function(res){
      console.log(res)
    },
    error : function(e){
      console.log(e)
    }
  })
  console.log(couplesJSON)
  document.getElementById("LoverName1").value = ""
  document.getElementById("LoverName2").value = ""
 
}


