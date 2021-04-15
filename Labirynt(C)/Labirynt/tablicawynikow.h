#pragma once
#include"Header.h"
///** @file */
//#ifndef tablicawynikow_H
//#define Tablicawynikow_h

/** Funkcja dodaje nowy wynik do listy wynikow
@param pHead wskaznik na tablice wynikow
@param nowy wstawiany element tablicy
*/
void dodajwynik(tabwyn **pHead, tabwyn *nowy);
/** Funkcja wypisuje tablice wynikow
@param pHead wskaznik na tablice wynikow
*/
void tablicawynikow(tabwyn *pHead);
/** Funkcja wpisuje do tablicy uzyskany przez gracza wynik
@param pHead wskaznik na tablice wynikow
@param nazwa imie gracza
@param ptk ilosc punktow jakie uzyskal gracz
*/
void wipiszdotablicy(tabwyn **pHead, char nazwa[30], int ptk);
/** Funkcja zapisuje tablice wynikow do pliku
@param pHead wskaznik na tablice wynikow
*/
void zapisztablice(tabwyn *pHead);
//#endif