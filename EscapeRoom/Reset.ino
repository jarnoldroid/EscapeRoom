
boolean shouldReset() {
  boolean shouldReset = resetButton.pressed();
  logger("Should reset?", shouldReset);
  return shouldReset;
}

/* Reset variables back to default state*/
void resetVars() {
  pixels.clear();
  resetSequence();
  logger("Reseting variables");
}
