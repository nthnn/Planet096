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

String Planet096Scene::getAppBarTitle() {
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

void Planet096Scene::render(Adafruit_SSD1306 display) {
    display.clearDisplay();
    display.setTextSize(1);

    if(this->appbar_style == APPBAR_NONE)
        return;

    switch(this->appbar_align) {
        case APPBAR_ALIGN_CENTER:
            display.setCursor(59 - ((this->title.length() * 5) / 2), 2);
            break;
        case APPBAR_ALIGN_LEFT:
            display.setCursor(4, 2);
            break;
        case APPBAR_ALIGN_RIGHT:
            display.setCursor((124 - this->title.length()) - (this->title.length() * 5), 2);
            break;
    }

    switch(this->appbar_style) {
        case APPBAR_NORMAL:
            display.fillRect(0, 0, 128, 10, WHITE);
            display.setTextColor(BLACK, WHITE);
            break;

        case APPBAR_LINE_BORDER:
            display.drawLine(0, 10, 128, 10, WHITE);
            display.setTextColor(WHITE, BLACK);
            break;
    }

    display.println(this->title);
    display.display();
}