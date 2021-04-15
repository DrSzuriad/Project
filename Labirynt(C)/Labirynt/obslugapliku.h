#pragma once
#include"Header.h"
///** @file */
//#ifndef obslugapliku_H
//#define Obslugapliku_h

/** Funkcja zczytuje z pliku tablice wynikow
@param pHead wskaznik na tablice wynikow
*/
void zczytajtablice(tabwyn **pHead);
/** Funkcja zczytuje plik zawierajacy mape
@param tablica wskaznik na mape
@param przeciwnicy wskaznik na liste przeciwnikow
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param postac wskaznik na pozycje postaci
@param nazwa nazwa mapy
@return czy otwarcie pliku sie udalo i czy dane sa poptawne
*/
bool zczytaj(wskpole tablica, wrog **przeciwnicy, int *wysokosc, int *szerokosc, kordy **postac, char *nazwa);
/** Funkcja obsluguje menu wpisywania nazwy mapy
@param tablica wskaznik na mape
@param przeciwnicy wskaznik na liste przeciwnikow
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param postac wskaznik na pozycje postaci
@return czy gracz chce przerwac wpisywanie mapy i wrocic do menu glownego
*/
bool czytaniemapy(wskpole tab, wrog **przeciwnicy, int *wysokosc, int *szerokosc, kordy **postac);
/** Funkcja zapisuje do pliku mape
@param tablica wskaznik na mape
@param przeciwnicy wskaznik na liste przeciwnikow
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
@param postac wskaznik na pozycje postaci
*/
void zapiszmape(wskpole mapa, wrog **przeciwnicy, int  wiersze, int  kolumny, kordy *postac);
//#endif