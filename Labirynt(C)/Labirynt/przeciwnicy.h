#pragma once
#include"Header.h"
///** @file */
//#ifndef przeciwnicy_H
//#define Przeciwnicy_h

/** Funkcja dodaje przeciwnika do listy przeciwnikow
@param przeciwnicy lista przeciwnikow
@param pozycja miejsce w ktorym znajduje sie przeciwnik
@param kierunek kierunek, w ktorym porusz sie przeciwnik
@param naczym na jakim polu stoi przeciwnik
*/
void dodprzec(wrog **przeciwnicy, kordy pozycja, int kierunek, int naczym);
/** Funkcja zmienia pozycje przeciwnika na mapie
@param ja aktualna pozycja przeciwnika
@param kolja nastepna pozycja przeciwnika
@param tablica wskaznik na mape
@param wiersze ilosc wierszy mapy
@param tymczasowy na jakim polu stoi przeciwnik
*/
void zmianapozycjiprze(kordy *ja, kordy *kolja, pole ***tablica, int wiersze, unsigned char *tymczasowy);
/** Funkcja szuka przeciwnika znajdujacego sie na danej pozcji w liscie przeciwnikow
@param gdzie pozycja przeciwnika
@param przec lista przeciwnikow
@return wskaznik na znalezionego przeciwnika
*/
wrog* znajdzprzeciwnika(kordy gdzie, wrog *przec);
/** Funkcja podaje nastepna pozycje przeciwnika
@param przeciw aktualnie ruszjacy sie przeciwnik 
@param kolejne kolejna pozycja przeciwnika
*/
void ruchnormalny(wrog *przeciw, kordy *kolejne);
/** Funkcja podaje pozycje pozycji przeciwnika pod zmianie kierunku oraz zmienia kierunek poruszania sie przeciwnika
@param przeciw aktualnie ruszjacy sie przeciwnik
@param kolejne kolejna pozycja przeciwnika
*/
void ruchodwrotny(wrog *przeciw, kordy *kolejne);
/** Funkcja obsluguje ruch, gdy potwor idzie zgodnie z aktualnym kierunkiem ruchu
@param przeciw aktualnie ruszajacy sie przeciwnik
@param tablica wkaznik na mape
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param koniec czy gracz zostal zabity
@param kolejne kolejna pozycja przeciwnika
@param wszyscy wskaznika na liste przeciwnikow
@return czy udalo sie wykonac ruch
*/
bool ruchnormalnyzw(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy *kolejne, wrog *wszyscy);
/** Funkcja obsluguje ruch, gdy potwor nie moze isc zgodnie z wczesniejszym kierunkiem ruchu
@param przeciw aktualnie ruszajacy sie przeciwnik
@param tablica wkaznik na mape
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param koniec czy gracz zostal zabity
@param kolejne kolejna pozycja przeciwnika
@param wszyscy wskaznika na liste przeciwnikow
@return czy udalo sie wykonac ruch
*/
bool ruchodwrotnyzw(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy *kolejne, wrog *wszyscy);
/** Funkcja obsluguje sytuacje gdy na drodze przeciwnika pojawi sie drugi przeciwnik
@param przeciw aktualnie ruszajacy sie przeciwnik
@param tablica wkaznik na mape
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param koniec czy gracz zostal zabity
@param odkogo ktory przeciwnik kazal ruszyc sie aktualnemu przeciwnikowi
@param sciana czy przeciwnik wykonuje ruch odwrotny
@param wszyscy wskaznika na liste przeciwnikow
@return czy udalo sie wykonac ruch
*/
bool potworprzed(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy odkogo, bool sciana, wrog *wszyscy);
/** Funkcja wykonuje ruch jednego przeciwnika
@param przeciw aktualnie ruszajacy sie przeciwnik
@param tablica wkaznik na mape
@param wysokosc ilosc wierszy mapy
@param szerokosc ilosc kolumn mapy
@param koniec czy gracz zostal zabity
@param wszyscy wskaznika na liste przeciwnikow
*/
void gdzieiscprze(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, wrog *wszyscy);
/** Funkcja czysci znacznik wykoniania ruchu przez przeciwnikow w danej turze 
@param przeciw wskaznik na liste przeciwnikow
*/
void wyszczscruch(wrog **przeciw);
/** Funkcja wykonuje ruchy wszystkich przeciwnikow
@param przeciw wskaznik na liste przeciwnikow
@param tablica wskaznik na mape
@param wiersze ilosc wierszy mapy
@param kolumny ilosc kolumn mapy
@return czy gracz zostal zabity
*/
bool poruszprzeciwnikami(wrog **przeciw, pole ***tablica, int wiersze, int kolumny);
/** Funkcja usuwa przeciwnika znajdujacego sie na danej pozycji na mapie z listy przeciwnikow
@param przeciwnicy wskaznik na liste przeciwnikow
@param pozycja pozycja usuwanego przeciwnika
*/
void usunprzeciw(wrog **przeciwnicy, kordy pozycja);
//#endif
