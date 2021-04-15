/** @file */
#pragma once
#include <Windows.h>
#include "enum.h"
#include "plansza.h"

/** Klasa opisuj¹ca miejsce w którym ma zostaæ wstawiona bitmapa
*/
class listazmian {
	int x; ///< pozycja na planszy w poziomie
	int y; ///< pozycja na planszy w pionie
	int obrazek; ///< oznaczenie bitmapy która ma byæ wstawiona
	listazmian *pNext; ///< wska¿nik na kolejny element listy
public:
	/** Pobiera informacje o miejscu w ktorym ma byæ wstawiony obrazek w pionie
@return miejsce w ktorym ma byæ wstawiony obrazek w pionie
*/
	int getx();
	/** Pobiera informacje o miejscu w ktorym ma byæ wstawiony obrazek w poziomie
@return miejsce w ktorym ma byæ wstawiony obrazek w poziomie
*/
	int gety();
	/** Pobiera informacje o obrazku
@return obrazek
*/
	int getobr();
	/** Zwraca wska¿nik na kolejny element listy
@return kolejny element listy
*/
	listazmian* getpNext();
	/** Ustawia jaki obrazek ma byæ wstawiony
@param a obrazek
*/
	void setobr(int a);
	/** Wstawia nowy element do listy
@param x pozycja wstawianego obrazka w pionie
@param y pozycja wstawianego obrazka w poziomie
@param obr obrazek
@param pHead wska¿nik na listê zmian
*/
	listazmian* wstaw(int x, int y, int obr, listazmian *&pHead);
	/** Usuwanie elementu z listy
@param pHead wskaŸnik na listê zmian
*/
	void usun(listazmian*& pHead);
	/** Podmienia obrazki wszystkich elementów listy na takie jakie s¹ na planszy
@param mapa plansza warcab
@param zmiany wskaŸnika na liste zmian
*/
	void podnamap(plansza* mapa, listazmian *zmiany);
	/** Usuwa ca³¹ listê elementów
@param pHead wskaŸnik na liste zmian
*/
	void usunliste(listazmian*& pHead);
};