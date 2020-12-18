// WiFi access data
const char *ssid = "Centigrade-Legacy";

// Gitlab Server
const char* host = "gitlab.intranet.centigrade.de";

// LED output mapping
const int greenLEDPin = 19;    
const int blueLEDPin  = 16; 
const int redLEDPin   = 15; 

// How often to poll for updates
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

String result;

//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED, 
  RUNNING,
  UNKNOWN, 
  FAILED 
};

PipelineState pState = UNKNOWN;
