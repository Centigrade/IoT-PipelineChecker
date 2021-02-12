//Here we we basically deal with Urls and next we move to the ConnectionToServer... class

//Class with a String array as parametter to get the diffents url and strore them
void SetUrlRequest(String RequestUrls[]) {
  Serial.println("Getting URL: ");
  
  // Allocate the JsonDocument
  DynamicJsonDocument jsonBuffer(200);   
  
  
     
  // Parse the JSON input
  deserializeJson(jsonBuffer, input);

   // Get a reference to the root array
  JsonArray array = jsonBuffer.as<JsonArray>();

 for (int i = 0; i < array.size(); i++) 
   {
       JsonObject repo = array[i];
      const char* apiVersion = repo["apiVersion"];
      const char* projectId  = repo["projectId"];
      //writing down the urls and saving them in the array one after the other
      RequestUrls[i] = String(apiVersion) + "/projects/" + String(projectId);
   }  
      
}
