//
// Created by Sergey on 01.11.2020.
//

#ifndef KURSACH_GAME_H
#define KURSACH_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace sf;
class Game{
public:
    Game() = default;

    static void endofgame(RenderWindow& window, RectangleShape& fadeRect, Music& music);

    static void mouseposition(int &posx, int &posy);

    static void gamestart();
};

#endif //KURSACH_GAME_H
