
#include <Adafruit_NeoPixel.h>
#include <Button.h>
#include <ShiftRegister_TPIC6A596.h>

/**
   OTHER CONFIGURATIONS
*/
const int NUMBER_OF_NEO_PIXELS_TOTAL = 339; 

/*
   PINS CONFIGURATION:
*/
const int HATCH_PIN = 8;
const int RESET_BUTTON_PIN = 9;
const int PLAY_BUTTON_PIN = 10;
const int NEO_PIXEL_PIN = 6;

const int CLOCK_PIN = 3;
const int LATCH_PIN = 4;
const int ENABLE_PIN = 5;
const int CLEAR_PIN = 6;
const int DATA_PIN = 7;

const int NOTE_DETECTION_PIN_G5 = 22;
const int NOTE_DETECTION_PIN_G5_SHARP = 23;
const int NOTE_DETECTION_PIN_A5 = 24;
const int NOTE_DETECTION_PIN_A5_SHARP = 25;
const int NOTE_DETECTION_PIN_B5 = 26;
const int NOTE_DETECTION_PIN_C6 = 27;
const int NOTE_DETECTION_PIN_C6_SHARP = 28;
const int NOTE_DETECTION_PIN_D6 = 29;
const int NOTE_DETECTION_PIN_D6_SHARP = 30;
const int NOTE_DETECTION_PIN_E6 = 31;
const int NOTE_DETECTION_PIN_F6 = 32;
const int NOTE_DETECTION_PIN_F6_SHARP = 33;
const int NOTE_DETECTION_PIN_G6 = 34;
const int NOTE_DETECTION_PIN_G6_SHARP = 35;
const int NOTE_DETECTION_PIN_A6 = 36;
const int NOTE_DETECTION_PIN_A6_SHARP = 37;
const int NOTE_DETECTION_PIN_B6 = 38;
const int NOTE_DETECTION_PIN_C7 = 39;
const int NOTE_DETECTION_PIN_C7_SHARP = 40;
const int NOTE_DETECTION_PIN_D7 = 41;
const int NOTE_DETECTION_PIN_D7_SHARP = 42;
const int NOTE_DETECTION_PIN_E7 = 43;
const int NOTE_DETECTION_PIN_F7 = 44;
const int NOTE_DETECTION_PIN_F7_SHARP = 45;
const int NOTE_DETECTION_PIN_G7 = 46;

/**
 * NOTES TO PLAY
 */
#define G5 1
#define GS5 2
#define A5 3
#define AS5 4
#define B5 5
#define C6 6
#define CS6 7
#define D6 8
#define DS6 9
#define E6 10
#define F6 11
#define FS6 12
#define G6 13
#define GS6 14
 
#define A6 15
#define AS6 16
#define B6 17
#define C7 18
#define CS7 19
#define D7 20
#define DS7 21
#define E7 22
#define F7 23
#define FS7 24
#define G7 25

/** 
 *  Note Detection
 */
enum Note {
  _G5 = NOTE_DETECTION_PIN_G5,
  _G5_SHARP = NOTE_DETECTION_PIN_G5_SHARP,
  _A5 = NOTE_DETECTION_PIN_A5,
  _A5_SHARP = NOTE_DETECTION_PIN_A5_SHARP,
  _B5 = NOTE_DETECTION_PIN_B5,
  _C6 = NOTE_DETECTION_PIN_C6,
  _C6_SHARP = NOTE_DETECTION_PIN_C6_SHARP,
  _D6 = NOTE_DETECTION_PIN_D6,
  _D6_SHARP = NOTE_DETECTION_PIN_D6_SHARP,
  _E6 = NOTE_DETECTION_PIN_E6,
  _F6 = NOTE_DETECTION_PIN_F6,
  _F6_SHARP = NOTE_DETECTION_PIN_F6_SHARP,
  _G6 = NOTE_DETECTION_PIN_G6,
  _G6_SHARP = NOTE_DETECTION_PIN_G6_SHARP,
  _A6 = NOTE_DETECTION_PIN_A6,
  _A6_SHARP = NOTE_DETECTION_PIN_A6_SHARP,
  _B6 = NOTE_DETECTION_PIN_B6,
  _C7 = NOTE_DETECTION_PIN_C7,
  _C7_SHARP = NOTE_DETECTION_PIN_C7_SHARP,
  _D7 = NOTE_DETECTION_PIN_D7,
  _D7_SHARP = NOTE_DETECTION_PIN_D7_SHARP,
  _E7 = NOTE_DETECTION_PIN_E7,
  _F7 = NOTE_DETECTION_PIN_F7,
  _F7_SHARP = NOTE_DETECTION_PIN_F7_SHARP,
  _G7 = NOTE_DETECTION_PIN_G7
};

ShiftRegister shiftRegister(CLOCK_PIN, LATCH_PIN, ENABLE_PIN, CLEAR_PIN, DATA_PIN);

Button resetButton(RESET_BUTTON_PIN);
Button playButton(PLAY_BUTTON_PIN);
Button noteDetectionButtons[] {_G5, _G5_SHARP, _A5, _A5_SHARP, _B5, _C6, _C6_SHARP, _D6, _D6_SHARP, _E6, _F6, _F6_SHARP, _G6, _G6_SHARP, _A6, _A6_SHARP, _B6, _C7, _C7_SHARP, _D7, _D7_SHARP, _E7, _F7, _F7_SHARP, _G7};

Adafruit_NeoPixel pixels(NUMBER_OF_NEO_PIXELS_TOTAL, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int neoPixelStartIndex[] = {
  0, 12, 24, 37, 49, 62, 74,
  85, 95, 107, 119, 132, 145, 159,
  172, 186, 198, 210, 223, 235, 241,
  251, 265, 277, 290, 302, 314, 327
};

const boolean LOGGER_ON = true;

void setup() {
  Serial.begin(115200);
  resetButton.begin();
  playButton.begin();

  for (int x = 0; x < 25; x++) {
    noteDetectionButtons[x].begin();
  }

  pixels.begin();
  pixels.setBrightness(255);
  resetVars();

  shiftRegister.begin();
}

void loop() {
  
  logger("Start of loop" + _G5);

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
