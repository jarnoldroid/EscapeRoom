
//G5, A6, B6, C6, D6, E6, F6, G6, A7, B7, C7, D7, E7, F7, G7, G5#, A6#, C6#, D6#, F6#, G6#, A7#, C7#, D7#, F7# 


boolean shouldPuzzleTunePlay() {
  boolean shouldPuzzleTunePlay = playButton.pressed();
  logger("Should Puzzle Tune Play?", shouldPuzzleTunePlay);
  return shouldPuzzleTunePlay;
}

void playPuzzleTune() {
  logger("Play Puzzle Tune");
  waitingSequence();
}


void playVictoryTune() {
  logger("Play Victory Tune");
  waitingSequence();
}
