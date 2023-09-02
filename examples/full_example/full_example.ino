#include <planet096.h>

void setup() {
    Planet096Scene scene("Example");
    scene.setAppBarAlignment(PLANET096_APPBAR_ALIGN_CENTER);
    scene.setAppBarStyle(PLANET096_APPBAR_NORMAL);
    scene.setSceneMenu("Back", "Set", "Ok");

    Planet096Text text(&scene, "Hello, world!");
    text.setX(26);
    text.setY(28);
    text.setTextSize(1);

    scene.setMainWidget(createWidget(&text));
    Planet096App::start(scene);
}

void loop() { }