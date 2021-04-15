/** @file */
#pragma once
#include <fstream>
#include <Windows.h>
#include "zasady.h"
#include "plansza.h"
using namespace std;

/**Klasa zawiera obs�ug� zapisywanie i wczytywanie do pliku
*/
class zapis {

public:
	/** Zapisuje aktualn� rozgrywk� do pliku
	@param reguly regu�y rozgrywki
	@param nazwa1 nazwa pierwszego gracza
	@param nazwa2 nazwa drugiego gracza
	@param mapa plansza warcab
	@param miejsce jaki jest stan rozgrywki?
	*/
	static void zapisz(zasady*& reguly, LPSTR& nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce);
	/** Wczytuje ostatnio zapisan� rozgrywk� z pliku
@param reguly regu�y rozgrywki
@param nazwa1 nazwa pierwszego gracza
@param nazwa2 nazwa drugiego gracza
@param mapa plansza warcab
@param miejsce jaki jest stan rozgrywki?
*/
	static void wczytaj(zasady*& reguly, LPSTR& nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce);
};