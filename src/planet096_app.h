#ifndef PLANET096_APP_H
#define PLANET096_APP_H

#include <Adafruit_SSD1306.h>
#include <planet096_scene.h>

class Planet096App {
public:
    static Adafruit_SSD1306 getI2CScreen();
    static void start(Planet096Scene &scene);
};

#endif