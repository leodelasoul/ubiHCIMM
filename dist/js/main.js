var express = require("express");
var app = express();

const mqtt = require('mqtt');
const cors = require("cors");
const router = express.Router();
var bodyParser = require('body-parser')


app.use(express.static(__dirname + './..'), router, cors());


// app.use(function(req, res, next){
//   res.header("Access-Control-Allow-Origin", 'localhost:8080');
//   res.header("Access-Control-Allow-Credentials", true);
//   res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE,OPTIONS');
//   res.header("Access-Control-Allow-Headers", 'Origin,X-Requested-With,Content-Type,Accept,content-type,application/json');
//   next();
//   /*res.header("Access-Control-Allow-Origin", "localhost:8080"); // update to match the domain you will make the request from
//   res.header("Access-Control-Allow-Headers", "Origin  , X-Requested-With, Content-Type, Accept");
//   next();*/
// });
app.use(bodyParser.json());


//start application server on port 8080
app.listen(process.env.PORT || 8080, () => {
  console.log("The server started on port 8080");
});
app.get('*', function (req, res) {
  res.sendFile('index.html', { root: __dirname + './..' });
});


var client = mqtt.connect("mqtt://1640f7e3:183a633f80feec7e@broker.shiftr.io",
  { clientId: "javascript" }
);

app.post('/notify', function(req, res){
  var stringToSend = req.body.coupleNames[0].name1 + " <3 " + req.body.coupleNames[0].name2
  client.publish('/loversNames', stringToSend);

  return res.send('Received a POST HTTP method');
});


client.on('connect', function () {
  console.log('client has connected!');

  client.subscribe('/loversNames');

});
