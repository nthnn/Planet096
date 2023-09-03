#include <planet096.h>

void app() {
    Planet096Scene scene("Example");
    scene.setAppBarAlignment(PLANET096_APPBAR_ALIGN_CENTER);
    scene.setAppBarStyle(PLANET096_APPBAR_NORMAL);

    scene.setSceneMenuStyle(PLANET096_SCENE_MENU_BUTTONS);
    scene.setSceneMenu("Back", "Set", "Ok");

    Planet096Text text(&scene, "Hello, world!");
    text.setLocation(26, 14);

    scene.setMainWidget(createWidget(&text));
    Planet096App::start(scene);
}