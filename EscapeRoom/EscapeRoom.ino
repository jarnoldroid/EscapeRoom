
#include <Adafruit_NeoPixel.h>
#include <Button.h>
#include <ShiftRegister_TPIC6A596.h>

/**
   OTHER CONFIGURATIONS
*/
const int NUMBER_OF_PIXELS_AROUND_EACH_HOLE = 7;
const int NUMBER_OF_NEO_PIXELS_TOTAL = 196; //28 * 7

/*
   PINS CONFIGURATION:
*/
const int HATCH_PIN = 47;
const int RESET_BUTTON_PIN = 48;
const int PLAY_BUTTON_PIN = 49;
const int NEO_PIXEL_PIN = 50;

//Shift Register for notes: G5, G#5, A5, A#5, B5, C6, C#6, D6
const int SHIFT_REGISTER_1_CLOCK_PIN = 2;
const int SHIFT_REGISTER_1_LATCH_PIN = 3;
const int SHIFT_REGISTER_1_ENABLE_PIN = 4;
const int SHIFT_REGISTER_1_CLEAR_PIN = 5;
const int SHIFT_REGISTER_1_DATA_PIN = 6;

//Shift Register for notes: D#6, E6, F6, F#6, G6, G#6, A6, A#6
const int SHIFT_REGISTER_2_CLOCK_PIN = 7;
const int SHIFT_REGISTER_2_LATCH_PIN = 8;
const int SHIFT_REGISTER_2_ENABLE_PIN = 9;
const int SHIFT_REGISTER_2_CLEAR_PIN = 10;
const int SHIFT_REGISTER_2_DATA_PIN = 11;

//Shift Register for notes: B6, C7, C#7, D7, D#7, E7, F7, F#7
const int SHIFT_REGISTER_3_CLOCK_PIN = 12;
const int SHIFT_REGISTER_3_LATCH_PIN = 13;
const int SHIFT_REGISTER_3_ENABLE_PIN = 14;
const int SHIFT_REGISTER_3_CLEAR_PIN = 15;
const int SHIFT_REGISTER_3_DATA_PIN = 16;

//Shift Register for note: G7
const int SHIFT_REGISTER_4_CLOCK_PIN = 17;
const int SHIFT_REGISTER_4_LATCH_PIN = 18;
const int SHIFT_REGISTER_4_ENABLE_PIN = 19;
const int SHIFT_REGISTER_4_CLEAR_PIN = 20;
const int SHIFT_REGISTER_4_DATA_PIN = 21;

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

ShiftRegister shiftRegister1(SHIFT_REGISTER_1_CLOCK_PIN, SHIFT_REGISTER_1_LATCH_PIN, SHIFT_REGISTER_1_ENABLE_PIN, SHIFT_REGISTER_1_CLEAR_PIN, SHIFT_REGISTER_1_DATA_PIN);
ShiftRegister shiftRegister2(SHIFT_REGISTER_2_CLOCK_PIN, SHIFT_REGISTER_2_LATCH_PIN, SHIFT_REGISTER_2_ENABLE_PIN, SHIFT_REGISTER_2_CLEAR_PIN, SHIFT_REGISTER_2_DATA_PIN);
ShiftRegister shiftRegister3(SHIFT_REGISTER_3_CLOCK_PIN, SHIFT_REGISTER_3_LATCH_PIN, SHIFT_REGISTER_3_ENABLE_PIN, SHIFT_REGISTER_3_CLEAR_PIN, SHIFT_REGISTER_3_DATA_PIN);
ShiftRegister shiftRegister4(SHIFT_REGISTER_4_CLOCK_PIN, SHIFT_REGISTER_4_LATCH_PIN, SHIFT_REGISTER_4_ENABLE_PIN, SHIFT_REGISTER_4_CLEAR_PIN, SHIFT_REGISTER_4_DATA_PIN);

Button resetButton(RESET_BUTTON_PIN);
Button playButton(PLAY_BUTTON_PIN);
Button noteDetectionButtons[] {_G5, _G5_SHARP, _A5, _A5_SHARP, _B5, _C6, _C6_SHARP, _D6, _D6_SHARP, _E6, _F6, _F6_SHARP, _G6, _G6_SHARP, _A6, _A6_SHARP, _B6, _C7, _C7_SHARP, _D7, _D7_SHARP, _E7, _F7, _F7_SHARP, _G7};

Adafruit_NeoPixel pixels(NUMBER_OF_NEO_PIXELS_TOTAL, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

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


  shiftRegister1.begin();
  shiftRegister2.begin();
  shiftRegister3.begin();
  shiftRegister4.begin();
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
