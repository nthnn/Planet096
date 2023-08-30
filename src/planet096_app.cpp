#include <Adafruit_SSD1306.h>
#include <Wire.h>

void Planet096App::getI2CScreen() {
    Adafruit_SSD1306 display(128, 64, &Wire, -1);
    return display;
}

void Planet096App::start(Planet096Scene scene) {
    scene.render(Planet096App::getI2CScreen());
}