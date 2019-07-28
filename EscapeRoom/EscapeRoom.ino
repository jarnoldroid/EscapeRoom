
#include <Adafruit_NeoPixel.h>
#include <Button.h>
#include <ShiftRegister_TPIC6A596.h>

/**
   OTHER CONFIGURATIONS
*/
const int NUMBER_OF_NEO_PIXELS_TOTAL = 339;
const boolean LOGGER_ON = true;

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

const int G5_PIN = 22;
const int GS5_PIN = 23;
const int A5_PIN = 24;
const int AS5_PIN = 25;
const int B5_PIN = 26;
const int C6_PIN = 27;
const int CS6_PIN = 28;
const int D6_PIN = 29;
const int DS6_PIN = 30;
const int E6_PIN = 31;
const int F6_PIN = 32;
const int FS6_PIN = 33;
const int G6_PIN = 34;
const int GS6_PIN = 35;
const int A6_PIN = 36;
const int AS6_PIN = 37;
const int B6_PIN = 38;
const int C7_PIN = 39;
const int CS7_PIN = 40;
const int D7_PIN = 41;
const int DS7_PIN = 42;
const int E7_PIN = 43;
const int F7_PIN = 44;
const int FS7_PIN = 45;
const int G7_PIN = 46;

/**
   Notes (Used to play - also used for detection)
*/
#define X 0
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
 * These notes are used to map the PIN to an array
*/
Button noteDetectionButtons[] {G5_PIN, GS5_PIN, A5_PIN, AS5_PIN, B5_PIN, C6_PIN, CS6_PIN, D6_PIN, DS6_PIN, E6_PIN, F6_PIN, FS6_PIN, G6_PIN, GS6_PIN, A6_PIN, AS6_PIN, B6_PIN, C7_PIN, CS7_PIN, D7_PIN, DS7_PIN, E7_PIN, F7_PIN, FS7_PIN, G7_PIN};

/**
   Neo Pixel config
*/
Adafruit_NeoPixel pixels(NUMBER_OF_NEO_PIXELS_TOTAL, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int neoPixelStartIndex[] = {
  0,   12,  24,  37,  49,  62,  74,
  85,  95,  107, 119, 132, 145, 159,
  172, 186, 198, 210, 223, 235, 241,
  251, 265, 277, 290, 302, 314, 327
};

int holeToNoteMapping[] = {
  G7,  FS7, F7,  E7,  DS7,  D7,  CS7,
  C7,  B6,  AS6, A6,  GS6,  G6,  FS6,
  F6,  E6,  DS6, D6,  CS6,  C6,  B5, 
  AS5, A5,  GS5, G5,  X,    X,   X
};

ShiftRegister shiftRegister(CLOCK_PIN, LATCH_PIN, ENABLE_PIN, CLEAR_PIN, DATA_PIN);

Button resetButton(RESET_BUTTON_PIN);
Button playButton(PLAY_BUTTON_PIN);


void setup() {
  Serial.begin(115200);
  resetButton.begin();
  playButton.begin();

  for (int x = 0; x < 25; x++) {
    noteDetectionButtons[x].begin();
    Serial.println(x);
  }

  pixels.begin();
  pixels.setBrightness(50);

  resetVars();

  shiftRegister.begin();
  Serial.println("Setup complete");
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
