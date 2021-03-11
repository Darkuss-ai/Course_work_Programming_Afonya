//
// Created by Sergey on 04.11.2020.
//

#include "view.h"
sf::View view;

void ViewChar::setPlayerCoordinateForView(float x, float y) {
    float tempX = x;
    float tempY = y;

    if (x < 125) tempX = 125;
    if (x > 739) tempX = 739;
    if (y < 100) tempY = 100;
    if (y > 752) tempY = 752;

    view.setCenter(tempX, tempY);
}
