#pragma once


#include <SFML/Graphics.hpp>
using namespace sf;

class grafika
{
private:
	Texture pionekbt;//Tekstury i Sprity wszystkich wyœwietlanych obrazków
	Sprite pionekb;
	Texture pionekct;
	Sprite pionekc;
	Texture wiebt;
	Sprite wiezab;
	Texture wiect;
	Sprite wiezac;
	Texture konbt;
	Sprite konnb;
	Texture konct;
	Sprite konnc;
	Texture gonbt;
	Sprite goniecb;
	Texture gonct;
	Sprite goniecc;
	Texture hetbt;
	Sprite hetmanb;
	Texture hetct;
	Sprite hetmanc;
	Texture krolbt;
	Sprite krolb;
	Texture krolct;
	Sprite krolc;
	Texture przyciskkt;
	Sprite przyciskk;
	Texture przyciskat;
	Sprite przyciska;
	Texture aktt;
	Sprite akt;
	Texture bialyt;
	Sprite bialys;
	Texture czarnyt;
	Sprite czarnys;
	Texture resett;
	Sprite reset;
	Texture wygranat;
	Sprite wygrana;
	Texture remist;
	Sprite remis;

public:
	grafika();
	~grafika();
	Sprite getpb();
	Sprite getpc();
	Sprite getwb();
	Sprite getwc();
	Sprite getkb();
	Sprite getkc();
	Sprite getgb();
	Sprite getgc();
	Sprite gethb();
	Sprite gethc();
	Sprite getkrb();
	Sprite getkrc();
	Sprite getprzk();
	Sprite getprza();
	Sprite getakt();
	Sprite getbialys();
	Sprite getczarnys();
	Sprite getwygrana();
	Sprite getreset();
	Sprite getremis();
	void setkordbia(int x,int y);//zmiana miejsca wyœwietlania obrazka  
	void setkordcz(int x,int y);//zmiana miejsca wyœwietlania obrazka  
};

