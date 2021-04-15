/** @file */
#pragma once
#include "plansza.h"
#include "kontener.h"
#include "zasady.h"
#include "listazmian.h"

/** Klasa obsuguje gre
*/
class gra: public plansza 
{
public:
	/** funkcja obs�uguje klikni�cia gracza na planszy
@param x miejsce w poziomie w kt�re klikn�� gracz
@param y miejsce w pionie w kt�re klikn�� gracz
@param mapa plansza gry
@param kiedy
@param reguly zasady rozgrywki
@param zmianyusu lista bitmap kt�re maj� by� wypisane i lista ma zosta� usuni�ta po wypisaniu
@param zmianynieusu lista bitmap kt�re maj� by� wypisane, ale lista nie jest usuwana po wypisaniu
@param popx miejsce poprzedniego klikni�cia gracza w poziomie
@param popy miejsce poprzedniego klikni�cia gracza w pionie
@param czybic czy gracz ju� bi� w swojej rundzie
*/
	static void klikniecie(int x, int y, plansza *mapa,int &kiedy, zasady* reguly, listazmian*& zmianyusu, listazmian*& zmianynieusu, int &popx, int &popy, bool &czybic);
	/** Funckja sprawdza gdzie mo�e si� ruszy� klikni�ty pionek
@param x miejsce w poziomie w kt�re klikn�� gracz
@param y miejsce w pionie w kt�re klikn�� gracz
@param mapa plansza gry
@param zmianynieusu lista bitmap kt�re maj� by� wypisane, ale lista nie jest usuwana po wypisaniu
@param reguly zasady rozgrywki
@param kiedy miejsce programu, w kt�rym znajduje si� u�ytkownik
*/
	static void gdzieruch(int x, int y, plansza *mapa, listazmian *&zmianynieusu, zasady* reguly, int &kiedy);
	/** Funcja sprawdza czy gracz ma mo�liwo�� ruchu
@param kiedy miejsce programu, w kt�rym znajduje si� u�ytkownik
@param mapa plansza gry
@param reguly zasady rozgrywki
*/
	static bool czymozeruszyc(int kiedy, plansza *mapa, zasady *reguly);
	/** Funckja sprawdza gdzie mo�e si� ruszy� klikni�ty dama
@param x miejsce w poziomie w kt�re klikn�� gracz
@param y miejsce w pionie w kt�re klikn�� gracz
@param mapa plansza gry
@param zmianynieusu lista bitmap kt�re maj� by� wypisane, ale lista nie jest usuwana po wypisaniu
@param reguly zasady rozgrywki
@param kiedy miejsce programu, w kt�rym znajduje si� u�ytkownik
*/
	static void gdzieruchdam(int x, int y, plansza* mapa, listazmian*& zmianynieusu, zasady* reguly, int& kiedy);
	/** Funckja sprawdza czy dama bi�a jaki� pionek lub dam� przeciwnika
@param mapa plansza gry
@param zmianynieusu lista bitmap kt�re maj� by� wypisane, ale lista nie jest usuwana po wypisaniu
@param x miejsce w poziomie w kt�re klikn�� gracz
@param y miejsce w pionie w kt�re klikn�� gracz
@param rozmiar rozmiar planszy
*/
	static bool czydambil(plansza* mapa,listazmian* zmianynieusu,int x, int y, int rozmiar);
	/** Funkcja zmienia pionka na dam�
@param mapa plansza gry
@param zmianyusu lista bitmap kt�re maj� by� wypisane i lista ma zosta� usuni�ta po wypisaniu
@param rozmiar rozmiar planszy
*/
	static void zmianadam(plansza* mapa, listazmian* &zmianyusu, int rozmiar);
};

