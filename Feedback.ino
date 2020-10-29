void loopFeedback(PipelineState status){

  //Here i set on the different pins in such a way that each pin should response to a particular order 
  switch (status){
    case PASSED: // green
      Serial.println("status in loopFeedback: PASSED");
      digitalWrite(greenLEDPin, HIGH);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      break;

    case FAILED: // red
      Serial.println("status in loopFeedback: FAILED");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
      break;

    case RUNNING: // blue
      Serial.println("status in loopFeedback: RUNNING");
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      break;
  }

  delay(1000);
 
}
