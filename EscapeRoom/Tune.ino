


boolean shouldPuzzleTunePlay() {
  boolean shouldPuzzleTunePlay = playButton.pressed();
  logger("Should Puzzle Tune Play?", shouldPuzzleTunePlay);
  return shouldPuzzleTunePlay;
}

void playPuzzleTune() {
  logger("Play Puzzle Tune");
  //TODO Code the play the puzzle tune here
  digitalWrite(TEST_LED_PIN, HIGH);
  delay(500);
  digitalWrite(TEST_LED_PIN, LOW);
  delay(500);
  digitalWrite(TEST_LED_PIN, HIGH);
  delay(500);
  digitalWrite(TEST_LED_PIN, LOW);
  delay(500);

}


void playVictoryTune() {
  logger("Play Victory Tune");
  //TODO Code the play the victory tune here
  digitalWrite(TEST_LED_PIN, HIGH);
  delay(500);
  digitalWrite(TEST_LED_PIN, LOW);
  delay(500);
  digitalWrite(TEST_LED_PIN, HIGH);
  delay(500);
  digitalWrite(TEST_LED_PIN, LOW);
  delay(500);
}
