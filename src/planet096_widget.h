#ifndef PLANET096_WIDGET_H
#define PLANET096_WIDGET_H

#include <planet096_ui_progress_bar.h>
#include <planet096_ui_scrollable_text.h>
#include <planet096_ui_text.h>

typedef struct _Planet096Widget {
    Planet096ProgressBar* progress_bar_ui;
    Planet096ScrollableText* scrollable_text_ui;
    Planet096Text* text_ui;
} Planet096Widget;

static Planet096Widget createWidgets() {
    Planet096Widget widget;
    widget.progress_bar_ui = nullptr;
    widget.scrollable_text_ui = nullptr;
    widget.text_ui = nullptr;

    return widget;
}

static Planet096Widget createWidget(Planet096Text* textUI) {
    Planet096Widget widget;
    widget.progress_bar_ui = nullptr;
    widget.scrollable_text_ui = nullptr;
    widget.text_ui = textUI;

    return widget;
}

static Planet096Widget createWidget(Planet096ScrollableText* scrollableTextUI) {
    Planet096Widget widget;
    widget.progress_bar_ui = nullptr;
    widget.scrollable_text_ui = scrollableTextUI;
    widget.text_ui = nullptr;

    return widget;
}

static Planet096Widget createWidget(Planet096ProgressBar* progressBarUI) {
    Planet096Widget widget;
    widget.progress_bar_ui = progressBarUI;
    widget.scrollable_text_ui = nullptr;
    widget.text_ui = nullptr;

    return widget;
}

#endif