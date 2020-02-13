var mqtt =  require('mqtt');


var client = mqtt.connect("mqtt://1640f7e3:183a633f80feec7e@broker.shiftr.io",
{clientId : "javascript"}
);


client.on('connect', function(){
    console.log('client has connected!');

    client.subscribe('/yolo');
    // client.unsubscribe('/example');
  
    setInterval(function(){
      client.publish('/yolo', 'yeeet');
    }, 1000);
});


client.on('message', function(topic, message) {
    console.log('new message:', topic, message.toString());
  });