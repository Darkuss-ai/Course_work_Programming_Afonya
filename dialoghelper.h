//
// Created by Sergey on 07.10.2020.
//

#ifndef KURSACH_DIALOGHELPER_H
#define KURSACH_DIALOGHELPER_H

#include <SFML/Graphics.hpp>
using namespace sf;



class DialogHelp{
public:
    DialogHelp() = default;

    static void dialoghelper(int& checkguidance, String& what, int& trigger, bool& ifryukzak);

};





#endif //KURSACH_DIALOGHELPER_H
