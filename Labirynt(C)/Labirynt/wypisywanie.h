#pragma once
#include"Header.h"
///** @file */
//#ifndef wypisywanie_H
//#define Wypisywanie_h

/** Funkcja wypisuje w konsoli ekwipunek
@param pGlowa wskaznik na liste przedmiotow
*/
void wypiszekw(Ekwipunekstr *pGlowa);
/** Funkcja wypisuje w konsoli mape i ekwipunek
@param tablica wskaznik na mape
@param wiersze ilosc wierczy mapy
@param kolumny ilosc kolumn mapy
@param ekw wskaznik na liste przedmiotow
*/
void wypiszmapiekw(pole ***tablica, int wiersze, int kolumny, Ekwipunekstr *ekw);
/** Funkcja wypisuje w konsoli mape
@param tablica wskaznik na mape
@param wiersze ilosc wierczy mapy
@param kolumny ilosc kolumn mapy
*/
void wypiszmapa(pole ***tablica, int wiersze, int kolumny);
/** Funkcja wypisuje pomoc w edytorze map
@param szerokosc ilosc kolumn mapy
*/
void wypiszpomoc(int szerokosc);
/** Funkcja wypisuje pomoc w trybie chodzenia w edytorze map
@param kolumny ilosc kolumn mapy
*/
void wypiszpomchodzenie(int kolumny);
//#endif

