
int codeline1[] = { 0, 1, 2};

int codeline2[] = { 13, 12, 11, 10, 9};

int codeline3[] = { 14, 15, 16, 17, 18, 19, 20};

int codeline4[] = { 27, 26};

int opposite1[] = { 3, 4, 5, 6 };

int opposite2[] = { 8, 7 };

int opposite3[] = { 25, 24, 23, 22, 21 };

const uint32_t RED = pixels.Color(255, 0, 0);
const uint32_t PURPLE = pixels.Color(128, 0, 128);
const uint32_t GREEN = pixels.Color(0, 255, 0);
const uint32_t BLUE = pixels.Color(0, 0, 255);

const uint32_t WHITE = pixels.Color(255, 255, 255);

const uint32_t LOW_WHITE = pixels.Color(10, 10, 10);

void displayCode() {

  displayCodeLine1(RED);
  displayCodeOpposite1(LOW_WHITE);
  displayCodeLine2(PURPLE);
  displayCodeOpposite2(LOW_WHITE);
  displayCodeLine3(GREEN);
  displayCodeLine4(BLUE);
  displayCodeOpposite3(LOW_WHITE);
}

void flashDisplayCode() {

  displayCodeLine1(WHITE);
  displayCodeLine1(RED);
  displayCodeLine2(WHITE);
  displayCodeLine2(PURPLE);
  displayCodeLine3(WHITE);
  displayCodeLine3(GREEN);
  displayCodeLine4(WHITE);
  displayCodeLine4(BLUE);
}


void displayCodeLine1(uint32_t colour) {
  for (int i = 0; i < 3; i++) {
    int from = neoPixelStartIndex[codeline1[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void displayCodeLine2(uint32_t colour) {
  for (int i = 0; i < 5; i++) {
    int from = neoPixelStartIndex[codeline2[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void displayCodeLine3(uint32_t colour) {
  for (int i = 0; i < 7; i++) {
    int from = neoPixelStartIndex[codeline3[i]];
    int to =  from + 5;
    colorWipe(from, to, colour);
  }
}

void displayCodeLine4(uint32_t colour) {
  for (int i = 0; i < 2; i++) {
    int from = neoPixelStartIndex[codeline4[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void displayCodeOpposite1(uint32_t colour) {
  for (int i = 0; i < 4; i++) {
    int from = neoPixelStartIndex[opposite1[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void displayCodeOpposite2(uint32_t colour) {
  for (int i = 0; i < 2; i++) {
    int from = neoPixelStartIndex[opposite2[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void displayCodeOpposite3(uint32_t colour) {
  for (int i = 0; i < 5; i++) {
    int from = neoPixelStartIndex[opposite3[i]];
    int to =  from + 7;
    colorWipe(from, to, colour);
  }
}

void colorWipe(int from, int to, uint32_t colour) {
  for (int i = from; i < to; i++) {
    pixels.setPixelColor(i, colour);
    pixels.show();
  }
}

void theaterChaseRainbow(int from, int to) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for (int a = 0; a < 30; a++) { // Repeat 30 times...
    for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
      pixels.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for (int c = from; c < to; c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / pixels.numPixels();
        uint32_t color = pixels.gamma32(pixels.ColorHSV(hue)); // hue -> RGB
        pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      pixels.show();                // Update strip with new contents

      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
