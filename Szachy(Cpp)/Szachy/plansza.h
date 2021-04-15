#pragma once
#include "pole.h"
#include "zmienne.h"
#include "enum.h"
#include "pionek.h"
#include "wieza.h"
#include "kon.h"
#include "goniec.h"
#include "hetman.h"
#include "krol.h"



class plansza: public Drawable
{

private:
	
	zmienne kontener;//Zmienne odpowiadaj�ce za ruchy specjalne oraz po�o�enie kr�li
	figura*** bierki = nullptr;//Tablica zwieraj�ca fiugury
	pole ***mapa=nullptr;//Szachownica
	pole boku = pole(48, 48, 404, 2, Color::Black, nic);//G�rny bok planszy
	pole bokl = pole(48, 48, 2, 404, Color::Black, nic);//Lewy bok planszy
	pole bokd = pole(48, 450, 404, 2, Color::Black, nic);//Dolny bok planszy
	pole bokr = pole(450, 48, 2, 404, Color::Black, nic);//Prawy bok planszy
	void draw(RenderTarget& target, RenderStates state) const;//Funckja rysuje plansze
public:

	plansza(grafika graf);//Konstruktor
	~plansza();//Destruktor
	pole getbu();
	pole getbl();
	pole getbd();
	pole getbr();
	figura *getfig(int x,int y);//Funkcja zwaraca jaka figura znajduje si� na wskazanym polu
	void setfig(figura* fig,int x, int y);//Funkcja ustawia figur� na wskazane pole
	void setfig(int fig, grafika graf,int x,int y);//Funckja tworzy figur� na wskazanym polu
	figura*** &getbierki();//Funkcja zwraca tablic� figur
	zmienne &getzmienne();//Funkcja zwraca kontener zmiennych
	void usunbiaprze();//Funckja usuwa mo�liwo� bicia w przelocie dla czarnych
	void usunczaprze();//Funckja usuwa mo�liwo� bicia w przelocie dla bialych
};



