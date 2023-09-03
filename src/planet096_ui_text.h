#ifndef PLANET096_UI_TEXT_H
#define PLANET096_UI_TEXT_H

#include <Arduino.h>
#include <planet096_colors.h>
#include <planet096_scene.h>

class Planet096Scene;

class Planet096Text {
public:
    Planet096Text();
    Planet096Text(Planet096Scene *scene, char* text);

    void setText(char* text);
    char* getText();

    void setX(uint8_t x);
    void setY(uint8_t y);
    void setTextSize(uint8_t size);

    uint8_t getX();
    uint8_t getY();
    uint8_t getTextSize();

    void setVisible(bool is_visible);
    bool isVisible();

    void setBackgroundColor(Planet096Color bg_color);
    void setForegroundColor(Planet096Color fg_color);

    Planet096Color getBackgroundColor();
    Planet096Color getForegroundColor();

    void hasRendered();

private:
    char* text;
    uint8_t x = 0, y = 0, size = 1;
    Planet096Color bg_color = PLANET096_BLACK,
        fg_color = PLANET096_WHITE;
    bool is_visible = true,
        has_rendered = false;

    Planet096Scene *scene;

    void invalidate();
};

#endif