//
// Created by Sergey on 04.11.2020.
//
#include "Guidance.h"

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

int Guidance::GuidanceFunc(float posx1, float posx2, float posy1, float posy2){
    if (((posx1 >= 289 && posx2 <= 319) && (posy1 >= 607 && posy2 <= 638)) && golddialog == 0)
        return 1;
    else if (((posx1 >= 575 && posx2 <= 607) && (posy1 >= 767 && posy2 <= 793)) && notesroomdialog == 0)
        return 2;
    else if (((posx1 >= 485 && posx2 <= 506) && (posy1 >= 640 && posy2 <= 666)))
        return 3;
    else if (((posx1 >= 416 && posx2 <= 445) && (posy1 >= 815 && posy2 <= 852)))
        return 4;
    else if (((posx1 >= 289 && posx2 <= 319) && (posy1 >= 458 && posy2 <= 480)))
        return 5;
    else if (((posx1 >= 389 && posx2 <= 410) && (posy1 >= 455 && posy2 <= 473)))
        return 6;
    else if (((posx1 >= 416 && posx2 <= 447) && (posy1 >= 450 && posy2 <= 495)))
        return 7;
    else if (((posx1 >= 574 && posx2 <= 640) && (posy1 >= 447 && posy2 <= 511)))
        return 8;
    else if (((posx1 >= 389 && posx2 <= 410) && (posy1 >= 6 && posy2 <= 25)))
        return 9;
    else if (((posx1 >= 574 && posx2 <= 640) && (posy1 >= 32 && posy2 <= 96)))
        return 10;
    else if (((posx1 >= 706 && posx2 <= 735) && (posy1 >= 13 && posy2 <= 50)))
        return 11;
    else if (((posx1 >= 800 && posx2 <= 831) && (posy1 >= 195 && posy2 <= 223)))
        return 12;
    else if (((posx1 >= 800 && posx2 <= 831) && (posy1 >= 384 && posy2 <= 416)) && ryukzakdialog == 0)
        return 13;
    else if (((posx1 >= 836 && posx2 <= 859) && (posy1 >= 521 && posy2 <= 534)))
        return 14;
    else if (((posx1 >= 834 && posx2 <= 861) && (posy1 >= 712 && posy2 <= 730)) && brelokkuxnyadialog == 0)
        return 15;
    else if (((posx1 >= 710 && posx2 <= 731) && (posy1 >= 771 && posy2 <= 794)))
        return 16;
    else if (((posx1 >= 420 && posx2 <= 442) && (posy1 >= 297 && posy2 <= 311)))
        return 17;
    else if (((posx1 >= 40 && posx2 <= 286) && (posy1 >= 3 && posy2 <= 32)))
        return 18;
    else if (((posx1 >= 260 && posx2 <= 285) && (posy1 >= 386 && posy2 <= 413)) && lopatadialog == 0)
        return 19;
    else if (((posx1 >= 130 && posx2 <= 159) && (posy1 >= 160 && posy2 <= 185)) && zapiskakamindialog == 0)
        return 20;
    else if (((posx1 >= 32 && posx2 <= 63) && (posy1 >= 384 && posy2 <= 506)))
        return 21;
    else if (((posx1 >= 32 && posx2 <= 64) && (posy1 >= 642 && posy2 <= 671)))
        return 22;
    else
        return 0;
}

bool Guidance::PlayerDistance(float posx1, float posx2, float posy1, float posy2) {
    return (((posx1 >= 259 && posx2 <= 349) && (posy1 >= 577 && posy2 <= 668)) ||
            ((posx1 >= 545 && posx2 <= 637) && (posy1 >= 737 && posy2 <= 823)) ||
            ((posx1 >= 455 && posx2 <= 536) && (posy1 >= 610 && posy2 <= 696)) ||
            ((posx1 >= 386 && posx2 <= 475) && (posy1 >= 785 && posy2 <= 882)) ||
            ((posx1 >= 259 && posx2 <= 349) && (posy1 >= 428 && posy2 <= 510)) ||
            ((posx1 >= 359 && posx2 <= 440) && (posy1 >= 425 && posy2 <= 503)) ||
            ((posx1 >= 386 && posx2 <= 477) && (posy1 >= 420 && posy2 <= 525)) ||
            ((posx1 >= 544 && posx2 <= 670) && (posy1 >= 417 && posy2 <= 541)) ||
            ((posx1 >= 359 && posx2 <= 440) && (posy1 >= 0 && posy2 <= 55)) ||
            ((posx1 >= 544 && posx2 <= 670) && (posy1 >= 2 && posy2 <= 126)) ||
            ((posx1 >= 676 && posx2 <= 765) && (posy1 >= 0 && posy2 <= 80)) ||
            ((posx1 >= 770 && posx2 <= 861) && (posy1 >= 165 && posy2 <= 253)) ||
            ((posx1 >= 770 && posx2 <= 861) && (posy1 >= 354 && posy2 <= 386)) ||
            ((posx1 >= 806 && posx2 <= 889) && (posy1 >= 491 && posy2 <= 564)) ||
            ((posx1 >= 804 && posx2 <= 891) && (posy1 >= 682 && posy2 <= 760)) ||
            ((posx1 >= 680 && posx2 <= 761) && (posy1 >= 741 && posy2 <= 824)) ||
            ((posx1 >= 390 && posx2 <= 472) && (posy1 >= 267 && posy2 <= 341)) ||
            ((posx1 >= 10 && posx2 <= 316) && (posy1 >= 0 && posy2 <= 62)) ||
            ((posx1 >= 230 && posx2 <= 315) && (posy1 >= 356 && posy2 <= 443)) ||
            ((posx1 >= 100 && posx2 <= 189) && (posy1 >= 130 && posy2 <= 215)) ||
            ((posx1 >= 2 && posx2 <= 93) && (posy1 >= 354 && posy2 <= 476)) ||
            ((posx1 >= 2 && posx2 <= 94) && (posy1 >= 612 && posy2 <= 701)));
}