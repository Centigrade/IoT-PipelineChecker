PipelineState getPipelineStatus(String document){
  
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
  {
    pState = PASSED;
  } 
  else if (strcmp(status , "failed") == 0)
  {
    pState = FAILED;
  } 
  else if (strcmp(status , "running") == 0) 
  {
    pState = RUNNING;
  }
  else 
  {
    pState = UNKNOWN;
  }
}
