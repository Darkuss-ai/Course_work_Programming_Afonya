//
// Created by Sergey on 26.10.2020.
//

#ifndef KURSACH_GUIDANCE_H
#define KURSACH_GUIDANCE_H
#include "SFML/Graphics.hpp"

using namespace sf;

class Guidance{
public:
    Guidance() = default;

    static int GuidanceFunc(float posx1, float posx2, float posy1, float posy2);

    static bool PlayerDistance(float posx1, float posx2, float posy1, float posy2);

};






#endif //KURSACH_GUIDANCE_H
