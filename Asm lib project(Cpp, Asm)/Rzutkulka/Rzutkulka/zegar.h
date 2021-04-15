#pragma once
#include "podstawowy.h"

class zegar: public Drawable
{
	void draw(RenderTarget& target, RenderStates state) const;
	Clock clock;
	Text tekst;
	Font font;
public:
	zegar();
	void reset();
	double gettime();
	double gettimes();
	void settekst();
	void setfont(Font a);
};

