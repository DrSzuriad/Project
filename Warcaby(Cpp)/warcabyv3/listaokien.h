/** @file */
#pragma once
#include <Windows.h>

/** Klasa odpowiedzialna za obs³ógê okien w grafice

*/
class okna {
	HWND *okno=NULL; ///< wska¿nik na uchwyt okna
	okna *kolejny=NULL; ///< wska¿nik na kolejny element listy
	public:
		/** Pobranie wskaŸnika na okno
@return wskaŸnik na kolejny element listy
*/
		HWND get();
		/** Ustawia kolejny element listy
@param lista wskaŸnik na liste
*/
		void setlista(okna *lista);
		/** Ustawia wska¿nik do okna
@param	okno uchwyt do okna
*/
		void setobiekt(HWND *okno);
		/** dodaje element do listy
@param nowy nowy element do listy
*/
		okna& operator+=(HWND* nowy);
		/** Konstruktor elementów listy
		@param lista lista elementów
@param nowy wka¿nik do okna który bêdzie wstawiony
@return wskaŸnik na liste
*/
		okna(okna* lista, HWND* nowy);
		/** Opierator usuwa ca³¹ listê
*/
		okna& operator--();
};
