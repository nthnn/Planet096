#ifndef PLANET096_UI_IMAGE_H
#define PLANET096_UI_IMAGE_H

#include <Arduino.h>
#include <planet096_bitmap.h>
#include <planet096_colors.h>
#include <planet096_scene.h>

class Planet096Scene;

class Planet096Image {
public:
    Planet096Image();
    Planet096Image(Planet096Scene *scene);
    Planet096Image(Planet096Scene *scene, Planet096Bitmap bitmap);

    void setX(uint8_t x);
    uint8_t getX();

    void setY(uint8_t y);
    uint8_t getY();

    void setColor(Planet096Color color);
    uint8_t getColor();

    void setBitmap(Planet096Bitmap bitmap);
    Planet096Bitmap getBitmap();

    bool isUpdated();
    void hasRendered();

private:
    uint8_t x = 0, y = 0;
    Planet096Color color = PLANET096_WHITE;
    bool has_rendered = false,
        is_updated = true;

    Planet096Bitmap bitmap;
    Planet096Scene *scene;

    void invalidate();
};

#endif