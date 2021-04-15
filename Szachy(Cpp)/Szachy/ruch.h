#pragma once
#include <deque>
#include <SFML/Graphics.hpp>
#include "plansza.h"
using namespace std;
using namespace sf;
class ruch
{
public:
	void czymozruch(deque<int>& lista, plansza& plan, const bool& gracz);//Funkcja sprawdza które figury danego gracza mog¹ siê ruszyæ i wpisuje je do listy
	bool gdzieruch(deque<int>& listafig, deque<int>& listamiej, plansza& plan, const bool& gracz, int x, int y);//Funckja sprawdza czy gracz klikn¹³ w figurê która mo¿e siê ruszyæ a nastêpnie wpisuje do listamiej pozycje na które ta figura mo¿e siê ruszyæ
	bool ruszaniesie(deque<int>& listamiejsc, int popx, int popy, int x, int y, plansza& plan);//Funckja obs³uguje ruszenie siê fugury na inne miejsce
};