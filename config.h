
// Here are the initial and constant value of digital signal of the diferent LEDs
const int greenLEDPin = 19;    
const int blueLEDPin  = 16; 
const int redLEDPin   = 15; 

// Here i introduce a dellay of 3 Seconds after every update
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
