//
// Created by Sergey on 04.11.2020.
//

#include "Game.h"
#include "dialoghelper.h"
#include "dialoginteraction.h"
#include "Menu.h"
#include "Hero.h"
#include "music.h"
#include "Guidance.h"
#include "dialogs.h"

extern View view;

extern float CurrentFrame;
extern int timer;

extern bool guidance;


extern sf::String who;


extern int gold;
extern int golddialog;

extern int notesroomdialog;
extern int notesroom;

extern int beardialog;
extern int bear;

extern int windowroomdialog;
extern int windowroom;

extern int sworddialog;
extern int sword;

extern int tablichkaroomdialog;
extern int tablichkaroom;

extern int mirrordialog;
extern int mirror;

extern int cabinetdialog;
extern int cabinet;

extern int tablichkakoridor;
extern int tablichkakoridordialog;

extern int skladkoridor;
extern int skladkoridordialog;

extern int Door;
extern int Doordialog;

extern int Badya;
extern int Badyadialog;

extern int ryukzak;
extern int ryukzakdialog;

extern int sundukkuxnya;
extern int sundukkuxnyadialog;

extern int brelokkuxnya;
extern int brelokkuxnyadialog;

extern int butilka;
extern int butilkadialog;

extern int sundukmasterskaya;
extern int sundukmasterskayadialog;

extern int portreti;
extern int portretidialog;

extern int lopata;
extern int lopatadialog;

extern int zapiskakamin;
extern int zapiskakamindialog ;

extern int armor;
extern int armordialog;

extern int zerno;
extern int zernodialog;


extern bool invent;
extern bool inventpickup;

extern int typeofshoes;
extern bool shoesininvent;


extern bool showarmory;

extern bool dialogview;


void Game::endofgame(RenderWindow& window, RectangleShape& fadeRect, Music& music){
    view.reset(FloatRect(0, 0, 1920, 1080));
    int number_of_str = 1;
    music.openFromFile("music/endmusic.ogg");
    music.setVolume(15);
    music.setLoop(true);
    music.play();
    float timemusic = music.getDuration().asSeconds();
    Image prepodimg, prepodradimg, prepodzolimg;
    prepodimg.loadFromFile("images/Prepod.png");
    prepodradimg.loadFromFile("images/Prepodrad.png");
    prepodzolimg.loadFromFile("images/Prepodzol.png");
    Texture prepodtex, prepodradtex, prepodzoltex;
    prepodtex.loadFromImage(prepodimg);
    prepodradtex.loadFromImage(prepodradimg);
    prepodzoltex.loadFromImage(prepodzolimg);
    Sprite prepod(prepodtex), prepodrad(prepodradtex), prepodzol(prepodzoltex);
    String firstanswer, secondanswer, thirdanswer;
    int markforexam = 2;
    bool isRight = false;
    prepod.setColor(Color::Transparent);
    prepodrad.setColor(Color::Transparent);
    prepodzol.setColor(Color::Transparent);
    prepod.setPosition(100, 210);
    prepodrad.setPosition(100, 210);
    prepodzol.setPosition(100, 210);
    window.setView(view);
    int timertitles = 0;
    float posytitles = 1100;
    Font font;
    font.loadFromFile("fonts/9041.ttf");
    Text txt(L"Вы успешно покинули своё жилище.", font, 33);
    Text txt2 = txt, txt3 = txt, txt4 = txt, txt5 = txt, txt6 = txt, txt7 = txt, txt8 = txt, txt9 = txt, txt10 = txt;
    txt.setPosition(100, 100);
    txt2.setPosition(100, 250);
    txt3.setPosition(100, 400);
    txt4.setPosition(100, 550);
    txt5.setPosition(100, 700);
    txt6.setPosition(100, 850);
    txt7.setPosition(100, 100);
    txt2.setFillColor(Color::Transparent);
    txt3.setFillColor(Color::Transparent);
    txt4.setFillColor(Color::Transparent);
    txt5.setFillColor(Color::Transparent);
    txt6.setFillColor(Color::Transparent);
    txt7.setFillColor(Color::Transparent);
    txt8.setFillColor(Color::Transparent);
    txt9.setFillColor(Color::Transparent);
    txt10.setFillColor(Color::Transparent);
    fadeRect.setFillColor(Color(0, 0, 0, 255));
    while(window.isOpen()) {

        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left) {
                    number_of_str++;
                }
            if(event.type == sf::Event::KeyPressed)
                if(event.key.code == Keyboard::Enter){
                    number_of_str++;
                }

            if(number_of_str  == 1){
                Strinit::dialogsofend(number_of_str, txt, markforexam);
            }

            else if(number_of_str == 2) {
                Strinit::dialogsofend(number_of_str, txt2, markforexam);
                txt2.setFillColor(Color::White);
            }
            else if(number_of_str == 3) {
                Strinit::dialogsofend(number_of_str, txt3, markforexam);
                txt3.setFillColor(Color::White);
            }
            else if(number_of_str == 4) {
                Strinit::dialogsofend(number_of_str, txt4, markforexam);
                txt4.setFillColor(Color::White);
            }
            else if(number_of_str == 5){
                Strinit::dialogsofend(number_of_str, txt5,markforexam);
                txt5.setFillColor(Color::White);
            }
            else if(number_of_str == 6){
                Strinit::dialogsofend(number_of_str, txt6, markforexam);
                txt6.setFillColor(Color::White);
            }
            else if(number_of_str == 7){
                Strinit::dialogsofend(number_of_str, txt7,markforexam);
                txt7.setFillColor(Color::White);
                txt.setFillColor(Color::Transparent);
                txt2.setFillColor(Color::Transparent);
                txt3.setFillColor(Color::Transparent);
                txt4.setFillColor(Color::Transparent);
                txt5.setFillColor(Color::Transparent);
                txt6.setFillColor(Color::Transparent);
            }
            else if(number_of_str == 8)
                prepod.setColor(Color(255, 255, 255, 255));
            else if(number_of_str == 9){
                Strinit::dialogsofend(number_of_str, txt, markforexam);
                txt.setPosition(800, 250);
                txt.setFillColor(Color(255, 255, 255, 255));
                txt.setFillColor(Color::Red);
            }
            else if(number_of_str == 10){
                txt3.setString(L"Введите ответ:");
                txt3.setPosition(800, 450);
                txt3.setFillColor(Color::Green);
                if(event.type == Event::TextEntered){
                    if(event.text.unicode < 128){
                        firstanswer += static_cast<char>(event.text.unicode);
                        txt2.setString(firstanswer);
                        txt2.setPosition(800, 500);
                        txt2.setFillColor(Color::Yellow);
                        std::cout << static_cast<std::string>(firstanswer) << std::endl;
                    }
                }
            }
            else if(number_of_str == 11){
                if(notesroomdialog != 0) {
                    if (static_cast<std::string>(firstanswer) == "static" && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                if(notesroomdialog == 0){
                    if (static_cast<std::string>(firstanswer) == "Class::met1()" && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                Strinit::dialogsofend(number_of_str, txt4, markforexam);
                txt4.setPosition(800, 600);

                txt4.setFillColor(Color(255, 255, 255, 255));
                txt4.setFillColor(Color::Red);
            }
            else if(number_of_str == 12){
                isRight = false;
                txt5.setString(L"Введите ответ:");
                txt5.setPosition(800, 700);
                txt5.setFillColor(Color::Green);
                if(event.type == Event::TextEntered){
                    if(event.text.unicode < 128){
                        secondanswer += static_cast<char>(event.text.unicode);
                        txt6.setString(secondanswer);
                        txt6.setPosition(800, 750);
                        txt6.setFillColor(Color::Yellow);
                        std::cout << static_cast<std::string>(secondanswer) << std::endl;
                    }
                }
            }
            else if(number_of_str == 13){
                if(notesroomdialog != 0) {
                    if (static_cast<std::string>(secondanswer) == "void" && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                if(notesroomdialog == 0){
                    if (static_cast<std::string>(secondanswer) == "virtual" && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                Strinit::dialogsofend(number_of_str, txt8, markforexam);
                txt8.setPosition(800, 800);
                txt8.setFillColor(Color(255, 255, 255, 255));
                txt8.setFillColor(Color::Red);
            }
            else if(number_of_str == 14){
                isRight = false;
                txt9.setString(L"Введите ответ:");
                txt9.setPosition(800, 900);
                txt9.setFillColor(Color::Green);
                if(event.type == Event::TextEntered){
                    if(event.text.unicode < 128){
                        thirdanswer += static_cast<char>(event.text.unicode);
                        txt10.setString(thirdanswer);
                        txt10.setPosition(800, 950);
                        txt10.setFillColor(Color::Yellow);
                        std::cout << static_cast<std::string>(thirdanswer) << std::endl;
                    }
                }
            }
            else if(number_of_str == 15){
                if(notesroomdialog != 0) {
                    if ((static_cast<std::string>(thirdanswer) == "python" || static_cast<std::string>(thirdanswer) == "Python" || static_cast<std::string>(thirdanswer) == "PYTHON") && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                if(notesroomdialog == 0){
                    if ((static_cast<std::string>(thirdanswer) == "iostream" || static_cast<std::string>(thirdanswer) == "<iostream>") && !isRight) {
                        markforexam++;
                        isRight = true;
                    }
                }
                txt2.setFillColor(Color::Transparent);
                txt3.setFillColor(Color::Transparent);
                txt4.setFillColor(Color::Transparent);
                txt5.setFillColor(Color::Transparent);
                txt6.setFillColor(Color::Transparent);
                txt7.setFillColor(Color::Transparent);
                txt8.setFillColor(Color::Transparent);
                txt9.setFillColor(Color::Transparent);
                txt10.setFillColor(Color::Transparent);
                prepod.setColor(Color::Transparent);
                if(markforexam == 2 || markforexam == 3){
                    prepodzol.setColor(Color(255, 255, 255, 255));
                    Strinit::dialogsofend(number_of_str, txt, markforexam);
                    txt.setPosition(100, 100);
                    txt.setFillColor(Color(255, 255, 255, 255));
                    txt.setFillColor(Color::Red);
                }
                else if(markforexam == 4 || markforexam == 5){
                    prepodrad.setColor(Color(255, 255, 255, 255));
                    Strinit::dialogsofend(number_of_str, txt, markforexam);
                    txt.setPosition(100, 100);
                    txt.setFillColor(Color(255, 255, 255, 255));
                    txt.setFillColor(Color::Red);
                }

            }
            else if(number_of_str == 16){
                Strinit::dialogsofend(number_of_str, txt2, markforexam);
                txt2.setFillColor(Color::White);
                txt2.setPosition(700, 250);
            }
            else if(number_of_str == 17){
                txt.setPosition(100, 250);
                prepodzol.setColor(Color::Transparent);
                prepodrad.setColor(Color::Transparent);
                txt2.setFillColor(Color::Transparent);
                Strinit::dialogsofend(number_of_str, txt, markforexam);
                music.openFromFile("music/titlesmusic.ogg");
                music.setVolume(25);
                music.play();

            }
            else if(number_of_str == 19)
                window.close();




        }
        if(number_of_str == 18){
            txt.setFillColor(Color::Transparent);
            txt5.setPosition(50, posytitles);
            txt5.setScale(0.8, 0.8);
            txt5.setFillColor(Color::White);
            Strinit::dialogsofend(number_of_str, txt5, markforexam);
            timertitles++;
            if(timertitles % 4 == 0)
                posytitles--;
            if(posytitles < 100 && timertitles % 40 == 0)
                music.setVolume(music.getVolume() - 1);
            if(posytitles == -200)
                window.close();
        }


        window.draw(fadeRect);
        window.draw(txt);
        window.draw(txt2);
        window.draw(txt3);
        window.draw(txt4);
        window.draw(txt5);
        window.draw(txt6);
        window.draw(txt7);
        window.draw(txt8);
        window.draw(txt9);
        window.draw(txt10);
        window.draw(prepod);
        window.draw(prepodrad);
        window.draw(prepodzol);
        window.display();
    }
}

void Game::mouseposition(int &posx, int &posy){
    if(posx >= 1919)
        posx = 1919;
    if(posx <= 0)
        posx = 0;
    if(posy >= 1079)
        posy = 1079;
    if(posy <= 0)
        posy = 0;
}

void Game::gamestart(){
    RenderWindow window(VideoMode(1920, 1080), "LESKEK", Style::Fullscreen);
    Menu::menu(window);
    window.setMouseCursorVisible(false);
    Image kursorimage;
    kursorimage.loadFromFile("cursor/cursor.png");
    Texture kursortexture;
    kursortexture.loadFromImage(kursorimage);
    Sprite kursorsprite;
    kursorsprite.setTexture(kursortexture);
    kursorsprite.setPosition(view.getCenter().x, view.getCenter().y);
    kursorsprite.setColor(Color(100, 100, 0, 255));

    Music music;

    music.openFromFile("music/test.ogg");
    music.setVolume(20);
    float timemusic = music.getDuration().asSeconds();
    music.play();

    SoundBuffer dialogBuffer, soundstepbuffer, stepwithoutbuffer;
    dialogBuffer.loadFromFile("sounds/PWAA/song046.wav");
    soundstepbuffer.loadFromFile("sounds/polxodba.ogg");
    stepwithoutbuffer.loadFromFile("sounds/polxodbabosoy.ogg");
    Sound dialogsound(dialogBuffer), stepsound(soundstepbuffer), stepbosoysound(stepwithoutbuffer);



    view.reset(FloatRect(0, 0, 250, 200));

    Level lvl, lvlground;//создали экземпляр класса уровень
    lvlground.LoadFromFile("map/lvl1groundtmx.tmx");
    lvl.LoadFromFile("map/lvl1.tmx");//загрузили в него карту, внутри класса с помощью методов он ее обработает.
    Font font;
    font.loadFromFile("fonts/9041.ttf");
    Font fontname;
    fontname.loadFromFile("fonts/gothic.ttf");
    Font naruto;
    naruto.loadFromFile("fonts/naruto.ttf");
    Text text("", font, 9);
    Text name("", fontname, 8);
    text.setFillColor(Color::Yellow);
    text.setStyle(Text::Bold);
    name.setStyle(Text::Bold);

    Text noryukzak(L"Вы не можете подобрать этот предмет.\n             Вам нужен рюкзак.", font, 10);
    noryukzak.setStyle(Text::Bold);
    bool ifryukzak = false;
    int ifryukzakcolor = 255;


    Text firstframe("", font, 9);
    Text secondframe("", font, 9);
    firstframe.setFillColor(Color::Yellow);
    secondframe.setFillColor(Color::Yellow);
    firstframe.setStyle(Text::Bold);
    secondframe.setStyle(Text::Bold);
    Image dialogframe;
    dialogframe.loadFromFile("images/ramkadialog.png");
    Texture dialogframetex;
    dialogframetex.loadFromImage(dialogframe);
    Sprite dialogframesprite;
    dialogframesprite.setTexture(dialogframetex);
    dialogframesprite.setTextureRect(IntRect(0, 0, 158, 31));  //приведение типов, размеры картинки исходные
    dialogframesprite.setPosition(view.getCenter().x, view.getCenter().y);
    dialogframesprite.setColor(Color(255, 255, 255, 170));
    Sprite dialogframesprite2 = dialogframesprite;


    Text firstmenuframe("", fontname, 10);
    Text secondmenuframe("", fontname, 10);
    firstmenuframe.setStyle(Text::Bold);
    secondmenuframe.setStyle(Text::Bold);

    Text daleko(L"Слишком далеко", font, 10);
    int dalekocolor = 255;
    daleko.setStyle(Text::Bold);

    Text opisanie(L"", font, 12);
    Text opisanie_of_item(L"", font, 10);
    Text canwear(L"(Можно надеть)", font, 6);
    canwear.setStyle(Text::Bold);
    canwear.setFillColor(Color::Green);
    opisanie_of_item.setStyle(Text::Bold);
    opisanie.setStyle(Text::Bold);
    opisanie.setFillColor(Color::Yellow);
    Image opisanieimg;
    opisanieimg.loadFromFile("images/Testopisanie.png");
    Texture opisanietex;
    opisanietex.loadFromImage(opisanieimg);
    Sprite opisaniesprite;
    opisaniesprite.setTexture(opisanietex);




    Image heroImage;
    heroImage.loadFromFile("images/herotest.png");

    Object player=lvl.GetObject("player");//объект игрока на нашей карте.задаем координаты игроку в начале при помощи него

    Player p(heroImage, "Player1", lvl, player.rect.left, player.rect.top, 32, 32, stepsound, stepbosoysound);//передаем координаты прямоугольника player из карты в координаты нашего игрока

    Clock clock;
    Image quest_image;
    quest_image.loadFromFile("images/ramkafinal.png");
    Texture quest_texture;
    quest_texture.loadFromImage(quest_image);
    Sprite boxofwords;
    boxofwords.setTexture(quest_texture);
    boxofwords.setTextureRect(IntRect(0, 0, 250, 50));  //приведение типов, размеры картинки исходные
    boxofwords.setPosition(view.getCenter().x - 260, view.getCenter().y + 240);
    boxofwords.setColor(Color(255, 255, 255, 170));
    text.setPosition(view.getCenter().x, view.getCenter().y);
    name.setPosition(view.getCenter().x, view.getCenter().y);



    Image menuframe;
    menuframe.loadFromFile("images/menu.png");
    Texture menuframetex;
    menuframetex.loadFromImage(menuframe);
    Sprite menuframesprite;
    menuframesprite.setTexture(menuframetex);
    menuframesprite.setTextureRect(IntRect(0, 0, 72, 38));  //приведение типов, размеры картинки исходные
    menuframesprite.setPosition(view.getCenter().x, view.getCenter().y);
    menuframesprite.setColor(Color(255, 255, 255));

    Sprite menuframesprite2 = menuframesprite;


    Image inventimage, armoryimg;
    inventimage.loadFromFile("images/inventory.png");
    armoryimg.loadFromFile("images/inventory/armory.png");
    Texture inventtexture, armorytex;
    inventtexture.loadFromImage(inventimage);
    armorytex.loadFromImage(armoryimg);
    Sprite inventorysprite, armorplate;
    armorplate.setTexture(armorytex);
    armorplate.setTextureRect(IntRect(0, 0, 50, 32));
    inventorysprite.setTexture(inventtexture);
    inventorysprite.setTextureRect(IntRect(0, 0, 118, 84));  //приведение типов, размеры картинки исходные

    Image items_in_inventory, shoesimg;
    items_in_inventory.loadFromFile("images/inventory/inventit.png");
    shoesimg.loadFromFile("images/inventory/shoes.png");
    Texture shoestex;
    shoestex.loadFromImage(shoesimg);
    Texture items_in_inventorytex;
    items_in_inventorytex.loadFromImage(items_in_inventory);
    Sprite shovelsprite, goldsprite, terversprite, zapisisprite, breloksprite, krossovki;
    shovelsprite.setTexture(items_in_inventorytex);
    goldsprite.setTexture(items_in_inventorytex);
    terversprite.setTexture(items_in_inventorytex);
    zapisisprite.setTexture(items_in_inventorytex);
    breloksprite.setTexture(items_in_inventorytex);
    krossovki.setTexture(shoestex);
    shovelsprite.setTextureRect(IntRect(46, 0, 19, 20));
    goldsprite.setTextureRect(IntRect(23, 0, 19, 20));
    terversprite.setTextureRect(IntRect(65, 0, 19, 20));
    zapisisprite.setTextureRect(IntRect(84, 0, 19, 20));
    breloksprite.setTextureRect(IntRect(0, 0, 19, 20));
    krossovki.setTextureRect(IntRect(0, 0, 19, 16));

    Image chararmorimg;
    chararmorimg.loadFromFile("images/inventory/chararmory.png");
    Texture chararmorytex;
    chararmorytex.loadFromImage(chararmorimg);
    Sprite heroes3armor;
    heroes3armor.setTexture(chararmorytex);



    Vector2f size = {1920, 1080};
    RectangleShape fadeRect;
    RectangleShape forestRect;
    fadeRect.setFillColor(Color::Black);
    forestRect.setFillColor(Color(0, 0, 0, 220));
    forestRect.setSize(size);
    fadeRect.setSize(size);
    int alpha = 1;
    bool isFading = false;
    int levelofdarkness = 220;
    int directionoflight = 0;
    int timeroflight = 220;

    bool isMove = false;
    float dX = 0, dY = 0;

    bool if_shoes_equip = false;

    bool koncovka = false;

    String mystring = L"init";
    String save;
    String what;
    int count = 0;
    int trigger = 0;
    int checkguidance = 0;

    int menutrigger = 0;
    float volume = 20;
    bool dalekotrigger = false;
    Musician mus;


    window.setFramerateLimit(144);
    while (window.isOpen())
    {
        if(who == L"Юрий") {
            name.setFillColor(Color(100, 100, 255));
        }
        else if(who == L"Чел"){
            name.setFillColor(Color(255, 255, 255));
        }


        float time = clock.getElapsedTime().asMicroseconds();

        if((float)timer / 144 >= timemusic && timemusic != 0) {
            timemusic = mus.changemusic(music);
            music.play();
            timer = 0;
        }


        clock.restart();
        time = time / 800;
        p.time = time;
        timer += 1;
        timeroflight++;

        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        kursorsprite.setPosition(pos.x, pos.y);

        //std::cout << pos.x << " " << pos.y << std::endl;

        mouseposition(pixelPos.x, pixelPos.y);



        if(gold == 1 || notesroom == 1 || bear == 1 || windowroom == 1 || sword == 1 || tablichkaroom == 1 ||
           mirror == 1 || cabinet == 1 || tablichkakoridor == 1 || skladkoridor == 1 || Door == 1 || Badya == 1 ||
           ryukzak == 1 || sundukkuxnya == 1 || brelokkuxnya == 1 || butilka == 1 || sundukmasterskaya == 1 ||
           portreti == 1 || lopata == 1 || zapiskakamin == 1 || armor == 1 || zerno == 1){ //Алгоритм вывода текста по букве
            name.setString(who);
            if(((timer % 6) == 0) && (count != mystring.getSize())) {
                p.trigger = true;
                trigger = 1;
                save += mystring[count];
                count++;
                text.setString(save);
                if(count % 2 == 0)
                    dialogsound.play();
            }
        }

        boxofwords.setPosition(view.getCenter().x - 125, view.getCenter().y + 50);
        text.setPosition(view.getCenter().x - 121, view.getCenter().y + 65);
        name.setPosition(view.getCenter().x - 121, view.getCenter().y + 51);

        inventorysprite.setPosition(view.getCenter().x + 7, view.getCenter().y - 101);
        shovelsprite.setPosition(view.getCenter().x + 12, view.getCenter().y - 86);
        goldsprite.setPosition(view.getCenter().x + 36, view.getCenter().y - 86);
        terversprite.setPosition(view.getCenter().x + 57, view.getCenter().y - 81);
        zapisisprite.setPosition(view.getCenter().x + 80, view.getCenter().y - 80);
        breloksprite.setPosition(view.getCenter().x + 101, view.getCenter().y - 86);
        if(!if_shoes_equip)
            krossovki.setPosition(view.getCenter().x + 12, view.getCenter().y - 62);
        else
            krossovki.setPosition(view.getCenter().x - 47, view.getCenter().y + 69);

        opisanie.setPosition(view.getCenter().x + 50, view.getCenter().y - 55);
        opisanie_of_item.setPosition(view.getCenter().x + 50, view.getCenter().y - 35);
        opisaniesprite.setPosition(view.getCenter().x + 47, view.getCenter().y - 55);
        canwear.setPosition(view.getCenter().x + 49, view.getCenter().y - 40);

        armorplate.setPosition(view.getCenter().x - 125, view.getCenter().y - 100);
        heroes3armor.setPosition(view.getCenter().x - 118, view.getCenter().y - 40);



        dialogframesprite.setPosition(view.getCenter().x - 75, view.getCenter().y - 50);
        dialogframesprite2.setPosition(view.getCenter().x - 75, view.getCenter().y - 15);
        firstframe.setPosition(view.getCenter().x - 73, view.getCenter().y - 50);
        secondframe.setPosition(view.getCenter().x - 73, view.getCenter().y - 15);
        menuframesprite.setPosition(view.getCenter().x - 25, view.getCenter().y - 70);
        menuframesprite2.setPosition(view.getCenter().x - 25, view.getCenter().y - 20);
        firstmenuframe.setPosition(view.getCenter().x - 18, view.getCenter().y - 65);
        secondmenuframe.setPosition(view.getCenter().x - 6, view.getCenter().y - 7);
        daleko.setPosition(view.getCenter().x - 30, view.getCenter().y - 30);
        noryukzak.setPosition(view.getCenter().x - 115, view.getCenter().y - 30);

        if(isFading){
            alpha++;
            if(alpha % 12 == 0)
                volume--;
            Color c = fadeRect.getFillColor();
            c.a = alpha;
            fadeRect.setFillColor(c);
            music.setVolume(volume);
            if(alpha == 255 && !koncovka){
                window.close();
            }
            else if(alpha == 255 && koncovka){
                alpha = 0;
                endofgame(window, fadeRect, music);
            }
        }


//        if(timeroflight % 144 == 0){
//            if(levelofdarkness == 220)
//                directionoflight = -1;
//            else if(levelofdarkness == 0)
//                directionoflight = 1;
//
//            if(directionoflight == -1)
//                levelofdarkness--;
//            else if(directionoflight == 1)
//                levelofdarkness++;
//
//            forestRect.setFillColor(Color(0, 0, 0, levelofdarkness));
//        }


        if(timeroflight % 65 == 0 && levelofdarkness != 1){
            levelofdarkness--;
            forestRect.setFillColor(Color(0, 0, 0, levelofdarkness));
        }

        checkguidance = Guidance::GuidanceFunc(pos.x, pos.x + 3, pos.y, pos.y + 3);
        //std::cout << checkguidance << " ";
        if(checkguidance != 0){
            guidance = true;
            kursorsprite.setColor(Color(255, 255, 0, 255));
            kursorsprite.setScale(1.6, 1.6);
        }
        else{
            guidance = false;
            kursorsprite.setColor(Color(100, 100, 0, 255));
            kursorsprite.setScale(1., 1.);
        }


        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {


                    if (guidance && !Guidance::PlayerDistance(p.sprite.getPosition().x, p.sprite.getPosition().x,
                                                              p.sprite.getPosition().y, p.sprite.getPosition().y)) {
                        dalekotrigger = true;
                    } else if (guidance && Guidance::PlayerDistance(p.sprite.getPosition().x, p.sprite.getPosition().x,
                                                                    p.sprite.getPosition().y, p.sprite.getPosition().y)) {
                        DialogHelp::dialoghelper(checkguidance, what, trigger, ifryukzak);

                    }

                    if (armorplate.getGlobalBounds().contains(pos.x, pos.y)) {
                        showarmory = !showarmory;
                    }



                    else if(dialogframesprite.getGlobalBounds().contains(pos.x, pos.y)) {
                        if (dialogview) {
                            dialogview = false;
                            Doordialog = 10;
                        }
                    }

                    else if (dialogframesprite2.getGlobalBounds().contains(pos.x, pos.y)){
                        if (dialogview) {
                            dialogview = false;
                            Doordialog = 5;
                        }
                    }

                    if (menuframesprite.getGlobalBounds().contains(pos.x, pos.y)) {
                        if (menutrigger == 1) {
                            menutrigger = 0;
                            p.trigger = false;
                        }
                    }

                    if (menuframesprite2.getGlobalBounds().contains(pos.x, pos.y)) {
                        if (menutrigger == 1) {
                            isFading = true;

                        }
                    }

                    Dialogs::DialogFunc(save, mystring, count, text, trigger, p.trigger, what, lvl);

                }

                if (event.mouseButton.button == Mouse::Left)
                    if (krossovki.getGlobalBounds().contains(pos.x, pos.y)) {
                        dX = pos.x - krossovki.getPosition().x;
                        dY = pos.y - krossovki.getPosition().y;
                        isMove = true;
                    }
            }

            if(event.type == Event::MouseButtonReleased)
                if(event.mouseButton.button == Mouse::Left){
                    isMove = false;
                    if(krossovki.getGlobalBounds().contains(view.getCenter().x - 35, view.getCenter().y + 80)) {
                        if_shoes_equip = true;
                    }
                    else
                        krossovki.setPosition(view.getCenter().x + 12, view.getCenter().y - 62);
                }



            if(event.type == Event::KeyPressed)
                if(event.key.code == Keyboard::Tab)
                    if(menutrigger == 0) {
                        invent = !invent;
                        if(showarmory)
                            showarmory = false;
                    }

            if(event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    if (menutrigger == 0) {
                        menutrigger = 1;
                        p.trigger = true;
                    } else {
                        menutrigger = 0;
                        p.trigger = false;
                    }
                }

//                if (event.key.code == Keyboard::T) {
//                    if (p.movetrigger == 0)
//                        p.movetrigger = 1;
//                    else if (p.movetrigger == 1)
//                        p.movetrigger = 0;
//                }
            }

        }

        p.update(time);
        window.setView(view);
        window.clear(Color(77,83,140));


        lvlground.Draw(window);

        window.draw(p.sprite);

        lvl.Draw(window);
        window.draw(forestRect);


        if(showarmory){
            window.draw(heroes3armor);
            if(if_shoes_equip)
                window.draw(krossovki);
        }


        if(isMove){
            krossovki.setPosition(pos.x - dX, pos.y - dY);
            if(krossovki.getGlobalBounds().contains(view.getCenter().x - 35, view.getCenter().y + 80)) {
                if_shoes_equip = true;
                typeofshoes = 1;
            }
            else{
                if_shoes_equip = false;
                typeofshoes = 0;
            }

        }


        if(invent && inventpickup){
            window.draw(inventorysprite);
            window.draw(armorplate);
            if(golddialog != 0){
                window.draw(goldsprite);
                if(goldsprite.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Золото");
                    opisanie_of_item.setString(L"Редчайшее\nзолото\nпрямиком из\nглубоких\nшахт.");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                }
            }
            if(notesroomdialog != 0) {
                window.draw(terversprite);
                if(terversprite.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Домашка");
                    opisanie_of_item.setString(L"Домашнее\nзадание по\nТеории\nвероятностей.\nМожет,\nкому-нибудь\nможно его\nпродать...");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                }
            }
            if(brelokkuxnyadialog != 0){
                window.draw(breloksprite);
                if(breloksprite.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Кулон");
                    opisanie_of_item.setString(L"Мой кулон\nв виде\nпера. Я\nвсегда ношу\nего с собой.");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                }
            }
            if(zapiskakamindialog != 0){
                window.draw(zapisisprite);
                if(zapisisprite.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Записи");
                    opisanie_of_item.setString(L"Я не знаю\nчто это за\nпредмет. Я\nпока не при-\nдумал для\nнего назна-\nчения.");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                }
            }
            if(lopatadialog != 0){
                window.draw(shovelsprite);
                if(shovelsprite.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Лопата");
                    opisanie_of_item.setString(L"Обычная,\nничем не\nпримечатель-\nная лопата.\nМожет, приго-\nдится\nдля чего-\nнибудь в\nВузе.");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                }
            }
            if(shoesininvent){
                if(!if_shoes_equip)
                    window.draw(krossovki);
                if(krossovki.getGlobalBounds().contains(pos.x, pos.y)){
                    opisanie.setString(L"Кроссовки");
                    opisanie_of_item.setString(L"Кроссовки,\nкупленные в\nдешёвом ма-\nгазине. Если\nнадеты, то\nпри нажатии\nL.Shift вы\nсможете уве-\nличить ско-\nрость персо-\nнажа в 2\nраза.");
                    window.draw(opisaniesprite);
                    window.draw(opisanie_of_item);
                    window.draw(opisanie);
                    window.draw(canwear);
                }
            }
        }

        if(trigger == 1) {
            window.draw(boxofwords);
            window.draw(name);
            window.draw(text);

        }

        if(dalekotrigger)
            if(dalekocolor >= 0) {
                daleko.setFillColor(Color(255, 255, 255, dalekocolor));
                window.draw(daleko);
                dalekocolor--;
                if(dalekocolor == -1){
                    dalekocolor = 255;
                    dalekotrigger = false;
                }
            }


        if(ifryukzak){
            if(ifryukzakcolor >= 0){
                noryukzak.setFillColor(Color(255, 255, 255, ifryukzakcolor));
                window.draw(noryukzak);
                if(timer % 2)
                    ifryukzakcolor--;
                if(ifryukzakcolor == -1){
                    ifryukzakcolor = 255;
                    ifryukzak = false;
                }
            }

        }



        if(dialogview){
            p.trigger = true;
            window.draw(dialogframesprite);
            window.draw(dialogframesprite2);
            if(Doordialog > 0) {
                window.draw(dialogframesprite2);
                firstframe.setString(L"Выйти из дома.");
                secondframe.setString(L"Остаться.");
                window.draw(firstframe);
                window.draw(secondframe);
            }
        }

        if(menutrigger == 1) {
            window.draw(menuframesprite);
            window.draw(menuframesprite2);
            firstmenuframe.setString(L"Вернуться\n   в игру");
            secondmenuframe.setString(L"Выход");
            window.draw(firstmenuframe);
            window.draw(secondmenuframe);
            if(isFading) {
                window.draw(fadeRect);
                kursorsprite.setColor(Color::Transparent);
            }
        }

        if(Doordialog == 12 && Door == 0){
            isFading = true;
            koncovka = true;
            if(alpha != 0) {
                window.draw(fadeRect);
                kursorsprite.setColor(Color::Transparent);
                p.trigger = false;
            }
            else if(alpha == 0) {
                isFading = false;
                fadeRect.setFillColor(Color(0, 0, 0, 255));
                kursorsprite.setColor(Color::Transparent);
                p.trigger = false;
            }

        }

        window.draw(kursorsprite);
        window.display();
    }
}