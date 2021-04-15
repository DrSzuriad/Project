/** @file */
#pragma once
#include "listaokien.h" 
#include "zasady.h"
#include "enum.h"
#include "gra.h"
#include "listazmian.h"



/** Klasa odpowiedzialna za przechowywanie dany potrzebnych do obs��gi grafiki

*/
class kontener : public zasady, public okna, public plansza, public listazmian {

public:

	static HWND przycisk1; ///< uchwyt pierwszego przycisku
	static HWND przycisk2; ///<uchwyt drugiego przycisku
	static HWND przycisk3; ///< uchwyt trzeciego przycisku
	static zasady* reguly; ///< wska�nik na regu�y rozgrywki
	static okna* listaokien; ///< wska�nik na list� uchwyt�w do okien
	static plansza* mapa; ///<wska�nik na plansze
	static int miejsce;///<miejsce programu, w kt�rym znajduje si� u�ytkownik
	static HINSTANCE hInstance;///< uchwyt aplikacji
	static HWND tekst1;///< uchwyt pierwszego okna z tekstem
	static HWND tekst2;///< uchwyt drugiego okna z tekstem
	static HWND tekst3;///< uchwyt trzeciego okna z tekstem
	static HWND poltekst1;///< uchwyt pierwszego pola tekstowego
	static HWND poltekst2;///< uchwyt drugiego pola tekstowego
	static HWND lista;///< uchwyt do okna comboboxa
	static LPCSTR NazwaKlasy;///< nazwa klasy okna
	static MSG Komunikat;///<komunikat wysy�any przez gracza poprzez klikni�cie
	static HBRUSH g_hBrush;///< uchwyt do stylu okien
	static HBRUSH g_hBrush1;///<  uchwyt do stylu okien
	static LPSTR nazwa1;///< nazwa gracza pierwszego
	static LPSTR nazwa2;///<nazwa gracza drugiego
	static HDC pbianacz;///< uchwyd do grafiki pionka bia�ego na czarnym polu
	static HDC	pbianabia;///< uchwyt do grafiki pionka bia�ego na bia�ym polu
	static HDC pcznacz;///<  uchwyt do grafiki pionka czarnego na czarnym polu
	static HDC pcznabia;///<uchwyt do grafiki pionka czarnego na bia�ym polu
	static HDC dbianacz;///< uchwyt do grafiki damy bia�ej na czarnym polu
	static HDC	dbianabia;///< uchwyt do grafiki damy bia�ej na bia�ym polu
	static HDC dcznacz;///<uchwyt do grafiki damy czarnej na czarnym polu
	static HDC dcznabia;///< uchwyt do grafiki damy czarnej na bia�ym polu
	static HDC bialy;///< uchwyt do bia�ego pustego pola
	static HDC czarny;///< uchwyt do czarnego pustego pola
	static HDC zielony;///< uchwyt do zielonego kwadratu oznaczaj�cego miejsce w kt�re mo�na si� ruszy�
	static HDC czerwony;///< uchwyt do czerwonego kwadratu oznaczaj�cego pionka kt�rym si� aktualnie gracz porusza
	static HDC pionowy;///< uchwyt do czarnego paska pionowego
	static 	HDC poziomy;///< uchwyt do czarnego paska poziomego
	static HDC dograf;///< uchwyt potrzebny do wy�wietlania grafik
	static listazmian* zmianyusu;///< lista zmian na planszy kt�ra b�dzie usuni�ta po wypisaniu
	static listazmian* zmianynieusu;///< lista zmian na planszy kt�ra nie b�dzie usuni�ta po wypisaniu
	static int popx;///< poprzednie miejsce na planszy w pionie w kt�re klikn�� gracz
	static int popy;///< poprzednie miejsce na planszy w pionie w kt�re klikn�� gracz
	static bool czybic;///< czy gracz ju� bi� w swojej turze
	static int remis;///< licznik rund potrzebnych do remisu
};

