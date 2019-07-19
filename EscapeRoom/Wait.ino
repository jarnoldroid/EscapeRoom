

int times = 0;
int waitingPos = 0;
//int red[] =    {0,   127, 0,   127};
//int green[] =  {0,   0,   127, 127};
//int blue[] =   {127, 0,   0,   127};

int red[] =    {0,   127,   0,   127};
int green[] =  {0,   127,   0,   127};
int blue[] =   {127, 127,   127, 127};


void waitingSequence() {
  if (waitingPos == 4) {
    waitingPos = 0;
  }

  int r = red[waitingPos];
  int g = green[waitingPos];
  int b = blue[waitingPos];
  uint32_t color = pixels.Color(r, g, b);
  theaterChase(color);

  waitingPos++;
}


// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color) {
  for (int a = 0; a < 50; a++) { // Repeat
    for (int b = 0; b < 3; b++) {
      pixels.clear();
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for (int c = b; c < pixels.numPixels(); c += 3) {
        pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      pixels.show(); // Update strip with new contents
      delay(50);  // Pause for a moment
    }
  }
}
