
const char *ssid = "Centigrade-Legacy";

const char* host = "gitlab.intranet.centigrade.de";

String setupNetwork() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  int value = 0;
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
  String url = "/api/v4/projects/377/pipelines";
  
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
  while(client.available()){
    queryResult = client.readStringUntil('\r');
    Serial.print("Result: " + queryResult);
  }
  
  Serial.println();
  Serial.println("closing connection");

  return queryResult;
}
