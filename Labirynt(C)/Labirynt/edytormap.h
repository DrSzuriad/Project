#pragma once
#include"Header.h"
///** @file */
//#ifndef edytormap_H
//#define Edytormap_h

/** Funkcja obsluguje uruchomienie edytora map
*/
void edytormap();
/** Funkcja tworzy nowa mape
*/
void nowamapa();
/** Funkcja wczytuje istniejaca mape
*/
void staramapa();
/** Funkcja zapisuje znak do tablicy
@param znak jak iznak ma byc wpisany
@param pozycja w jakim miejscu ma sie znajdowac ten znak
@param mapa wskaznik na mape
*/
void wpisz(int znak, kordy pozycja, wskpole mapa);
/** Funkcja zczytuje od gracza, w ktora strone ma poruszac sie przeciwnik
@return kierunek poruszania sie
*/
int wktorastrone();
/** Funkcja obsluguje porusznie sie po mapie podczas edycji
@param pozycja aktualna pozycja znacznika
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
*/
void przemieszczenie(kordy *pozycja, int wiersze, int kolumny);
/** Funkcja pozwala edytowac mape oraz ja zapisac
@param mapa wskaznik na mape
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
@param przeciwnicy wskaznik na liste przeciwnikow
@param pozycja postaci na mapie
*/
void edycja(wskpole mapa, int wiersze, int kolumny, wrog **przeciwnicy, kordy **postac);
//#endif
