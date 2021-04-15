/** @file */
#pragma once
#include <Windows.h>

/** Klasa odpowiedzialna za obs��g� okien w grafice

*/
class okna {
	HWND *okno=NULL; ///< wska�nik na uchwyt okna
	okna *kolejny=NULL; ///< wska�nik na kolejny element listy
	public:
		/** Pobranie wska�nika na okno
@return wska�nik na kolejny element listy
*/
		HWND get();
		/** Ustawia kolejny element listy
@param lista wska�nik na liste
*/
		void setlista(okna *lista);
		/** Ustawia wska�nik do okna
@param	okno uchwyt do okna
*/
		void setobiekt(HWND *okno);
		/** dodaje element do listy
@param nowy nowy element do listy
*/
		okna& operator+=(HWND* nowy);
		/** Konstruktor element�w listy
		@param lista lista element�w
@param nowy wka�nik do okna kt�ry b�dzie wstawiony
@return wska�nik na liste
*/
		okna(okna* lista, HWND* nowy);
		/** Opierator usuwa ca�� list�
*/
		okna& operator--();
};
