#include <planet096.h>
#include <PortaMob.h>

void app() {
    pinMode(PORTAMOB_KEY_2, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_8, INPUT_PULLUP);

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
        if(digitalRead(PORTAMOB_KEY_8) == LOW) {
            scrollableText.scrollDown();
            delay(1000);
        }
        else if (digitalRead(PORTAMOB_KEY_2) == LOW) {
            scrollableText.scrollUp();
            delay(500);
        }
}