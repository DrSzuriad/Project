#pragma once
#include "figura.h"
class kon :
	public figura
{
private:

public:

	kon(Sprite obr, bool kol);//Funkcja tworzy obiekt skoczka o podanym kolorze
	virtual bool mozrusz(figura*** mapa, zmienne kontener, int x, int y);//Funkcja sprawdza czy dana figura ma mo�liwo�� ruchu
	virtual void gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista);//Funkcja sprawdza na jakie pola figura ma mo�liwo�� si� ruszy�
	virtual bool ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne& kontener);//Funkcja realizuje ruchy specjalne(roszady itp.)
	virtual bool jakafigura(int rodzaj);//Funkcja zwraca widomo�� czy obiekt dla kt�rego jest wywo�ana ta funkcja jest taki jak podany przez funkcj�
};

