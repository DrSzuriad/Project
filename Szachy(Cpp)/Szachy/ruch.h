#pragma once
#include <deque>
#include <SFML/Graphics.hpp>
#include "plansza.h"
using namespace std;
using namespace sf;
class ruch
{
public:
	void czymozruch(deque<int>& lista, plansza& plan, const bool& gracz);//Funkcja sprawdza kt�re figury danego gracza mog� si� ruszy� i wpisuje je do listy
	bool gdzieruch(deque<int>& listafig, deque<int>& listamiej, plansza& plan, const bool& gracz, int x, int y);//Funckja sprawdza czy gracz klikn�� w figur� kt�ra mo�e si� ruszy� a nast�pnie wpisuje do listamiej pozycje na kt�re ta figura mo�e si� ruszy�
	bool ruszaniesie(deque<int>& listamiejsc, int popx, int popy, int x, int y, plansza& plan);//Funckja obs�uguje ruszenie si� fugury na inne miejsce
};