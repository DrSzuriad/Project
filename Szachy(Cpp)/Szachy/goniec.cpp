#include "goniec.h"



goniec::goniec(Sprite obr, bool kol)
{
	obrazek = obr;
	kolor = kol;
}

bool goniec::mozrusz(figura*** mapa, zmienne kontener,int x,int y)
{
	if (kolor == bialy) {//bia³y goniec

		if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == czarny)&&!czykrolbity(mapa,kolor,x,y,x-1,y-1,kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//prawo ty³
			return true;
	}

	else {
		if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//prawo ty³
			return true;
	}



	return false;
}

void goniec::gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista)
{

	if (kolor == bialy) {
		for (int i = 1; i < 8; i++) {
			if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i] == nullptr ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y - i);
				}
			}
			else if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i]->getkol() == czarny ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {
			if (x + i < 8 && y - i >= 0 && mapa[x + i][y - i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y - i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y - i);
				}
			}
			else if (x + i < 8 && y - i >= 0 && mapa[x + i][y - i]->getkol() == czarny) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y - i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {
			if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i] == nullptr ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y + i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y + i);
				}
			}
			else if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i]->getkol() == czarny ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y + i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {
			if (x + i < 8 && y + i < 8 && mapa[x + i][y + i] == nullptr ) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
				}
			}
			else if (x + i < 8 && y + i < 8 && mapa[x + i][y + i]->getkol() == czarny ) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}

	}
	else {//dla czarnego

		for (int i = 1; i < 8; i++) {
			if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y - i);
				}
			}
			else if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i]->getkol() == bialy ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}

		for (int i = 1; i < 8; i++) {
			if (x + i < 8 && y - i >= 0 && mapa[x + i][y - i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y - i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y - i);
				}
			}
			else if (x + i < 8 && y - i >= 0 && mapa[x + i][y - i]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y - i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {
			if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i] == nullptr ) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y + i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y + i);
				}
			}
			else if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y + i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {
			if (x + i < 8 && y + i < 8 && mapa[x + i][y + i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
				}
			}
			else if (x + i < 8 && y + i < 8 && mapa[x + i][y + i]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
	}
}

bool goniec::ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne &kontener)
{
	return false;
}

bool goniec::jakafigura(int rodzaj)
{
	if (rodzaj == gonc && kolor == czarny)
		return true;
	else if (rodzaj == gonb && kolor == bialy)
		return true;
	return false;
}
