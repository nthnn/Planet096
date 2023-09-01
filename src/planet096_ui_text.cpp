#include <Arduino.h>
#include <planet096_scene.h>
#include <planet096_ui_text.h>
#include <planet096_widget.h>

Planet096Text::Planet096Text(const char* text):
    text(text) { }

void Planet096Text::setText(const char* text) {
    this->text = text;
    this->refresh();
}

const char* Planet096Text::getText() {
    return this->text;
}

void Planet096Text::setX(int x) {
    this->x = x;
    this->refresh();
}

void Planet096Text::setY(int y) {
    this->y = y;
    this->refresh();
}

int Planet096Text::getX() {
    return this->x;
}

int Planet096Text::getY() {
    return this->y;
}

void Planet096Text::setTextSize() {
    this->size = size;
    this->refresh();
}

int Planet096Text::getTextSize() {
    return this->size;
}

void Planet096Text::render(Planet096Scene &scene) const {
    if(!this->has_rendered) {
        this->scene = scene;
        this->has_rendered = true;
    }
}

void Planet096Text::refresh() const {
    if(this->has_rendered)
        this->render(this->scene);
}