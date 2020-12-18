 #include <ESP8266WiFi.h>

//WIFI
const char *ssid = "Centigrade-Legacy";

// GitLab
const char* gitLabServer = "gitlab.intranet.centigrade.de";
// API Version: https://docs.gitlab.com/ee/api/README.html#current-status
const String gitLabAPIVersion = "/api/v4";
// The project pipeline part of the requested URL
const String gitLabProjectID = "377";


//Setup the conncetion to the WIFI network
void setupNetwork() {
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
}

int getGitLabPipelinesDataFunctionCallCounter = 0;

// Request a Single Pipeline Request from GitLab.
// More details in GitLab Documentation: https://docs.gitlab.com/ee/api/pipelines.html
String GetGitLabPipelinesData() {
  delay(5000);
  ++getGitLabPipelinesDataFunctionCallCounter;

  Serial.print("connecting to ");
  Serial.println(gitLabServer);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(gitLabServer, httpPort)) {
    Serial.println("connection failed");
    return "";
  }
  
  Serial.println("Requesting GitLabProjectID: " + gitLabProjectID);
  
  // This will send the get request for a single projects pipelines list -> GET /projects/:id/pipelines
  // https://docs.gitlab.com/ee/api/pipelines.html#list-project-pipelines
  client.print(String("GET ") + gitLabAPIVersion + "/projects/" + gitLabProjectID + "/pipelines" + " HTTP/1.1\r\n" +
               "HOST: " + gitLabServer + "\r\n" + 
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
