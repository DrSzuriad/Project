#pragma once


#include <map>
#include <SFML/Graphics.hpp>
#include "zmienne.h"
#include "enum.h"
#include <deque>

using namespace sf;



class figura: public Drawable
{
protected:
	Sprite obrazek;
	bool kolor;
public:
	void draw(RenderTarget& target, RenderStates state) const;//Funkcja rysuje obrazek w oknie
	bool getkol();//Funkcja zwraca kolor figury
	void setpos(Vector2f a);//Funkcja ustawia pozycje figury
	void setpos(float x,float y);//Funkcja ustawia pozycje figury
	void setpos(int x, int y);//Funkcja ustawia pozycje figury
	virtual bool mozrusz(figura*** mapa, zmienne kontener,int x,int y) = 0;//Funkcja sprawdza czy dana figura ma mo¿liwoœæ ruchu
	virtual void gdzierusz(figura*** mapa, zmienne kontener, int x, int y,deque<int>& lista) = 0;//Funkcja sprawdza na jakie pola figura ma mo¿liwoœæ siê ruszyæ
	virtual bool ruchspecjalny(int popx,int popy,int x,int y,figura*** bierki,zmienne &kontener)=0;//Funkcja realizuje ruchy specjalne(roszady itp.)
	virtual bool jakafigura(int rodzaj) = 0;//Funkcja zwraca widomoœæ czy obiekt dla którego jest wywo³ana ta funkcja jest taki jak podany przez funkcjê
	bool bitepole(figura*** bierki, deque<int>& kto, bool kolor, int x, int y);//Funkcja sprawdza czy dane pole jest bite przez dany kolor
	bool czykrolbity(figura*** bierki, bool kolor, int pox, int popy, int x, int y, zmienne kontener);//Funkcja sprawdza czy król jest bity przez przeciwnika
};