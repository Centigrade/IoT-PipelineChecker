/*Here i import the different libraries which i will 
 * need to run my program, using the include fonction
 */
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "config.h"
#include "secrets.h" 

//all setup functions
void setup(){
  
  setupSwitchLEDLights();
  setupNetwork();
  result = GitlabServerConnection();
  
  Serial.println("This is the program running");
}

//all loop functions
void loop(){
  pState = getPipelineStatus(result);
  delay(5000);
  loopSwitchLEDLights(pState);
}
