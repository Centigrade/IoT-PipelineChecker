//here we store all the parameters running through the project as a whole

// WiFi access data
//const char *ssid = "Centigrade-Legacy";
const char *ssid = "Teutonet";

// Gitlab Server
//const char* host = "gitlab.intranet.centigrade.de";
const char* host = "gitlab.centigrade.de";

// LED output mapping
const int greenLEDPinProject1 = 19;    
const int blueLEDPinProject1  = 16; 
const int redLEDPinProject1   = 15; 

const int greenLEDPinProject2 = 21;    
const int blueLEDPinProject2  = 18; 
const int redLEDPinProject2   = 17; 


// How often to poll for updates
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

// Put the JSON input in memory
  char input[] = "[{\"apiVersion\":\"/api/v4\",\"projectId\":\"253\"},{\"apiVersion\":\"/api/v4\",\"projectId\":\"237\"}]";

int urlSize = 10;


//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED, 
  RUNNING,
  UNKNOWN, 
  FAILED 
};

PipelineState pState = UNKNOWN;
