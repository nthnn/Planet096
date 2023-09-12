#ifndef PLANET096_UI_PROGRESS_BAR_H
#define PLANET096_UI_PROGRESS_BAR_H

#include <Arduino.h>
#include <planet096_scene.h>

#define PLANET096_PROGRESS_BAR_HORIZONTAL   0x00
#define PLANET096_PROGRESS_BAR_VERTICAL     0x01

#define PLANET096_PROGRESS_BAR_LEFT_RIGHT   0x00
#define PLANET096_PROGRESS_BAR_RIGHT_LEFT   0x01

#define PLANET096_PROGRESS_BAR_TOP_BOTTOM   0x00
#define PLANET096_PROGRESS_BAR_BOTTOM_TOP   0x01

class Planet096Scene;

class Planet096ProgressBar {
public:
    Planet096ProgressBar();
    Planet096ProgressBar(Planet096Scene *scene);
    Planet096ProgressBar(Planet096Scene *scene, int x, int y);
    Planet096ProgressBar(Planet096Scene *scene, int min, int max, int value);

    Planet096ProgressBar(
        Planet096Scene *scene,
        int x, int y,
        int width, int height
    );

    Planet096ProgressBar(
        Planet096Scene *scene,
        int x, int y,
        int width, int height,
        int min, int max, int value
    );

    void setX(uint8_t x);
    uint8_t getX();

    void setY(uint8_t y);
    uint8_t getY();

    void setWidth(uint8_t width);
    uint8_t getWidth();

    void setHeight(uint8_t height);
    uint8_t getHeight();

    void setOrientation(uint8_t orientation);
    uint8_t getOrientation();

    void setDirection(uint8_t direction);
    uint8_t getDirection();

    void setMin(uint8_t min);
    uint8_t getMin();

    void setMax(uint8_t max);
    uint8_t getMax();

    void setValue(uint8_t value);
    uint8_t getValue();

    bool isUpdated();
    void hasRendered();

private:
    uint8_t x = 0, y = 0, width = 50, height = 10;
    uint8_t min = 0, max = 100, value = 0;
    uint8_t orientation = PLANET096_PROGRESS_BAR_HORIZONTAL,
        direction = PLANET096_PROGRESS_BAR_LEFT_RIGHT;
    bool has_rendered = false,
        is_updated = true;

    Planet096Scene *scene;

    void invalidate();
};

#endif