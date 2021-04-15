#pragma once
#include"Header.h"
///** @file */
//#ifndef gra_H
//#define Gra_h


/** Funkcja obsluguje uruchomienie gry oraz jej zakonczenie
@param pHead wskaznik na tablice wynikow
@param nazwa imie uzytkownika
*/
void gra(tabwyn **pHead, char *nazwa);
/** Funkcja czysci konslole
@param ja wskaznik na pozycje gracza
@param tablica wskaznik na tablice zwierajaca mape
@param pGlowa wskaznik na tablice wynikow
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
@param przeciw wspaznik na liste przeciwnikow
@return czy gracz wygral (true - wygral, false - przegral)
*/
bool klawiatura(kordy *ja, pole ***tablica, Ekwipunekstr **pGlowa, int wiersze, int kolumny, wrog **przeciw);
/** Funkcja obsluguje porusznie sie gracza
@param ja wskaznik na pozycje gracza
@param kolja wskaznik na nastepna pozycje gracza
@param tablica wskaznik na tablice zwierajaca mape
@param pGlowa wskaznik na liste kluczy ktore posiada gracz
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
@param tymczasowy wskaznik na znak jaki mia³o pole przed wejsciem gracza
@param koniec czy gracz doszedl do wyjscia z mapy
@return wartoœæ sygna³u wyjsciowego
*/
bool poruszaniesie(kordy *ja, kordy *kolja, pole ***tablica, Ekwipunekstr **pGlowa, int wiersze, int kolumny, unsigned char *tymczasowy, bool *koniec);
/** Funkcja dodaje nowy klucz do listy ekwipunku
@param pGlowa wskaznik na liste kluczy ktore posiada gracz
@param znak jaki klucz jest wstawiany
*/
void dodlista(Ekwipunekstr **pGlowa, unsigned char *znak);
/** Funkcja dodaje znaleziony klucz do ekwipunku oraz wypisuje ponownie ekwipunek
@param wysokosc ilosc wierszy mapy
@param pGlowa wskaznik na liste kluczy ktore posiada gracz
@param znak jaki klucz zostal znaleziony
*/
void znaklu(int wysokosc, Ekwipunekstr **pGlowa, unsigned char *znak);
/** Funkcja znajduje klucz w ekwipunku
@param pGlowa wskaznik na liste kluczy ktore posiada gracz
@param znak jaki klucz ma byc zaleziony w ekwipunku
@return wskaznik na znaleziony klucz
*/
Ekwipunekstr *znajdzwekw(Ekwipunekstr *pGlowa, unsigned char znak);
/** Funkcja usuwa klucz z ekwipunku i otwiera drzwi
@param wysokosc ilosc wierszy mapy
@param pGlowa wskaznik na liste kluczy ktore posiada gracz
@param jakie drzwi gracz probuje otworzyc
@return czy udalo sie otworzyc drzwi
*/
bool otwdrzwi(int wysokosc, Ekwipunekstr **pGlowa, unsigned char *znak);
/** Funkcja zczytuje wcisniety klawisz oraz przekazuje kolejna pozycje gracza
@param ja wskaznik na pozycje gracza
@param kolja wskaznik na nastepna pozycje gracza
@return czy gracz chce wyjsc z rozgrywki
*/
bool ruch(kordy *ja, kordy *kolja);
//#endif
