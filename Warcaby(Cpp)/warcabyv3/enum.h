/** @file */
#pragma once

/** Obrazek jaki ma si� wy�wietli�
*/
enum obrazek { ///pionek bia�y na bia�ym polu
    pbnb,///pionek bia�y na czarnym polu
    pbnc, ///pionek czarny na bia�ym polu
    pcnb,///pionek czarny na czarnym polu
    pcnc,///czarne pole
    cz,///bia�e pole
    bia,/// pionowa kreska
    pio,///pozioma kreska
    poz,///czewony kwadrat
    czer,///zielony kwadrat
    ziel,///dama bia�a na bia�ym poli
    dbnb,///dama bia�a na czarnym polu
    dbnc,///dama czarna na czarnym polu
    dcnc,///dama czarna na bia�ym polu
    dcnb};

/** Wersja warcab
*/
enum wersje {  ///warcaby polskie
    polskie, ///warcaby angielskie
    angielskie };

/** Miejsce programu, w kt�rym znajduje si� u�ytkownik
*/
enum miejsce {  ///menu
    menu, ///miejsce wpisywania nazw graczy oraz wybieranie rodzaju warcab
    wpinazw, ///bia�y gracz wybiera pionka lub dam� do ruchu
    biagrabp, ///czarny gracz wybiera pionka lub dam� do ruchu 
    czagrabp,///czarny gracz wybiera miejsce gdzie ma si� ruszy� pionek lub dama
    czagrabw,///bia�y gracz wybiera miejsce gdzie ma si� ruszy� pionek lub dama
    biagrabw,///bia�y gracz ko�czy sw�j ruch
    biagrakon,///czarny gracz ko�czy sw�j ruch
    czagrakon,///program sprawdza czy bia�y gracz ma mo�liwo�� ruchu
    biagraspr,///program sprawdza czy czarny gracz ma mo�liwo�� ruchu
    czagraspr };

/** Figura
*/
enum figura { ///pole jest puste
    nic,///na polu stoi pionek bialy 
    pionekbia,///na polu stoi pionek czarny
    pionekcza, ///na polu stoi bia�a dama
    damabia,/// na polu stoi czarna dama
    damacza };
