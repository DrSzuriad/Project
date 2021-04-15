/** @file */
#pragma once
#include <windows.h> 
#include <Windowsx.h>
#include "listaokien.h" 
#include "zasady.h"
#include <string>
#include "kontener.h"
#include "gra.h"
#include "zapis.h"

	/** Klasa obs³uguj¹ca tworzenie okien, rysowania bitmap oraz przyjmowania komunikatów od gracza
*/
class grafika :public kontener, public gra, public zapis{

public:
	/** Funkcja odpowiada za obs³ugê komunikatów otrzymanych od gracza
@param hwnd uchwyt do g³ównego okna gry
@param msg komunikat
@param wParam indentyfikator kontrolki któr¹ klikn¹³ gracz
@param lParam uchwyt do okna które klikn¹³ gracz
*/
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	/** Funkcja tworzy klasê gównego okna gry
*/
	static WNDCLASSEX stwkla();
	/** Wypisanie menu gry
@param hwnd uchwyt g³ównego okna gry
*/
	static void wypiszm(HWND hwnd);
	/** Wypisanie miejsca gdzie gracze wybieraj¹ rodzaj warcab i wpisuj¹ swoj¹ nazwê
@param hwnd uchwyt g³ównego okna
*/
	static void wypisznaz(HWND hwnd);
	/** Wypisanie gry
@param hwnd uchwyt g³ównego okna
*/
	static void wypiszgre(HWND hwnd);
	/** Wczytanie z pliku bitmap
*/
	static void bitmapy();
	/** Funkcja wyœwietla dan¹ bitmapê w danym miejscu
@param co bitmapa która ma byæ wyœwietlona
@param x pozycja w poziomie gdzie ma byæ wyœwietlona bitmapa
@param y pozycja w pionie gdzie ma byæ wyœwietlona bitmapa
@param hwnd uchwyt g³ównego okna
*/
	static void wyswbit(int co, int x, int y, HWND hwnd);
	/** funkcja wypisuje mape wraz z innymi oknami
@param mapa1 plansza gry
@param roz rozmiar planszy
@param hwnd uchwyt g³ównego okna
*/
	static void wypiszmape(plansza *mapa1,int roz,HWND hwnd);
	/** Funkcja wypisuj¹ca bitmapy które nadpisuj¹ poprzednie
@param listanieusu lista bitmap które maj¹ byæ wypisane, ale lista nie jest usuwana po wypisaniu
@param listausu lista bitmap które maj¹ byæ wypisane i lista ma zostaæ usuniêta po wypisaniu
@param hwnd uchwyt do g³ównego kona
*/
	static void wypiszzmiany(listazmian* listanieusu, listazmian*& listausu, HWND hwnd);
	/** Funkcja wypisuje plansze
@param mapa1 plansza gry
@param roz rozmiar planszy
@param hwnd uchwyt do g³ównego onka
*/
	static void wypiszplansze(plansza* mapa1, int roz, HWND hwnd);
	/** Funkcja obs³uguj¹ca powrót do menu z gry
@param lista lista otwartych okien
@param hwnd uchwyt do g³ównego okna
@param kiedy miejsce programu, w którym znajduje siê u¿ytkownik
@param mapa plansza gry
@param rozmiar rozmiar planszy
*/
	static void powdomen(okna* lista, HWND hwnd, int& kiedy, plansza* &mapa, int rozmiar);
	/** Funkcja sprawdza czy nie ma remisu
@param remi licznik rund bez zbicia
@param hwnd uchwyt do g³ównego okna
@param lista lista otwartych okien
@param bic czy gracz bi³ w swojej turze
@param kiedy miejsce programu, w którym znajduje siê u¿ytkownik
@param mapa plansza gry
@param rozmiar rozmiar planszy
*/
	static void czremis(int& remi, HWND hwnd, okna* lista, bool &bic, int& kiedy, plansza* mapa, int rozmiar);
	/** Usuwa wszystkie uchwyty do potrzebne do wyœwietlania grafiki
@param hwnd uchwyt do g³ównego okna
*/
	static void usuwaniegrafiki(HWND& hwnd);
};

