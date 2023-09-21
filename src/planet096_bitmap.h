#ifndef PLANET096_BITMAP_H
#define PLANET096_BITMAP_H

#include <Arduino.h>

typedef struct _Planet096Bitmap {
    uint8_t *bitmap;
    uint8_t width, height;
} Planet096Bitmap;

static inline Planet096Bitmap createBitmap(uint8_t *bitmap, uint8_t width, uint8_t height) {
    Planet096Bitmap bitmap_image;
    bitmap_image.bitmap = bitmap;
    bitmap_image.width = width;
    bitmap_image.height = height;

    return bitmap_image;
}

#endif