#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <List.hpp>

#include "planet096_scene.h"

Planet096Scene::Planet096Scene() { }

Planet096Scene::Planet096Scene(String title):
    title(title) { }

void Planet096Scene::setAppBarTitle(String title) {
    this->title = title;
}

String getAppBarTitle() {
    return this->title;
}

void Planet096Scene::setAppBarStyle(uint8_t appbar_style) {
    this->appbar_style = appbar_style;
}

uint8_t Planet096Scene::getAppbarStyle() {
    return this->appbar_style;
}

void Planet096Scene::setAppBarAlignment(uint8_t appbar_align) {
    this->appbar_align = appbar_align;
}

uint8_t Planet096Scene::getAppBarAlignment() {
    return this->appbar_align;
}

void render(Adafruit_SSD1306 display) {
    if(this->appbar_style == APPBAR_STYLE_NORMAL) {
        oled.fillRect(0, 0, 128, 14, WHITE);
        oled.setTextSize(1);
        oled.setTextColor(BLACK, WHITE);
        oled.setCursor(64 - ((this->title.length() * 5) / 2), 4);
        oled.println(this->title);
    }
}