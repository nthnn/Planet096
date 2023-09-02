#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#include <planet096_app.h>
#include <planet096_scene.h>
#include <planet096_ui_text.h>

Planet096Scene::Planet096Scene():
    display(Planet096App::getI2CScreen()) { }

Planet096Scene::Planet096Scene(char* title):
    title(title),
    display(Planet096App::getI2CScreen()) { }

Adafruit_SSD1306* Planet096Scene::getDisplay() {
    return &this->display;
}

void Planet096Scene::setAppBarTitle(char* title) {
    this->title = title;

    if(this->has_rendered)
        this->renderAppBar();
}

const char* Planet096Scene::getAppBarTitle() {
    return this->title;
}

void Planet096Scene::setAppBarStyle(uint8_t appbar_style) {
    this->appbar_style = appbar_style;

    if(this->has_rendered)
        this->renderAppBar();
}

uint8_t Planet096Scene::getAppbarStyle() {
    return this->appbar_style;
}

void Planet096Scene::setAppBarAlignment(uint8_t appbar_align) {
    this->appbar_align = appbar_align;

    if(this->has_rendered)
        this->renderAppBar();
}

uint8_t Planet096Scene::getAppBarAlignment() {
    return this->appbar_align;
}

void Planet096Scene::setSceneMenu(
    char* menu_left,
    char* menu_right
) {
    this->menu_left = menu_left;
    this->menu_right = menu_right;

    if(this->has_rendered) {
        this->menu_center = NULL;
        this->renderMenu();
    }
}

void Planet096Scene::setSceneMenu(
    char* menu_left,
    char* menu_center,
    char* menu_right
) {
    this->menu_left = menu_left;
    this->menu_right = menu_right;
    this->menu_center = menu_center;

    if(this->has_rendered)
        this->renderMenu();
}

const char** Planet096Scene::getSceneMenu() {
    const char* menus[this->menu_center != "_" ? 3 : 2];
    int idx = 0;

    if(this->menu_left != NULL)
        menus[idx++] = this->menu_left;

    if(this->menu_center != NULL)
        menus[idx++] = this->menu_center;

    if(this->menu_right != NULL)
        menus[idx] = this->menu_right;

    return menus;
}

void Planet096Scene::setSceneMenuStyle(uint8_t scene_menu_style) {
    this->scene_menu_style = scene_menu_style;

    if(this->has_rendered)
        this->renderMenu();
}

uint8_t Planet096Scene::getSceneMenuStyle() {
    return this->scene_menu_style;
}

void Planet096Scene::setMainWidget(Planet096Widget main_widget) {
    this->main_widget = main_widget;

    if(this->has_rendered)
        this->renderWidget();
}

Planet096Widget Planet096Scene::getMainWidget() {
    return this->main_widget;
}

void Planet096Scene::renderAppBar() {
    if(this->appbar_style == PLANET096_APPBAR_NONE)
        return;

    if(this->has_rendered)
        this->display.fillRect(0, 0, 128, 9, BLACK);
    this->display.setTextSize(1);

    int title_length = strlen(this->title);
    switch(this->appbar_align) {
        case PLANET096_APPBAR_ALIGN_CENTER:
            this->display.setCursor(59 - ((title_length * 5) / 2), 1);
            break;
        case PLANET096_APPBAR_ALIGN_LEFT:
            this->display.setCursor(4, 1);
            break;
        case PLANET096_APPBAR_ALIGN_RIGHT:
            this->display.setCursor((124 - title_length) - (title_length * 5), 1);
            break;
    }

    switch(this->appbar_style) {
        case PLANET096_APPBAR_NORMAL:
            this->display.fillRect(0, 0, 128, 9, WHITE);
            this->display.setTextColor(BLACK, WHITE);

            break;

        case PLANET096_APPBAR_LINE_BORDER:
            this->display.drawLine(0, 10, 128, 9, WHITE);
            this->display.setTextColor(WHITE, BLACK);

            break;
    }

    this->display.println(this->title);
    this->display.display();
}

void Planet096Scene::renderMenu() {
    if(this->scene_menu_style == PLANET096_SCENE_MENU_NONE)
        return;

    if(this->has_rendered)
        this->display.fillRect(0, 46, 128, 18, BLACK);

    this->display.setTextSize(1);
    this->display.setTextColor(WHITE);

    switch(this->scene_menu_style) {
        case PLANET096_SCENE_MENU_BUTTONS:
            if(this->menu_center != NULL) {
                this->display.drawRect(4, 52, 38, 12, WHITE);
                this->display.setCursor(6 + ((32 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.drawRect(46, 52, 38, 12, WHITE);
                this->display.setCursor(48 + ((32 - (strlen(this->menu_center) * 5)) / 2), 54);
                this->display.println(this->menu_center);

                this->display.drawRect(88, 52, 38, 12, WHITE);
                this->display.setCursor(90 + ((32 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }
            else {
                this->display.drawRect(4, 52, 58, 12, WHITE);
                this->display.setCursor(6 + ((50 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.drawRect(66, 52, 58, 12, WHITE);
                this->display.setCursor(68 + ((50 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }

            break;

        case PLANET096_SCENE_MENU_DIVIDER:
            if(this->menu_center != NULL) {
                this->display.drawLine(0, 52, 128, 52, WHITE);
                this->display.drawLine(43, 52, 43, 64, WHITE);
                this->display.drawLine(85, 52, 85, 64, WHITE);

                this->display.setCursor(6 + ((32 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.setCursor(48 + ((32 - (strlen(this->menu_center) * 5)) / 2), 54);
                this->display.println(this->menu_center);

                this->display.setCursor(90 + ((32 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }
            else {
                this->display.drawLine(0, 52, 128, 52, WHITE);
                this->display.drawLine(64, 52, 64, 64, WHITE);

                this->display.setCursor(6 + ((50 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.setCursor(70 + ((50 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }

            break;

        case PLANET096_SCENE_MENU_HL_ONLY:
            this->display.drawLine(0, 52, 128, 52, WHITE);

        case PLANET096_SCENE_MENU_PLAIN:
            if(this->menu_center != NULL) {
                this->display.setCursor(6 + ((32 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.setCursor(48 + ((32 - (strlen(this->menu_center) * 5)) / 2), 54);
                this->display.println(this->menu_center);

                this->display.setCursor(90 + ((32 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }
            else {
                this->display.setCursor(6 + ((50 - (strlen(this->menu_left) * 5)) / 2), 54);
                this->display.println(this->menu_left);

                this->display.setCursor(70 + ((50 - (strlen(this->menu_right) * 5)) / 2), 54);
                this->display.println(this->menu_right);
            }

            break;
    }

    this->display.display();
}

void Planet096Scene::renderWidget() {
    if(this->main_widget.widget_type == PLANET096_WUI_NONE)
        return;

    if(this->appbar_style == PLANET096_APPBAR_NONE &&
        this->scene_menu_style == PLANET096_SCENE_MENU_NONE)
        this->display.fillRect(0, 0, 128, 64, BLACK);
    else if(this->appbar_style != PLANET096_APPBAR_NONE &&
        this->scene_menu_style == PLANET096_SCENE_MENU_NONE)
        this->display.fillRect(0, 10, 128, 54, BLACK);
    else if(this->appbar_style == PLANET096_APPBAR_NONE &&
        this->scene_menu_style != PLANET096_SCENE_MENU_NONE)
        this->display.fillRect(0, 0, 128, 52, BLACK);
    else this->display.fillRect(0, 10, 128, 42, BLACK);

    if(this->main_widget.widget_type == PLANET096_WUI_TEXT)
        this->renderTextWidget(this->main_widget.text_ui);
}

void Planet096Scene::render() {
    this->display.clearDisplay();
 
    this->renderAppBar();
    this->renderWidget();
    this->renderMenu();
 
    this->has_rendered = true;
}

void Planet096Scene::renderTextWidget(Planet096Text* textUI) {
    if(!textUI->isVisible())
        return;

    this->display.setTextSize(textUI->getTextSize());
    this->display.setTextColor(WHITE);
    this->display.setCursor(textUI->getX(), textUI->getY());
    this->display.println(textUI->getText());
    this->display.display();

    textUI->hasRendered();
}