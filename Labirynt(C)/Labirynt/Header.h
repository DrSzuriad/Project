#pragma once
#include<stdbool.h>
//#include <stdlib.h>
//#include <vld.h>
///** @file */
//#ifndef header_H
//#define Header_h


enum czmwej { tak = 0, nie = 1, drz = 2, kon = 3 };
enum sterowanie { zkps=224,zkps0=0, lewo=75,prawo=77,gora=72,dol=80 };
enum postacie { gracz=208, potwor = 245 };
enum elementydlagracza{chodzenie=1,eglr,egpr,edlr,edpr,epoz,epio,elsc,epsc,egsc,edsc,esro,ekro,epus,eklu1,eklu2,eklu3,eklu4,eklu5,eklu6,ezam1,ezam2,ezam3,ezam4,ezam5,ezam6,ewyjscie,epotwor,egracz,wyjsciezzapisem,wyjsciebezzapisu};
typedef struct {
	unsigned char obraz;///<jaki obrazek ma sie wyswietlac na tym polu
	int wejscie;///<czy gracz lub potwor moze wejsc na to pole
}pole;
typedef struct {
	int cordx;///<pozycja w pionie
	int cordy;///<pozycja w poziomie
} kordy;

typedef pole**** wskpole;

typedef struct Ekwipunekstr {
	struct Ekwipunekstr *pNext;///<wskaznik na kolejny element listy
	unsigned char przedmiot;///<rodzaj przedmiotu
}Ekwipunekstr;

typedef struct wrog{
	kordy pozycja;///<pozycja wroga na mapie
	int kierunek;///<kierunek, w ktorym sie porusza
	unsigned char naczymstoi;///<co znajduje sie na polu na ktorym stoi 
	struct wrog *pNext;///<wskaznik na kolejnego przeciwnika w liscie
	bool ruch;///<czy przeciwnik sie ruszyl w tym przebiegu petli
}wrog;

typedef struct tabwyn {
	struct tabwyn *pNext;///<wskaznik na kolejny element tablicy
	char nazwa[30];///<dlugosc nazwy gracza
	int wynik;///<ilosc punktow, jaka zdobyl gracz
}tabwyn;

/** Funkcja przemieszcza kursor wpisywania na podana pozycje
@param x pozycja w pionie
@param y pozycja w poziomie
*/
void gotoxy(int x, int y);
/** Funkcja czysci konslole
*/
void czyszczenie();
/** Funkcja usuwa wszystkie elementy z bufora stdin
*/
void czyszczeniebufora();
/** Funkcja wpisuje znak w podanym miejscu
@param wiersz w ktorym wierszu ma byc wstawiony znak
@param kolumna w ktorej kolumnie ma byc wstawiony znak
@param znak jaki znak ma byc wstawiony
@param wysokosc mapy
*/
void podmien(int wiersz, int kolumna, int znak,int wysokosc);
/** Funkcja czeka, az gracz wcisnie dowolny klawisz
*/
void dowolnyprzycisk();
//#endif








