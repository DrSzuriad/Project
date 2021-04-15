/** @file */
#pragma once
#include "pole.h"
#include "enum.h"
/** Pobranie informacji jaka figura jest ustawiona na polu
*/
class plansza: public pole{
	pole** tablica; ///< tablica pól planszy warcab
public:
	/** Konstruktor klasy plansza
@param wiel wielkosc planszy
@param kolor kolor pola w lewym dolnym rogu planszy
*/
	plansza(int wiel, bool kolor);
	/** Wpisuje figury na plansze zale¿nie od rodzaju rozgrywki
@param rodzaj rodzaj rozgrywki
*/
	void wpiszf(int rodzaj);
	/** Zwraca figurê jaka jest danym polu planszy
@param x pozycja w poziomie
@param y pozycja w pionie
@return jaka figura jest na danym polu
*/
	int getf(int x, int y);
	/** Zwraca kolor jaki jest danym polu planszy
@param x pozycja w poziomie
@param y pozycja w pionie
@return jaki kolor jest na danym polu
*/
	bool getc(int x, int y);
	/** Ustawia figurê na danym polu planszy
@param x pozycja w poziomie
@param y pozycja w pionie
@param fig figura która ma byæ wstawiona
*/
	void setf(int x, int y, int fig);
	/** Ustawia kolor na danym polu planszy
@param x pozycja w poziomie
@param y pozycja w pionie
@param col kolor który ma byæ wstawiony
*/
	void setc(int x, int y, bool col);
	/** Usuwa ca³¹ planszê
@param roz rozmiar planszy
*/	
	plansza* usun(int roz);
	/** Zmienia miejsce klikniêcia na pozycjê myszki na planszy
@param x pozycja na planszy w poziomie
@param y pozycja na planszy w pionie
*/
	static void pozycja(int &x, int &y);

};

