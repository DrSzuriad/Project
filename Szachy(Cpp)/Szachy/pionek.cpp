#include "pionek.h"


pionek::pionek(Sprite obr, bool kol)
{
	obrazek = obr;
	kolor=kol;
}

bool pionek::mozrusz(figura*** mapa, zmienne kontener, int x, int y)
{
	if (kolor == bialy) {//bia³y pionek
		if (y - 1 >= 0 && mapa[x][y - 1] == nullptr && !czykrolbity(mapa, kolor, x, y, x, y - 1, kontener))//ruch do przodu
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && mapa[x + 1][y - 1] != nullptr && mapa[x + 1][y - 1]->getkol() == czarny && !czykrolbity(mapa, kolor, x, y, x +1, y - 1, kontener))//bicie w w prawo
			return true;
		else if (x - 1 >= 0 && y - 1 >= 0 && mapa[x - 1][y - 1] != nullptr && mapa[x - 1][y - 1]->getkol() == czarny && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener))//bicie w w lewo
			return true;
		else if (x + 1 < 8 && y ==3 && mapa[x + 1][y - 1] == nullptr && kontener.getcprze(x + 1, y - 1) == true && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener))//bicie w w prawo
			return true;
		else if (x - 1 >= 0 && y ==3 && mapa[x - 1][y - 1] == nullptr && kontener.getcprze(x - 1, y - 1) == true && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener))//bicie w w prawo
			return true;
	}

	else {//czarny pionek
		if (y + 1 < 8 && mapa[x][y + 1] == nullptr && !czykrolbity(mapa, kolor, x, y, x, y + 1, kontener))//ruch do przodu
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && mapa[x + 1][y + 1] != nullptr && mapa[x + 1][y + 1]->getkol() == bialy && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//bicie w w prawo
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && mapa[x - 1][y + 1] != nullptr && mapa[x - 1][y + 1]->getkol() == bialy && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener))//bicie w w lewo
			return true;
		else if (x + 1 < 8 && y == 4 && mapa[x + 1][y + 1] == nullptr && kontener.getbprze(x + 1, y + 1) == true && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//bicie w w prawo
			return true;
		else if (x - 1 >= 0 && y == 4 && mapa[x -1][y + 1]== nullptr && kontener.getbprze(x - 1, y + 1) == true && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener))//bicie w w prawo
			return true;
	}


	return false;
}

void pionek::gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista)
{
	if (kolor == bialy) {//bia³y pionek
		if (y - 1 >= 0 && mapa[x][y - 1] == nullptr && !czykrolbity(mapa, kolor, x, y, x, y - 1, kontener)) {//ruch do przodu
			lista.push_back(x);
			lista.push_back(y - 1);
		}
		if (x + 1 < 8 && y - 1 >= 0 && mapa[x + 1][y - 1] != nullptr && mapa[x + 1][y - 1]->getkol() == czarny && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener)) {//bicie w w prawo
			lista.push_back(x + 1);
			lista.push_back(y - 1);
		}
		if (x - 1 >= 0 && y - 1 >= 0 && mapa[x - 1][y - 1] != nullptr && mapa[x - 1][y - 1]->getkol() == czarny && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener)) {//bicie w w lewo
			lista.push_back(x - 1);
			lista.push_back(y - 1);
		}
		if (y == 6 && mapa[x][y - 2] == nullptr && !czykrolbity(mapa, kolor, x, y, x, y - 2, kontener)) {
			lista.push_back(x);
			lista.push_back(y - 2);
		}
		if (x + 1 < 8 && y == 3 && mapa[x + 1][y - 1] == nullptr && kontener.getcprze(x + 1, y - 1) == true && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener)) {//bicie w w prawo
			lista.push_back(x + 1);
			lista.push_back(y - 1);
		}
		if (x - 1 >= 0 && y == 3 && mapa[x - 1][y - 1] == nullptr && kontener.getcprze(x - 1, y - 1) == true && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener)) {//bicie w w lewo
			lista.push_back(x - 1);
			lista.push_back(y - 1);
		}
	}

	else {//czarny pionek
		if (y + 1 < 8 && mapa[x][y + 1] == nullptr && !czykrolbity(mapa, kolor, x, y, x , y +1, kontener)) {//ruch do przodu
			lista.push_back(x);
			lista.push_back(y + 1);
		}
		if (x + 1 < 8 && y + 1 < 8 && mapa[x + 1][y + 1] != nullptr && mapa[x + 1][y + 1]->getkol() == bialy && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener)) {//bicie w w prawo
			lista.push_back(x + 1);
			lista.push_back(y + 1);
		}
		if (x - 1 >= 0 && y + 1 < 8 && mapa[x - 1][y + 1] != nullptr && mapa[x - 1][y + 1]->getkol() == bialy && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener)) {//bicie w w lewo
			lista.push_back(x - 1);
			lista.push_back(y + 1);
		}
		if (y == 1 && mapa[x][y + 2] == nullptr && !czykrolbity(mapa, kolor, x, y, x, y +2, kontener)) {
			lista.push_back(x);
			lista.push_back(y + 2);
		}
		if (x + 1 < 8 && y == 4 && mapa[x + 1][y + 1] == nullptr && kontener.getbprze(x + 1, y + 1) == true && !czykrolbity(mapa, kolor, x, y, x+ 1, y + 1, kontener)) {//bicie w w prawo
			lista.push_back(x + 1);
			lista.push_back(y + 1);
		}
		if (x - 1 >= 0 && y == 4 && mapa[x - 1][y + 1] == nullptr && kontener.getbprze(x - 1, y + 1) == true && !czykrolbity(mapa, kolor, x, y, x-1, y+ 1, kontener)) {//bicie w w lewo
			lista.push_back(x - 1);
			lista.push_back(y + 1);
		}
	}
}

bool pionek::ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne &kontener)
{
	if (kolor == bialy) {
		if (kontener.getcprze(x, y) == true) {//bicie w przelocie
			delete(bierki[x][popy]);
			bierki[x][popy] = nullptr;
			figura* akt = bierki[popx][popy];
			bierki[x][y] = akt;
			bierki[x][y]->setpos(x, y);
			bierki[popx][popy] = nullptr;
			return true;
		}
		else if(popy - y== 2) {
			kontener.setkorbia(x, y + 1);
		}
	}
	else {
		if (kontener.getbprze(x, y) == true) {
			delete(bierki[x][popy]);
			bierki[x][popy] = nullptr;
			figura* akt = bierki[popx][popy];
			bierki[x][y] = akt;
			bierki[x][y]->setpos(x, y);
			bierki[popx][popy] = nullptr;
			return true;
		}
		else if (popy - y == -2) {
			kontener.setkorcza(x, y - 1);
		}
	}
	return false;
}

bool pionek::jakafigura(int rodzaj)
{
	if (rodzaj == pioc && kolor == czarny)
		return true;
	else if (rodzaj == piob && kolor == bialy)
		return true;
	return false;
}
