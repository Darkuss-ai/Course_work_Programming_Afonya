//
// Created by Sergey on 27.10.2020.
//

#ifndef KURSACH_HERO_H
#define KURSACH_HERO_H
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include "level.h"


using namespace sf;

class Entity {
public:
    std::vector<Object> obj;//вектор объектов карты
    float dx, dy, x, y, speed, time;
    int w,h,health, movetrigger;
    bool life, isMove, trigger;
    Texture texture;
    Sprite sprite;
    String name;
    Sound step, stepwithout;
    Vector2i pixelPos;
    Vector2f pos;




    Entity(Image &image, const String& Name, float X, float Y, int W, int H, Sound& stepshoes, Sound& stepbosoy);

    FloatRect getRect() const;
};
////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player : public Entity {
public:
    enum { left, right, up, down, stay, angle1, angle2, angle3, angle4} state;

    Player(Image &image, const String& Name, Level &lev, float X, float Y, int W, int H, Sound& stepshoes, Sound& stepbosoy);


    void control();


    void checkCollisionWithMap(float Dx, float Dy);


    void update(float time);
};




#endif //KURSACH_HERO_H
