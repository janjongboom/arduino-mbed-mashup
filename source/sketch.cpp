#include "Arduino.h"
#include <ChainableLED.h>

// demo from https://github.com/pjpmarques/ChainableLED
#define NUM_LEDS  1

ChainableLED leds(4, 5, NUM_LEDS);

void setup() {
    leds.init();
    pinMode(LED_BUILTIN, OUTPUT);
}

float hue = 0.0;
boolean up = true;

void loop() {
    for (byte i=0; i<NUM_LEDS; i++)
        leds.setColorHSB(i, hue, 1.0, 0.5);

    delay(50);

    if (up)
        hue += 0.025;
    else
        hue -= 0.025;

    if (hue >= 1.0 && up)
        up = false;
    else if (hue <= 0.0 && !up)
        up = true;
}

// Mbed OS bootstrap code
int main() {
    setup();

    while (1) loop();
}
