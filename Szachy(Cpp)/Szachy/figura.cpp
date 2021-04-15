#include "figura.h"

void figura::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(obrazek, state);
}

bool figura::getkol()
{
	return kolor;
}

void figura::setpos(Vector2f a)
{
	obrazek.setPosition(a);
}

void figura::setpos(float x, float y)
{
	obrazek.setPosition(x, y);
}

void figura::setpos(int x, int y)
{
	obrazek.setPosition(float(x * 50 + 50), float(y * 50 + 50));
}

bool figura::bitepole(figura*** bierki, deque<int>& kto, bool kolor, int x, int y) {
	kto.clear();
	if (kolor == bialy) {

		///////////////pionek
		if (x - 1 >= 0 && y - 1 >= 0 && bierki[x - 1][y - 1] != nullptr && bierki[x - 1][y - 1]->jakafigura(pioc)) {//pionek z lewej
			kto.push_back(x - 1);
			kto.push_back(y - 1);
		}
		if (x + 1 < 8 && y - 1 >= 0 && bierki[x + 1][y - 1] != nullptr && bierki[x + 1][y - 1]->jakafigura(pioc)) {//pionek z prawej
			kto.push_back(x + 1);
			kto.push_back(y - 1);
		}
		/////////////////////////kon
		if (x - 1 >= 0 && y - 2 >= 0 && bierki[x - 1][y - 2] != nullptr && bierki[x - 1][y - 2]->jakafigura(konc)) {//koñ przód lewo
			kto.push_back(x - 1);
			kto.push_back(y - 2);
		}
		if (x + 1 < 8 && y - 2 >= 0 && bierki[x + 1][y - 2] != nullptr && bierki[x + 1][y - 2]->jakafigura(konc)) {//koñ przód prawo
			kto.push_back(x + 1);
			kto.push_back(y - 2);
		}
		if (x - 2 >= 0 && y - 1 >= 0 && bierki[x - 2][y - 1] != nullptr && bierki[x - 2][y - 1]->jakafigura(konc)) {//koñ lewo przód
			kto.push_back(x - 2);
			kto.push_back(y - 1);
		}
		if (x - 2 >= 0 && y + 1 < 8 && bierki[x - 2][y + 1] != nullptr && bierki[x - 2][y + 1]->jakafigura(konc)) {//koñ lewo tyl
			kto.push_back(x - 2);
			kto.push_back(y + 1);
		}
		if (x + 2 < 8 && y - 1 >= 0 && bierki[x + 2][y - 1] != nullptr && bierki[x + 2][y - 1]->jakafigura(konc)) {//koñ prawo przód
			kto.push_back(x + 2);
			kto.push_back(y - 1);
		}
		if (x + 2 < 8 && y + 1 < 8 && bierki[x + 2][y + 1] != nullptr && bierki[x + 2][y + 1]->jakafigura(konc)) {//koñ prawo tyl
			kto.push_back(x + 2);
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && y + 2 < 8 && bierki[x - 1][y + 2] != nullptr && bierki[x - 1][y + 2]->jakafigura(konc)) {//koñ tyl lewo
			kto.push_back(x - 1);
			kto.push_back(y + 2);
		}
		if (x + 1 < 8 && y + 2 < 8 && bierki[x + 1][y + 2] != nullptr && bierki[x + 1][y + 2]->jakafigura(konc)) {//koñ przód prawo
			kto.push_back(x + 1);
			kto.push_back(y + 2);
		}
		//////wie¿a lub hetman
		for (int i = 1; i < 7; i++) {//w prawo
			if (x + i < 8) {
				if (bierki[x + i][y] != nullptr) {
					if (bierki[x + i][y]->jakafigura(hetc)|| bierki[x + i][y]->jakafigura(wiec)) {
						kto.push_back(x + i);
						kto.push_back(y);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo
			if (x - i >= 0) {
				if (bierki[x - i][y] != nullptr) {
					if (bierki[x - i][y]->jakafigura(hetc)|| bierki[x - i][y]->jakafigura(wiec)) {
						kto.push_back(x - i);
						kto.push_back(y);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w dó³
			if (y + i < 8) {
				if (bierki[x][y + i] != nullptr) {
					if (bierki[x][y + i]->jakafigura(hetc)||bierki[x][y + i]->jakafigura(wiec)) {
						kto.push_back(x);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w górê
			if (y - i >= 0) {
				if (bierki[x][y - i] != nullptr) {
					if (bierki[x][y - i]->jakafigura(hetc)|| bierki[x][y - i]->jakafigura(wiec)) {
						kto.push_back(x);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		//////////////////////goniec lub hetman
		for (int i = 1; i < 7; i++) {//w prawo dó³
			if (x + i < 8 && y + i < 8) {
				if (bierki[x + i][y + i] != nullptr) {
					if (bierki[x + i][y + i]->jakafigura(hetc)|| bierki[x + i][y + i]->jakafigura(gonc)) {
						kto.push_back(x + i);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo dó³
			if (x - i >= 0 && y + i < 8) {
				if (bierki[x - i][y + i] != nullptr) {
					if (bierki[x - i][y + i]->jakafigura(hetc)|| bierki[x - i][y + i]->jakafigura(gonc)) {
						kto.push_back(x - i);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo góra
			if (x - i >= 0 && y - i >= 0) {
				if (bierki[x - i][y - i] != nullptr) {
					if (bierki[x - i][y - i]->jakafigura(hetc)|| bierki[x - i][y - i]->jakafigura(gonc)) {
						kto.push_back(x - i);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w prawo góra
			if (x + i < 8 && y - i >=0) {
				if (bierki[x + i][y - i] != nullptr) {
					if (bierki[x + i][y - i]->jakafigura(hetc)|| bierki[x + i][y - i]->jakafigura(gonc)) {
						kto.push_back(x + i);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		/////////król
		if (x - 1 >= 0 && y - 1 >= 0 && bierki[x - 1][y - 1] != nullptr && bierki[x - 1][y - 1]->jakafigura(kroc)) {
			kto.push_back(x - 1);
			kto.push_back(y - 1);
		}
		if (y - 1 >= 0 && bierki[x][y - 1] != nullptr && bierki[x][y - 1]->jakafigura(kroc)) {
			kto.push_back(x);
			kto.push_back(y - 1);
		}
		if (x + 1 < 8 && y - 1 >= 0 && bierki[x + 1][y - 1] != nullptr && bierki[x + 1][y - 1]->jakafigura(kroc)) {
			kto.push_back(x + 1);
			kto.push_back(y - 1);
		}
		if (x + 1 < 8 && bierki[x + 1][y] != nullptr && bierki[x + 1][y]->jakafigura(kroc)) {
			kto.push_back(x + 1);
			kto.push_back(y);
		}
		if (x + 1 < 8 && y + 1 < 8 && bierki[x + 1][y + 1] != nullptr && bierki[x + 1][y + 1]->jakafigura(kroc)) {
			kto.push_back(x + 1);
			kto.push_back(y + 1);
		}
		if (y + 1 < 8 && bierki[x][y + 1] != nullptr && bierki[x][y + 1]->jakafigura(kroc)) {
			kto.push_back(x);
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && y + 1 < 8 && bierki[x - 1][y + 1] != nullptr && bierki[x - 1][y + 1]->jakafigura(kroc)) {
			kto.push_back(x - 1);
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && bierki[x - 1][y] != nullptr && bierki[x - 1][y]->jakafigura(kroc)) {
			kto.push_back(x - 1);
			kto.push_back(y);
		}


	}
	else {

		///////////////pionek
		if (x - 1 >= 0 && y + 1 < 8 && bierki[x - 1][y + 1] != nullptr && bierki[x - 1][y + 1]->jakafigura(piob)) {//pionek z lewej
			kto.push_back(x - 1);
			kto.push_back(y + 1);
		}
		if (x + 1 < 8 && y + 1 < 8 && bierki[x + 1][y + 1] != nullptr && bierki[x + 1][y + 1]->jakafigura(piob)) {//pionek z prawej
			kto.push_back(x + 1);
			kto.push_back(y + 1);
		}
		/////////////////////////kon
		if (x - 1 >= 0 && y - 2 >= 0 && bierki[x - 1][y - 2] != nullptr && bierki[x - 1][y - 2]->jakafigura(konb)) {//koñ przód lewo
			kto.push_back(x - 1);
			kto.push_back(y - 2);
		}
		if (x + 1 < 8 && y - 2 >= 0 && bierki[x + 1][y - 2] != nullptr && bierki[x + 1][y - 2]->jakafigura(konb)) {//koñ przód prawo
			kto.push_back(x + 1);
			kto.push_back(y - 2);
		}
		if (x - 2 >= 0 && y - 1 >= 0 && bierki[x - 2][y - 1] != nullptr && bierki[x - 2][y - 1]->jakafigura(konb)) {//koñ lewo przód
			kto.push_back(x - 2);
			kto.push_back(y - 1);
		}
		if (x - 2 >= 0 && y + 1 < 8 && bierki[x - 2][y + 1] != nullptr && bierki[x - 2][y + 1]->jakafigura(konb)) {//koñ lewo tyl
			kto.push_back(x - 2);
			kto.push_back(y + 1);
		}
		if (x + 2 < 8 && y - 1 >= 0 && bierki[x + 2][y - 1] != nullptr && bierki[x + 2][y - 1]->jakafigura(konb)) {//koñ prawo przód
			kto.push_back(x + 2);
			kto.push_back(y - 1);
		}
		if (x + 2 < 8 && y + 1 < 8 && bierki[x + 2][y + 1] != nullptr && bierki[x + 2][y + 1]->jakafigura(konb)) {//koñ prawo tyl
			kto.push_back(x + 2);
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && y + 2 < 8 && bierki[x - 1][y + 2] != nullptr && bierki[x - 1][y + 2]->jakafigura(konb)) {//koñ tyl lewo
			kto.push_back(x - 1);
			kto.push_back(y + 2);
		}
		if (x + 1 < 8 && y + 2 < 8 && bierki[x + 1][y + 2] != nullptr && bierki[x + 1][y + 2]->jakafigura(konb)) {//koñ przód prawo
			kto.push_back(x + 1);
			kto.push_back(y + 2);
		}
		//////wie¿a lub hetman
		for (int i = 1; i < 7; i++) {//w prawo
			if (x + i < 8) {
				if (bierki[x + i][y] != nullptr) {
					if (bierki[x + i][y]->jakafigura(hetb)|| bierki[x + i][y]->jakafigura(wieb)) {
						kto.push_back(x + i);
						kto.push_back(y);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo
			if (x - i >= 0) {
				if (bierki[x - i][y] != nullptr) {
					if (bierki[x - i][y]->jakafigura(hetb)||bierki[x - i][y]->jakafigura(wieb)) {
						kto.push_back(x - i);
						kto.push_back(y);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w dó³
			if (y + i < 8) {
				if (bierki[x][y + i] != nullptr) {
					if (bierki[x][y + i]->jakafigura(hetb)|| bierki[x][y + i]->jakafigura(wieb)) {
						kto.push_back(x);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w górê
			if (y - i >= 0) {
				if (bierki[x][y - i] != nullptr) {
					if (bierki[x][y - i]->jakafigura(hetb)|| bierki[x][y - i]->jakafigura(wieb)) {
						kto.push_back(x);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		//////////////////////goniec lub hetman
		for (int i = 1; i < 7; i++) {//w prawo dó³
			if (x + i < 8 && y + i < 8) {
				if (bierki[x + i][y + i] != nullptr) {
					if (bierki[x + i][y + i]->jakafigura(hetb)|| bierki[x + i][y + i]->jakafigura(gonb)) {
						kto.push_back(x + i);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo dó³
			if (x - i >= 0 && y + i < 8) {
				if (bierki[x - i][y + i] != nullptr) {
					if (bierki[x - i][y + i]->jakafigura(hetb)|| bierki[x - i][y + i]->jakafigura(gonb)) {
						kto.push_back(x - i);
						kto.push_back(y + i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w lewo góra
			if (x - i >= 0 && y - i >= 0) {
				if (bierki[x - i][y - i] != nullptr) {
					if (bierki[x -i][y - i]->jakafigura(hetb)|| bierki[x - i][y - i]->jakafigura(gonb)) {
						kto.push_back(x - i);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 7; i++) {//w prawo góra
			if (x + i < 8 && y - i >=0) {
				if (bierki[x + i][y - i] != nullptr) {
					if (bierki[x + i][y - i]->jakafigura(hetb)|| bierki[x + i][y - i]->jakafigura(gonb)) {
						kto.push_back(x + i);
						kto.push_back(y - i);
					}
					break;
				}
			}
			else
				break;
		}
		/////////król
		if (x - 1 >= 0 && y - 1 >= 0 && bierki[x - 1][y - 1] != nullptr && bierki[x - 1][y - 1]->jakafigura(krob)) {
			kto.push_back(x - 1);
			kto.push_back(y - 1);
		}
		if (y - 1 >= 0 && bierki[x][y - 1] != nullptr && bierki[x][y - 1]->jakafigura(krob)) {
			kto.push_back(x);
			kto.push_back(y - 1);
		}
		if (x + 1 <8 && y - 1 >= 0 && bierki[x + 1][y - 1] != nullptr && bierki[x + 1][y - 1]->jakafigura(krob)) {
			kto.push_back(x + 1);
			kto.push_back(y - 1);
		}
		if (x + 1 < 8 && bierki[x + 1][y] != nullptr && bierki[x + 1][y]->jakafigura(krob)) {
			kto.push_back(x + 1);
			kto.push_back(y);
		}
		if (x + 1 < 8 && y + 1 < 8 && bierki[x + 1][y + 1] != nullptr && bierki[x + 1][y+ 1]->jakafigura(krob)) {
			kto.push_back(x + 1);
			kto.push_back(y + 1);
		}
		if (y + 1 < 8 && bierki[x][y + 1] != nullptr && bierki[x][y + 1]->jakafigura(krob)) {
			kto.push_back(x );
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && y + 1 < 8 && bierki[x - 1][y + 1] != nullptr && bierki[x - 1][y + 1]->jakafigura(krob)) {
			kto.push_back(x -1);
			kto.push_back(y + 1);
		}
		if (x - 1 >= 0 && bierki[x - 1][y ] != nullptr && bierki[x - 1][y]->jakafigura(krob)) {
			kto.push_back(x - 1);
			kto.push_back(y);
		}


	}

	if (kto.size() > 0)
		return true;
	else
		return false;
}

bool figura::czykrolbity(figura*** bierki, bool kolor, int popx, int popy, int x, int y,zmienne kontener)
{

	figura* tym = bierki[x][y];
	bierki[x][y] = bierki[popx][popy];
	bierki[popx][popy] = nullptr;
	deque<int>akt;
	if (kolor == bialy) {
		if (jakafigura(krob)) {
			if (bitepole(bierki, akt, kolor, x, y)) {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return true;
			}
			else {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return false;
			}
		}
		else {
			int krx = 0, kry = 0;
			kontener.getkrbia(krx, kry);
			if (bitepole(bierki, akt, kolor, krx, kry)) {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return true;
			}
			else {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return false;
			}
		}
	}
	else {
		if (jakafigura(kroc)) {
			if (bitepole(bierki, akt, kolor, x, y)) {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return true;
			}
			else {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return false;
			}
		}
		else {
			int krx = 0, kry = 0;
			kontener.getkrcza(krx, kry);
			if (bitepole(bierki, akt, kolor, krx, kry)) {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return true;
			}
			else {
				bierki[popx][popy] = bierki[x][y];
				bierki[x][y] = tym;
				return false;
			}
		}
	}
}
