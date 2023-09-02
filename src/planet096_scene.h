#ifndef PLANET096_SCENE_H
#define PLANET096_SCENE_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <planet096_ui_text.h>
#include <planet096_widget.h>

#define PLANET096_APPBAR_NONE         0x00
#define PLANET096_APPBAR_NORMAL       0x01
#define PLANET096_APPBAR_LINE_BORDER  0x02

#define PLANET096_APPBAR_ALIGN_LEFT   0x00
#define PLANET096_APPBAR_ALIGN_CENTER 0x01
#define PLANET096_APPBAR_ALIGN_RIGHT  0x02

#define PLANET096_SCENE_MENU_NONE     0x00
#define PLANET096_SCENE_MENU_PLAIN    0x01
#define PLANET096_SCENE_MENU_BUTTONS  0x02
#define PLANET096_SCENE_MENU_DIVIDER  0x03
#define PLANET096_SCENE_MENU_HL_ONLY  0x04

class Planet096Scene {
public:
    Planet096Scene();
    Planet096Scene(char* title);

    Adafruit_SSD1306* getDisplay();

    void setAppBarTitle(char* title);
    const char* getAppBarTitle();

    void setAppBarStyle(uint8_t appbar_style);
    uint8_t getAppbarStyle();

    void setAppBarAlignment(uint8_t appbar_align);
    uint8_t getAppBarAlignment();

    void setSceneMenu(
        char* menu_left,
        char* menu_right
    );

    void setSceneMenu(
        char* menu_left,
        char* menu_center,
        char* menu_right
    );

    const char** getSceneMenu();

    void setSceneMenuStyle(uint8_t scene_menu_style);
    uint8_t getSceneMenuStyle();

    void setMainWidget(Planet096Widget main_widget);
    Planet096Widget getMainWidget();

    void render();
    void renderWidget();

private:
    char *title = "_";
    char *menu_left = NULL,
        *menu_center = NULL,
        *menu_right = NULL;

    uint8_t appbar_style = PLANET096_APPBAR_NONE;
    uint8_t appbar_align = PLANET096_APPBAR_ALIGN_CENTER;
    uint8_t scene_menu_style = PLANET096_SCENE_MENU_NONE;

    bool has_rendered = false;
    Planet096Widget main_widget;
    Adafruit_SSD1306 display;

    void renderAppBar();
    void renderMenu();

    void renderTextWidget(Planet096Text* textUI);
};

#endif