String GetUrlRequest() {
  Serial.println("Getting URL: ");
  
  // Allocate the JsonDocument
  DynamicJsonDocument jsonBuffer(200);   
  
  // Put the JSON input in memory
  char input[] = "[{\"apiVersion\":\"/api/v4\",\"projectId\":\"/projects/253\"},{\"apiVersion\":\"/api/v4\",\"projectId\":\"/projects/237\"}]";
     
  // Parse the JSON input
  deserializeJson(jsonBuffer, input);

   // Get a reference to the root array
   JsonArray arr = jsonBuffer.as<JsonArray>();

   const char* apiVersion;
   const char* projectId;

   for (JsonObject repo : arr) 
   {
      apiVersion = repo["apiVersion"];
      projectId = repo["projectId"];
   
      Serial.print("apiVersion = ");
      Serial.println(apiVersion);
      Serial.print("projectId = ");
      Serial.println(projectId);

   }  
      String av = String(apiVersion);
      String pi = String(projectId);
      return av + pi;
}
