#include <planet096.h>

void setup() {
    Planet096Scene scene("Hello");
    scene.setAppBarAlignment(P96_APPBAR_ALIGN_CENTER);
    scene.setAppBarStyle(P96_APPBAR_NORMAL);
    scene.setSceneMenu("Back", "Set", "Ok");

    Planet096App::start(scene);
}

void loop() { }