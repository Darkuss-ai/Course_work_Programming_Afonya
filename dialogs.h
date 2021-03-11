//
// Created by Sergey on 05.10.2020.
//

#ifndef KURSACH_DIALOGS_H
#define KURSACH_DIALOGS_H

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace sf;



class Strinit{
public:
    Strinit() = default;

    static String strinit(const std::string& whatdialog);

    static void dialogsofend(int number, Text& txt, int& mark);


};







#endif //KURSACH_DIALOGS_H
