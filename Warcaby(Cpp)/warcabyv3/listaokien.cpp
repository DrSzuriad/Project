#include "listaokien.h"



HWND okna::get() {
	return *okno;
}



okna& okna::operator+=(HWND* nowy) {
	
	this->kolejny = new okna(this->kolejny, nowy);
	return *this;

}


void okna::setlista(okna *lista) {
	this->kolejny = lista;
}


void okna::setobiekt(HWND *okno) {
	this->okno = okno;
}

okna::okna(okna *lista,HWND *nowy):kolejny(lista),okno(nowy) {}

okna& okna::operator--() {
	okna* usuwany = NULL;
	while (kolejny != NULL)
	{
		DestroyWindow(*kolejny->okno);
		usuwany = kolejny;
		kolejny = kolejny->kolejny;
		delete(usuwany);
	}
	kolejny = nullptr;
	return *this;
}