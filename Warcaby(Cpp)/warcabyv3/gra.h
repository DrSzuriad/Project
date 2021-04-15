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
	/** funkcja obs³uguje klikniêcia gracza na planszy
@param x miejsce w poziomie w które klikn¹³ gracz
@param y miejsce w pionie w które klikn¹³ gracz
@param mapa plansza gry
@param kiedy
@param reguly zasady rozgrywki
@param zmianyusu lista bitmap które maj¹ byæ wypisane i lista ma zostaæ usuniêta po wypisaniu
@param zmianynieusu lista bitmap które maj¹ byæ wypisane, ale lista nie jest usuwana po wypisaniu
@param popx miejsce poprzedniego klikniêcia gracza w poziomie
@param popy miejsce poprzedniego klikniêcia gracza w pionie
@param czybic czy gracz ju¿ bi³ w swojej rundzie
*/
	static void klikniecie(int x, int y, plansza *mapa,int &kiedy, zasady* reguly, listazmian*& zmianyusu, listazmian*& zmianynieusu, int &popx, int &popy, bool &czybic);
	/** Funckja sprawdza gdzie mo¿e siê ruszyæ klikniêty pionek
@param x miejsce w poziomie w które klikn¹³ gracz
@param y miejsce w pionie w które klikn¹³ gracz
@param mapa plansza gry
@param zmianynieusu lista bitmap które maj¹ byæ wypisane, ale lista nie jest usuwana po wypisaniu
@param reguly zasady rozgrywki
@param kiedy miejsce programu, w którym znajduje siê u¿ytkownik
*/
	static void gdzieruch(int x, int y, plansza *mapa, listazmian *&zmianynieusu, zasady* reguly, int &kiedy);
	/** Funcja sprawdza czy gracz ma mo¿liwoœæ ruchu
@param kiedy miejsce programu, w którym znajduje siê u¿ytkownik
@param mapa plansza gry
@param reguly zasady rozgrywki
*/
	static bool czymozeruszyc(int kiedy, plansza *mapa, zasady *reguly);
	/** Funckja sprawdza gdzie mo¿e siê ruszyæ klikniêty dama
@param x miejsce w poziomie w które klikn¹³ gracz
@param y miejsce w pionie w które klikn¹³ gracz
@param mapa plansza gry
@param zmianynieusu lista bitmap które maj¹ byæ wypisane, ale lista nie jest usuwana po wypisaniu
@param reguly zasady rozgrywki
@param kiedy miejsce programu, w którym znajduje siê u¿ytkownik
*/
	static void gdzieruchdam(int x, int y, plansza* mapa, listazmian*& zmianynieusu, zasady* reguly, int& kiedy);
	/** Funckja sprawdza czy dama bi³a jakiœ pionek lub damê przeciwnika
@param mapa plansza gry
@param zmianynieusu lista bitmap które maj¹ byæ wypisane, ale lista nie jest usuwana po wypisaniu
@param x miejsce w poziomie w które klikn¹³ gracz
@param y miejsce w pionie w które klikn¹³ gracz
@param rozmiar rozmiar planszy
*/
	static bool czydambil(plansza* mapa,listazmian* zmianynieusu,int x, int y, int rozmiar);
	/** Funkcja zmienia pionka na damê
@param mapa plansza gry
@param zmianyusu lista bitmap które maj¹ byæ wypisane i lista ma zostaæ usuniêta po wypisaniu
@param rozmiar rozmiar planszy
*/
	static void zmianadam(plansza* mapa, listazmian* &zmianyusu, int rozmiar);
};

