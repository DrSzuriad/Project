/** @file */
#pragma once

/** Klasa opisuje pole planszy warcab

*/
class pole{
	int figura; ///< figura jaka znajduje si� na tym polu
	bool kolor; ///< kolor jaki ma to pole

public:
	/** Ustawienie figury na polu
@param fig figura kt�ra b�dzie ustawiona na tym polu
*/
	void setfigura(int fig);
	/** Ustawienie koloru pola
@param kol kolor kt�ry b�dzie ustawiony na polu
*/
	void setkolor(bool kol);
	/** Pobranie informacji jaka figura jest ustawiona na polu
@return jaka figura jest ustawiona na polu
*/
	int getfigura();
	/** Pobranie informacji jaka figura jest ustawiona na polu
@return jaki kolor ma to pole
*/
	bool getkolor();
};

