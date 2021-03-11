//
// Created by Sergey on 04.11.2020.
//

#include "music.h"

Musician::Musician(){
    countmusic = 1;
}


float Musician::changemusic(sf::Music &music){
    countmusic++;
    float timemusic;
    if(music.openFromFile("music/test" + std::to_string(countmusic) + ".ogg")) {
        timemusic = music.getDuration().asSeconds();
        return timemusic;
    }
    else{
        return 0;
    }
}

