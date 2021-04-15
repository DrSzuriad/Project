#include "zegar.h"

void zegar::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(tekst, state);
}

zegar::zegar()
{
	clock.restart();
	tekst.setString(to_string(float(0)));
	tekst.setPosition(52, 150);
	tekst.setFillColor(Color::Black);
	tekst.setCharacterSize(17);
}

void zegar::reset()
{
	clock.restart();
}

double zegar::gettime()
{
	return double((clock.getElapsedTime()).asMicroseconds());
}

double zegar::gettimes()
{
	return (clock.getElapsedTime()).asSeconds();
}

void zegar::settekst()
{
		tekst.setString(to_string((clock.getElapsedTime()).asSeconds()));
}

void zegar::setfont(Font a)
{
	font = a;
	tekst.setFont(font);
}
