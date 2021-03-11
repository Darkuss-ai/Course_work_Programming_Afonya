//
// Created by Sergey on 04.11.2020.
//
#include "dialoginteraction.h"
#include "dialogs.h"

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

void Dialogs::Change(int& trigger, bool& ptrigger, int& count, String& str, Text& text){
    trigger = 0;
    ptrigger = false;
    count = 0;
    str.clear();
    text.setString("");
}

void Dialogs::DialogFunc(String& save, String& str, int &count, Text& text, int &trigger, bool &ptrigger, String& what, Level& lvl){
    save.clear();
    str.clear();
    count = 0;

    if(what == "gold"){
        if(gold == 1) {
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            golddialog++;
            if (golddialog == 2) {
                Change(trigger, ptrigger, count, str, text);
                gold = 0;
            }
        }
    }

    if(what == "notesroom"){
        if(notesroom == 1){
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            notesroomdialog++;
            if(notesroomdialog == 2) {
                Change(trigger, ptrigger, count, str, text);
                notesroom = 0;
            }
        }
    }

    if(what == "bear"){
        if(bear == 1){
            str = Strinit::strinit(what);
            beardialog++;
            if(beardialog == 4){
                Change(trigger, ptrigger, count, str, text);
                bear = 0;
            }
        }
    }

    if(what == "window"){
        if(windowroom == 1){
            str = Strinit::strinit(what);
            windowroomdialog++;
            if(windowroomdialog == 2){
                Change(trigger, ptrigger, count, str, text);
                windowroom = 0;
            }
        }
    }

    if(what == "sword"){
        if(sword == 1){
            str = Strinit::strinit(what);
            sworddialog++;
            if(sworddialog == 5){
                Change(trigger, ptrigger, count, str, text);
                sword = 0;
            }
        }
    }

    if(what == "tablichkaroom"){
        if(tablichkaroom == 1){
            str = Strinit::strinit(what);
            tablichkaroomdialog++;
            if(tablichkaroomdialog == 2){
                Change(trigger, ptrigger, count, str, text);
                tablichkaroom = 0;
            }
        }
    }

    if(what == "mirror"){
        if(mirror == 1){
            str = Strinit::strinit(what);
            mirrordialog++;
            if(mirrordialog == 2){
                Change(trigger, ptrigger, count, str, text);
                mirror = 0;
            }
        }
    }

    if(what == "cabinet"){
        if(cabinet == 1){
            str = Strinit::strinit(what);
            cabinetdialog++;
            if(cabinetdialog == 2){
                Change(trigger, ptrigger, count, str, text);
                cabinet = 0;
            }
        }
    }
    if(what == "tablichkakoridor"){
        if(tablichkakoridor == 1){
            str = Strinit::strinit(what);
            tablichkakoridordialog++;
            if(tablichkakoridordialog == 2){
                Change(trigger, ptrigger, count, str, text);
                tablichkakoridor = 0;
            }
        }
    }
    if(what == "skladkoridor"){
        if(skladkoridor == 1){
            str = Strinit::strinit(what);
            skladkoridordialog++;
            if(skladkoridordialog == 3){
                Change(trigger, ptrigger, count, str, text);
                skladkoridor = 0;
            }
        }
    }
    if(what == "door"){
        if(Door == 1){
            str = Strinit::strinit(what);
            Doordialog++;
            if(Doordialog == 2){
                dialogview = true;
            }
            else if(Doordialog == 7){
                Change(trigger, ptrigger, count, str, text);
                Door = 0;
            }
            else if(Doordialog == 12){
                Change(trigger, ptrigger, count, str, text);
                Door = 0;
            }
        }
    }
    if(what == "badya"){
        if(Badya == 1){
            str = Strinit::strinit(what);
            Badyadialog++;
            if(Badyadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                Badya = 0;
            }
        }
    }
    if(what == "ryukzak"){
        if(ryukzak == 1){
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            ryukzakdialog++;
            if(ryukzakdialog == 2){
                Change(trigger, ptrigger, count, str, text);
                ryukzak = 0;
            }
        }
    }
    if(what == "sundukkuxnya"){
        if(sundukkuxnya == 1){
            str = Strinit::strinit(what);
            sundukkuxnyadialog++;
            if(sundukkuxnyadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                sundukkuxnya = 0;
            }
        }
    }
    if(what == "brelokkuxnya"){
        if(brelokkuxnya == 1){
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            brelokkuxnyadialog++;
            if(brelokkuxnyadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                brelokkuxnya = 0;
            }
        }
    }
    if(what == "butilka"){
        if(butilka == 1){
            str = Strinit::strinit(what);
            butilkadialog++;
            if(butilkadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                butilka = 0;
            }
        }
    }
    if(what == "sundukmasterskaya"){
        if(sundukmasterskaya == 1){
            str = Strinit::strinit(what);
            sundukmasterskayadialog++;
            if(sundukmasterskayadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                sundukmasterskaya = 0;
            }
        }
    }
    if(what == "portreti"){
        if(portreti == 1){
            str = Strinit::strinit(what);
            portretidialog++;
            if(portretidialog == 2){
                Change(trigger, ptrigger, count, str, text);
                portreti = 0;
            }
        }
    }
    if(what == "lopata"){
        if(lopata == 1){
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            lopatadialog++;
            if(lopatadialog == 2){
                Change(trigger, ptrigger, count, str, text);
                lopata = 0;
            }
        }
    }
    if(what == "zapiskakamin"){
        if(zapiskakamin == 1){
            str = Strinit::strinit(what);
            lvl.LoadFromFile("map/lvl1.tmx");
            zapiskakamindialog++;
            if(zapiskakamindialog == 2){
                Change(trigger, ptrigger, count, str, text);
                zapiskakamin = 0;
            }
        }
    }
    if(what == "armor"){
        if(armor == 1){
            str = Strinit::strinit(what);
            armordialog++;
            if(armordialog == 2){
                Change(trigger, ptrigger, count, str, text);
                armor = 0;
            }
        }
    }
    if(what == "zerno"){
        if(zerno == 1){
            str = Strinit::strinit(what);
            zernodialog++;
            if(zernodialog == 2){
                Change(trigger, ptrigger, count, str, text);
                zerno = 0;
            }
        }
    }
}

