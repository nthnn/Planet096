#include <planet096_scene.h>
#include <planet096_ui_progress_bar.h>

Planet096ProgressBar::Planet096ProgressBar():
    scene(nullptr) { }

Planet096ProgressBar::Planet096ProgressBar(Planet096Scene *scene):
    scene(scene) { }

void Planet096ProgressBar::setX(uint8_t x) {
    this->x = x;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getX() {
    return this->x;
}

void Planet096ProgressBar::setY(uint8_t y) {
    this->y = y;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getY() {
    return this->y;
}

void Planet096ProgressBar::setWidth(uint8_t width) {
    this->width = width;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getWidth() {
    return this->width;
}

void Planet096ProgressBar::setHeight(uint8_t height) {
    this->height = height;
    return this->height;
}

uint8_t Planet096ProgressBar::getHeight() {
    return this->height;
}

void Planet096ProgressBar::setOrientation(uint8_t orientation) {
    this->orientation = orientation;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getOrientation() {
    return this->orientation;
}

void Planet096ProgressBar::setDirection(uint8_t direction) {
    this->direction = direction;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getDirection() {
    return this->direction;
}

void Planet096ProgressBar::setMin(uint8_t min) {
    this->min = min;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getMin() {
    return this->min;
}

void Planet096ProgressBar::setMax(uint8_t max) {
    this->max = max;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getMax() {
    return this->max;
}

void Planet096ProgressBar::setValue(uint8_t value) {
    this->value = value;
    this->invalidate();
}

uint8_t Planet096ProgressBar::getValue() {
    return this->value;
}

void Planet096ProgressBar::hasRendered() {
    this->has_rendered = true;
}

void Planet096ProgressBar::invalidate() {
    if(this->has_rendered)
        this->scene->renderWidget();
}