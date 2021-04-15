#include "kon.h"







kon::kon(Sprite obr, bool kol)
{
	obrazek = obr;
	kolor = kol;
}

bool kon::mozrusz(figura*** mapa, zmienne kontener,int x,int y)
{

	if (kolor == bialy) {//bia³y koñ

		if (x - 1>= 0 && y - 2 >= 0 && (mapa[x - 1][y - 2] == nullptr || mapa[x - 1][y - 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y -2, kontener))//przód lewo
			return true;
		else if (x +1<8&& y -2 >=0 && (mapa[x +1][y -2] == nullptr || mapa[x +1][y -2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y-2, kontener))//przód prawo
			return true;
		else if (x - 2 >= 0 && y -1 >=0 && (mapa[x - 2][y -1] == nullptr || mapa[x -2][y -1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x -2, y-1, kontener))//lewo przód
			return true;
		else if (x -2 >=0 && y + 1<8 && (mapa[x -2][y +1] == nullptr || mapa[x -2][y +1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x -2, y+1, kontener))//lewo ty³
			return true;
		else if (x +2 < 8 && y -1 >=0 && (mapa[x +2][y -1] == nullptr || mapa[x +2][y -1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 2, y-1, kontener))//prawo przód
			return true;
		else if (x + 2 < 8 && y + 1 < 8 && (mapa[x +2][y + 1] == nullptr || mapa[x +2][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 2, y+1, kontener))//prawo ty³
			return true;
		else if (x -1 >=0 && y +2 <8 && (mapa[x - 1][y +2] == nullptr || mapa[x -1][y +2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y+2, kontener))//ty³ lewo
			return true;
		else if (x + 1 < 8 && y + 2 < 8 && (mapa[x + 1][y + 2] == nullptr || mapa[x + 1][y + 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y+2, kontener))//ty³ prawo
			return true;
	}

	else {//czarny koñ
		if (x - 1 >= 0 && y - 2 >= 0 && (mapa[x - 1][y - 2] == nullptr || mapa[x - 1][y - 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y-2, kontener))//przód lewo
			return true;
		else if (x + 1 < 8 && y - 2 >= 0 && (mapa[x + 1][y - 2] == nullptr || mapa[x + 1][y - 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y-2, kontener))//przód prawo
			return true;
		else if (x - 2 >= 0 && y - 1 >= 0 && (mapa[x - 2][y - 1] == nullptr || mapa[x - 2][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x -2, y-1, kontener))//lewo przód
			return true;
		else if (x - 2 >= 0 && y + 1 < 8 && (mapa[x - 2][y + 1] == nullptr || mapa[x - 2][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x -2, y+1, kontener))//lewo ty³
			return true;
		else if (x + 2 < 8 && y - 1 >= 0 && (mapa[x + 2][y - 1] == nullptr || mapa[x + 2][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 2, y-1, kontener))//prawo przód
			return true;
		else if (x + 2 < 8 && y + 1 < 8 && (mapa[x + 2][y + 1] == nullptr || mapa[x + 2][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 2, y+1, kontener))//prawo ty³
			return true;
		else if (x - 1 >= 0 && y + 2 < 8 && (mapa[x - 1][y + 2] == nullptr || mapa[x - 1][y + 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y+2, kontener))//ty³ lewo
			return true;
		else if (x + 1 < 8 && y + 2 < 8 && (mapa[x + 1][y + 2] == nullptr || mapa[x + 1][y + 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y+2, kontener))//ty³ prawo
			return true;
	}



	return false;
}

void kon::gdzierusz(figura*** mapa, zmienne kontener, int x, int y, deque<int>& lista)
{
	if (kolor == bialy) {//bia³y koñ

		if (x - 1 >= 0 && y - 2 >= 0 && (mapa[x - 1][y - 2] == nullptr || mapa[x - 1][y - 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y-2, kontener)) {//przód lewo
			lista.push_back(x - 1);
			lista.push_back(y - 2);
		}
		 if (x + 1 < 8 && y - 2 >= 0 && (mapa[x + 1][y - 2] == nullptr || mapa[x + 1][y - 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y-2, kontener)) {//przód prawo
			lista.push_back(x + 1);
			lista.push_back(y - 2);
		}
		 if (x - 2 >= 0 && y - 1 >= 0 && (mapa[x - 2][y - 1] == nullptr || mapa[x - 2][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x -2, y-1, kontener)) {//lewo przód
			lista.push_back(x - 2);
			lista.push_back(y - 1);
		}
		 if (x - 2 >= 0 && y + 1 < 8 && (mapa[x - 2][y + 1] == nullptr || mapa[x - 2][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x -2, y+1, kontener)) {//lewo ty³
			lista.push_back(x - 2);
			lista.push_back(y + 1);
		}
		 if (x + 2 < 8 && y - 1 >= 0 && (mapa[x + 2][y - 1] == nullptr || mapa[x + 2][y - 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 2, y-1, kontener)) {//prawo przód
			lista.push_back(x +2);
			lista.push_back(y - 1);
		}
		 if (x + 2 < 8 && y + 1 < 8 && (mapa[x + 2][y + 1] == nullptr || mapa[x + 2][y + 1]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 2, y+1, kontener)) {//prawo ty³
			lista.push_back(x +2);
			lista.push_back(y +1);
		}
		 if (x - 1 >= 0 && y + 2 < 8 && (mapa[x - 1][y + 2] == nullptr || mapa[x - 1][y + 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x - 1, y+2, kontener)) {//ty³ lewo
			lista.push_back(x - 1);
			lista.push_back(y +2);
		}
		 if (x + 1 < 8 && y + 2 < 8 && (mapa[x + 1][y + 2] == nullptr || mapa[x + 1][y + 2]->getkol() == czarny) && !czykrolbity(mapa, kolor, x, y, x + 1, y+2, kontener)) {//ty³ prawo
			lista.push_back(x +1);
			lista.push_back(y +2);
		}
	}

	else {//czarny koñ
		if (x - 1 >= 0 && y - 2 >= 0 && (mapa[x - 1][y - 2] == nullptr || mapa[x - 1][y - 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y-2, kontener)) {//przód lewo
			lista.push_back(x - 1);
			lista.push_back(y - 2);
		}
		 if (x + 1 < 8 && y - 2 >= 0 && (mapa[x + 1][y - 2] == nullptr || mapa[x + 1][y - 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y-2, kontener)) {//przód prawo
			 lista.push_back(x + 1);
			 lista.push_back(y - 2);
		}
		 if (x - 2 >= 0 && y - 1 >= 0 && (mapa[x - 2][y - 1] == nullptr || mapa[x - 2][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x -2, y-1, kontener)) {//lewo przód
			 lista.push_back(x - 2);
			 lista.push_back(y - 1);
		}
		 if (x - 2 >= 0 && y + 1 < 8 && (mapa[x - 2][y + 1] == nullptr || mapa[x - 2][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x -2, y+1, kontener)) {//lewo ty³
			 lista.push_back(x - 2);
			 lista.push_back(y + 1);
		}
		 if (x + 2 < 8 && y - 1 >= 0 && (mapa[x + 2][y - 1] == nullptr || mapa[x + 2][y - 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 2, y-1, kontener)) {//prawo przód
			 lista.push_back(x + 2);
			 lista.push_back(y - 1);
		}
		 if (x + 2 < 8 && y + 1 < 8 && (mapa[x + 2][y + 1] == nullptr || mapa[x + 2][y + 1]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 2, y+1, kontener)) {//prawo ty³
			 lista.push_back(x + 2);
			 lista.push_back(y + 1);
		}
		 if (x - 1 >= 0 && y + 2 < 8 && (mapa[x - 1][y + 2] == nullptr || mapa[x - 1][y + 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x - 1, y+2, kontener)) {//ty³ lewo
			 lista.push_back(x - 1);
			 lista.push_back(y + 2);
		}
		 if (x + 1 < 8 && y + 2 < 8 && (mapa[x + 1][y + 2] == nullptr || mapa[x + 1][y + 2]->getkol() == bialy) && !czykrolbity(mapa, kolor, x, y, x + 1, y+2, kontener)) {//ty³ prawo
			 lista.push_back(x + 1);
			 lista.push_back(y + 2);
		}
	}
}

bool kon::ruchspecjalny(int popx, int popy, int x, int y, figura*** bierki, zmienne &kontener)
{
	return false;
}

bool kon::jakafigura(int rodzaj)
{
	if (rodzaj == konc && kolor == czarny)
		return true;
	else if (rodzaj == konb && kolor == bialy)
		return true;
	return false;
}

