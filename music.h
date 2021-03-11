//
// Created by Sergey on 11.10.2020.
//

#ifndef KURSACH_MUSIC_H
#define KURSACH_MUSIC_H

#include <SFML/Audio.hpp>

class Musician{
public:
    int countmusic;

    Musician();

    float changemusic(sf::Music &music);
};

#endif //KURSACH_MUSIC_H
