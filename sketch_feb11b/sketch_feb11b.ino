#include <Bridge.h>
#include <YunClient.h>
#include <MQTTClient.h>

YunClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void setup() {
  Bridge.begin();
  Serial.begin(115200);
  client.begin("broker.shiftr.io", net);
  connect();

}

void connect() {
  Serial.print("connecting...");

  
  while (!client.connect("lovebridgeIO", "1640f7e3", "183a633f80feec7e")) {
    
    
  }

  Serial.println("\nconnected!");
}


void loop() {
  // put your main code here, to run repeatedly:
  client.loop();

  if(!client.connected()) {
    connect();
  }


}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();
}
