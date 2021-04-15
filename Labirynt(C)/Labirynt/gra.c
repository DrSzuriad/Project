#include <stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<Windows.h>
#include<time.h>
#include"gra.h"
#include"usuwanie.h"
#include"obslugapliku.h"
#include"przeciwnicy.h"
#include"tablicawynikow.h"
#include"wypisywanie.h"


void gra(tabwyn **pHead, char *nazwa) {
	int wysokosc, szerokosc;
	pole ***tab = NULL;
	Ekwipunekstr *pHeadekw = NULL;
	wrog *przeciwnicy = NULL;
	kordy *postac=NULL;
	if (!czytaniemapy(&tab, &przeciwnicy,  &wysokosc, &szerokosc, &postac))//odczytanie mapy
		return;
	if (postac == NULL) {//czy na mapie jest postac
		printf(" Na tej mapie nie ma bohatera!/n Nacisnij dowolny klawisz, wrocic do menu.");
		dowolnyprzycisk();
		usuncalamape(&tab, wysokosc, szerokosc, &przeciwnicy, &postac);
		return;
	}
	czyszczenie();
	wypiszmapiekw(tab, wysokosc, szerokosc, pHeadekw);
	clock_t czasstartu = clock();
	if (!klawiatura(postac, tab, &pHeadekw, wysokosc, szerokosc, &przeciwnicy))
		printf(" Przegrales\n");
	else {
		printf(" Gratulacje! Wygrales!\n");
		int punkty = (szerokosc*wysokosc) * 100 - 250 * ((clock() - czasstartu) / CLOCKS_PER_SEC);
		if (punkty < 0)
			punkty = 0;
		wipiszdotablicy(pHead,nazwa,punkty);
		printf(" Punkty: %i\n", punkty);
	}
	printf(" Menu - nacisnij dowolny klawisz");
	czyszczeniebufora();
	dowolnyprzycisk();
	usuncalamape(&tab, wysokosc, szerokosc, &przeciwnicy, &postac);
	usunekwipunek(&pHeadekw);
}

bool klawiatura(kordy *ja, pole ***tablica, Ekwipunekstr **pGlowa, int wiersze, int kolumny, wrog **przeciw) {
	double czasruchu;
	kordy *kolja = malloc(sizeof(kordy));
	czasruchu = clock() + 0.5 * CLOCKS_PER_SEC;
	unsigned char tymczasowy = pus;
	bool koniec = false;
	while (!koniec) {
		Sleep(100);
		if (_kbhit()) {
			if (!ruch(ja, kolja)) {
				break;//gdy gracz wcisnie 9
			}
			if (ja->cordx != kolja->cordx || ja->cordy != kolja->cordy) {//czy zmieni³a siê pozycja
				if (!poruszaniesie(ja, kolja, tablica, pGlowa, wiersze, kolumny, &tymczasowy, &koniec)) {
					break;//gdy gracz spotaka przeciwnika
				}
			}
		}
		if (clock() >= czasruchu) {
			if (poruszprzeciwnikami(przeciw, tablica, wiersze, kolumny)) {
				break;//gdy przeciwnik spotka gracza
			}
			czasruchu = czasruchu + 0.3* CLOCKS_PER_SEC;
		}
	}
	free(kolja);
	kolja = NULL;
	return koniec;
}

bool poruszaniesie(kordy *ja, kordy *kolja, pole ***tablica, Ekwipunekstr **pGlowa, int wiersze, int kolumny, unsigned char *tymczasowy, bool *koniec) {
	if (kolja->cordx >= 0 && kolja->cordx < wiersze && kolja->cordy>=0 && kolja->cordy < kolumny) {//czy nie poza plansz¹?
		if (tablica[kolja->cordx][kolja->cordy]->wejscie != nie) {//czy to nie œciana?
			if (tablica[kolja->cordx][kolja->cordy]->wejscie == drz) {//czy to drzwi?
				if (otwdrzwi(wiersze, pGlowa, &tablica[kolja->cordx][kolja->cordy]->obraz))//czy mozemy otworzyc drzwi
					tablica[kolja->cordx][kolja->cordy]->wejscie = tak;
			}
			if (tablica[kolja->cordx][kolja->cordy]->obraz == potwor) {
				return false;
			}
			if (tablica[kolja->cordx][kolja->cordy]->wejscie == tak || tablica[kolja->cordx][kolja->cordy]->wejscie == kon) {//czy mogê wejœæ?
				tablica[ja->cordx][ja->cordy]->obraz = *tymczasowy;
				*tymczasowy = tablica[kolja->cordx][kolja->cordy]->obraz;
				tablica[kolja->cordx][kolja->cordy]->obraz = gracz;
				podmien(ja->cordx, ja->cordy, tablica[ja->cordx][ja->cordy]->obraz, wiersze);
				podmien(kolja->cordx, kolja->cordy, gracz, wiersze);
				ja->cordx = kolja->cordx;
				ja->cordy = kolja->cordy;
				if (*tymczasowy >= klu1 && *tymczasowy <= klu6) {//czy znaleziono klucz?
					znaklu(wiersze, pGlowa, & *tymczasowy);
					tablica[ja->cordx][ja->cordy]->obraz = pus;
				}
				if (tablica[ja->cordx][ja->cordy]->wejscie == kon) {//czy to koniec?
					*koniec = true;
				}
			}
		}
	}
	return true;
}

void dodlista(Ekwipunekstr **pGlowa, unsigned char *znak) {
	Ekwipunekstr *aktualny, *wsknanowy;
	wsknanowy = malloc(sizeof(Ekwipunekstr));
	wsknanowy->przedmiot = *znak;
	wsknanowy->pNext = NULL;
	if ((*pGlowa) == NULL) {
		(*pGlowa) = wsknanowy;
	}
	else {
		aktualny = (*pGlowa);
		while (aktualny->pNext != NULL) {
			aktualny = aktualny->pNext;
		}
		aktualny->pNext = wsknanowy;
	}
}

void znaklu(int wysokosc, Ekwipunekstr **pGlowa, unsigned char *znak) {
	dodlista(pGlowa, znak);
	gotoxy(0, wysokosc);
	wypiszekw(*pGlowa);
	gotoxy(0, wysokosc + 1);
	*znak = pus;
}

Ekwipunekstr *znajdzwekw(Ekwipunekstr *pGlowa, unsigned char znak) {
	if (pGlowa == NULL)
		return NULL;
	else if (pGlowa->przedmiot == znak)
		return pGlowa;
	else {
		Ekwipunekstr *poprzedni = pGlowa;
		pGlowa = pGlowa->pNext;
		while (pGlowa != NULL) {
			if (pGlowa->przedmiot == znak)
				return poprzedni;
			else {
				poprzedni = pGlowa;
				pGlowa = pGlowa->pNext;
			}
		}
		return NULL;
	}
}



bool otwdrzwi(int wysokosc, Ekwipunekstr **pGlowa, unsigned char *znak) {
	unsigned char klucz = *znak - ('A' - 'a');
	Ekwipunekstr *popprzedmiot = znajdzwekw(*pGlowa, klucz), *usuwany;
	if (popprzedmiot == NULL)
		return false;
	else {
		if (popprzedmiot == (*pGlowa) && (*pGlowa)->przedmiot == klucz) {
			usuwany = (*pGlowa);
			(*pGlowa) = (*pGlowa)->pNext;
			free(usuwany);
			usuwany = NULL;
			gotoxy(0, wysokosc);
			wypiszekw(*pGlowa);
		}
		else {
			usuwany = popprzedmiot->pNext;
			popprzedmiot->pNext = usuwany->pNext;
			free(usuwany);
			usuwany = NULL;
			gotoxy(0, wysokosc);
			wypiszekw(*pGlowa);
			gotoxy(0, wysokosc+1);
		}
		*znak = pus;
		return true;
	}
}

bool ruch(kordy *ja, kordy *kolja) {
	int klawisz;
	klawisz = _getch();
	if (klawisz == zkps || klawisz == zkps0) {
		klawisz = _getch();
		switch (klawisz) {
		case lewo://w lewo
			kolja->cordx = ja->cordx;
			kolja->cordy = ja->cordy - 1;
			break;
		case dol://w dó³
			kolja->cordx = ja->cordx + 1;
			kolja->cordy = ja->cordy;
			break;
		case prawo://w prawo
			kolja->cordx = ja->cordx;
			kolja->cordy = ja->cordy + 1;
			break;
		case gora://w górê
			kolja->cordx = ja->cordx - 1;
			kolja->cordy = ja->cordy;
			break;
		}
	}
	else if (klawisz == '9')
		return false;
	return true;
}

