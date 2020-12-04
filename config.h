
// Here are the initial and constant value of digital signal of the diferent LEDs
const int greenLEDPin = 10;    
const int blueLEDPin  = 9; 
const int redLEDPin   = 8; 

// Here i introduce a dellay of 3 Seconds after every update
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED, 
  RUNNING,
  UNKNOWN, 
  FAILED 
};

PipelineState pState = UNKNOWN;
