#include "listazmian.h"


int listazmian::getx() {
	return x;
}

int listazmian::gety(){
	return y;
}

int listazmian::getobr(){
	return obrazek;
}
listazmian* listazmian::getpNext() {
	return pNext;
}

void listazmian::setobr(int a){
	obrazek = a;
}

listazmian* listazmian::wstaw(int x, int y, int obr, listazmian*& pHead) {

	listazmian* stary = pHead;
	pHead = new listazmian;
	pHead->x = x;
	pHead->y = y;
	pHead->obrazek = obr;
	pHead->pNext = stary;
	return pHead;
}

void listazmian::usun(listazmian*& pHead) {
	listazmian* kol = pHead->pNext;
	delete(pHead);
	pHead = kol;
}

void listazmian::podnamap(plansza* mapa, listazmian* zmiany) {
	while (zmiany != NULL) {
		if (mapa->getc(zmiany->getx(), zmiany->gety()) == true) {
			if (mapa->getf(zmiany->getx(), zmiany->gety()) == pionekbia)
				zmiany->setobr(pbnb);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == pionekcza)
				zmiany->setobr(pcnb);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == damabia)
				zmiany->setobr(dbnb);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == damacza)
				zmiany->setobr(dcnb);
			else
				zmiany->setobr(bia);
		}
		else {
			if (mapa->getf(zmiany->getx(), zmiany->gety()) == pionekbia)
				zmiany->setobr(pbnc);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == pionekcza)
				zmiany->setobr(pcnc);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == damabia)
				zmiany->setobr(dbnc);
			else if (mapa->getf(zmiany->getx(), zmiany->gety()) == damacza)
				zmiany->setobr(dcnc);
			else
				zmiany->setobr(cz);
		}
		zmiany = zmiany->pNext;
	}
}

void listazmian::usunliste(listazmian*& pHead) {
	while (pHead != nullptr)
		pHead->usun(pHead);
}