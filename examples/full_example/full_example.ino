#include <planet096.h>

void setup() {
    auto scene = Planet096Scene("Hello");
    scene.setAppBarAlignment(APPBAR_ALIGN_CENTER);
    scene.setAppBarStyle(APPBAR_NORMAL);

    Planet096App::start(scene);
}

void loop() { }