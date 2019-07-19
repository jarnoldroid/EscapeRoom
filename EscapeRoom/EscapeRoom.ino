
#include <Adafruit_NeoPixel.h>
#include <Button.h>

const int HATCH_PIN = 2;
const int RESET_BUTTON_PIN = 2;
const int PLAY_BUTTON_PIN = 3;
const int NEO_PIXEL_PIN = 6;
const int NOTE_DETECTION_PINS[] = {22};

Button resetButton(RESET_BUTTON_PIN);
Button playButton(PLAY_BUTTON_PIN);
Button noteButtons[] {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};


const int NUMPIXELS = 192;

Adafruit_NeoPixel pixels(NUMPIXELS, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

const boolean LOGGER_ON = true;

void setup() {
  Serial.begin(115200);
  resetButton.begin();
  playButton.begin();

  for (int x = 0; x < 25; x++) {
    noteButtons[x].begin();
  }

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

    delay(200);
  }

  logger("End of loop");
}
