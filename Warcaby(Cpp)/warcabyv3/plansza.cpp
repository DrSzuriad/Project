#include "plansza.h"




plansza::plansza(int wiel, bool kolor) {
	tablica = new pole * [wiel];
	for (int i = 0; i < wiel; i++) {
		tablica[i] = new pole[wiel];
		for (int a = 0; a < wiel; a++) {
			if (((a + i) % 2) == 1 && kolor == false || ((a + i) % 2) == 0 && kolor == true) {
				tablica[i][a].setkolor(false);
			}
			else
				tablica[i][a].setkolor(true);
			tablica[i][a].setfigura(nic);
		}

	}
}

void plansza::wpiszf(int rodzaj) {

	switch (rodzaj) {
	case polskie:
		for (int i = 1; i < 10; i+=2) {
			this->tablica[i % 10][0].setfigura(pionekcza);
			this->tablica[i % 10][2].setfigura(pionekcza);
			this->tablica[i % 10][6].setfigura(pionekbia);
			this->tablica[i % 10][8].setfigura(pionekbia);
		}
		for (int i = 0; i < 10; i += 2) {
			this->tablica[i % 10][1].setfigura(pionekcza);
			this->tablica[i % 10][3].setfigura(pionekcza);
			this->tablica[i % 10][7].setfigura(pionekbia);
			this->tablica[i % 10][9].setfigura(pionekbia);
		}
		break;

	case angielskie:
		for (int i = 1; i < 8; i += 2) {
			this->tablica[i % 10][0].setfigura(pionekcza);
			this->tablica[i % 10][2].setfigura(pionekcza);
			this->tablica[i % 10][6].setfigura(pionekbia);
		}
		for (int i = 0; i < 8; i += 2) {
			this->tablica[i % 10][1].setfigura(pionekcza);
			this->tablica[i % 10][5].setfigura(pionekbia);
			this->tablica[i % 10][7].setfigura(pionekbia);
		}
		break;
	}


}

int plansza::getf(int x, int y) {
	return tablica[x][y].getfigura();
}
bool plansza::getc(int x, int y) {
	return tablica[x][y].getkolor();
}

void plansza::setf(int x, int y, int fig) {
	 tablica[x][y].setfigura(fig);
}
void plansza::setc(int x, int y, bool col) {
	 tablica[x][y].setkolor(col);
}

plansza* plansza::usun(int roz) {
	if (tablica != nullptr) {
		for (int i = 0; i < roz; i++) {
			delete(tablica[i]);

		}
		delete tablica;
		tablica = nullptr;
		return nullptr;
	}
	return nullptr;
}


void plansza::pozycja(int& x, int& y) {
	if (x < 50)
		x = -1;
	else {
		x -= 50;
		x = x / 50;
	}
	if (y < 22)
		y = -1;
	else {
		y -= 22;
		y = y / 50;
	}
}