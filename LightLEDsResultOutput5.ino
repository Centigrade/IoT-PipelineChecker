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
  ligths on the Leds on the hard
  arduino set up device based on
  outcomes(enum)
*/
void loopSwitchLEDLights(int projectNr) {
  Serial.println("let´s start the game" + pState);
  switch (pState)
  {
    case 0: // UNKNOWN case, blink bleu LED
      Serial.println("now in the UNKNOWN case");
      if (projectNr == 0)
      {
        Serial.println("This is UNKNOWN, blue LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, HIGH);
        digitalWrite(redLEDPinProject1, LOW);
        delay(1000);
        digitalWrite(blueLEDPinProject1, LOW);
      }
      else if (projectNr == 1)
      {
        Serial.println("This is UNKNOWN, blue LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, HIGH);
        digitalWrite(redLEDPinProject2, LOW);
        delay(1000);
        digitalWrite(blueLEDPinProject2, LOW);
      }
      break;

    case 1: // PASSED case, light green LED
      Serial.println("now in the PASSED case");
      if (projectNr == 0)
      {
        Serial.println("This is Passed, green LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject1, HIGH);
        digitalWrite(blueLEDPinProject1, LOW);
        digitalWrite(redLEDPinProject1, LOW);
      }
      else if (projectNr == 1)
      {
        Serial.println("This is Passed, green LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject2, HIGH);
        digitalWrite(blueLEDPinProject2, LOW);
        digitalWrite(redLEDPinProject2, LOW);
      }
      break;

    case 2: // FAILED case, light red LED
      Serial.println("now in the FAILED case");
      if (projectNr == 0)
      {
        Serial.println("This is failed, red LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, LOW);
        digitalWrite(redLEDPinProject1, HIGH);
      }
      else if (projectNr == 1)
      {
        Serial.println("This is failed, red LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, LOW);
        digitalWrite(redLEDPinProject2, HIGH);
      }
      break;

    case 3:  // RUNNING case, light bleu LED
      Serial.println("now in the RUNNING case");
      if (projectNr == 0)
      {
        Serial.println("This is pending, blue LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject1, LOW);
        digitalWrite(blueLEDPinProject1, HIGH);
        digitalWrite(redLEDPinProject1, LOW);
      }
      else if (projectNr == 1)
      {
        Serial.println("This is pending, blue LED on for project " + projectNr);
        digitalWrite(greenLEDPinProject2, LOW);
        digitalWrite(blueLEDPinProject2, HIGH);
        digitalWrite(redLEDPinProject2, LOW);
      }
      break;

    default:
      Serial.println("now in the default case");
  }

  delay(1000);

}
