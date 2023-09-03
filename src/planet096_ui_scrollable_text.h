#ifndef PLANET096_UI_SCROLLABLE_TEXT_H
#define PLANET096_UI_SCROLLABLE_TEXT_H

#include <Arduino.h>
#include <planet096_colors.h>
#include <planet096_scene.h>

class Planet096Scene;

class Planet096ScrollableText {
public:
    Planet096ScrollableText();
    Planet096ScrollableText(Planet096Scene *scene, char* text);

    void setText(char* text);
    char* getText();

    void setVisible(bool is_visible);
    bool isVisible();

    void setBackgroundColor(Planet096Color bg_color);
    void setForegroundColor(Planet096Color fg_color);

    Planet096Color getBackgroundColor();
    Planet096Color getForegroundColor();

    void scrollUp();
    void scrollDown();

    void setScrollPosition(int scroll_position);
    int getScrollPosition();

    void maxScroll(int max_scroll);
    int maxScroll();

    void hasRendered();

private:
    char* text;
    uint8_t scroll_position = 0, max_scroll = 0;
    Planet096Color bg_color = PLANET096_BLACK,
        fg_color = PLANET096_WHITE;
    bool is_visible = true,
        has_rendered = false;

    Planet096Scene *scene;

    void invalidate();
};

#endif