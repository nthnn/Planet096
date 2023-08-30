#ifndef PLANET096_SCENE_H
#define PLANET096_SCENE_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <List.hpp>

#define APPBAR_NONE         0x00
#define APPBAR_NORMAL       0x01
#define APPBAR_BORDER_ONLY  0x02

#define APPBAR_ALIGN_LEFT   0x00
#define APPBAR_ALIGN_CENTER 0x01
#define APPBAR_ALIGN_RIGHT  0x02

class Planet096Scene {
public:
    Planet096Scene();
    Planet096Scene(String title);

    void setAppBarTitle(String title);
    String getAppBarTitle();

    void setAppBarStyle(uint8_t appbar_style);
    uint8_t getAppbarStyle();

    void setAppBarAlignment(uint8_t appbar_align);
    uint8_t getAppBarAlignment();

    void render(Adafruit_SSD1306 display);

private:
    String title;

    uint8_t appbar_style;
    uint8_t appbar_align;
};

#endif