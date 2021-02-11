//here we store all the parameters running through the project as a whole

// WiFi access data
//const char *ssid = "Centigrade-Legacy";
const char *ssid = "Teutonet";

// Gitlab Server
//const char* host = "gitlab.intranet.centigrade.de";
const char* host = "gitlab.centigrade.de";


// LED output mapping
const int greenLEDPin = 19;    
const int blueLEDPin  = 16; 
const int redLEDPin   = 15; 

// How often to poll for updates
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

int urlSize = 10;
String results[10];

//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED, 
  RUNNING,
  UNKNOWN, 
  FAILED 
};

PipelineState pState = UNKNOWN;
