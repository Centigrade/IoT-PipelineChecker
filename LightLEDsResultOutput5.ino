//Here is the end of the journy where we output the results on to the hardware part of the project

void setupSwitchLEDLights() {
  // set LEDs as output
  pinMode(greenLEDPinProject1, OUTPUT);
  pinMode(blueLEDPinProject1, OUTPUT);
  pinMode(redLEDPinProject1, OUTPUT);
  pinMode(greenLEDPinProject2, OUTPUT);
  pinMode(blueLEDPinProject2, OUTPUT);
  pinMode(redLEDPinProject2, OUTPUT);
  
}
/*recieves the final parsed result and 
* ligths on the Leds on the hard 
* arduino set up device based on 
* outcomes(enum)
*/
void loopSwitchLEDLights(PipelineState pState){
  String RequestUrls[urlSize];
  Serial.println("let´s start the game");
  switch (pState)
  {
   Serial.println("LoopSwitchPState: " + pState);
   case UNKNOWN: // blink bleu LED
     for (int i=0; i< urlSize; i++)
     {
       if(RequestUrls[i]==RequestUrls[0])
       {
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, HIGH);
        digitalWrite(redLEDPinProject1, LOW); 
        delay(1000); 
        digitalWrite(blueLEDPinProject1, LOW);
        break;
       }
       else if(RequestUrls[i]==RequestUrls[1])
       {
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, HIGH);
        digitalWrite(redLEDPinProject2, LOW);
        delay(1000);
        digitalWrite(blueLEDPinProject2, LOW);
        break;
       }
     }
      
   case PASSED: // light green LED
     for (int i=0; i< urlSize; i++)
     {
       if(RequestUrls[i]==RequestUrls[0])
       {
        Serial.println("This is Passed, green LED on");
        digitalWrite(greenLEDPinProject1, HIGH);
        digitalWrite(blueLEDPinProject1, LOW);
        digitalWrite(redLEDPinProject1, LOW); 
        break;
       }
       else if(RequestUrls[i]==RequestUrls[1])
       {
        Serial.println("This is Passed, green LED on"); 
        digitalWrite(greenLEDPinProject2, HIGH);
        digitalWrite(blueLEDPinProject2, LOW);
        digitalWrite(redLEDPinProject2, LOW);
        break;
       }
     }

  case FAILED: // light red LED
    for (int i=0; i< urlSize; i++)
     {
       if(RequestUrls[i]==RequestUrls[0])
       {
        Serial.println("This is failed, red LED on");
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, LOW);
        digitalWrite(redLEDPinProject1, HIGH); 
        break;
       }
       else if(RequestUrls[i]==RequestUrls[1])
       {
        Serial.println("This is failed, red LED on"); 
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, LOW);
        digitalWrite(redLEDPinProject2, HIGH);
        break;
       }
     }

  case RUNNING:  // light bleu LED
    for (int i=0; i< urlSize; i++)
     {
       if(RequestUrls[i]==RequestUrls[0])
       {
        Serial.println("This is pending, blue LED on");
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, HIGH);
        digitalWrite(redLEDPinProject1, LOW); 
        break;
       }
       else if(RequestUrls[i]==RequestUrls[1])
       {
        Serial.println("This is pending, blue LED on"); 
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, HIGH);
        digitalWrite(redLEDPinProject2, LOW);
        break;
       }
     }

  }
  
  delay(1000);
 
}
