//Here i import the different libraries which i will need to run my program, using the include fonction
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// Here are the WiFi access data which i will later need internet connection
const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

// Here is the private token of my Gitlab user
const char *private_token = "GITLAB_PRIVATE_TOKEN";

// Here i had to import the Gitlab HTTPS certificate SHA-1 fingerprint inorder to have access to every https source 
const char *https_fingerprint = "F3 85 85 A1 04 F3 77 26 CF CC E5 CE E2 23 ED 63 A1 8F 54 DC";

//Here i copied the url of the page containing the test inorder to pull and therefore link my Arduino program to the Gitlab
const char *url_pipeline = "http://gitlab.intranet.centigrade.de/centigrade/trainee-pipeline-tests/api/v4/projects/377/pipelines?ref=master&per_page=1";

// Here are the initial and constant value of digital signal of the diferent LEDs
 const int greenLEDPin = 10;    
const int blueLEDPin = 9; 
const int redLEDPin = 8; 

// Here i introduce a dellay of 3 Seconds after every update
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED,
  RUNNING,
  FAILED,
};

//Here i declare my currentState argument
PipelineState currentState;

void setup(){
  //Here i configure my digital pins to be outputs since there will be producing a lightsource 
   pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

//
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // LED test
  Serial.println("Testing LEDs...");
  currentState = PASSED;
  lastUpdateMillis = millis();
  loop();
  delay(3000);
  currentState = RUNNING;
  lastUpdateMillis = millis();
  loop();
  delay(3000);
  currentState = FAILED;
  lastUpdateMillis = millis();
  loop();
  delay(3000);

  Serial.println("Starting.");
  
}

void loop()
{
  switch (currentState){
  case PASSED: // green
     digitalWrite(greenLEDPin, HIGH);
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    break;

  case FAILED: // red
     digitalWrite(greenLEDPin, LOW);
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    break;

  case RUNNING: // yellow
     digitalWrite(greenLEDPin, LOW);
    digitalWrite(blueLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    break;
  }

  delay(1000);
  update();
}

void update()
{
  if (millis() <= (lastUpdateMillis + updateDelayMillis))
    return;

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Updating pipeline status... ");

    HTTPClient http;
    http.begin(url_pipeline, https_fingerprint);
    http.addHeader("PRIVATE-TOKEN", private_token);

    int returnCode = http.GET();
    if (returnCode != 200){
      Serial.print("update retrieved. ");

      DynamicJsonDocument doc(http.getSize());
      deserializeJson(doc, http.getString());

      const char *pipelineStatus = doc[0]["status"];
      Serial.print("Pipeline status: ");
      Serial.print(pipelineStatus);

      if (strcmp(pipelineStatus, "success") == 0)
      {
        currentState = PASSED;
      }
      else if (strcmp(pipelineStatus, "failed") == 0)
      {
        currentState = FAILED;
      }
      else if (strcmp(pipelineStatus, "running") == 0)
      {
        currentState = RUNNING;
      }
     
    }
    Serial.println("");
  }
  lastUpdateMillis = millis();
}
