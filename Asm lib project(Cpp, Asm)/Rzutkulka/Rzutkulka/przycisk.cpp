#include "przycisk.h"

void przycisk::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(ramka, state);
	target.draw(tekst, state);
}

przycisk::przycisk()
{
}

void przycisk::setall(int pozx, int pozy, int rozx, int rozy, Font fonttyp, string napis, int rozmiar, Color kolorramki, int poznap)
{
	ramka.setSize(Vector2f(float(rozx), float(rozy)));
	ramka.setOutlineColor(kolorramki);
	ramka.setOutlineThickness(float(2));
	ramka.setFillColor(Color::White);
	ramka.setPosition(float(pozx), float(pozy));
	font = fonttyp;
	tekst.setFillColor(Color::Black);
	tekst.setFont(font);
	tekst.setString(napis);
	tekst.setPosition(float(poznap + pozx), float(pozy));
	tekst.setCharacterSize(rozmiar);
	tekst.setStyle(Text::Bold);
}

void przycisk::setkol(bool a)
{
	if (a)
		ramka.setFillColor(Color(255, 235, 174));
	else
		ramka.setFillColor(Color(255, 255, 255));
}
