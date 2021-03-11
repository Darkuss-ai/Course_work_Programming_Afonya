//
// Created by Sergey on 04.11.2020.
#include "Hero.h"
#include "view.h"

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

Entity::Entity(Image &image, const String& Name, float X, float Y, int W, int H, Sound& stepshoes, Sound& stepbosoy){
x = X; y = Y; w = W; h = H; name = Name;
speed = 0.07; health = 100; dx = 0; dy = 0; time = 1; movetrigger = 0;
life = true; isMove = false; trigger = false;
texture.loadFromImage(image);
sprite.setTexture(texture);
sprite.setOrigin((float)w / 2, (float)h / 2);
step = stepshoes;
stepwithout = stepbosoy;
}

FloatRect Entity::getRect() const{
    return FloatRect(x, y, w, h);
}

Player::Player(Image &image, const String& Name, Level &lev, float X, float Y, int W, int H, Sound& stepshoes, Sound& stepbosoy) : Entity(image, Name, X, Y, W, H, stepshoes, stepbosoy){
obj = lev.GetAllObjects();//инициализируем.получаем все объекты для взаимодействия персонажа с картой
state = stay;
if (name == "Player1"){
sprite.setTextureRect(IntRect(0, 0, w, h));
}
}


void Player::control(){
    if (&Keyboard::isKeyPressed){
        if (movetrigger == 0) {
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                state = left;
                //speed = 0.07;
                //step.play();
                if ((int) time % 2 == 0) {
                    CurrentFrame += (float) 0.005 * time;
                    if (CurrentFrame > 3){
                        CurrentFrame -= 3;
                        if(typeofshoes == 1) {
                            step.play();
                        }
                        else if(typeofshoes == 0)
                            stepwithout.play();
                    }
                    if(typeofshoes == 0)
                        speed = 0.07;
                    else if(typeofshoes == 1) {
                        if (Keyboard::isKeyPressed(Keyboard::LShift))
                            speed = 0.14;
                        else
                            speed = 0.07;
                    }
                    sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
                }


            } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                state = right;
                //speed = 0.07;
                //step.play();
                if ((int) time % 2 == 0) {
                    CurrentFrame += (float) 0.005 * time;
                    if (CurrentFrame > 3){
                        CurrentFrame -= 3;
                        if(typeofshoes == 1) {
                            step.play();
                        }

                        else if(typeofshoes == 0)
                            stepwithout.play();
                    }
                    if(typeofshoes == 0)
                        speed = 0.07;
                    else if(typeofshoes == 1) {
                        if (Keyboard::isKeyPressed(Keyboard::LShift))
                            speed = 0.14;
                        else
                            speed = 0.07;
                    }
                    sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
                }

            } else if (Keyboard::isKeyPressed(Keyboard::W)) {
                state = up;
                //speed = 0.07;
                //step.play();
                if ((int) time % 2 == 0) {
                    CurrentFrame += (float) 0.005 * time;
                    if (CurrentFrame > 3){
                        CurrentFrame -= 3;
                        if(typeofshoes == 1) {
                            step.play();
                        }
                        else if(typeofshoes == 0)
                            stepwithout.play();
                    }
                    if(typeofshoes == 0)
                        speed = 0.07;
                    else if(typeofshoes == 1) {
                        if (Keyboard::isKeyPressed(Keyboard::LShift))
                            speed = 0.14;
                        else
                            speed = 0.07;
                    }
                    sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
                }
//

            } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                state = down;
                //speed = 0.07;
                //step.play();
                if ((int) time % 2 == 0) {
                    CurrentFrame += (float) 0.005 * time;
                    if (CurrentFrame > 3){
                        CurrentFrame -= 3;
                        if(typeofshoes == 1) {
                            step.play();
                        }
                        else if(typeofshoes == 0)
                            stepwithout.play();
                    }
                    if(typeofshoes == 0)
                        speed = 0.07;
                    else if(typeofshoes == 1) {
                        if (Keyboard::isKeyPressed(Keyboard::LShift))
                            speed = 0.14;
                        else
                            speed = 0.07;
                    }
                    sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
                }


            } else {
                state = stay;
                sprite.setTextureRect(IntRect(32, 0, 32, 32));
                step.stop();
                stepwithout.stop();
            }


            if (trigger) {
                state = stay;
                sprite.setTextureRect(IntRect(32, 0, 32, 32));

            }
        }
//            else if (movetrigger == 1) {
//                if (&Mouse::isButtonPressed)
//                    if (Mouse::isButtonPressed(Mouse::Left)) {
//                        speed = 0.07;
//                        //std::cout << x << " " << y << " " << posx << " " << posy << "\n";
//                        if(posx > x && posy > y){
//                            state = angle1;
//
//                            float xchange = posx - x;
//                            float ychange = posy - y;
//                            if(xchange > ychange){
//                                float matter = xchange / ychange;
//                                x++;
//                                y += 1 / matter;
//                            }
//                            else{
//                                float matter = ychange / xchange;
//                                x += 1 / matter;
//                                y++;
//                            }
//                        }
//                        else if(posx > x && posy < y){
//                            state = angle2;
//
//                            float xchange = posx - x;
//                            float ychange = y - posy;
//                            if(xchange > ychange){
//                                float matter = xchange / ychange;
//                                x++;
//                                y -= 1 / matter;
//                            }
//                            else{
//                                float matter = ychange / xchange;
//                                x += 1 / matter;
//                                y--;
//                            }
//                        }
//                        else if(posx < x && posy > y){
//                            state = angle3;
//
//                            float xchange = x - posx;
//                            float ychange = posy - y;
//                            if(xchange > ychange){
//                                float matter = xchange / ychange;
//                                x--;
//                                y += 1 / matter;
//                            }
//                            else{
//                                float matter = ychange / xchange;
//                                x -= 1 / matter;
//                                y++;
//                            }
//                        }
//                        else if(posx < x && posy < y){
//                            state = angle4;
//
//                            float xchange = x - posx;
//                            float ychange = y - posy;
//                            if(xchange > ychange){
//                                float matter = xchange / ychange;
//                                x--;
//                                y -= 1 / matter;
//                            }
//                            else{
//                                float matter = ychange / xchange;
//                                x -= 1 / matter;
//                                y--;
//                            }
//                        }
//                        else{
//                            state = stay;
//                        }
//                    }
//
//
//            }


    }
}

//    std::string WallDir(){
//        RectangleShape shape({5, 5});
//        shape.setPosition(x, y);
//
//
//    }



void Player::checkCollisionWithMap(float Dx, float Dy){
    for (int i = 0; i<obj.size(); i++)//проходимся по объектам
        if (getRect().intersects(obj[i].rect))//проверяем пересечение игрока с объектом
        {
            if (obj[i].name == "solid")//если встретили препятствие
            {
                if(movetrigger == 0) {
                    if (Dy > 0) {
                        y = obj[i].rect.top - (float) h;
                        dy = 0;
                    }
                    if (Dy < 0) {
                        y = obj[i].rect.top + obj[i].rect.height;
                        dy = 0;
                    }
                    if (Dx>0)	{ x = obj[i].rect.left - (float)w; }
                    if (Dx<0)	{ x = obj[i].rect.left + obj[i].rect.width; }
                }

//                    else if(movetrigger == 1){
//                        if(Dy > 0){
//                            y = obj[i].rect.top  - (float) h;
//                            dy = 0;
//                       }
//                       if(Dy < 0){
//                            y = obj[i].rect.top + obj[i].rect.height;
//                            dy = 0;
//                        }
//                        RectangleShape shape({32, 32});
//                        shape.setPosition(x, y - 47);
//                        if(shape.getGlobalBounds().intersects(obj[i].rect)){
//                            shape.setPosition()
//                            if(shape.getGlobalBounds().intersects(obj[i].rect)){
//
//                            }
//                       }
//
//
//
//                        if(Dy > 0 && Dx > 0 && walldir == "vert")
//                        if(Dy > 0 && Dx > 0 && walldir == "gor")
//                        if(Dy > 0 && Dx < 0 && walldir == "vert")
//                        if(Dy > 0 && Dx < 0 && walldir == "gor")
//                        if(Dy < 0 && Dx > 0 && walldir == "vert)
//                        if(Dy < 0 && Dx > 0 && walldir == "gor)
//                        if(Dy < 0 && Dx < 0 && walldir == "vert")
//                        if(Dy < 0 && Dx < 0 && walldir == "gor")
//
//                        if(Dx > 0 && Dy < 0){
//                            x += obj[i].rect.left - (float)w;
//                            y += obj[i].rect.top + obj[i].rect.height;
//                        }
//                        else if(Dx > 0 && Dy > 0){
//                            x = obj[i].rect.left - (float)w;
//                            y = obj[i].rect.top + obj[i].rect.height;
//                        }
//
//                        if(Dx < 0 && Dy != 0){
//                            x += obj[i].rect.left - (float)w;
//                            y += obj[i].rect.top + obj[i].rect.height;
//                        }
//                        else if(Dx < 0 && Dy == 0){
//                            x = obj[i].rect.left - (float)w;
//                            y = obj[i].rect.top + obj[i].rect.height;
//                        }
//                    }


            }

            //if(obj[i].name == "item"){
            //obj.clear(); //Delete all objects. Can use as cheatcode

            //}
        }
}


void Player::update(float time){
    control();
    //std::cout << state << " ";
    switch (state){
        case right:dx = speed; dy = 0; break;
        case left:dx = -speed; dy = 0; break;
        case up: dx = 0; dy = -speed; break;
        case down: dx = 0; dy = speed; break;
        case angle1: dx = speed; dy = -speed; break;
        case angle2: dx = speed; dy = speed; break;
        case angle3: dx = -speed; dy = speed; break;
        case angle4: dx = -speed; dy = -speed; break;
        case stay: dx = 0; dy = 0;
    }
    //std::string walldir = WallDir();
    if(movetrigger == 0)
        x += dx*time;
    checkCollisionWithMap(dx, 0);
    if(movetrigger == 0)
        y += dy*time;
    checkCollisionWithMap(0, dy);
    sprite.setPosition(x + (float)w / 2, y + (float)h / 2);
    ViewChar::setPlayerCoordinateForView(x, y);
}

