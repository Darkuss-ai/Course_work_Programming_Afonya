//
// Created by Sergey on 04.11.2020.
//

#include "Menu.h"

extern sf::View view;

void Menu::menu(RenderWindow & window) {
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    Font font;
    Music musicmenu;
    musicmenu.openFromFile("music/menumusic.ogg");
    musicmenu.setVolume(30);
    musicmenu.play();
    musicmenu.setLoop(true);
    font.loadFromFile("fonts/9041.ttf");
    Text start(L"Начать игру", font, 36);
    Text exit(L"Выход", font, 36);
    start.setStyle(Text::Bold);
    exit.setStyle(Text::Bold);
    menuTexture1.loadFromFile("images/menu/menubox.jpg");
    menuTexture3.loadFromFile("images/menu/menubox.jpg");
    aboutTexture.loadFromFile("images/herotest.png");
    menuBackground.loadFromFile("images/menu/oboi.jpg");
    Sprite menu1(menuTexture1), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
    bool isMenu = true;
    int menuNum = 0;
    menu1.setPosition(1500, 50);
    menu3.setPosition(1500, 450);
    menuBg.setPosition(0, 0);
    start.setPosition(1600, 140);
    exit.setPosition(1650, 540);
    window.setMouseCursorVisible(false);
    Image kursorimage;
    kursorimage.loadFromFile("cursor/cursor.png");
    Texture kursortexture;
    kursortexture.loadFromImage(kursorimage);
    Sprite kursorsprite;
    kursorsprite.setTexture(kursortexture);
    kursorsprite.setPosition(view.getCenter().x, view.getCenter().y);
    kursorsprite.setColor(Color(255, 255, 255, 255));
    kursorsprite.setScale(4, 4);


    while (isMenu)
    {
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        menu1.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        kursorsprite.setPosition(pos.x, pos.y);


        if (menu1.getGlobalBounds().contains(pos.x, pos.y)) {
            menu1.setColor(Color::Blue);
            menuNum = 1; }



        if (menu3.getGlobalBounds().contains(pos.x, pos.y)) {
            menu3.setColor(Color::Blue);
            menuNum = 3; }




        if (Mouse::isButtonPressed(Mouse::Left)){
            if (menuNum == 1)
                isMenu = false;

            if (menuNum == 3)  {
                window.close();
                isMenu = false;
            }

            Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }


        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu3);
        window.draw(start);
        window.draw(exit);
        window.draw(kursorsprite);

        window.display();
    }
}