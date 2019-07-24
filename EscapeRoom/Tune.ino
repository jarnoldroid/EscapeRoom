
//G5, G#5, A5, A#5, B5, C6, C#6, D6, D#6, E6, F6, F#6, G6, G#6, A6, A#6, B6, C7, C#7, D7, D#7, E7, F7, F#7, G7
//22, 23,  24, 25,  26, 27, 28,  29, 30,  31, 32, 33,  34, 35,  36, 37,  38, 39, 40,  41, 42,  43, 44, 45,  46

byte currentNoteBytes = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

const byte EMPTY = 0b00000000;

void updateNoteToPlayBytes(Note note, byte noteToPlayBytes[]) {

  switch (note) {
    case _G5:
      noteToPlayBytes[0] = 0b00000001;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _G5_SHARP:
      noteToPlayBytes[0] = 0b00000010;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _A5:
      noteToPlayBytes[0] = 0b00000100;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _A5_SHARP:
      noteToPlayBytes[0] = 0b00001000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _B5:
      noteToPlayBytes[0] = 0b00010000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _C6:
      noteToPlayBytes[0] = 0b00100000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _C6_SHARP:
      noteToPlayBytes[0] = 0b01000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _D6:
      noteToPlayBytes[0] = 0b10000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _D6_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000001;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _E6:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000010;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _F6:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000100;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _F6_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00001000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _G6:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00010000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _G6_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00100000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _A6:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b01000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _A6_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b10000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _B6:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000001;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _C7:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000010;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _C7_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000100;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _D7:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00001000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _D7_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00010000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _E7:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00100000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _F7:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b01000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _F7_SHARP:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b10000000;
      noteToPlayBytes[3] = 0b00000000;
      break;
    case _G7:
      noteToPlayBytes[0] = 0b00000000;
      noteToPlayBytes[1] = 0b00000000;
      noteToPlayBytes[2] = 0b00000000;
      noteToPlayBytes[3] = 0b00000001;
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
  //G6, 
  //A6, 
  //B6,  F7 
  //C7,  E7, F7
  //G#6, C7
  //G6,  C7
  //F#6, C7
  //F6
}

void playNote(Note note) {
  byte noteBytes[] = { EMPTY, EMPTY, EMPTY, EMPTY };
  updateNoteToPlayBytes(note, noteBytes);
  playNote(noteBytes);
}

void playNote(byte noteBytes[]) {
  playNote(100, 200, noteBytes);
}

void playNote(int startWait, int endWait, byte noteBytes[]) {

  if (noteBytes[0] != EMPTY) {
    playNoteOnShiftRegister(startWait, endWait, noteBytes[0], shiftRegister1);
  } else if (noteBytes[1] != EMPTY) {
    playNoteOnShiftRegister(startWait, endWait, noteBytes[1], shiftRegister2);
  } else if (noteBytes[2] != EMPTY) {
    playNoteOnShiftRegister(startWait, endWait, noteBytes[2], shiftRegister3);
  } else if (noteBytes[3] != EMPTY) {
    playNoteOnShiftRegister(startWait, endWait, noteBytes[3], shiftRegister4);
  }
}

void playNoteOnShiftRegister(int startWait, int endWait, byte noteByte, ShiftRegister shiftRegister) {
  shiftRegister.updateShiftRegister(noteByte);
  delay(startWait);
  shiftRegister.updateShiftRegister(0);
  delay(endWait);
}
