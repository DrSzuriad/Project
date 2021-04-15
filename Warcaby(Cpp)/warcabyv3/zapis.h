/** @file */
#pragma once
#include <fstream>
#include <Windows.h>
#include "zasady.h"
#include "plansza.h"
using namespace std;

/**Klasa zawiera obs³ugê zapisywanie i wczytywanie do pliku
*/
class zapis {

public:
	/** Zapisuje aktualn¹ rozgrywkê do pliku
	@param reguly regu³y rozgrywki
	@param nazwa1 nazwa pierwszego gracza
	@param nazwa2 nazwa drugiego gracza
	@param mapa plansza warcab
	@param miejsce jaki jest stan rozgrywki?
	*/
	static void zapisz(zasady*& reguly, LPSTR& nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce);
	/** Wczytuje ostatnio zapisan¹ rozgrywkê z pliku
@param reguly regu³y rozgrywki
@param nazwa1 nazwa pierwszego gracza
@param nazwa2 nazwa drugiego gracza
@param mapa plansza warcab
@param miejsce jaki jest stan rozgrywki?
*/
	static void wczytaj(zasady*& reguly, LPSTR& nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce);
};