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

	/** Klasa obs�uguj�ca tworzenie okien, rysowania bitmap oraz przyjmowania komunikat�w od gracza
*/
class grafika :public kontener, public gra, public zapis{

public:
	/** Funkcja odpowiada za obs�ug� komunikat�w otrzymanych od gracza
@param hwnd uchwyt do g��wnego okna gry
@param msg komunikat
@param wParam indentyfikator kontrolki kt�r� klikn�� gracz
@param lParam uchwyt do okna kt�re klikn�� gracz
*/
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	/** Funkcja tworzy klas� g�wnego okna gry
*/
	static WNDCLASSEX stwkla();
	/** Wypisanie menu gry
@param hwnd uchwyt g��wnego okna gry
*/
	static void wypiszm(HWND hwnd);
	/** Wypisanie miejsca gdzie gracze wybieraj� rodzaj warcab i wpisuj� swoj� nazw�
@param hwnd uchwyt g��wnego okna
*/
	static void wypisznaz(HWND hwnd);
	/** Wypisanie gry
@param hwnd uchwyt g��wnego okna
*/
	static void wypiszgre(HWND hwnd);
	/** Wczytanie z pliku bitmap
*/
	static void bitmapy();
	/** Funkcja wy�wietla dan� bitmap� w danym miejscu
@param co bitmapa kt�ra ma by� wy�wietlona
@param x pozycja w poziomie gdzie ma by� wy�wietlona bitmapa
@param y pozycja w pionie gdzie ma by� wy�wietlona bitmapa
@param hwnd uchwyt g��wnego okna
*/
	static void wyswbit(int co, int x, int y, HWND hwnd);
	/** funkcja wypisuje mape wraz z innymi oknami
@param mapa1 plansza gry
@param roz rozmiar planszy
@param hwnd uchwyt g��wnego okna
*/
	static void wypiszmape(plansza *mapa1,int roz,HWND hwnd);
	/** Funkcja wypisuj�ca bitmapy kt�re nadpisuj� poprzednie
@param listanieusu lista bitmap kt�re maj� by� wypisane, ale lista nie jest usuwana po wypisaniu
@param listausu lista bitmap kt�re maj� by� wypisane i lista ma zosta� usuni�ta po wypisaniu
@param hwnd uchwyt do g��wnego kona
*/
	static void wypiszzmiany(listazmian* listanieusu, listazmian*& listausu, HWND hwnd);
	/** Funkcja wypisuje plansze
@param mapa1 plansza gry
@param roz rozmiar planszy
@param hwnd uchwyt do g��wnego onka
*/
	static void wypiszplansze(plansza* mapa1, int roz, HWND hwnd);
	/** Funkcja obs�uguj�ca powr�t do menu z gry
@param lista lista otwartych okien
@param hwnd uchwyt do g��wnego okna
@param kiedy miejsce programu, w kt�rym znajduje si� u�ytkownik
@param mapa plansza gry
@param rozmiar rozmiar planszy
*/
	static void powdomen(okna* lista, HWND hwnd, int& kiedy, plansza* &mapa, int rozmiar);
	/** Funkcja sprawdza czy nie ma remisu
@param remi licznik rund bez zbicia
@param hwnd uchwyt do g��wnego okna
@param lista lista otwartych okien
@param bic czy gracz bi� w swojej turze
@param kiedy miejsce programu, w kt�rym znajduje si� u�ytkownik
@param mapa plansza gry
@param rozmiar rozmiar planszy
*/
	static void czremis(int& remi, HWND hwnd, okna* lista, bool &bic, int& kiedy, plansza* mapa, int rozmiar);
	/** Usuwa wszystkie uchwyty do potrzebne do wy�wietlania grafiki
@param hwnd uchwyt do g��wnego okna
*/
	static void usuwaniegrafiki(HWND& hwnd);
};

