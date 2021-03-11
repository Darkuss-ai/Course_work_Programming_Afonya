//
// Created by Sergey on 21.10.2020.
//

#ifndef KURSACH_DIALOGINTERACTION_H
#define KURSACH_DIALOGINTERACTION_H

#include "SFML/Graphics.hpp"
#include "level.h"


using namespace sf;

class Dialogs{
public:
    Dialogs() = default;

    static void Change(int& trigger, bool& ptrigger, int& count, String& str, Text& text);

    static void DialogFunc(String& save, String& str, int &count, Text& text, int &trigger, bool &ptrigger, String& what, Level& lvl);
};

#endif //KURSACH_DIALOGINTERACTION_H
