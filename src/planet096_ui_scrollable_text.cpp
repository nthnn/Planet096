#include <Arduino.h>
#include <planet096_scene.h>
#include <planet096_ui_scrollable_text.h>

Planet096ScrollableText::Planet096ScrollableText():
    scene(nullptr),
    text("_") { }

Planet096ScrollableText::Planet096ScrollableText(
    Planet096Scene *scene,
    char* text
):
    text(text),
    scene(scene) { }

void Planet096ScrollableText::setText(char* text) {
    this->text = text;
    this->invalidate();
}

char* Planet096ScrollableText::getText() {
    return this->text;
}

void Planet096ScrollableText::setVisible(bool is_visible) {
    this->is_visible = is_visible;
    this->invalidate();
}

bool Planet096ScrollableText::isVisible() {
    return this->is_visible;
}

void Planet096ScrollableText::hasRendered() {
    this->has_rendered = true;
}

void Planet096ScrollableText::setBackgroundColor(Planet096Color bg_color) {
    this->bg_color = bg_color;
    this->invalidate();
}

void Planet096ScrollableText::setForegroundColor(Planet096Color fg_color) {
    this->fg_color = fg_color;
    this->invalidate();
}

Planet096Color Planet096ScrollableText::getBackgroundColor() {
    return this->bg_color;
}

Planet096Color Planet096ScrollableText::getForegroundColor() {
    return this->fg_color;
}

void Planet096ScrollableText::scrollUp() {
    if(this->scroll_position == 0)
        return;

    this->scroll_position--;
    this->invalidate();
}

void Planet096ScrollableText::scrollDown() {
    if(this->scroll_position + 1 >= this->max_scroll)
        return;

    this->scroll_position++;
    this->invalidate();
}

void Planet096ScrollableText::setScrollPosition(int scroll_position) {
    if(scroll_position < 0)
        return;

    this->scroll_position = scroll_position;
    this->invalidate();
}

int Planet096ScrollableText::getScrollPosition() {
    return this->scroll_position;
}

void Planet096ScrollableText::maxScroll(int max_scroll) {
    this->max_scroll = max_scroll;
}

int Planet096ScrollableText::maxScroll() {
    return this->max_scroll;
}

void Planet096ScrollableText::invalidate() {
    if(this->has_rendered)
        this->scene->renderWidget();
}