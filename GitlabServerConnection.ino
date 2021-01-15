int value = 0;

// Use WiFiClient class to create TCP connections
WiFiClientSecure client;

String GitlabServerConnection() {
  delay(5000);
  ++value;
  
  Serial.print("connecting to ");
  Serial.println(host);
  
  const int httpsPort = 443;
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return "";
  }
  
  // We now create a URI for the request
  
  String apiVersion      = "/api/v4";
  //String gitlabProjectId = "/projects/377";
  String gitlabProjectId = "/projects/237";
  String projectName     = "/pipelines";
  
  String url = apiVersion + gitlabProjectId + projectName;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);

  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "PRIVATE-TOKEN: " + API_AUTH_TOKEN + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  // Error handling if client is not available
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return "";
    }
  }
  String queryResult;
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    queryResult = client.readStringUntil('\r');
    
    int indexOfJsonBeginning = queryResult.indexOf("[");
    if(indexOfJsonBeginning != -1)
    {
      // only use the JSON Data from the result string as query result substring 
      queryResult = queryResult.substring(indexOfJsonBeginning);
      Serial.print("LastWhileLoop");
      break;
    }

    Serial.print(queryResult);
  }
  
  Serial.println();
  Serial.println("closing connection");

  return queryResult;
}
