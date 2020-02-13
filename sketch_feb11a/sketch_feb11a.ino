#include <WiFi.h>


void setup() {
  // put your setup code here, to run once
  Serial.begin(115200);

  Serial.println("yolo");
   WiFi.begin("Mahboii", "meisterball"); 
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Establishing connection to WiFi..");
   }

   
  

  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());

 
  Serial.println(WiFi.localIP());

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
