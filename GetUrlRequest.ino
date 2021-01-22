
void setupGetUrlRequest() {
  Serial.println("Getting URL: ");
  DynamicJsonDocument jsonBuffer(200);
 
  char json[] = 
  "{\"id\":1,\"method\":\"GET\",\"url\":\"/api/v4/projects/237/pipelines\"},{\"id\":2,\"method\":\"GET\",\"url\":\"url2\"},{\"id\":3,\"method\":\"GET\",\"url\":\"url3\"}";
      
  deserializeJson(jsonBuffer, json);
  for(int i = 0; i < 8; i++)
  {
    int id = jsonBuffer[i]["id"];
    const char* url = jsonBuffer[i]["url"]; 
  
    if(strcmp(id[i], 1)==0)
     {
        Serial.print("id: ");
        Serial.println(id[i]); 
        Serial.print("url: ");
        Serial.println(url[i]);  
     }
     else if(strcmp(id[i], 2)==0)
     {
        Serial.print("id: ");
        Serial.println(id[i]); 
        Serial.print("url: ");
        Serial.println(url[i]);
     }
     else if(strcmp(id[i], 3)==0)
     {
        Serial.print("id: ");
        Serial.println(id[i]); 
        Serial.print("url: ");
        Serial.println(url[i]);
     }
     else
     {
        Serial.println("URL not found");
     }
  }
  
}
