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
	int kordx;//Aktualne miejsce gdzie klikn¹³ gracz
	int kordy;
	int popkordx;//Poprzednie miejsce, gdzie klikn¹³ gracz
	int popkordy;
	int fazaruchu;//W jakim stanie znajduje siê program


	deque<int> listafigur;//Lista figur, które mog¹ wykonaæ ruch
	deque<int> listamiejsc;//Lista miejsc, gdzie mo¿e siê ruszyæ wybrana figura

public:
	void transkord(int &x,int &y);//Funkcja t³umaczy pozycjê klikniêcia myszki na pozycjê na planszy
	glowna();//Konstruktor
	deque<int>* getlistafig();//Zwraca listê figur, które mog¹ wykonaæ ruch
	bool eventy(Event event, RenderWindow* okno,plansza& plan);//Funkcja obs³uguj¹ca zdarzenia w programie
	void wypisz(RenderWindow* okno, plansza &plan, grafika& graf);//Funkcja wypisuje wszystkie elementy gry
	bool szach(deque<int>& listafig,zmienne& kontener,bool kolor,figura*** &mapa, plansza& plan);//Funkcja sprawdza czy nie ma szachu
};

