

boolean hatchIsOpen = false;

void openHatch() {
  logger("open hatch");
  digitalWrite(hatchPin, HIGH);
  hatchIsOpen = true;
}


void closeHatch() {
  logger("close hatch");
  if (hatchIsOpen) {
    digitalWrite(hatchPin, LOW);
    hatchIsOpen = false;
  }
}
