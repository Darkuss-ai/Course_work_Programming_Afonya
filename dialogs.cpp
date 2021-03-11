//
// Created by Sergey on 04.11.2020.
//
#include "dialogs.h"
#include <fstream>

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

String Strinit::strinit(const std::string& whatdialog){
    String save = "";
    String papacho;
    std::ifstream fileinput("dialogs/dialogs.txt");
    std::string hoho = "jergnej";
    papacho = hoho;

    if(whatdialog == "gold") {
        who = L"Студи";
        if (golddialog == 0) {
            save.begin();
            papacho = L"О, отлично! Немного денежек не помешает!\nНа проезд должно хватить.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "notesroom"){
        who = L"Студи";
        if(notesroomdialog == 0){
            save.begin();
            papacho = L"Так, домашка по терверу. Хорошо, что я её\nне забыл. Только для начала\nнадо найти рюкзак.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "bear"){
        who = L"Студи";
        if(beardialog == 0){
            papacho = L"О, любимая игрушка моего одногруппника.\nКак же он там говорил...";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        else if(beardialog == 1){
            who = L"Юрий";
            papacho = L"Каждый день я засыпаю с ним в обнимку.\nНо мама решила выкинуть его, подержишь\nу себя Мистера Топтыгина?";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        else if(beardialog == 2){
            who = L"Студи";
            papacho = L"Ну мишка и правда классный.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "window"){
        who = L"Студи";
        if(windowroomdialog == 0) {
            papacho = L"Погодка сегдня радует. Зонт брать не надо.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "sword"){
        who = L"Студи";
        if(sworddialog == 0){
            papacho = L"Эх...кортик моего умершего деда...";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        if(sworddialog == 1){
            papacho = L"Именно он дал мне много житейских\nмудростей. Как сейчас помню:";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        if(sworddialog == 2){
            who = L"Дед";
            papacho = L"Дело не сдвинется с места, если\nничего не предпринимать!";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        if(sworddialog == 3){
            who = L"Студи";
            papacho = L"Мне его сильно не хватает...";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "tablichkaroom"){
        who = L"";
        if(tablichkaroomdialog == 0){
            papacho = L"Чел, не забудь домашку по терверу.\nОна лежит на столе";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "mirror"){
        who = L"Студи";
        if(mirrordialog == 0){
            papacho = L"Время никого не щадит...";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "cabinet"){
        who = L"Студи";
        if(cabinetdialog == 0){
            papacho = L"Грязная одежда, рваные носки.\nНичего полезного.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "tablichkakoridor"){
        who = L"";
        if(tablichkakoridordialog == 0){
            papacho = L"Перед выходом не забудь поесть!";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "skladkoridor") {
        who = L"";
        if (skladkoridordialog == 0 && ryukzakdialog == 0) {
            papacho = L"Немного порывшись в вещах, вы обнаружи-\nваете свои старенькие кроссовки.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }

        if (skladkoridordialog == 1 && ryukzakdialog == 0) {
            who = L"Студи";
            papacho = L"Мне пока некуда их убрать. Надо найти\nрюкзак.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
        if (skladkoridordialog == 0 && ryukzakdialog != 0 && !shoesininvent) {
            papacho = L"Немного порывшись в вещах, вы обнаружи-\nваете свои старенькие кроссовки.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
        else if (skladkoridordialog == 1 && ryukzakdialog != 0 && !shoesininvent) {
            who = L"Студи";
            papacho = L"Положу-ка я их в рюкзак. У меня сегодня\nфизкультура по-моему есть.";
            shoesininvent = true;
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
        else if(skladkoridordialog == 0 && ryukzakdialog != 0 && shoesininvent){
            who = L"Студи";
            papacho = L"Здесь нет ничего интересного.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
        else if(skladkoridordialog == 1 && ryukzakdialog != 0 && shoesininvent){
            who = L"Студи";
            papacho = L"Кроссовки я уже забрал, больше здесь нечего\nловить.";
            for (int i = 0; i < papacho.getSize(); i++) {
                save += papacho[i];
            }
        }
    }

    if(whatdialog == "door"){
        who = L"";
        if(Doordialog == 0){
            papacho = L"Вы действительно хотите выйти?";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        else if(Doordialog == 5){
            papacho = L"Пока здесь останусь. Может ещё чего найду.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
        else if(Doordialog == 10){
            papacho = L"Ну вроде всё собрал, можно и в Вуз\nотправиться.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "badya"){
        who = L"";
        if(Badyadialog == 0){
            papacho = L"~Ух, умылся. Впервые за 3 дня.~";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "ryukzak"){
        who = L"Студи";
        if(ryukzakdialog == 0){
            papacho = L"О, а вот и мой рюкзак! Только что он делает здесь?";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "sundukkuxnya"){
        who = L"Студи";
        if(sundukkuxnyadialog == 0){
            papacho = L"Вряд ли мне понадобится туалетная бумага\nв университете. Не буду брать отсюда ничего.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "brelokkuxnya"){
        who = L"Студи";
        if(brelokkuxnyadialog == 0){
            papacho = L"Так, мой кулон. Почему он лежит на кухне,\nавтор, тебе 5 лет?";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "butilka"){
        who = L"Студи";
        if(butilkadialog == 0){
            papacho = L"Винка для рывка! Ещё и курочку покушаю.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "sundukmasterskaya"){
        who = L"Студи";
        if(sundukmasterskayadialog == 0){
            papacho = L"Отцовские инструменты. Вроде из всего этого\nмне ничего не нужно.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "portreti"){
        who = L"";
        if(portretidialog == 0){
            papacho = L"~Зачем родители вешают в свою комнату\nвсякие портреты? Это же бессмысленно.~";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "lopata"){
        who = L"Студи";
        if(lopatadialog == 0){
            papacho = L"Сапёрная лопатка. Почему бы не взять?\nМеста она занимает немного, а в хозяйстве\nвещь нужная.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "zapiskakamin"){
        who = L"";
        if(zapiskakamindialog == 0){
            papacho = L"~Карта, которую мне дал тот странный чувак.\nНе думаю, что он говорил о сокровище правду,\nно проверить можно.~";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "armor"){
        who = L"";
        if(armordialog == 0){
            papacho = L"~Коллекция доспехов моего отца. Зачем он\nих коллекционирует?~";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }
    if(whatdialog == "zerno"){
        who = L"Студи";
        if(zernodialog == 0){
            papacho = L"О, кажется я нашёл годовой запас гречки.\nКарантин всё-таки.";
            for(int i = 0; i < papacho.getSize(); i++){
                save += papacho[i];
            }
        }
    }




    return save;
}


void Strinit::dialogsofend(int number, Text& txt, int& mark){
    if(number == 2 && shoesininvent)
        txt.setString(L"На улице вы встретили алкоголиков, которые хотели украсть ваши вещи.\nК счастью, у вас были ваши супер кроссовки и вы смогли от них убежать.");
    else if(number == 2 && !shoesininvent)
        txt.setString(L"На улице вы встретили алкоголиков, которые хотели украсть ваши вещи.\nВы вышли из дома босиком, и из-за этого не смогли убежать от них. Они избили вас, но ничего не забрали.");
    else if(number == 3 && golddialog != 0)
        txt.setString(L"Вы взяли с собой деньги, поэтому без проблем добрались до Университета.\nВам даже хватило денег, чтобы купить себе воды.");
    else if(number == 3 && golddialog == 0)
        txt.setString(L"Вы не взяли с собой деньги, поэтому проехали на автобусе зайцем. С электричкой же вам не повезло:\nНа третьей станции вам пришлось высадиться. Худо-бедно вы добрались до точки назначения,\nно вы опоздали на первую пару и испортили себе настроение. Вы хотели купить себе воды, но на что?");
    else if(number == 4 && brelokkuxnyadialog != 0)
        txt.setString(L"Вы взяли с cобой кулон. Чел думает, что он приносит ему удачу, поэтому он чувствует себя более уверенно\nперед экзаменом. Это немного подняло настроение вашему персонажу.");
    else if(number == 4 && brelokkuxnyadialog == 0 && golddialog == 0)
        txt.setString(L"Ко всему прочему вы забыли свой кулон, который, по мнению вашего персонажа, приносит ему удачу.\nЕго день сегодня точно не задался.");
    else if(number == 4 && brelokkuxnyadialog == 0 && golddialog != 0)
        txt.setString(L"Ваше настроение немного подпортилось из-за того, что вы не взяли с cобой любимый кулон персонажа.\nПо его мнению, он приносит удачу, что могло помочь при сдаче экзамена.");
    else if(number == 5 && notesroomdialog == 0)
        txt.setString(L"Вы не очень хороши в программировании, поэтому решили найти кого-то, кто сможет вам помочь.\nПросто так никто помогать вам не будет. На этот случай вы сделали домашнее задание по Теории вероятностей.\nНо вот незадача: вы его забыли. Значит, вам придётся рассчитывать только на свои силы.");
    else if(number == 5 && notesroomdialog != 0)
        txt.setString(L"Вы не очень хороши в программировании, поэтому решили найти кого-то, кто сможет вам помочь.\nПросто так никто помогать вам не будет. На этот случай вы сделали домашнее задание по Теории вероятностей.\nВы взяли его с собой, так что найдя шарящего человека, вы с ним 'договорились'.Теперь вам будет намного легче\nсдать экзамен");
    else if(number == 6 && lopatadialog != 0 && zapiskakamindialog != 0 && brelokkuxnyadialog == 0)
        txt.setString(L"До экзамена было ещё немного времени и вы решили проверить место, отмеченное на карте. На этот случай вы взяли\nс собой лопату. Найдя нужную точку, вы начали копать яму.\nСпустя несколько минут вы наткнулись на какую-то бутылку.\nБутылку 'Столичной'.\nВы взяли её себе на будущее, авось пригодится.");
    else if(number == 6 && lopatadialog != 0 && zapiskakamindialog != 0 && brelokkuxnyadialog != 0)
        txt.setString(L"До экзамена было ещё немного времени и вы решили проверить место, отмеченное на карте. На этот случай вы взяли\nс собой лопату. Найдя нужную точку, вы начали копать яму.\nСпустя несколько минут вы наткнулись на какой-то ящик.\nОн был полностью заполнен бутылками 'Столичной'. Вы закопали ящик обратно до лучших времён,\nибо донести всё это добро не представляется возможным.");
    else if(number == 6 && lopatadialog != 0 && zapiskakamindialog == 0)
        txt.setString(L"Вы до сих пор не понимаете, зачем вы взяли с собой лопату в Университет. У вас есть стойкое ощущение,\nчто вы что-то забыли...");
    else if(number == 6 && lopatadialog == 0 && zapiskakamindialog == 0)
        txt.setString(L"До экзамена было ещё немного времени и вы решили проверить место, отмеченное на карте.\nНа полпути к нему вы понимаете, что вам нечем выкопать яму. Вы проклинаете себя и идёте ожидать экзамена.");
    else if(number == 7 && lopatadialog != 0 && zapiskakamindialog != 0 && brelokkuxnyadialog != 0 && golddialog != 0 && notesroomdialog != 0 &&shoesininvent)
        txt.setString(L"И вот наконец подошло время экзамена. Сегодня твой день. Ты чувствуешь это.\nТебе всё под силу. У тебя есть шпоры, удача из-за брелка, ящик водки, в конце концов.\nТы готов и ничто тебя не остановит. Осталась лишь одна преграда и она сидит прямо перед тобой.");
    else if(number == 7)
        txt.setString(L"И вот наконец подошло время экзамена. Ты не знаешь, какие вопросы тебе выпадут, но\nу тебя есть чувство, что просто не будет. Ты готовился\nи вот настал кульминационный момент: перед тобой сидит он.");
    else if(number == 9 && notesroomdialog != 0)
        txt.setString(L"Ну что, на самые сложные вопросы ты ответил, благодаря\nсвоей тетрадке, видимо. Давай теперь что-нибудь полегче.\nИтак, первый вопрос: Какое ключевое слово\nставится перед методом класса, если этот метод\nНЕ использует поля данного класса?");
    else if(number == 9 && notesroomdialog == 0)
        txt.setString(L"Я хочу сразу начать со сложных вопросов, чтобы оценить твои знания.\nИтак, первый вопрос: У нас есть класс под названием Class.\nУ него есть один лишь статический метод\nпод название met1. Как мы обратимся к данному\nметоду? (Вариант ответа должен выглядеть, как\nимя_класса и метод с круглыми скобками.");
    else if(number == 11 && notesroomdialog != 0)
        txt.setString(L"Отлично, второй вопрос: Какой тип имеет функция\nили метод, которая НЕ возвращает значения?");
    else if(number == 11 && notesroomdialog == 0)
        txt.setString(L"Отлично, второй вопрос:  Назови мне особый тип функции, которая, при\nеё вызове, выполняет «наиболее» дочерний метод, который\nсуществует между родительским и дочерними классами.");
    else if(number == 13 && notesroomdialog != 0)
        txt.setString(L"Ну, и последний вопрос: Назови мне САМЫЙ\nлучший язык программирования в мире.");
    else if(number == 13 && notesroomdialog == 0)
        txt.setString(L"Ну, и последний вопрос:  Какой заголовочный файл с классами, функциями\nи переменными отвечает за организацию ввода-вывода\nв языке программирования C++?");
    else if(number == 15 && mark == 2)
        txt.setString(L"Ты ответил на все вопросы НЕПРАВИЛЬНО!\nТы как вообще к экзамену готовился? Шанса на пересдачу нет, ты завалил экзамен и теперь должен прекратить\nобучение в нашем Университете. Всего доброго! СЛЕДУЮЩИЙ!");
    else if(number == 15 && mark == 3)
        txt.setString(L"Что же, на троечку ты ответил, но не больше. Вопросы были лёгкие, но ты всё равно ошибся.\nВсего доброго. СЛЕДУЮЩИЙ!");
    else if(number == 15 && mark == 4)
        txt.setString(L"Неплохо, неплохо. Ты ответил на 4 балла. Давай зачётку и можешь идти.\nВсего тебе доброго. Следующий!");
    else if(number == 15 && mark == 5)
        txt.setString(L"Хм...не ожидал от тебя, но... поздравляю! Ты ответил на все вопросы верно.\nДавай зачётку, я поставлю тебе оценку. Берите с него пример, лоботрясы! Вот, держи, всего доброго. СЛЕДУЮЩИЙ!");




    else if(number == 16 && mark == 2 && lopatadialog != 0 && zapiskakamindialog != 0)
        txt.setString(L"С заплетающимися ногами вы вышли из Университета.\nВы решили потопить свою боль в алкоголе, благо у вас\nесть целый ящик. Вы считали, что этот день станет\nсамым лучшим в вашей жизни, но это оказалось не так.");
    else if(number == 16 && mark == 2 && golddialog == 0 && !shoesininvent)
        txt.setString(L"С заплетающимися ногами вы вышли из Университета.\nСегодня точно не ваш день. Вас избили, вы не\nвыкопали клад, вы натерпелись страстей в общественном транспорте.\nПолностью убитый, вы сели на лавку и заплакали...");
    else if(number == 16 && mark == 2)
        txt.setString(L"С заплетающимися ногами вы вышли из Университета.\nВидимо, вы что-то упустили. Вы чувствуте, что\nэтот день мог быть намного лучше, но ничего уже не изменить.\nВы сели на лавку и стали размышлять над своей жизнью...");
    else if(number == 16 && mark == 3)
        txt.setString(L"Пребывая в не самом хорошем расположении духа вы вышли из Университета.\nНу, вы хотя бы сдали, что не скажешь о некоторых ваших одногруппниках. Но всё же, нужно было\nбольше времени уделить подготовке к экзаменам.");
    else if(number == 16 && mark == 4)
        txt.setString(L"Вы лёгкой походкой покинули Университет. Вы получили ту оценку, на\nкоторую вы и рассчитывали.");
    else if(number == 16 && mark == 5)
        txt.setString(L"Вы пулей вылетели из Университета и начали благословить\nГоспода во всю мощь вашей грудной клетки.Вы получили максимальную\nоценку, а значит, что все ваши труды окупились сполна!");




    else if(number == 17 && mark == 2)
        txt.setString(L"Вам следовало лучше подумать над ответами, которые\nвы давали на экзамене. Благо, это всего лишь игра и влюбой момент можно перепройти сложную ситуацию.\nНо помни, что такие ситуации могут произойти и с тобой! Да-да, именно с тобой, человек за экраном!\nК сожалению, в нашей жизни нет функции сохранения, так что за каждый свой поступок тебе необходимо отвечать\nв полной мере. Надеюсь, эта история чему-то тебя научила. Я верю, что ты не совершишь\nтакие ошибки в будущем! Удачи!");
    else if(number == 17 && mark == 3)
        txt.setString(L"Вам следовало лучше подумать над ответами. Хоть вы и получили оценку, но удовлетворит ли она вас?\nБлаго, это всего лишь игра и в любой момент можно перепройти сложную ситуацию.\nНо помни, что такие ситуации могут произойти и с тобой! Да-да, именно с тобой, человек за экраном!\nК сожалению, в нашей жизни нет функции сохранения, так что за каждый свой поступок тебе необходимо отвечать\nв полной мере. Надеюсь, эта история чему-то тебя научила. Я верю, что ты не совершишь\nтакие ошибки в будущем! Удачи!");
    else if(number == 17 && mark > 3)
        txt.setString(L"Вы справились с экзаменами. Вы хорошо подготовились к вопросам и с лёгкостью\nответили на каждый из них (Интернетом не пользовался, хитрец?). Надеюсь, что ты, человек из-за экрана, также сдашь все свои экзамены!\n Удачи тебе в будущем, надеюсь, у теюя всё сложится хорошо!");


    else if(number == 18)
        txt.setString(L"Поздравляю, ты прошёл игру. Независимо от её результатов мне хочется сказать немного слов (себе, конечно, кто в это играть будет?)\n"
                      "Разработка этого творения была невероятно сложной. По несколько часов в день после универа, жертвуя другими предметами и своими нервами.\n"
                      "Но на самом деле, это был интересный опыт. Я наконец-то понял одну важную вещь - Я НИКОГДА НЕ БУДУ РАЗРАБАТЫВАТЬ ИГРУ, А ОСОБЕННО ДИАЛОГИ!\n"
                      "Что же, спасибо, что оценили мой проект. Я постараюсь и в дальнейшем не разочаровывать вас (Алексей Викторович, скоро вам всё сдам, обещаю).");
}


