unsigned long DEBOUCE_DELAY = 50;    // the debounce time; increase if the output flickers

/* PLAY BUTTON */



const int playButtonPin = 1;
int lastPlayButtonState = LOW; // the previous reading from the playbutton pin
unsigned long lastDebounceTimePlayButton = 0;  // the last time the play output pin was toggled
int playButtonState;

boolean playButtonClicked() {
  int playButtonReading = digitalRead(playButtonPin);

  if (playButtonReading != lastPlayButtonState) {
    lastDebounceTimePlayButton = millis();
  }

  lastPlayButtonState = playButtonReading;

  if ((millis() - lastDebounceTimePlayButton) > DEBOUCE_DELAY) {

    if (playButtonReading != playButtonState) {
      playButtonState = playButtonReading;

      // only toggle the LED if the new button state is HIGH
      if (playButtonState == LOW) {
        return true;
      }
    }
  }

  return false;
}


/* RESET BUTTON */

//const int resetButtonPin = 2;
//int lastResetButtonState = LOW; // the previous reading from the resetbutton pin
//unsigned long lastDebounceTimeResetButton = 0;  // the last time the reset output pin was toggled
//int resetButtonState;
//
//boolean resetButtonClicked() {
//  int resetButtonReading = digitalRead(resetButtonPin);
//
//  if (resetButtonReading != lastResetButtonState) {
//    lastDebounceTimeResetButton = millis();
//  }
//
//  lastResetButtonState = resetButtonReading;
//
//  if ((millis() - lastDebounceTimeResetButton) > DEBOUCE_DELAY) {
//
//    if (resetButtonReading != resetButtonState) {
//      resetButtonState = resetButtonReading;
//
//      // only toggle the LED if the new button state is HIGH
//      if (resetButtonState == LOW) {
//        return true;
//      }
//    }
//  }
//
//  return false;
//}
