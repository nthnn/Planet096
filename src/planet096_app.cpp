#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "planet096_app.h"
#include "planet096_scene.h"

static Adafruit_SSD1306 display(128, 64, &Wire, -1);

Adafruit_SSD1306 Planet096App::getI2CScreen() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        return NULL;

    return display;
}

void Planet096App::start(Planet096Scene &scene) {
    scene.render();
}