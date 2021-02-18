//here we basically parse the result obtain from the previous calss and implement the following metods on to the LightLEDS.. class
/*all parameters and functions
  fron the ArduinoJson.h library
  to parse the actual results  and get
  only the desired outputs (pipeline-id
  and -status)
*/
String getPipelineStatus(String document) {

  Serial.println("Parsing start: ");

  DynamicJsonDocument jsonBuffer(2048);

  deserializeJson(jsonBuffer, document);
  int id = jsonBuffer[0]["id"];
  const char* status = jsonBuffer[0]["status"];

  // Output to serial monitor
  Serial.print("id: ");
  Serial.println(id);
  Serial.print("status: ");
  Serial.println(status);
  
  if (strcmp(status , "success") == 0)
  { Serial.println("here we are successful");// to remove. debugging printout
    pState = PASSED;// PASSED case
  }
  else if (strcmp(status , "failed") == 0)
  { Serial.println("here we meet failure");// to remove. debugging printout
    pState = FAILED;// FAILED case
  }
  else if (strcmp(status , "running") == 0)
  { Serial.println("still running");// to remove. debugging printout
    pState = RUNNING;// RUNNING case
  }
  else
  { Serial.println("no one knowsss");// to remove. debugging printout
    pState = UNKNOWN;// UNKNOWN case
  }
}
