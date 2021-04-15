#include "poletekstowe.h"

void poletekstowe::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(ramka, state);
	target.draw(tekst, state);
}

void poletekstowe::setall(int pozx, int pozy, int rozx, int rozy, Font fonttyp, int rozmiar, double warto, int num)
{
	wartosc = warto;
	napis = to_string(wartosc);
	while(napis[napis.size()-1] == '0')
		napis.pop_back();
	if (napis[napis.size() - 1] == '.')
		napis.pop_back();

	ramka.setSize(Vector2f(float(rozx), float(rozy)));
	ramka.setOutlineColor(Color::Black);
	ramka.setOutlineThickness(float(1));
	ramka.setFillColor(Color::White);
	ramka.setPosition(float(pozx), float(pozy));
	font = fonttyp;
	tekst.setFillColor(Color::Black);
	tekst.setFont(font);
	tekst.setString(napis);
	tekst.setPosition(float(pozx+1), float(pozy));
	tekst.setCharacterSize(rozmiar);
	tekst.setStyle(Text::Bold);
	numer = num;

}


void poletekstowe::setkol(bool a)
{
	if (a)
		ramka.setFillColor(Color(255, 235, 174));
	else
		ramka.setFillColor(Color(255, 255, 255));
}

void poletekstowe::usuost()
{
	napis.pop_back();
	tekst.setString(napis);
}

void poletekstowe::dodlit(string znak)
{
	napis += znak;
	tekst.setString(napis);
}

void poletekstowe::wpisywanie(char znak)
{
	if (znak >='0' && znak <='9'&& napis.size()<=8) {
		if (napis == "0")
			napis.pop_back();
		napis += znak;
		tekst.setString(napis);
		wartosc = stof(napis);
	}
	else if (znak == '.' && napis.size() <= 8) {
		if (napis.find('.')==string::npos) {//sprawdzam czy nie ma ju¿ kropki
			napis += znak;
			tekst.setString(napis);
			wartosc = stof(napis);
		}
	}
	else if (znak == 8) {//backspace
		napis.pop_back();
		if (napis.size() == 0) {
			napis = "0";
		}
		tekst.setString(napis);
		wartosc = stof(napis);
	}
	else if (znak == '-' && numer == 5) {
		if (napis.find('-') == string::npos) {
			napis = '-' + napis;
			if (napis.size() > 8)
				napis.pop_back();
			tekst.setString(napis);
			wartosc = stof(napis);
		}
		else {
			napis.erase(0,1);
			tekst.setString(napis);
			wartosc = stof(napis);
		}
	}

	if (numer == 2) {//gdy jest to k¹t rzutu
		if (wartosc > 180) {
			wartosc = 180;
			napis = to_string(wartosc);
			while (napis[napis.size() - 1] == '0')
				napis.pop_back();
			if (napis[napis.size() - 1] == '.')
				napis.pop_back();
			tekst.setString(napis);
		}
	}

}

double poletekstowe::getwar()
{
	return wartosc;
}
