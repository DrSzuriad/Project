#include "glowna.h"


void glowna::transkord(int &x, int &y)
{
	if (x >= 500 && x < 642 && y >= 200 && y < 240) {
		x = -2;

	}
	else if (x >= 500 && x < 642 && y >= 250 &&y < 290) {
		x = -3;
	}
	else if (x >= 500 && x < 642 && y >= 300 && y < 340) {
		x = -4;
	}
	else {
		x = x / 50 - 1;
		y = y / 50 - 1;
		if (x >= 8)
			x = -1;
		if (y >= 8)
			y = -1;
	}
}

glowna::glowna()
{
	kordy = -1;
	kordx = -1;
	popkordx = 0;
	popkordy = 0;
	fazaruchu = bialypocz;
}


deque<int>* glowna::getlistafig()
{
	return &listafigur;
}

bool glowna::eventy(Event event, RenderWindow* okno, plansza& plan) {


	switch (event.type) {
	case Event::Closed:
		(*okno).close();
		return false;
	case Event::MouseButtonPressed:
		if (event.mouseButton.button == Mouse::Left) {
			kordx = event.mouseButton.x;
			kordy = event.mouseButton.y;
			transkord(kordx, kordy);
			if (kordx >= 0 && kordy >= 0) {//czy gracz klikn¹³ w planszê
				if (fazaruchu == bialypocz) {
					if (gdzieruch(listafigur, listamiejsc, plan, bialy, kordx, kordy)) {
						fazaruchu = bialywyb;
						popkordx = kordx;
						popkordy = kordy;
					}
				}
				else if (fazaruchu == bialywyb) {
					if (ruszaniesie(listamiejsc, popkordx, popkordy, kordx, kordy, plan)) {
						fazaruchu = bialykon;
						listamiejsc.clear();
					}
				}
				else if (fazaruchu == bialykon) {

				}
				else if (fazaruchu == czarnypocz) {
					if (gdzieruch(listafigur, listamiejsc, plan, czarny, kordx, kordy)) {
						fazaruchu = czarnywyb;
						popkordx = kordx;
						popkordy = kordy;
					}
				}
				else if (fazaruchu == czarnywyb) {
					if (ruszaniesie(listamiejsc, popkordx, popkordy, kordx, kordy, plan)) {
						fazaruchu = czarnykon;
						listamiejsc.clear();
					}
				}
				else if (fazaruchu == czarnykon) {

				}
			}
			else if (kordx == -2) {//gracz klikn¹³ w przycisk koñca ruchu
				if (fazaruchu == bialykon) {
					listafigur.clear();
					if (szach(listafigur, plan.getzmienne(), czarny, plan.getbierki(), plan)) //jest szach-mat
						fazaruchu = bialywyg;
					else {
						if (listafigur.size() == 0)
							fazaruchu = remis;
						else {
							fazaruchu = czarnypocz;
							plan.usunczaprze();
						}
					}

				}
				else if (fazaruchu == czarnykon) {
					listafigur.clear();
					if (szach(listafigur, plan.getzmienne(), bialy, plan.getbierki(), plan)) //jest szach-mat
						fazaruchu = czarnywyg;
					else {
						if (listafigur.size() == 0)
							fazaruchu = remis;
						else {
							fazaruchu = bialypocz;
							plan.usunbiaprze();
						}
					}
				}
			}
			else if (kordx == -3) {//gracz klikn¹³ w przycisk anuluj
				if (fazaruchu == bialywyb) {
					listamiejsc.clear();
					fazaruchu = bialypocz;
				}
				else if (fazaruchu == czarnywyb) {
					listamiejsc.clear();
					fazaruchu = czarnypocz;
				}
			}
			else if (kordx == -4) {//gracz klikn¹³ w przycisk reset
				return false;
			}
		}
	}

	return true;

}

void glowna::wypisz(RenderWindow* okno, plansza& plan,grafika& graf)
{
	(*okno).draw(plan);
	(*okno).draw(graf.getprzk());
	(*okno).draw(graf.getreset());
	(*okno).draw(graf.getakt());

	if (fazaruchu == bialykon || fazaruchu == bialypocz || fazaruchu == bialywyb)
		(*okno).draw(graf.getbialys());
	else
		(*okno).draw(graf.getczarnys());
	if ((fazaruchu == bialypocz || fazaruchu == czarnypocz) && listafigur.empty() != true) {
		CircleShape kolo(5);
		kolo.setFillColor(Color::Red);
		for (size_t i = 0; i < listafigur.size(); i = i + 2) {
			kolo.setPosition(float(50 * listafigur[i] + 53), float(50 * listafigur[i + 1] + 53));
			(*okno).draw(kolo);
		}

	}
	else if ((fazaruchu == bialywyb || fazaruchu == czarnywyb) && listamiejsc.empty() != true) {
		(*okno).draw(graf.getprza());
		CircleShape kolo(5);
		kolo.setFillColor(Color::Green);
		for (size_t i = 0; i < listamiejsc.size(); i = i + 2) {
			kolo.setPosition(float(50 * listamiejsc[i] + 53), float(50 * listamiejsc[i + 1] + 53));
			(*okno).draw(kolo);
		}
	}
	else if (fazaruchu == bialywyg || fazaruchu == czarnywyg) {
		(*okno).draw(graf.getwygrana());
		if (fazaruchu == bialywyg) {
			graf.setkordbia(176, 200);
			(*okno).draw(graf.getbialys());
		}
		else {
			graf.setkordcz(165, 200);
			(*okno).draw(graf.getczarnys());
		}
	}
	else if (fazaruchu == remis)
		(*okno).draw(graf.getremis());
}

bool glowna::szach(deque<int>& listafig, zmienne& kontener, bool kolor, figura***& mapa, plansza& plan) {

	deque<int> akt;
	int x = 0, y = 0;
	if (kolor == bialy) {
		kontener.getkrbia(x, y);
		czymozruch(listafig, plan, bialy);
		if (listafig.size() == 0) {
			if (mapa[x][y]->bitepole(mapa, akt, bialy, x, y)) //czy król jest bity
				return true;
			else
				return false;
		}
	}
	else {
		kontener.getkrcza(x, y);
		czymozruch(listafig, plan, czarny);
		if (listafig.size() == 0) {
			if (mapa[x][y]->bitepole(mapa, akt, czarny, x, y)) //czy król jest bity
				return true;
			else
				return false;
		}
	}
	return false;
}