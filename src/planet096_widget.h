#ifndef PLANET096_WIDGET_H
#define PLANET096_WIDGET_H

#include <Adafruit_SSD1306.h>
#include <planet096_scene.h>

class Planet096Widget {
public:
    virtual void render(Planet096Scene &scene) const = 0;

protected:
    virtual void refresh() const = 0;

private:
    uint8_t x, y;
    uint8_t width, height;
};

#endif