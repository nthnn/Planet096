#include <planet096_scene.h>
#include <planet096_ui_image.h>

Planet096Image::Planet096Image():
    scene(nullptr) { }

Planet096Image::Planet096Image(Planet096Scene *scene):
    scene(scene) { }

Planet096Image::Planet096Image(Planet096Scene *scene, Planet096Bitmap bitmap):
    scene(scene),
    bitmap(bitmap) { }

void Planet096Image::setX(uint8_t x) {
    this->x = x;
    this->invalidate();
}

uint8_t Planet096Image::getX() {
    return this->x;
}

void Planet096Image::setY(uint8_t y) {
    this->y = y;
    this->invalidate();
}

uint8_t Planet096Image::getY() {
    return this->y;
}

void Planet096Image::setColor(Planet096Color color) {
    this->color = color;
    this->invalidate();
}

uint8_t Planet096Image::getColor() {
    return this->color;
}

void Planet096Image::setBitmap(Planet096Bitmap bitmap) {
    this->bitmap = bitmap;
    this->invalidate();
}

Planet096Bitmap Planet096Image::getBitmap() {
    return this->bitmap;
}

bool Planet096Image::isUpdated() {
    bool is_updated = this->is_updated;
    this->is_updated = !is_updated;

    return is_updated;
}

void Planet096Image::hasRendered() {
    this->has_rendered = true;
}

void Planet096Image::invalidate() {
    if(this->has_rendered)
        this->scene->renderWidget();
}