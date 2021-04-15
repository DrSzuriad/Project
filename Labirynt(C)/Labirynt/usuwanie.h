#pragma once
#include"Header.h"
///** @file */
//#ifndef usuwanie_H
//#define Usuwanie_h

/** Funkcja zwalnia pamiec zajenta przez liste wynikow
@param lista wskaznik na liste wynikow
*/
void usuntablice(tabwyn **lista);
/** Funkcja zwalnia pamiec zajeta przez mape
@param mapa wskaznik na mape
@param wiersze ilosc wierszy mapy
@param kolumny ilisc kolumn mapy
*/
void usunmape(wskpole mapa, int wiersze, int kolumny);
/** Funkcja zwalnia pamiec zajenta przez liste przeciwnikow
@param przeciwnik wskaznik na liste przeciwnikow
*/
void usunliste(wrog **przeciwnik);
/** Funkcja zwalnia pamiec zajeta prze mape oraz liste przeciwnikow i postac
@param mapa wskaznik na mape
@param wiersze ilosc wierszy mapy
@param kolumny ilisc kolumn mapy
@param przeciwnik wskaznik na liste przeciwnikow
@param postac wskaznik na miejsce, w ktorym znajduje sie postac
*/
void usuncalamape(wskpole mapa, int wiersze, int kolumny, wrog **przeciwnik, kordy **postac);
/** Funkcja zwalnia pamiec zajeta przez liste przedmiotow
@param pHeadekw wskaznik na liste przedmiotow
*/
void usunekwipunek(Ekwipunekstr **pHeadekw);
/** Funkcja zwalnia pamiec zajenta przez nazwe gracza
@param nazwa imie uzytkownika
*/
void usunnazwe(char **nazwa);
//#endif
