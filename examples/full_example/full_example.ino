#include <planet096.h>

void setup() {
    Planet096Scene scene("Hello");
    scene.setAppBarAlignment(APPBAR_ALIGN_CENTER);
    scene.setAppBarStyle(APPBAR_NORMAL);
    scene.setSceneMenu("Back", "Set", "Ok");

    Planet096App::start(scene);
}

void loop() { }