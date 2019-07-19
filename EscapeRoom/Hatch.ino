

boolean hatchIsOpen = false;

void openHatch() {
  logger("open hatch");
  digitalWrite(HATCH_PIN, HIGH);
  hatchIsOpen = true;
}


void closeHatch() {
  logger("close hatch");
  if (hatchIsOpen) {
    digitalWrite(HATCH_PIN, LOW);
    hatchIsOpen = false;
  }
}
