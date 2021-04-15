#include "hetman.h"




hetman::hetman(Sprite obr, bool kol)
{
	obrazek = obr;
	kolor = kol;
}

bool hetman::mozrusz(figura*** mapa, zmienne kontener,int x,int y)
{

	if (kolor == bialy) {//bia³y hetman
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1,y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x -1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x, y + 1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x, y - 1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//prawo ty³
			return true;
	}

	else {
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1,y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x, y + 1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x , y - 1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x -1, y + 1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener))//prawo ty³
			return true;
	}

	return false;
}

void hetman::gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista)
{
	if (kolor == bialy) {
		for (int i = 1; i < 8; i++) {
			if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i] == nullptr) {//lewo góra
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y - i);
				}
			}
			else if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i]->getkol() == czarny) {
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
			if (x + i < 8 && y - i >= 0 && mapa[x + i][y - i] == nullptr) {//prawo góra
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
			if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i] == nullptr) {//lewo dó³
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
			if (x + i < 8 && y + i < 8 && mapa[x + i][y + i] == nullptr) {//prawo dó³
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
				}
			}
			else if (x + i < 8 && y + i < 8 && mapa[x + i][y + i]->getkol() == czarny) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y + i, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {// w lewo
			if (y - i >= 0 && mapa[x][y - i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x, y - i, kontener)) {
					lista.push_back(x);
					lista.push_back(y - i);
				}
			}
			else if (y - i >= 0 && mapa[x][y - i]->getkol() == czarny ) {
				if (!czykrolbity(mapa, kolor, x, y, x, y - i, kontener)) {
					lista.push_back(x);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {// w prawo
			if (y + i < 8 && mapa[x][y + i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x, y + i, kontener)) {
					lista.push_back(x);
					lista.push_back(y + i);
				}
			}
			else if (y + i < 8 && mapa[x][y + i]->getkol() == czarny ) {
				if (!czykrolbity(mapa, kolor, x, y, x, y + i, kontener)) {
					lista.push_back(x);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {//w górê
			if (x - i >= 0 && mapa[x - i][y] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y);
				}
			}
			else if (x - i >= 0 && mapa[x - i][y]->getkol() == czarny) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {//w dó³
			if (x + i < 8 && y < 8 && mapa[x + i][y] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y);
				}
			}
			else if (x + i < 8 && y < 8 && mapa[x + i][y]->getkol() == czarny) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y);
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
			else if (x - i >= 0 && y - i >= 0 && mapa[x - i][y - i]->getkol() == bialy) {
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
				if (!czykrolbity(mapa, kolor, x, y, x - i, y - i, kontener)) {
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
			if (x - i >= 0 && y + i < 8 && mapa[x - i][y + i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y + i, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y + i);
				}
			}
			else if (x - i >= 0 && y * i < 8 && mapa[x - i][y + i]->getkol() == bialy) {
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
		for (int i = 1; i < 8; i++) {// w lewo
			if (y - i >= 0 && mapa[x][y - i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x, y - i, kontener)) {
					lista.push_back(x);
					lista.push_back(y - i);
				}
			}
			else if (y - i >= 0 && mapa[x][y - i]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x, y - i, kontener)) {
					lista.push_back(x);
					lista.push_back(y - i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {// w prawo
			if (y + i < 8 && mapa[x][y + i] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x, y + i, kontener)) {
					lista.push_back(x);
					lista.push_back(y + i);
				}
			}
			else if (y + i < 8 && mapa[x][y + i]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x, y + i, kontener)) {
					lista.push_back(x);
					lista.push_back(y + i);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {//w górê
			if (x - i >= 0 && mapa[x - i][y] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y);
				}
			}
			else if (x - i >= 0 && mapa[x - i][y]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x - i, y, kontener)) {
					lista.push_back(x - i);
					lista.push_back(y);
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++) {//w dó³
			if (x + i < 8 && y < 8 && mapa[x + i][y] == nullptr) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y);
				}
			}
			else if (x + i < 8 && y < 8 && mapa[x + i][y]->getkol() == bialy) {
				if (!czykrolbity(mapa, kolor, x, y, x + i, y, kontener)) {
					lista.push_back(x + i);
					lista.push_back(y);
					break;
				}
			}
			else
				break;
		}
	}
}

bool hetman::ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne &kontener)
{
	return false;
}

bool hetman::jakafigura(int rodzaj)
{
	if (rodzaj == hetc && kolor == czarny)
		return true;
	else if (rodzaj == hetb && kolor == bialy)
		return true;
	return false;
}


