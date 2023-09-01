#ifndef PLANET096_UI_TEXT_H
#define PLANET096_UI_TEXT_H

#include <Arduino.h>
#include <planet096_widget.h>

class Planet096Text : public Planet096Widget {
public:
    Planet096Text(const char* text);

    void setText(const char* text);
    const char* getText();

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    virtual void render(Planet096Scene &scene) const override;

protected:
    virtual void refresh() const override;

private:
    char* text;
    int x, y;

    Planet096Scene &scene;
    mutable bool has_rendered = false;
};

#endif