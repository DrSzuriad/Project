#pragma once
#include "podstawowy.h"
#include "przycisk.h"
#include "poletekstowe.h"
#include "kulka.h"
#include "zegar.h"

class grafika : public Drawable
{
	void draw(RenderTarget& target, RenderStates state) const;
	int kordx;
	int kordy;
	Font font;
	przycisk przy1;
	przycisk przy2;
	przycisk przy4;
	przycisk przyasm;
	przycisk przyc;
	przycisk przystart;
	przycisk przystop;
	Text wybwat;
	Text jezyk;

	poletekstowe* poleakt = NULL;

	poletekstowe* pole1 = NULL;
	poletekstowe* pole2 = NULL;
	poletekstowe* pole3 = NULL;
	poletekstowe* pole4 = NULL;
	poletekstowe* pole5 = NULL;
	poletekstowe* pole6 = NULL;

	Text tekstpol1;
	Text tekstpol2;
	Text tekstpol3;
	Text tekstpol4;
	Text tekstpol5;
	Text tekstpol6;

	kulka obiekt;
	zegar zegarek;
	Text czas;
	Text iloscpowt;
	Text liczbapowt;
	int powtorzenia = 0;
	Text sredniczas;
	Text sredniczasliczba;
	double aktpop;
	Text czaspo;
	int licznik = 0;
	Text sredni100;
	Text prey;
	Text preyt;
	Text prex;
	Text prext;
	Text pozxt;
	Text pozyt;
	Text pozx;
	Text pozy;
public:
	grafika();
	void setx(int a);
	void sety(int a);
	void setxy(int a, int b);
	int getx();
	int gety();
	void getxy(int& a, int& b);
	void transpoz();
	Font getfont();
	void setkolprzy(int ktory, bool kol);
	void obs³ugaklawiszy(int znak);
	void wyborpola(int ktore);
	void settext(Text& zmieniany, int rozmiar, wstring tekst, int posx, int posy);
	void obliczruch(double x, double y, double vy, double vx);
	void resetsym();
	void getzmienne(double& m, double& cd, double& gamma, double& prepocz, double& t, double& tpop, double& cw, double& vw);
	double getczas();
};