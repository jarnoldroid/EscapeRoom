
#include <Adafruit_NeoPixel.h>
#include <Button.h>

const int RESET_BUTTON_PIN = 2;
const int PLAY_BUTTON_PIN = 3;
const int NOTE_DETECTION_PINS[] = {22};

Button resetButton(RESET_BUTTON_PIN);
Button playButton(PLAY_BUTTON_PIN);
Button noteButtons[] = {4};

const int TEST_BUTTON_PIN = 2;
const int TEST_LED_PIN = 6;
const int NUMPIXELS = 192;

Adafruit_NeoPixel pixels(NUMPIXELS, TEST_LED_PIN, NEO_GRB + NEO_KHZ800);

const boolean LOGGER_ON = true;

void setup() {
  Serial.begin(115200);
  resetButton.begin();
  playButton.begin();
  noteButtons[0].begin();
  
  pinMode(TEST_BUTTON_PIN, INPUT);
  pinMode(TEST_LED_PIN, OUTPUT);

  pixels.begin();
  pixels.setBrightness(255);
  resetVars();
}

void loop() {

  logger("Start of loop");

  if (shouldReset()) {

    closeHatch();
    resetVars();
    delay(5000);

  } else if (isSequenceComplete()) {

    waitingSequence();

  } else if (shouldPuzzleTunePlay()) {

    playPuzzleTune();

  } else {

    startNotePlayedDetection();

    if (isSequenceComplete()) {

      openHatch();
      playVictoryTune();
      
    }
    
    delay(5000); // TODO Remove
  }

  logger("End of loop");
}
