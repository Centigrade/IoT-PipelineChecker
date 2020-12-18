void setupSwitchLEDLights() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  
}

void loopSwitchLEDLights(PipelineState pState){Serial.println("let´s start the game");
  //Here i set on the different pins in such a way that each pin should response to a particular order 
  switch (pState){
    Serial.println("LoopSwitchPState: " + pState);
    case UNKNOWN: // blink bleu LED
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      delay(1000);
      digitalWrite(blueLEDPin, LOW);
      break;
    
    case PASSED: // green
      Serial.println("This is Passed");
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      break;

    case FAILED: // red
      Serial.println("This is failed");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
      break;

    case RUNNING: // blue
       Serial.println("This is pending");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      break;
  }

  delay(1000);
 
}
