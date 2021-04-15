#include "krol.h"






krol::krol(Sprite obr, bool kol)
{
	obrazek = obr;
	kolor = kol;
}

bool krol::mozrusz(figura*** mapa, zmienne kontener,int x,int y)
{
	deque<int>akt;
	if (kolor == bialy) {//bia³y król
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == czarny)&&!bitepole(mapa,akt,bialy,x+1,y) && !czykrolbity(mapa, kolor, x, y, x + 1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x -1, y) && !czykrolbity(mapa, kolor, x, y, x - 1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x, y+1) && !czykrolbity(mapa, kolor, x, y, x , y+1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x , y-1) && !czykrolbity(mapa, kolor, x, y, x , y-1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x - 1, y-1) && !czykrolbity(mapa, kolor, x, y, x - 1, y-1, kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x + 1, y-1) && !czykrolbity(mapa, kolor, x, y, x + 1, y-1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x - 1, y+1) && !czykrolbity(mapa, kolor, x, y, x -1, y+1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x + 1, y+1) && !czykrolbity(mapa, kolor, x, y, x + 1, y+1, kontener))//prawo ty³
			return true;
		//roszada lewa
		else if (kontener.getrobi0()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, bialy, 4, 7)) {//król nie mo¿e byæ szachowany
				if (mapa[3][7] == nullptr && mapa[2][7] == nullptr && mapa[1][7] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, bialy, 3, 7) && !bitepole(mapa, akt, bialy, 2, 7)) {
						return true;
					}

				}
			}
		}
		//prawa roszada
		else if (kontener.getrobi7()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, bialy, 4, 7)) {//król nie mo¿e byæ szachowany
				if (mapa[5][7] == nullptr && mapa[6][7] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, bialy, 5, 7) && !bitepole(mapa, akt, bialy, 6, 7)) {
						return true;
					}

				}
			}
		}
	}
	else {
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y)&& !czykrolbity(mapa, kolor, x, y, x + 1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y) && !czykrolbity(mapa, kolor, x, y, x -1, y, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x , y+1) && !czykrolbity(mapa, kolor, x, y, x , y+1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x , y-1) && !czykrolbity(mapa, kolor, x, y, x , y-1, kontener))//czy pole jest puste, jeœli nie to czy mo¿na biæ
			return true;
		else if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y-1) && !czykrolbity(mapa, kolor, x, y, x-1, y-1, kontener))//lewo przód
			return true;
		else if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y-1) && !czykrolbity(mapa, kolor, x, y, x+1, y-1, kontener))//prawo przód
			return true;
		else if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y+1) && !czykrolbity(mapa, kolor, x, y, x-1, y+1, kontener))//lewo ty³
			return true;
		else if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y+1) && !czykrolbity(mapa, kolor, x, y, x+1 , y+1, kontener))//prawo ty³
			return true;
		//lewa roszada
		else if (kontener.getrocz0()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, czarny, 4,0)) {//król nie mo¿e byæ szachowany
				if (mapa[3][0] == nullptr && mapa[2][0] == nullptr && mapa[1][0] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, czarny, 3,0) && !bitepole(mapa, akt, czarny, 2, 0)) {
						return true;
					}

				}
			}
		}
		//prawa roszada
		else if (kontener.getrocz7()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, czarny, 4, 0)) {//król nie mo¿e byæ szachowany
				if (mapa[5][0] == nullptr && mapa[6][0] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, czarny, 5, 0) && !bitepole(mapa, akt, czarny, 6, 0)) {
						return true;
					}

				}
			}
		}
	}
	return false;
}


void krol::gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista)
{
	deque<int>akt;
	if (kolor == bialy) {//bia³y król
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x + 1, y)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y, kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y);
			}
		}
		if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x - 1, y)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x - 1, y, kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y);
			}
		}
		if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x, y + 1)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x, y + 1, kontener)) {
				lista.push_back(x);
				lista.push_back(y + 1);
			}
		}
		if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x, y - 1)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x, y - 1, kontener)) {
				lista.push_back(x);
				lista.push_back(y - 1);
			}
		}
		if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x - 1, y - 1)) {//lewo przód
			if (!czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y - 1);
			}
		}
		if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x + 1, y - 1)) {//prawo przód
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y - 1);
			}
		}
		if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x - 1, y + 1)) {//lewo ty³
			if (!czykrolbity(mapa, kolor, x, y, x - 1, y + 1, kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y + 1);
			}
		}
		if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == czarny) && !bitepole(mapa, akt, bialy, x + 1, y + 1)) {//prawo ty³
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y + 1);
			}
		}
		//roszada lewa
		if (kontener.getrobi0()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, bialy, 4, 7)) {//król nie mo¿e byæ szachowany
				if (mapa[3][7] == nullptr && mapa[2][7] == nullptr && mapa[1][7] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, bialy, 3, 7) && !bitepole(mapa, akt, bialy, 2, 7)) {
						lista.push_back(2);
						lista.push_back(7);
					}

				}
			}
		}
		//prawa roszada
		if (kontener.getrobi7()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, bialy, 4, 7)) {//król nie mo¿e byæ szachowany
				if (mapa[5][7] == nullptr && mapa[6][7] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, bialy, 5, 7) && !bitepole(mapa, akt, bialy, 6, 7)) {
						lista.push_back(6);
						lista.push_back(7);
					}

				}
			}
		}
	}

	else {
		if (x + 1 < 8 && (mapa[x + 1][y] == nullptr || mapa[x + 1][y]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y , kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y);
			}
		}
		if (x - 1 >= 0 && (mapa[x - 1][y] == nullptr || mapa[x - 1][y]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x -1, y , kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y);
			}
		}
		if (y + 1 < 8 && (mapa[x][y + 1] == nullptr || mapa[x][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x, y + 1)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x , y + 1, kontener)) {
				lista.push_back(x);
				lista.push_back(y + 1);
			}
		}
		if (y - 1 >= 0 && (mapa[x][y - 1] == nullptr || mapa[x][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x, y - 1)) {//czy pole jest puste, jeœli nie to czy mo¿na biæ
			if (!czykrolbity(mapa, kolor, x, y, x , y - 1, kontener)) {
				lista.push_back(x);
				lista.push_back(y - 1);
			}
		}
		if (x - 1 >= 0 && y - 1 >= 0 && (mapa[x - 1][y - 1] == nullptr || mapa[x - 1][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y - 1)) {//lewo przód
			if (!czykrolbity(mapa, kolor, x, y, x - 1, y - 1, kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y - 1);
			}
		}
		if (x + 1 < 8 && y - 1 >= 0 && (mapa[x + 1][y - 1] == nullptr || mapa[x + 1][y - 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y - 1)) {//prawo przód
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y - 1, kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y - 1);
			}
		}
		if (x - 1 >= 0 && y + 1 < 8 && (mapa[x - 1][y + 1] == nullptr || mapa[x - 1][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x - 1, y + 1)) {//lewo ty³
			if (!czykrolbity(mapa, kolor, x, y, x -1, y + 1, kontener)) {
				lista.push_back(x - 1);
				lista.push_back(y + 1);
			}
		}
		if (x + 1 < 8 && y + 1 < 8 && (mapa[x + 1][y + 1] == nullptr || mapa[x + 1][y + 1]->getkol() == bialy) && !bitepole(mapa, akt, czarny, x + 1, y + 1)) {//prawo ty³
			if (!czykrolbity(mapa, kolor, x, y, x + 1, y + 1, kontener)) {
				lista.push_back(x + 1);
				lista.push_back(y + 1);
			}
		}
		//lewa roszada
		if (kontener.getrocz0()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, czarny, 4, 0)) {//król nie mo¿e byæ szachowany
				if (mapa[3][0] == nullptr && mapa[2][0] == nullptr && mapa[1][0] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, czarny, 3, 0) && !bitepole(mapa, akt, czarny, 2, 0)) {
						lista.push_back(2);
						lista.push_back(0);
					}

				}
			}
		}
		//prawa roszada
		if (kontener.getrocz7()) {
			deque<int> akt;
			if (!bitepole(mapa, akt, czarny, 4, 0)) {//król nie mo¿e byæ szachowany
				if (mapa[5][0] == nullptr && mapa[6][0] == nullptr) {//czy pola s¹ puste
					if (!bitepole(mapa, akt, czarny, 5, 0) && !bitepole(mapa, akt, czarny, 6, 0)) {
						lista.push_back(6);
						lista.push_back(0);
					}

				}
			}
		}
	}
}

bool krol::ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne& kontener)
{
	if (x == 2 && y == 7 && popx == 4 && popy == 7) {//biala lewa
		bierki[3][7] = bierki[0][7];
		bierki[0][7] = nullptr;
		bierki[3][7]->setpos(3, 7);
	}
	else if (x == 6 && y == 7 && popx == 4 && popy == 7) {
		bierki[5][7] = bierki[7][7];
		bierki[7][7] = nullptr;
		bierki[5][7]->setpos(5, 7);
	}
	else if (x == 2 && y == 0 && popx == 4 && popy == 0) {
		bierki[3][0] = bierki[0][0];
		bierki[0][0] = nullptr;
		bierki[3][0]->setpos(3, 0);
	}
	else if (x == 6 && y == 0 && popx == 4 && popy == 0) {
		bierki[5][0] = bierki[7][0];
		bierki[7][0] = nullptr;
		bierki[5][0]->setpos(5, 0);
	}


	if (kolor == bialy) {
		kontener.setkrbia(x, y);
		kontener.setrobi0(false);
		kontener.setrobi7(false);
	}
	else {
		kontener.setkrcza(x, y);
		kontener.setrocz0(false);
		kontener.setrocz7(false);
	}
	return false;
}

bool krol::jakafigura(int rodzaj)
{
	if (rodzaj == kroc && kolor == czarny)
		return true;
	else if (rodzaj == krob && kolor == bialy)
		return true;
	return false;
}
