// this is the main part of the program , from herre we move to the GetUrl class
/*Here i import the different libraries which i will
   need to run my program, using the include fonction
*/
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "config.h"
#include "secrets.h"

String results[3];

//all setup functions
void setup() {
  setupSwitchLEDLights();
  setupNetwork();
  String RequestUrls[urlSize];
  // function returns an array of urls
  SetUrlRequest(RequestUrls);
  for (int i = 0; i < urlSize; i++)
  {
    String url =  RequestUrls[i];
    if (url.length() > 0)
    {
      results[i] = GitlabServerConnection(url);
    }
  }

}

//all loop functions
void loop() {
  for (int i = 0; i < urlSize; i++)
  {
    getPipelineStatus(results[i]);
    delay(5000);
    loopSwitchLEDLights(i);
  }
}
