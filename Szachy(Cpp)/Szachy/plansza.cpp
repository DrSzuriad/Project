#include "plansza.h"
#include <stdlib.h>

void plansza::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(boku,state);
	target.draw(bokl, state);
	target.draw(bokd, state);
	target.draw(bokr, state);
	for (int i = 0; i < 8; i++) {
		for (int o = 0; o < 8; o++) {
			target.draw(*(mapa[i][o]),state);
			if (bierki[i][o] != nullptr)
				target.draw(*(bierki[i][o]), state);
		}
	}
}

plansza::plansza(grafika graf)
{
	mapa = new pole ** [8];
	bierki = new figura**[8];
	for (int i = 0; i < 8; i++) {
		mapa[i] = new pole *[8];
		bierki[i] = new figura * [8];
		for (int o = 0; o < 8; o++) {
			if ((o + i) % 2 == 0)
				mapa[i][o] = new pole(float(i *50 + 50), float(o * 50 + 50), 50, 50, Color(255, 232, 112), nic);
			else
				mapa[i][o] = new pole(float(i*50+50), float(o*50+50), 50, 50, Color(139,69,19), nic);
			bierki[i][o] = nullptr;
		}
	}

	for (int i = 0; i < 8; i++) {//dodanie pionków
		setfig(pioc, graf, i, 1);
		setfig(piob, graf, i, 6);
	}

	setfig(wiec, graf, 0, 0);//dodanie wie¿
	setfig(wiec, graf, 7, 0);
	setfig(wieb, graf, 0, 7);
	setfig(wieb, graf, 7, 7);

	setfig(konc, graf, 1, 0);//dodanie koni
	setfig(konc, graf, 6, 0);
	setfig(konb, graf, 1, 7);
	setfig(konb, graf, 6, 7);

	setfig(gonc, graf, 2, 0);//dodanie goñców
	setfig(gonc, graf, 5, 0);
	setfig(gonb, graf, 2, 7);
	setfig(gonb, graf, 5, 7);


	setfig(hetc, graf, 3, 0);//dodanie hetmanów
	setfig(hetb, graf, 3, 7);

	setfig(kroc, graf, 4, 0);//dodanie króli
	setfig(krob, graf, 4, 7);
	kontener.setkrbia(4, 7);
	kontener.setkrcza(4, 0);
}





plansza::~plansza()
{
	for (int i = 0; i < 8; i++) {
		for (int a = 0; a < 8; a++) {
			delete(bierki[i][a]);
			delete(mapa[i][a]);
		}
		delete(bierki[i]);
		delete(mapa[i]);
	}
	delete(bierki);
	bierki = nullptr;
	delete(mapa);
	mapa = nullptr;
}

pole plansza::getbu()
{
	return boku;
}

pole plansza::getbl()
{
	return bokl;
}

pole plansza::getbd()
{
	return bokd;
}

pole plansza::getbr()
{
	return bokr;
}

figura* plansza::getfig(int x, int y)
{
	return bierki[x][y];
}

void plansza::setfig(figura* fig, int x, int y)
{
	if (fig != nullptr)
		fig->setpos(x, y);
	bierki[x][y] = fig;

}

void plansza::setfig(int fig, grafika graf,int x,int y)
{
		switch (fig)
	{
	case piob:
		bierki[x][y] = new pionek(graf.getpb(), bialy);
		break;
	case pioc:
		bierki[x][y] = new pionek(graf.getpc(), czarny);
		break;
	case wieb:
		bierki[x][y] = new wieza(graf.getwb(), bialy);
		break;
	case wiec:
		bierki[x][y] = new wieza(graf.getwc(), czarny);
		break;
	case konb:
		bierki[x][y] = new kon(graf.getkb(), bialy);
		break;
	case konc:
		bierki[x][y] = new kon(graf.getkc(), czarny);
		break;
	case gonb:
		bierki[x][y] = new goniec(graf.getgb(), bialy);
		break;
	case gonc:
		bierki[x][y] = new goniec(graf.getgc(), czarny);
		break;
	case hetb:
		bierki[x][y] = new hetman(graf.gethb(), bialy);
		break;
	case hetc:
		bierki[x][y] = new hetman(graf.gethc(), czarny);
		break;
	case krob:
		bierki[x][y] = new krol(graf.getkrb(), bialy);
		break;
	case kroc:
		bierki[x][y] = new krol(graf.getkrc(), czarny);
		break;
	}
	bierki[x][y]->setpos(x,y);
}

figura*** &plansza::getbierki()
{
	return bierki;
}

zmienne& plansza::getzmienne()
{
	return kontener;
}

void plansza::usunbiaprze()
{
	kontener.usunbiprze();

}

void plansza::usunczaprze()
{
	kontener.usunczprze();

}
