void setupGetUrlRequest() {
  Serial.println("Getting URL: ");
  
  // Allocate the JsonDocument
  DynamicJsonDocument jsonBuffer(200);   
  
  // Put the JSON input in memory
  char input[] = "[{\"apiVersion\":\"/api/v4\",\"projectId\":237},{\"apiVersion\":\"/api/v4\",\"projectId\":253}]";
     
  // Parse the JSON input
  DeserializationError err = deserializeJson(jsonBuffer, input);

  // Parse succeeded?
   if (err) 
   {
     Serial.print(F("deserializeJson() returned "));
     Serial.println(err.c_str());
     return;
   }

   // Get a reference to the root array
   JsonArray arr = jsonBuffer.as<JsonArray>();

   for (JsonObject repo : arr) 
   {
      const char* apiVersion = repo["apiVersion"];
      int projectId = repo["projectId"];
   
      Serial.print("apiVersion = ");
      Serial.println(apiVersion);
      Serial.print("projectId = ");
      Serial.println(projectId);
   }  
}
