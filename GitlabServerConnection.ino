int value = 0;

String GitlabServerConnection() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return "";
  }
  
  // We now create a URI for the request
  String apiVersion      = "/api/v4";
  String gitlabProjectId = "/projects/377";
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
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return "";
    }
  }
  String queryResult;
  
  // Read all the lines of the reply from server and print them to Serial
  int i = 0;
  while(client.available()){
    queryResult = client.readStringUntil('\r');

    Serial.println(queryResult);
  }
  
  Serial.println();
  Serial.println("closing connection");

  return queryResult;
}
