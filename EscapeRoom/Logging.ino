
void logger(String message, boolean value) {
  String b = value ? "true" : "false";
  logger(message + " " + b);
}

void logger(String message, int value) {
  logger(message + " " + String(value));
}

void logger(String message, int value, int value2) {
  logger(message + " " + String(value) + " - " + String(value2));
}

void logger(String message) {
  if (LOGGER_ON) {
    Serial.println(message);
  }
}

void loggerOverride(String message, boolean value) {
  String b = value ? "true" : "false";
  loggerOverride(message + " " + b);
}

void loggerOverride(String message, int value) {
  loggerOverride(message + " " + String(value));
}


void loggerOverride(String message) {
  Serial.println(message);
}
