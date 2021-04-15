#pragma once
#include "podstawowy.h"
class przycisk : public Drawable
{
	void draw(RenderTarget& target, RenderStates state) const;
	Text tekst;
	Font font;
	RectangleShape ramka;
public:
	przycisk();
	void setall(int pozx, int pozy, int rozx, int rozy, Font fonttyp, string napis, int rozmiar, Color kolorramki, int poznap);
	void setkol(bool a);
};

