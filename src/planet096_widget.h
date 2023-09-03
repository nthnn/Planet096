#ifndef PLANET096_WIDGET_H
#define PLANET096_WIDGET_H

#include <planet096_ui_scrollable_text.h>
#include <planet096_ui_text.h>

#define PLANET096_WUI_NONE              0x00
#define PLANET096_WUI_TEXT              0x01
#define PLANET096_WUI_SCROLLABLE_TEXT   0x02

typedef struct _Planet096Widget {
    uint8_t widget_type;
    Planet096ScrollableText* scrollable_text_ui;
    Planet096Text* text_ui;

    _Planet096Widget() {
        widget_type = PLANET096_WUI_NONE;
    }

    _Planet096Widget(uint8_t wtype) {
        widget_type = wtype;
    }
} Planet096Widget;

static Planet096Widget createWidget(Planet096Text* textUI) {
    Planet096Widget widget(PLANET096_WUI_TEXT);
    widget.text_ui = textUI;

    return widget;
}

static Planet096Widget createWidget(Planet096ScrollableText* scrollableTextUI) {
    Planet096Widget widget(PLANET096_WUI_SCROLLABLE_TEXT);
    widget.scrollable_text_ui = scrollableTextUI;

    return widget;
}

#endif