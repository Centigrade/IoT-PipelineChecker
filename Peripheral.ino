void setupSwitchLEDLights() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  
// LED test
  Serial.println("Testing LEDs...");
  pState = PASSED;
  lastUpdateMillis = millis();
  loop();
  delay(3000);
  pState = RUNNING;
  lastUpdateMillis = millis();
  loop();
  delay(3000);
  pState = FAILED;
  lastUpdateMillis = millis();
  loop();
  delay(3000);

  Serial.println("Starting.");
  pState = UNKNOWN;
   
}

void loopSwitchLEDLights(PipelineState pState){
  //Here i set on the different pins in such a way that each pin should response to a particular order 
  switch (pState){

    case UNKNOWN: // blink bleu LED
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      delay(1000);
      digitalWrite(blueLEDPin, LOW);
      break;
    
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

    case RUNNING: // blue
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      break;
  }

  delay(1000);
 
}
