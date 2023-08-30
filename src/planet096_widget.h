#ifndef PLANET096_WIDGET_H
#define PLANET096_WIDGET_H

class Planet096Widget {
public:
    virtual void render(Adafruit_SSD1306 display);

private:
    uint8_t x, y;
    uint8_t width, height;
};

#endif