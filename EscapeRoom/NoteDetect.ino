const int DELAY_TIME_BETWEEN_RED_LIGHTS = 1000;
const int NO_NOTE_PLAYED = -1;

int sequence[] = {G5, C6, F6, B6, G7};
int sequencePosition = 0;
int nextNoteInSequence = sequence[sequencePosition];

boolean isSequenceComplete() {
  int sizeOfSequence = (sizeof(sequence) / sizeof(sequence[0]));
  boolean isSequenceComplete = sequencePosition == sizeOfSequence;
  logger("Is sequence complete?", isSequenceComplete);
  return isSequenceComplete;
}

void startNotePlayedDetection() {

  int notePlayedIndex = getNotePlayedIndex();

  if (notePlayedIndex == NO_NOTE_PLAYED) {
    //do nothing
  } else {
    lightUpNote(notePlayedIndex);

    if (isNoteNextInSequence(notePlayedIndex)) {
      turnSequenceLightGreen(notePlayedIndex);
      updateSequence();
    } else {
      resetSequence();
      turnSequenceLightRed(notePlayedIndex);
      delay(DELAY_TIME_BETWEEN_RED_LIGHTS);
      turnAllSequenceLightsRed();
      delay(DELAY_TIME_BETWEEN_RED_LIGHTS);
      turnAllSequenceLightsOff();
    }
  }
}

//If a note has been played get its Index
int getNotePlayedIndex() {

  for (int x = 0; x < 25; x++) {
    if (noteDetectionButtons[x].pressed()) {
      logger("Note Played?", x);
      return x;
    }
  }

  logger("Note Played? NO_NOTE_PLAYED");
  return NO_NOTE_PLAYED;
}

void lightUpNote(int noteIndex) {
  logger("light up note", noteIndex);
  //TODO light up the note that was played
}

boolean isNoteNextInSequence(int noteIndex) {
  boolean isNoteNextInSequence = noteIndex == nextNoteInSequence;
  logger("Is note next in sequence", noteIndex);
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

void turnSequenceLightGreen(int noteIndex) {
  logger("Turn sequence light Green", noteIndex);

  int first = noteIndex * 7;
  int last = first + 7;

  for (int i = first; i < last; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
}

void turnSequenceLightRed(int noteIndex) {
  logger("Turn sequence light Red", noteIndex);

  int first = noteIndex * 7;
  int last = first + 7;

  for (int i = first; i < last; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

void turnAllSequenceLightsRed() {
  logger("Turn all sequence lights Red");

  for (int i = 0; i < NUMBER_OF_NEO_PIXELS_TOTAL; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

void turnAllSequenceLightsOff() {
  logger("Turn all sequence lights off");

  pixels.clear();
  pixels.show();
}
