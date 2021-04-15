#pragma once
#include "deque"
using namespace std;

class zmienne
{
private:
	deque<int> bialyprzelot;//Czy kolor bia³y wykona³ przeskok pionka o dwa pola
	deque<int> czarnyprzelot;//Czy kolor czarny wykona³ przeskok pionka o dwa pola
	deque<int> czarnykrol;//Pozycja czarnego króla
	deque<int> bialykrol;//Pozycja bia³rgo króla
	bool roszadabial0 = true;//Czy jest mo¿liwa d³uga roszada bia³ego króla
	bool roszadabial7 = true;//Czy jest mo¿liwa krótka roszada bia³ego króla
	bool roszadaczar0 = true;//Czy jest mo¿liwa d³uga roszada czarnego króla
	bool roszadaczar7 = true;//Czy jest mo¿liwa krótka roszada czarnego króla
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

