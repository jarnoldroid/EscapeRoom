const int DELAY_TIME_BETWEEN_RED_LIGHTS = 1000;

int sequence[] = {0, 2, 4, 1, 3};
int sequencePosition = 0;
int nextNoteInSequence = sequence[sequencePosition];



boolean isSequenceComplete() {
  int sizeOfSequence = (sizeof(sequence) / sizeof(sequence[0]));
  boolean isSequenceComplete = sequencePosition == sizeOfSequence;
  logger("Is sequence complete?", isSequenceComplete);
  return isSequenceComplete;
}

void startNotePlayedDetection() {

  if (noteHasBeenPlayed()) {

    int notePlayedIndex = getNotePlayedIndex();
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

//Has a note been played?
boolean noteHasBeenPlayed() {
  boolean noteplayed = true;
  logger("Has a note been played?", noteplayed);
  return noteplayed;
}

//If a note has been played get its Index
int getNotePlayedIndex() {
  //  int notePlayedIndex = 0;
  int notePlayedIndex = sequence[sequencePosition]; //simulate sequence
  logger("Note Played?", notePlayedIndex);
  return notePlayedIndex;
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

  int first = noteIndex * 8;
  int last = first + 8;

  for (int i = first; i < last; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
}

void turnSequenceLightRed(int noteIndex) {
  logger("Turn sequence light Red", noteIndex);

  int first = noteIndex * 8;
  int last = first + 8;

  for (int i = first; i < last; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

void turnAllSequenceLightsRed() {
  logger("Turn all sequence lights Red");

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

void turnAllSequenceLightsOff() {
  logger("Turn all sequence lights off");
  pixels.clear();
}
