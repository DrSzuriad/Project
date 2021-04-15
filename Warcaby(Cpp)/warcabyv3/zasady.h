/** @file */
#pragma once
#include "enum.h"



/**Klasa zawiera zasady gry dla aktualnie rozgrywanej rozgrywki

*/


class zasady {
	int rodzaj; ///<  rodzaj rozgrywki
	int rozmiar; ///<  rozmiar planszy
	bool czydambit; ///<  czy dama mo�e by� zbita przez pionka?
	bool czydamwiel; ///<  czy dama mo�e porusz� si� wiele p�l?
	bool obbic; ///< czy jest obowi�zek najlepszego bicia?
	bool bicdot; ///< czy pionek mo�e bi� do ty�u?
	bool polwdl; ///< kolor pola w lewym dolnym rogu planszy
public:
	/** Zwraca wersje rozpocz�tej rozgrywki
	@return a rodzaj rozgrywki
	*/
	int getrodz();
	/** Zwraca rozmiar rozpocz�tej rozgrywki
	@return a rozmiar planszy
*/
	int getroz();
	/** Zwraca informacje o tym czy dama mo�e by� zbita przez pionka
	@return a czy dama mo�e by� zbita przez pionka?
*/
	bool getczydambit();
	/** Zwraca informacje o tym czy dama mo�e porusz� si� o wiele p�l
	@return a czy dama mo�e porusz� si� wiele p�l?
*/
	bool getczydamwiel();
	/** Zwraca informacje o tym czy jest obowi�zek najlepszego bicia
	@return a czy pionek mo�e bi� do ty�u?
*/
	bool getobbic();
	/** Zwraca informacje czy pionek mo�e bi� do ty�u
	@return a czy pionek mo�e bi� do ty�u?
*/
	bool getbicdot();
	/** Zwraca informacje o kolorze pola w dolnym lewym rogu
	@return a kolor pola w lewym dolnym rogu planszy
*/
	bool getpolwdl();
	/** Ustawia rodzaj rozgrywki
	@param a rodzaj rozgrywki
*/
	void setrodz(int a);
	/** Ustawia rozmiar planszy
@param a rozmiar planszy
*/
	void setroz(int a);
	/** Ustawia informacje o tym czy dama mo�e zosta� zbita przez pionka
@param a Czy dama mo�e by� zbita przez pionka?
*/
	void setczydambit(bool a);
	/** Ustawia informacje o tym czy dama mo�e porusz� si� o wiele p�l
@param a Czy dama mo�e porusz� si� wiele p�l?
*/
	void setczydamwiel(bool a);
	/** Ustawia informacje o tym czy jest obowi�zek najlepszego bicia
@param a Czy jest obowi�zek najlepszego bicia?
*/
	void setobbic(bool a);
	/** Ustawia informacje czy pionek mo�e bi� do ty�u
@param a Ustawia czy pionek mo�e bi� do ty�u?
*/
	void setbicdot(bool a);
	/** Ustawia informacje o kolorze pola w dolnym lewym rogu
@param a Kolor pola w lewym dolnym rogu planszy
*/
	void setpolwdl(bool a);

	/** Ustawia zasady zaleznie od wybranego rodzaju warcab
@param a Rodzaj warcab
*/
	zasady* ustawzasady(int a);
	/** Konstruktor klasy zasady
@param rodz Rodzaj rozgrywki
@param roz Rozmiar planszy
@param dambit Czy dama mo�e by� zbita przez pionka?
@param damwiel Czy dama mo�e porusz� si� wiele p�l?
@param bic Czy jest obowi�zek najlepszego bicia?
@param dot  Czy pionek mo�e bi� do ty�u?
@param polwdl Kolor pola w lewym dolnym rogu planszy
*/
	zasady(int rodz, int roz, bool dambit, bool damwiel, bool bic, bool dot, bool polwdl);

};
