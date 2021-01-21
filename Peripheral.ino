void setupSwitchLEDLights() {
  // set LEDs as output
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  
}
/*recieves the final parsed result and 
* ligths on the Leds on the hard 
* arduino set up device based on 
* outcomes(enum)
*/
void loopSwitchLEDLights(PipelineState pState){
  Serial.println("let´s start the game");
   
  switch (pState){
    Serial.println("LoopSwitchPState: " + pState);
    case UNKNOWN: // blink bleu LED
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      delay(1000);
      digitalWrite(blueLEDPin, LOW);
      break;
    
    case PASSED: // light green LED
      Serial.println("This is Passed");
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      break;

    case FAILED: // light red LED
      Serial.println("This is failed");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
      break;

    case RUNNING:  // light bleu LED
       Serial.println("This is pending");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      break;
  }

  delay(1000);
 
}
