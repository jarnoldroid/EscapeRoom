//G5, G#5, A5, A#5, B5, C6, C#6, D6, D#6, E6, F6, F#6, G6, G#6, A6, A#6, B6, C7, C#7, D7, D#7, E7, F7, F#7, G7

byte currentNoteBytes = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

boolean shouldPuzzleTunePlay() {
  boolean shouldPuzzleTunePlay = playButton.pressed();
  logger("Should Puzzle Tune Play?", shouldPuzzleTunePlay);
  return shouldPuzzleTunePlay;
}

void playPuzzleTune() {
  logger("Play Puzzle Tune");

  playNote(G5);
  delay(300);
  playNote(C6);
  delay(300);
  playNote(F6);
  delay(300);
  playNote(B6);
  delay(300);
  playNote(G7);
  delay(300);
}

void playVictoryTune() {
  logger("Play Victory Tune");
  delay(5000);
}

void playNote(int note) {
  uint32_t dataValue = noteToUint32(note);
  shiftRegister.updateShiftRegister(dataValue);
  delay(80);
  shiftRegister.clearShiftRegister();
}

void playNotes(int notes[]) {
  uint32_t dataValue = noteToUint32(notes[0]);

  int sizeOfNoteSequence = (sizeof(notes) / sizeof(notes[0]));

  for (int index = 1; index <= sizeOfNoteSequence; index++) {
    dataValue = dataValue | noteToUint32(notes[index]);
  }

  shiftRegister.updateShiftRegister(dataValue);
  delay(80);
  shiftRegister.clearShiftRegister();
}

uint32_t noteToUint32(uint32_t note){
  note-=1; // account for zero indexing
  uint32_t result = 0x00000001 ;
  result = result << note;
  return result;
}
