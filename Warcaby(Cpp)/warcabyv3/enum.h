/** @file */
#pragma once

/** Obrazek jaki ma siê wyœwietliæ
*/
enum obrazek { ///pionek bia³y na bia³ym polu
    pbnb,///pionek bia³y na czarnym polu
    pbnc, ///pionek czarny na bia³ym polu
    pcnb,///pionek czarny na czarnym polu
    pcnc,///czarne pole
    cz,///bia³e pole
    bia,/// pionowa kreska
    pio,///pozioma kreska
    poz,///czewony kwadrat
    czer,///zielony kwadrat
    ziel,///dama bia³a na bia³ym poli
    dbnb,///dama bia³a na czarnym polu
    dbnc,///dama czarna na czarnym polu
    dcnc,///dama czarna na bia³ym polu
    dcnb};

/** Wersja warcab
*/
enum wersje {  ///warcaby polskie
    polskie, ///warcaby angielskie
    angielskie };

/** Miejsce programu, w którym znajduje siê u¿ytkownik
*/
enum miejsce {  ///menu
    menu, ///miejsce wpisywania nazw graczy oraz wybieranie rodzaju warcab
    wpinazw, ///bia³y gracz wybiera pionka lub damê do ruchu
    biagrabp, ///czarny gracz wybiera pionka lub damê do ruchu 
    czagrabp,///czarny gracz wybiera miejsce gdzie ma siê ruszyæ pionek lub dama
    czagrabw,///bia³y gracz wybiera miejsce gdzie ma siê ruszyæ pionek lub dama
    biagrabw,///bia³y gracz koñczy swój ruch
    biagrakon,///czarny gracz koñczy swój ruch
    czagrakon,///program sprawdza czy bia³y gracz ma mo¿liwoœæ ruchu
    biagraspr,///program sprawdza czy czarny gracz ma mo¿liwoœæ ruchu
    czagraspr };

/** Figura
*/
enum figura { ///pole jest puste
    nic,///na polu stoi pionek bialy 
    pionekbia,///na polu stoi pionek czarny
    pionekcza, ///na polu stoi bia³a dama
    damabia,/// na polu stoi czarna dama
    damacza };
