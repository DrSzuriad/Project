/** @file */
#pragma once
#include <Windows.h>
#include "enum.h"
#include "plansza.h"

/** Klasa opisuj�ca miejsce w kt�rym ma zosta� wstawiona bitmapa
*/
class listazmian {
	int x; ///< pozycja na planszy w poziomie
	int y; ///< pozycja na planszy w pionie
	int obrazek; ///< oznaczenie bitmapy kt�ra ma by� wstawiona
	listazmian *pNext; ///< wska�nik na kolejny element listy
public:
	/** Pobiera informacje o miejscu w ktorym ma by� wstawiony obrazek w pionie
@return miejsce w ktorym ma by� wstawiony obrazek w pionie
*/
	int getx();
	/** Pobiera informacje o miejscu w ktorym ma by� wstawiony obrazek w poziomie
@return miejsce w ktorym ma by� wstawiony obrazek w poziomie
*/
	int gety();
	/** Pobiera informacje o obrazku
@return obrazek
*/
	int getobr();
	/** Zwraca wska�nik na kolejny element listy
@return kolejny element listy
*/
	listazmian* getpNext();
	/** Ustawia jaki obrazek ma by� wstawiony
@param a obrazek
*/
	void setobr(int a);
	/** Wstawia nowy element do listy
@param x pozycja wstawianego obrazka w pionie
@param y pozycja wstawianego obrazka w poziomie
@param obr obrazek
@param pHead wska�nik na list� zmian
*/
	listazmian* wstaw(int x, int y, int obr, listazmian *&pHead);
	/** Usuwanie elementu z listy
@param pHead wska�nik na list� zmian
*/
	void usun(listazmian*& pHead);
	/** Podmienia obrazki wszystkich element�w listy na takie jakie s� na planszy
@param mapa plansza warcab
@param zmiany wska�nika na liste zmian
*/
	void podnamap(plansza* mapa, listazmian *zmiany);
	/** Usuwa ca�� list� element�w
@param pHead wska�nik na liste zmian
*/
	void usunliste(listazmian*& pHead);
};