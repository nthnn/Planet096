#ifndef PLANET096_SCENE_H
#define PLANET096_SCENE_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <List.hpp>

#include <planet096_app.h>

#define APPBAR_NONE         0x00
#define APPBAR_NORMAL       0x01
#define APPBAR_LINE_BORDER  0x02

#define APPBAR_ALIGN_LEFT   0x00
#define APPBAR_ALIGN_CENTER 0x01
#define APPBAR_ALIGN_RIGHT  0x02

#define SCENE_MENU_BUTTONS  0x00
#define SCENE_MENU_DIVIDER  0x01
#define SCENE_MENU_PLAIN    0x02

class Planet096Scene {
public:
    Planet096Scene();
    Planet096Scene(const char* title);

    void setAppBarTitle(const char* title);
    const char* getAppBarTitle();

    void setAppBarStyle(uint8_t appbar_style);
    uint8_t getAppbarStyle();

    void setAppBarAlignment(uint8_t appbar_align);
    uint8_t getAppBarAlignment();

    void setSceneMenu(
        const char* menu_left,
        const char* menu_right
    );

    void setSceneMenu(
        const char* menu_left,
        const char* menu_center,
        const char* menu_right
    );

    const char** getSceneMenu();

    void setSceneMenuStyle(uint8_t scene_menu_style);
    uint8_t getSceneMenuStyle();

    void render();

private:
    char *title = "_";
    char *menu_left = NULL,
        *menu_center = NULL,
        *menu_right = NULL;

    uint8_t appbar_style = APPBAR_NORMAL;
    uint8_t appbar_align = APPBAR_ALIGN_CENTER;
    uint8_t scene_menu_style = SCENE_MENU_BUTTONS;

    bool has_rendered = false;

    Adafruit_SSD1306 display;

    void renderAppBar();
    void renderMenu();
    void renderWidgets();
};

#endif