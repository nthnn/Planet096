#ifndef PLANET096_WIDGET_H
#define PLANET096_WIDGET_H

#include <planet096_ui_text.h>

#define PLANET096_WUI_NONE 0x00
#define PLANET096_WUI_TEXT 0x01

struct Planet096Widget {
    uint8_t widget_type;
    Planet096Text* text_ui;

    Planet096Widget() {
        widget_type = PLANET096_WUI_NONE;
    }

    Planet096Widget(uint8_t wtype) {
        widget_type = wtype;
    }
};

static struct Planet096Widget createWidget(Planet096Text* textUI) {
    struct Planet096Widget widget(PLANET096_WUI_TEXT);
    widget.text_ui = textUI;

    return widget;
}

#endif