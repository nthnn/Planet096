#include <Arduino.h>
#include <planet096_scene.h>
#include <planet096_ui_text.h>

Planet096Text::Planet096Text():
    scene(nullptr),
    text("_") { }

Planet096Text::Planet096Text(
    Planet096Scene *scene,
    char* text
):
    text(text),
    scene(scene) { }

void Planet096Text::setText(char* text) {
    this->text = text;
    this->invalidate();
}

const char* Planet096Text::getText() {
    return this->text;
}

void Planet096Text::setX(uint8_t x) {
    this->x = x;
    this->invalidate();
}

void Planet096Text::setY(uint8_t y) {
    this->y = y;
    this->invalidate();
}

uint8_t Planet096Text::getX() {
    return this->x;
}

uint8_t Planet096Text::getY() {
    return this->y;
}

void Planet096Text::setTextSize(uint8_t size) {
    this->size = size;
    this->invalidate();
}

uint8_t Planet096Text::getTextSize() {
    return this->size;
}

void Planet096Text::setVisible(bool is_visible) {
    this->is_visible = is_visible;
    this->invalidate();
}

bool Planet096Text::isVisible() {
    return this->is_visible;
}

void Planet096Text::hasRendered() {
    this->has_rendered = true;
}

void Planet096Text::setHasScrollbar(bool has_scrollbar) {
    this->has_scrollbar = true;
    this->invalidate();
}

bool Planet096Text::hasScrollbar() {
    return this->has_scrollbar;
}

void Planet096Text::setBackgroundColor(Planet096Color bg_color) {
    this->bg_color = bg_color;
    this->invalidate();
}

void Planet096Text::setForegroundColor(Planet096Color fg_color) {
    this->fg_color = fg_color;
    this->invalidate();
}

Planet096Color Planet096Text::getBackgroundColor() {
    return this->bg_color;
}

Planet096Color Planet096Text::getForegroundColor() {
    return this->fg_color;
}

void Planet096Text::invalidate() {
    if(this->has_rendered)
        this->scene->renderWidget();
}