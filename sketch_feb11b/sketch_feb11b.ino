// This example uses an ESP32 Development Board
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <WiFi.h>
#include <MQTT.h>
#include <SPI.h>
#include "LedMatrix.h"
#include <string.h>

#define NUMBER_OF_DEVICES 8 //number of led matrix connect in series
#define CS_PIN 15
#define CLK_PIN 14
#define MISO_PIN 2 //we do not use this pin just fill to match constructor
#define MOSI_PIN 12


WiFiClient net;
MQTTClient client;


LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);


unsigned long lastMillis = 0;
String prior = "";
//byte [8] heart = {0x0E, 0x1F, 0x3F, 0x7E, 0x3F, 0x1F, 0x0E, 0x00};


void connect() {
  Serial.print("checking wifi...");


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
    
  
  }

  Serial.print("\nconnecting...");
  while (!client.connect("LOLIN32", "1640f7e3", "183a633f80feec7e")) {
  }
  client.subscribe("/loversNames");

  Serial.println("\nconnected!");

}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  prior = payload+ " " + prior;
  ledMatrix.setText(prior);
}

void setup() {

  
  Serial.begin(115200);
   WiFi.begin("iPhone", "velvetunderground"); 

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  client.begin("broker.shiftr.io", net);
  client.onMessage(messageReceived);
  //connect();
        ledMatrix.init();
    ledMatrix.setText("test");

  
}

void loop() {
  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  ledMatrix.commit();

  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }


  
}
