#include<time.h>
#include<stdlib.h>
#include"przeciwnicy.h"


void dodprzec(wrog **przeciwnicy, kordy pozycja, int kierunek, int naczym){
	wrog *wstawiany = malloc(sizeof(wrog));
	wstawiany->pozycja = pozycja;
	wstawiany->kierunek = kierunek;
	wstawiany->naczymstoi = naczym;
	wstawiany->ruch = false;
	wstawiany->pNext = NULL;
	if (*przeciwnicy == NULL) {
		*przeciwnicy = wstawiany;
	}
	else {
		wrog *aktualny;
		aktualny = *przeciwnicy;
		while (aktualny->pNext != NULL) {
			aktualny = aktualny->pNext;
		}
		aktualny->pNext = wstawiany;
	}
}

void zmianapozycjiprze(kordy *ja, kordy *kolja, pole ***tablica, int wiersze, unsigned char *tymczasowy) {
	tablica[ja->cordx][ja->cordy]->obraz = *tymczasowy;
	*tymczasowy = tablica[kolja->cordx][kolja->cordy]->obraz;
	(*tablica[kolja->cordx][kolja->cordy]).obraz = potwor;
	podmien(ja->cordx, ja->cordy, tablica[ja->cordx][ja->cordy]->obraz, wiersze);
	podmien(kolja->cordx, kolja->cordy, potwor, wiersze);
	ja->cordx = kolja->cordx;
	ja->cordy = kolja->cordy;
}

wrog* znajdzprzeciwnika(kordy gdzie, wrog *przec) {
	wrog *aktualny = przec;
	while(aktualny->pozycja.cordx != gdzie.cordx||aktualny->pozycja.cordy != gdzie.cordy) {
		aktualny = aktualny->pNext;
	}
	return aktualny;
}

void ruchnormalny(wrog *przeciw, kordy *kolejne){
	switch (przeciw->kierunek) {
	case lewo:
		kolejne->cordx = przeciw->pozycja.cordx;
		kolejne->cordy = przeciw->pozycja.cordy - 1;
		break;
	case dol:
		kolejne->cordx = przeciw->pozycja.cordx + 1;
		kolejne->cordy = przeciw->pozycja.cordy;
		break;
	case prawo:
		kolejne->cordx = przeciw->pozycja.cordx;
		kolejne->cordy = przeciw->pozycja.cordy + 1;
		break;
	case gora:
		kolejne->cordx = przeciw->pozycja.cordx - 1;
		kolejne->cordy = przeciw->pozycja.cordy;
		break;
	}
}

void ruchodwrotny(wrog *przeciw, kordy *kolejne) {
	switch (przeciw->kierunek) {
	case lewo:
		przeciw->kierunek = prawo;
		kolejne->cordy += 2;
		break;
	case dol:
		przeciw->kierunek = gora;
		kolejne->cordx -= 2;
		break;
	case prawo:
		przeciw->kierunek = lewo;
		kolejne->cordy -= 2;
		break;
	case gora:
		przeciw->kierunek = dol;
		kolejne->cordx += 2;
		break;
	}
}

bool ruchnormalnyzw(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy *kolejne,wrog *wszyscy) {
	if (kolejne->cordx < 0 || kolejne->cordx >= wysokosc || kolejne->cordy < 0 || kolejne->cordy >= szerokosc)//czy nie poza mapa
		return false;
	if (tablica[kolejne->cordx][kolejne->cordy]->obraz == potwor) {//czy tam nie ma innego potwora
		kordy odkogo = przeciw->pozycja;
		if (potworprzed(znajdzprzeciwnika(*kolejne, wszyscy), tablica, wysokosc, szerokosc, koniec, odkogo,false,wszyscy) == false)
			return false;
	}
	if (tablica[kolejne->cordx][kolejne->cordy]->obraz == gracz) {//czy tam nie ma gracza
		*koniec = true;
		return true;
	}
	if (tablica[kolejne->cordx][kolejne->cordy]->wejscie == nie)//czy tam moge wejsc
		return false;
	przeciw->ruch = true;
	zmianapozycjiprze(&przeciw->pozycja, kolejne, tablica, wysokosc, &przeciw->naczymstoi);//wykonanie ruchu
	return true;
}

bool ruchodwrotnyzw(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy *kolejne, wrog *wszyscy) {
	if (kolejne->cordx < 0 || kolejne->cordx >= wysokosc || kolejne->cordy < 0 || kolejne->cordy >= szerokosc)//czy nie poza mapa
		return false;
	if (tablica[kolejne->cordx][kolejne->cordy]->obraz == potwor) {//czy tam nie ma potwora
		kordy odkogo = przeciw->pozycja;
		if (potworprzed(znajdzprzeciwnika(*kolejne, wszyscy) , tablica, wysokosc, szerokosc, koniec, odkogo,true,wszyscy) == false)
			return false;
	}
	if (tablica[kolejne->cordx][kolejne->cordy]->obraz == gracz) {//czy tam nie ma gracza
		*koniec = true;
		return true;
	}
	if (tablica[kolejne->cordx][kolejne->cordy]->wejscie == nie)//czy tam moge wejsc
		return false;
	przeciw->ruch = true;
	zmianapozycjiprze(&przeciw->pozycja, kolejne, tablica, wysokosc, &przeciw->naczymstoi);
	return true;
}

bool potworprzed(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, kordy odkogo, bool sciana, wrog *wszyscy) {
	if (przeciw->ruch == true) {//czy juz sie nie ruszyl
		return false;
	}
	kordy *kolejne = malloc(sizeof(kordy));
	ruchnormalny(przeciw, kolejne);
	if (kolejne->cordx == odkogo.cordx&&kolejne->cordy == odkogo.cordy) {//czy to nie ten ktory nam kazal sie ruszyc
		ruchodwrotny(przeciw, kolejne);
		if (ruchodwrotnyzw(przeciw, tablica, wysokosc, szerokosc, koniec, kolejne, wszyscy)) {//czy udal sie ruch
			if (sciana == true) {//czy wczesniejszy napotakal sciane, tzw. czy juz wykonuje ruch odwrotny
				free(kolejne);
				kolejne = NULL;
				return true;
			}
		}
		free(kolejne);
		kolejne = NULL;
		return false;
	}
	else
		if (ruchnormalnyzw(przeciw, tablica, wysokosc, szerokosc, koniec, kolejne, wszyscy) == false) {
			ruchodwrotny(przeciw, kolejne);
			free(kolejne);
			kolejne = NULL;
			return false;
		}
	free(kolejne);
	kolejne = NULL;
	return true;
}

void gdzieiscprze(wrog *przeciw, pole ***tablica, int wysokosc, int szerokosc, bool *koniec, wrog *wszyscy) {
	if (przeciw->ruch == false) {
		kordy *kolejne = malloc(sizeof(kordy));
		ruchnormalny(przeciw, kolejne);
		if (ruchnormalnyzw(przeciw, tablica, wysokosc, szerokosc, koniec, kolejne, wszyscy) == false) {
			ruchodwrotny(przeciw, kolejne);
			ruchodwrotnyzw(przeciw, tablica, wysokosc, szerokosc, koniec, kolejne, wszyscy);
		}
		free(kolejne);
		kolejne = NULL;
	}
	return;
}
void wyszczscruch(wrog **przeciw){
	wrog *aktualny = *przeciw;
	while (aktualny!=NULL)
	{
		aktualny->ruch = false;
		aktualny = aktualny->pNext;
	}
}

bool poruszprzeciwnikami(wrog **przeciw, pole ***tablica,int wiersze,int kolumny) {
	wrog *aktualny = (*przeciw);
	bool koniec=false;
	kordy puste = { 0,0 };
	while (aktualny != NULL)
	{
		gdzieiscprze(aktualny, tablica, wiersze, kolumny, &koniec,*przeciw);
		if (koniec == true)
			return true;
		aktualny = aktualny->pNext;
	}
	wyszczscruch(przeciw);
	return false;
}

void usunprzeciw(wrog **przeciwnicy, kordy pozycja) {
	wrog *usuwany = NULL;
	if (*przeciwnicy == NULL);
	else if ((*przeciwnicy)->pozycja.cordx == pozycja.cordx && (*przeciwnicy)->pozycja.cordy == pozycja.cordy) {
		usuwany = *przeciwnicy;
		*przeciwnicy = (*przeciwnicy)->pNext;
		free(usuwany);
		usuwany = NULL;
	}
	else {
		wrog *aktualny = (*przeciwnicy);
		while (aktualny->pNext != NULL){
			if (aktualny->pNext->pozycja.cordx = pozycja.cordx&&aktualny->pNext->pozycja.cordy == pozycja.cordy) {
				usuwany = aktualny->pNext;
				aktualny->pNext = usuwany->pNext;
				free(usuwany);
				usuwany = NULL;
				return;
			}
			else
				aktualny = aktualny->pNext;
		}
	}
}
