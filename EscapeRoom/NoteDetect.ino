const int DELAY_TIME_BETWEEN_RED_LIGHTS = 1000;
const int NO_NOTE_PLAYED = -1;
const int NEO_PIXEL_NOT_FOUND = -1;

int sequence[] = {G5, C6, F6, B6, G7};
int sequencePosition = 0;
int nextNoteInSequence = sequence[sequencePosition];

const uint32_t RED = pixels.Color(255, 0, 0);
const uint32_t GREEN = pixels.Color(0, 255, 0);

boolean isSequenceComplete() {
  int sizeOfSequence = (sizeof(sequence) / sizeof(sequence[0]));
  boolean isSequenceComplete = sequencePosition == sizeOfSequence;
  logger("Is sequence complete?", isSequenceComplete);
  return isSequenceComplete;
}

void startNotePlayedDetection() {

  int notePlayed = getNotePlayed();

  if (notePlayed == NO_NOTE_PLAYED) {
    //do nothing
  } else {
    lightUpNote(notePlayed);

    if (isNoteNextInSequence(notePlayed)) {
      turnSequenceLightGreen(notePlayed);
      updateSequence();
    } else {
      resetSequence();
      turnSequenceLightRed(notePlayed);
      delay(DELAY_TIME_BETWEEN_RED_LIGHTS);
      turnAllSequenceLightsRed();
      delay(DELAY_TIME_BETWEEN_RED_LIGHTS);
      turnAllSequenceLightsOff();
    }
  }
}

//If a note has been played get its Index
int getNotePlayed() {

  for (int x = 0; x < 25; x++) {
    if (noteDetectionButtons[x].pressed()) {
      logger("Note Played?", x);
      return x + 1;
    }
  }

  logger("Note Played? NO_NOTE_PLAYED");
  return NO_NOTE_PLAYED;
}

void lightUpNote(int noteIndex) {
  logger("light up note", noteIndex);
  //TODO light up the note that was played
}

boolean isNoteNextInSequence(int notePlayed) {
  boolean isNoteNextInSequence = notePlayed == nextNoteInSequence;
  logger("Is note next in sequence", notePlayed);
  return isNoteNextInSequence;
}

void updateSequence() {
  int currentNoteInSequence = nextNoteInSequence;
  sequencePosition++;

  if (!isSequenceComplete()) {
    nextNoteInSequence = sequence[sequencePosition];
  }

  logger("updateSequence from - to ", currentNoteInSequence, nextNoteInSequence);
}

void resetSequence() {
  logger("resetSequence");
  sequencePosition = 0;
  nextNoteInSequence = sequence[sequencePosition];
}

void turnSequenceLightGreen(int notePlayed) {
  logger("Turn sequence light Green", notePlayed);
  turnSequenceLightOn(notePlayed, GREEN);
}

void turnSequenceLightRed(int notePlayed) {
  logger("Turn sequence light Red", notePlayed);
  turnSequenceLightOn(notePlayed, RED);
}

void turnSequenceLightOn(int notePlayed, uint32_t colour) {
  int first = getNeoPixelFirstInHole(notePlayed);
  int last = first + 5;

  for (int i = first; i < last; i++) {
    pixels.setPixelColor(i, colour);
  }
  pixels.show();
}

int getNeoPixelFirstInHole(int notePlayed) {
  for (int i = 0; i < 28; i++) {
    if (holeToNoteMapping[i] == notePlayed) {
      int neoPixelStart = neoPixelStartIndex[i];
      logger("Neo Pixel Start", neoPixelStart);
      return neoPixelStart;
    }
  }
  logger("----------- ERROR! ----------", notePlayed);
  logger("--------- NEO PIXEL ---------", notePlayed);
  logger("--------- NOT FOUND ---------", notePlayed);

  return NEO_PIXEL_NOT_FOUND;
}

void turnAllSequenceLightsRed() {
  logger("Turn all sequence lights Red");

  for (int i = 0; i < NUMBER_OF_NEO_PIXELS_TOTAL; i++) {
    pixels.setPixelColor(i, RED);
  }
  pixels.show();
}

void turnAllSequenceLightsOff() {
  logger("Turn all sequence lights off");

  pixels.clear();
  pixels.show();
}
