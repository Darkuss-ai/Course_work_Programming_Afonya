#ifndef KURSACH_VIEW_H
#define KURSACH_VIEW_H


#include <SFML/Graphics.hpp>
using namespace sf;


class ViewChar {
public:

    ViewChar() = default;

    static void setPlayerCoordinateForView(float x, float y);
};

#endif

