#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/String.hpp>
#include "plansza.h"
#include "enum.h"
#include "ruch.h"
using namespace sf;

class glowna : public ruch
{
	int kordx;//Aktualne miejsce gdzie klikn�� gracz
	int kordy;
	int popkordx;//Poprzednie miejsce, gdzie klikn�� gracz
	int popkordy;
	int fazaruchu;//W jakim stanie znajduje si� program


	deque<int> listafigur;//Lista figur, kt�re mog� wykona� ruch
	deque<int> listamiejsc;//Lista miejsc, gdzie mo�e si� ruszy� wybrana figura

public:
	void transkord(int &x,int &y);//Funkcja t�umaczy pozycj� klikni�cia myszki na pozycj� na planszy
	glowna();//Konstruktor
	deque<int>* getlistafig();//Zwraca list� figur, kt�re mog� wykona� ruch
	bool eventy(Event event, RenderWindow* okno,plansza& plan);//Funkcja obs�uguj�ca zdarzenia w programie
	void wypisz(RenderWindow* okno, plansza &plan, grafika& graf);//Funkcja wypisuje wszystkie elementy gry
	bool szach(deque<int>& listafig,zmienne& kontener,bool kolor,figura*** &mapa, plansza& plan);//Funkcja sprawdza czy nie ma szachu
};

