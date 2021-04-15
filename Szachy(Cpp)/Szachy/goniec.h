#pragma once
#include "figura.h"
class goniec :
	public figura
{
private:

public:

	goniec(Sprite obr, bool kol);//funkcja tworzy obiekt goñca o podanym kolorze
	virtual bool mozrusz(figura*** mapa, zmienne kontener,int x,int y);//Funkcja sprawdza czy dana figura ma mo¿liwoœæ ruchu
	virtual void gdzierusz(figura*** mapa, zmienne kontener, int x, int y,deque<int>& lista);//Funkcja sprawdza na jakie pola figura ma mo¿liwoœæ siê ruszyæ
	virtual bool ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne &kontener);//Funkcja realizuje ruchy specjalne(roszady itp.)
	virtual bool jakafigura(int rodzaj);//Funkcja zwraca widomoœæ czy obiekt dla którego jest wywo³ana ta funkcja jest taki jak podany przez funkcjê
};

