String GetUrlRequest() {
  Serial.println("Getting URL: ");
  
  // Allocate the JsonDocument
  DynamicJsonDocument jsonBuffer(200);   
  
  // Put the JSON input in memory
  char input[] = "[{\"apiVersion\":\"/api/v4\",\"projectId\":\"253\"},{\"apiVersion\":\"/api/v4\",\"projectId\":\"237\"}]";
     
  // Parse the JSON input
  deserializeJson(jsonBuffer, input);

   // Get a reference to the root array
   JsonArray array = jsonBuffer.as<JsonArray>();

  
  String myUrls, url1, url2;
  
  for (int i = 0; i < array.size(); i++) 
   {
       /*JsonObject repo = array[i];
      const char* apiVersion = repo["apiVersion"];
      const char* projectId  = repo["projectId"];*/
      const char* apiVersion1 = array[0]["apiVersion"];
      const char* projectId1  = array[0]["projectId"];
      const char* apiVersion2 = array[1]["apiVersion"];
      const char* projectId2  = array[1]["projectId"];
   
      url1 = String(apiVersion1) + "/projects/" + String(projectId1);
      url2 = String(apiVersion2) + "/projects/" + String(projectId2);
      
   }  
      int urlsSize = 10;
      String Urls[urlsSize] = {url1, url2};

      for (int i=0; i< urlsSize; i++)
      {
        Serial.println(Urls[i]);
        myUrls = Urls[i];
        break;
      } 
      
      return myUrls;

}
