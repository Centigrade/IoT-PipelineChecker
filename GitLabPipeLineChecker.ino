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
  { Serial.println("here we are successful");
    pState = PASSED;
  } 
  else if (strcmp(status , "failed") == 0)
  {Serial.println("here we meet failure");
    pState = FAILED;
  } 
  else if (strcmp(status , "running") == 0) 
  {Serial.println("still running");
    pState = RUNNING;
  }
  else 
  {Serial.println("no one knowsss");
    pState = UNKNOWN;
  }
}
