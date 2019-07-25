
//G5, G#5, A5, A#5, B5, C6, C#6, D6, D#6, E6, F6, F#6, G6, G#6, A6, A#6, B6, C7, C#7, D7, D#7, E7, F7, F#7, G7
//22, 23,  24, 25,  26, 27, 28,  29, 30,  31, 32, 33,  34, 35,  36, 37,  38, 39, 40,  41, 42,  43, 44, 45,  46

byte currentNoteBytes = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

const byte EMPTY = 0b00000000;

void updateNoteToPlayBytes(Note note, byte noteToPlayBytes[]) {

  switch (note) {
    case _G5:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00000001;
      break;
    case _G5_SHARP:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00000010;
      break;
    case _A5:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00000100;
      break;
    case _A5_SHARP:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00001000;
      break;
    case _B5:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00010000;
      break;
    case _C6:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b00100000;
      break;
    case _C6_SHARP:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b01000000;
      break;
    case _D6:
      noteToPlayBytes[0] = noteToPlayBytes[0] | 0b10000000;
      break;
    case _D6_SHARP:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00000001;
      break;
    case _E6:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00000010;
      break;
    case _F6:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00000100;
      break;
    case _F6_SHARP:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00001000;
      break;
    case _G6:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00010000;
      break;
    case _G6_SHARP:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b00100000;
      break;
    case _A6:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b01000000;
      break;
    case _A6_SHARP:
      noteToPlayBytes[1] = noteToPlayBytes[1] | 0b10000000;
      break;
    case _B6:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00000001;
      break;
    case _C7:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00000010;
      break;
    case _C7_SHARP:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00000100;
      break;
    case _D7:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00001000;
      break;
    case _D7_SHARP:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00010000;
      break;
    case _E7:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b00100000;
      break;
    case _F7:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b01000000;
      break;
    case _F7_SHARP:
      noteToPlayBytes[2] = noteToPlayBytes[2] | 0b10000000;
      break;
    case _G7:
      noteToPlayBytes[3] = noteToPlayBytes[3] | 0b00000001;
      break;
  }
}

boolean shouldPuzzleTunePlay() {
  boolean shouldPuzzleTunePlay = playButton.pressed();
  logger("Should Puzzle Tune Play?", shouldPuzzleTunePlay);
  return shouldPuzzleTunePlay;
}

void playPuzzleTune() {
  logger("Play Puzzle Tune");
}

void playVictoryTune() {
  logger("Play Victory Tune");

  playNote(_G6);
  playNote(_A6);

  Note notes0[] = {_B6, _F7};
  playNotes(notes0);

  Note notes1[] = {_C7, _E7, _F7};
  playNotes(notes1);

  Note notes2[] = {_G6_SHARP, _C7};
  playNotes(300, 200, notes2);

  Note notes3[] = {_G6, _C7};
  playNotes(300, 200, notes3);

  Note notes4[] = {_F6_SHARP, _C7};
  playNotes(notes4);

  playNote(_F6);

  //G6,
  //A6,
  //B6,  F7
  //C7,  E7, F7
  //G#6, C7
  //G6,  C7
  //F#6, C7
  //F6
}

void playNotes(Note notes[]) {
  playNotes(100, 200, notes);
}

void playNotes(int startWait, int endWait, Note notes[]) {
  byte noteBytes[] = { EMPTY, EMPTY, EMPTY, EMPTY };

  int sizeOfSequence = (sizeof(notes) / sizeof(notes[0]));

  for (int i = 0; i < sizeOfSequence; i++) {
    updateNoteToPlayBytes(notes[i], noteBytes);
  }

  playNote(startWait, endWait, noteBytes);
}

void playNote(Note note) {
  playNote(100, 200, note);
}

void playNote(int startWait, int endWait, Note note) {
  byte noteBytes[] = { EMPTY, EMPTY, EMPTY, EMPTY };
  updateNoteToPlayBytes(note, noteBytes);
  playNote(startWait, endWait, noteBytes);
}

void playNote(int startWait, int endWait, byte noteBytes[]) {
  
  shiftRegister1.updateShiftRegister(noteBytes[0]);
  shiftRegister2.updateShiftRegister(noteBytes[1]);
  shiftRegister3.updateShiftRegister(noteBytes[2]);
  shiftRegister4.updateShiftRegister(noteBytes[3]);

  delay(startWait);

  shiftRegister1.updateShiftRegister(EMPTY);
  shiftRegister2.updateShiftRegister(EMPTY);
  shiftRegister3.updateShiftRegister(EMPTY);
  shiftRegister4.updateShiftRegister(EMPTY);

  delay(endWait);
}
