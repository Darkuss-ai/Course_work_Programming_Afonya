//
// Created by Sergey on 04.11.2020.
//
#include "dialoghelper.h"

float CurrentFrame = 0;
int timer  = 1;

bool guidance = false;


sf::String who;


int gold = 0;
int golddialog = 0;

int notesroomdialog = 0;
int notesroom = 0;

int beardialog = 0;
int bear = 0;

int windowroomdialog = 0;
int windowroom = 0;

int sworddialog = 0;
int sword = 0;

int tablichkaroomdialog = 0;
int tablichkaroom = 0;

int mirrordialog = 0;
int mirror = 0;

int cabinetdialog = 0;
int cabinet = 0;

int tablichkakoridor = 0;
int tablichkakoridordialog = 0;

int skladkoridor = 0;
int skladkoridordialog = 0;

int Door = 0;
int Doordialog = 0;

int Badya = 0;
int Badyadialog = 0;

int ryukzak = 0;
int ryukzakdialog = 0;

int sundukkuxnya = 0;
int sundukkuxnyadialog = 0;

int brelokkuxnya = 0;
int brelokkuxnyadialog = 0;

int butilka = 0;
int butilkadialog = 0;

int sundukmasterskaya = 0;
int sundukmasterskayadialog = 0;

int portreti = 0;
int portretidialog = 0;

int lopata = 0;
int lopatadialog = 0;

int zapiskakamin = 0;
int zapiskakamindialog = 0;

int armor = 0;
int armordialog = 0;

int zerno = 0;
int zernodialog = 0;


bool invent = false;
bool inventpickup = false;

int typeofshoes = 0;
bool shoesininvent = false;


bool showarmory = false;




bool dialogview;

void DialogHelp::dialoghelper(int& checkguidance, String& what, int& trigger, bool& ifryukzak){
    if(checkguidance == 1 && golddialog == 0){
        if(ryukzakdialog == 0) {
            ifryukzak = true;
            return;
        }
        ifryukzak = false;
        gold++;
        what = "gold";

    }
    if(checkguidance == 2 && notesroomdialog == 0){
        if(ryukzakdialog == 0) {
            ifryukzak = true;
            return;
        }
        ifryukzak = false;
        notesroom++;
        what = "notesroom";
    }
    if(checkguidance == 3 && trigger == 0){
        bear = 1;
        what = "bear";
        beardialog = 0;
    }
    if(checkguidance == 4 && trigger == 0){
        windowroom = 1;
        what = "window";
        windowroomdialog = 0;
    }
    if(checkguidance == 5 && trigger == 0){
        sword = 1;
        what = "sword";
        sworddialog = 0;
    }
    if(checkguidance == 6 && trigger == 0){
        tablichkaroom = 1;
        what = "tablichkaroom";
        tablichkaroomdialog = 0;
    }
    if(checkguidance == 7 && trigger == 0){
        mirror = 1;
        what = "mirror";
        mirrordialog = 0;
    }
    if(checkguidance == 8 && trigger == 0){
        cabinet = 1;
        what = "cabinet";
        cabinetdialog = 0;
    }
    if(checkguidance == 9 && trigger == 0){
        tablichkakoridor = 1;
        what = "tablichkakoridor";
        tablichkakoridordialog = 0;
    }
    if(checkguidance == 10 && trigger == 0){
        skladkoridor = 1;
        what = "skladkoridor";
        skladkoridordialog = 0;
    }
    if(checkguidance == 11 && trigger == 0){
        Door = 1;
        what = "door";
        Doordialog = 0;

    }
    if(checkguidance == 12 && trigger == 0){
        Badya = 1;
        what = "badya";
        Badyadialog = 0;

    }
    if(checkguidance == 13 && ryukzakdialog == 0){
        ryukzak++;
        inventpickup = true;
        what = "ryukzak";

    }
    if(checkguidance == 14 && trigger == 0){
        sundukkuxnya = 1;
        what = "sundukkuxnya";
        sundukkuxnyadialog = 0;

    }
    if(checkguidance == 15 && brelokkuxnyadialog == 0){
        if(ryukzakdialog == 0) {
            ifryukzak = true;
            return;
        }
        ifryukzak = false;
        brelokkuxnya++;
        what = "brelokkuxnya";


    }
    if(checkguidance == 16 && trigger == 0){
        butilka = 1;
        what = "butilka";
        butilkadialog = 0;

    }
    if(checkguidance == 17 && trigger == 0){
        sundukmasterskaya = 1;
        what = "sundukmasterskaya";
        sundukmasterskayadialog = 0;

    }
    if(checkguidance == 18 && trigger == 0){
        portreti = 1;
        what = "portreti";
        portretidialog = 0;

    }
    if(checkguidance == 19 && lopatadialog == 0){
        if(ryukzakdialog == 0) {
            ifryukzak = true;
            return;
        }
        ifryukzak = false;
        lopata++;
        what = "lopata";


    }
    if(checkguidance == 20 && zapiskakamindialog == 0){
        if(ryukzakdialog == 0) {
            ifryukzak = true;
            return;
        }
        ifryukzak = false;
        zapiskakamin++;
        what = "zapiskakamin";


    }
    if(checkguidance == 21 && trigger == 0){
        armor = 1;
        what = "armor";
        armordialog = 0;

    }
    if(checkguidance == 22 && trigger == 0){
        zerno = 1;
        what = "zerno";
        zernodialog = 0;

    }
}



