#pragma once
#include "deque"
using namespace std;

class zmienne
{
private:
	deque<int> bialyprzelot;//Czy kolor bia�y wykona� przeskok pionka o dwa pola
	deque<int> czarnyprzelot;//Czy kolor czarny wykona� przeskok pionka o dwa pola
	deque<int> czarnykrol;//Pozycja czarnego kr�la
	deque<int> bialykrol;//Pozycja bia�rgo kr�la
	bool roszadabial0 = true;//Czy jest mo�liwa d�uga roszada bia�ego kr�la
	bool roszadabial7 = true;//Czy jest mo�liwa kr�tka roszada bia�ego kr�la
	bool roszadaczar0 = true;//Czy jest mo�liwa d�uga roszada czarnego kr�la
	bool roszadaczar7 = true;//Czy jest mo�liwa kr�tka roszada czarnego kr�la
public:
	bool getbprze(int  x, int y);
	bool getcprze(int  x, int y);
	bool getrobi0();
	bool getrobi7();
	bool getrocz0();
	bool getrocz7();
	void setrobi0(bool war);
	void setrobi7(bool war);
	void setrocz0(bool war);
	void setrocz7(bool war);
	void setkorbia(int x, int y);
	void setkorcza(int x, int y);
	void usunczprze();
	void usunbiprze();
	void setkrbia(int x,int y);
	void getkrbia(int& x, int& y);
	void setkrcza(int x, int y);
	void getkrcza(int& x, int& y);

};

