//Here i import the different libraries which i will need to run my program, using the include fonction
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "config.h"
#include "secrets.h" 

void setup(){
  
  setupNetwork();
  String result = GetGitLabPipelinesData();
  pState = getPipelineStatus(result);
  setupSwitchLEDLights();
 
}

void loop(){
  loopSwitchLEDLights(pState);
}
