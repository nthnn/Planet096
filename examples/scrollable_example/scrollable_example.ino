#include <planet096.h>

void app() {
    pinMode(4, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);

    Planet096Scene scene("Scrollable Text");
    scene.setAppBarAlignment(PLANET096_APPBAR_ALIGN_LEFT);
    scene.setAppBarStyle(PLANET096_APPBAR_NORMAL);
    scene.setSceneMenuStyle(PLANET096_SCENE_MENU_DIVIDER);
    scene.setSceneMenu("Back", "Set", "Ok");

    Planet096ScrollableText scrollableText(
        &scene,
        "This is an example of scrollable text in Planet096. Awesome, ain't it?"
    );
    scene.setMainWidget(createWidget(&scrollableText));

    Planet096App::start(scene);
    while(true)
        if(digitalRead(4) == LOW) {
            scrollableText.scrollDown();
            scene.render();

            delay(1000);
        }
        else if (digitalRead(2) == LOW) {
            scrollableText.scrollUp();
            scene.render();

            delay(500);
        }
}