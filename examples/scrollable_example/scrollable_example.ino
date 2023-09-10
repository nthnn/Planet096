#include <planet096.h>
#include <PortaMob.h>

void app() {
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);

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
        if(digitalRead(2) == LOW) {
            scrollableText.scrollDown();
            delay(1000);
        }
        else if (digitalRead(3) == LOW) {
            scrollableText.scrollUp();
            delay(500);
        }
}