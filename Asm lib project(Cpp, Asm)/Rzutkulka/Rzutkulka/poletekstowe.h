#pragma once
#include "podstawowy.h"
class poletekstowe : public Drawable
{
	void draw(RenderTarget& target, RenderStates state) const;
	double wartosc;
	Text tekst;
	Font font;
	string napis;
	RectangleShape ramka;
	int numer;
public:
	void setall(int pozx, int pozy, int rozx, int rozy, Font fonttyp, int rozmiar, double warto, int num);
	void setkol(bool a);
	void usuost();
	void dodlit(string znak);
	void wpisywanie(char znak);
	double getwar();
};

