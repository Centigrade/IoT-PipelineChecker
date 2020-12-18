//Here i import the different libraries which i will need to run my program, using the include fonction
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "config.h"
#include "secrets.h" 

void setup(){
  
  setupSwitchLEDLights();
  String setupNetwork();
  result = GitlabServerConnection();
  
  Serial.println("This is the program running");
}

void loop(){
  pState = getPipelineStatus(result);
  delay(5000);
  loopSwitchLEDLights(pState);
}
