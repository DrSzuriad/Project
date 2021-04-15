#include <stdio.h>
#include<conio.h>
#include<stdbool.h>
#include <stdlib.h>
#include"edytormap.h"
#include"usuwanie.h"
#include"obslugapliku.h"
#include"przeciwnicy.h"
#include"wypisywanie.h"

void edytormap() {
	int a = 0;
	while (true) {
		czyszczenie();
		printf(" 1. Nowa mapa\n 2. Edytuj mape\n 3. Powrot\n ");
		scanf("%i", &a);
		if (a > 0 && a < 5) {
			switch (a) {
			case 1:
				nowamapa();
				return;
				break;
			case 2:
				staramapa();
				return;
				break;
			case 3:
				return;
				break;
			}
		}
		else
			czyszczeniebufora();

	}
}

void nowamapa() {
	czyszczenie();
	pole ***tablica;
	int wiersze = 0, kolumny = 0;
	printf(" Podaj rozmiar mapy ( maksymalnie 200 na 200).\n Wiersze: ");
	czyszczeniebufora();
	scanf("%i", &wiersze);
	while (wiersze<1||wiersze>200) {
		czyszczenie();
		printf(" Bledna wartosc!\n Podaj jeszcze raz ilosc wierszy (max 200) : ");
		czyszczeniebufora();
		scanf("%i", &wiersze);
	}
	printf(" Kolumny: ");
	czyszczeniebufora();
	scanf("%i", &kolumny);
	while (kolumny<1 || kolumny>200) {
		czyszczenie();
		printf(" Bledna wartosc!\n Podaj jeszcze raz ilosc kolumn (max 200) : ");
		czyszczeniebufora();
		scanf("%i", &kolumny);
	}
	tablica = malloc(wiersze * sizeof(pole**));
	for (int i = 0; i < wiersze; i++) {
		tablica[i] = malloc(kolumny * sizeof(pole*));
		for (int o = 0; o < wiersze; o++) {
			tablica[i][o] = malloc(sizeof(pole));
			tablica[i][o]->obraz = pus;
			tablica[i][o]->wejscie = tak;
		}
	}
	wrog *przeciwnicy = NULL;
	kordy *postac =NULL;
	edycja(&tablica,wiersze,kolumny,&przeciwnicy,&postac);
	return;
}

void staramapa() {
	int wysokosc, szerokosc;
	pole ***tab = NULL;
	Ekwipunekstr *pHeadekw = NULL;
	wrog *przeciwnicy = NULL;
	kordy *postac=NULL;
	if (!czytaniemapy(&tab, &przeciwnicy, &wysokosc, &szerokosc, &postac))
		return;
	edycja(&tab, wysokosc, szerokosc, &przeciwnicy, &postac);
	return;
}

void wpisz(int znak, kordy pozycja, wskpole mapa) {
	(*mapa)[pozycja.cordx][pozycja.cordy]->obraz = znak;
}

int wktorastrone() {
	while (true) {
		int klawisz = _getch();
		if (klawisz == zkps || klawisz == zkps0)
			return _getch();
	}
}

void przemieszczenie(kordy *pozycja, int wiersze, int kolumny) {
	kordy *kolejna = malloc(sizeof(kordy));
	while (true) {
		gotoxy(pozycja->cordy, pozycja->cordx);
		int znak = _getch();
		if (znak == zkps || znak == zkps0) {
			kolejna->cordx = pozycja->cordx;
			kolejna->cordy = pozycja->cordy;
			switch (_getch())
			{
			case lewo:
				kolejna->cordy--;
				break;
			case prawo:
				kolejna->cordy++;
				break;
			case gora:
				kolejna->cordx--;
				break;
			case dol:
				kolejna->cordx++;
				break;
			}
			if (kolejna->cordx >= 0 && kolejna->cordx < wiersze && kolejna->cordy>=0 && kolejna->cordy < kolumny) {
				gotoxy(kolejna->cordy, kolejna->cordy);
				pozycja->cordx = kolejna->cordx;
				pozycja->cordy = kolejna->cordy;

			}
		}
		else if (znak == '1') {//powrot
			break;
		}
	}
	free(kolejna);
	kolejna = NULL;
	return;
}

void edycja(wskpole mapa, int wiersze, int kolumny, wrog **przeciwnicy, kordy **postac) {
	kordy pozycja = { 0,0 };
	int wczesniejczy;
	czyszczenie();
	wypiszpomoc(kolumny);
	while (true) {
		wypiszmapa(*mapa, wiersze, kolumny);
		gotoxy(pozycja.cordy, pozycja.cordx);
		wczesniejczy = (*mapa)[pozycja.cordx][pozycja.cordy]->obraz;
		bool zmianaznaku = false;
		int znak = 0;
		czyszczeniebufora();
		scanf("%i", &znak);
		switch (znak) {
		case chodzenie:
			czyszczenie();
			wypiszmapa(*mapa, wiersze, kolumny);
			wypiszpomchodzenie(kolumny);
			przemieszczenie(&pozycja, wiersze, kolumny);
			czyszczenie();
			wypiszpomoc(kolumny);
			break;
		case eglr:
			wpisz(glr, pozycja,mapa);
			zmianaznaku = true;
			break;
		case egpr:
			wpisz(gpr, pozycja,mapa);
			zmianaznaku = true;
			break;
		case edlr:
			wpisz(dlr, pozycja,mapa);
			zmianaznaku = true;
			break;
		case edpr:
			wpisz(dpr, pozycja,mapa);
			zmianaznaku = true;
			break;
		case epoz:
			wpisz(poz, pozycja,mapa);
			zmianaznaku = true;
			break;
		case epio:
			wpisz(pio, pozycja,mapa);
			zmianaznaku = true;
			break;
		case elsc:
			wpisz(lsc, pozycja,mapa);
			zmianaznaku = true;
			break;
		case epsc:
			wpisz(psc, pozycja,mapa);
			zmianaznaku = true;
			break;
		case egsc:
			wpisz(egsc, pozycja,mapa);
			zmianaznaku = true;
			break;
		case edsc:
			wpisz(dsc, pozycja,mapa);
			zmianaznaku = true;
			break;
		case esro:
			wpisz(sro, pozycja,mapa);
			zmianaznaku = true;
			break;
		case ekro:
			wpisz(kro, pozycja,mapa);
			zmianaznaku = true;
			break;
		case epus:
			wpisz(pus, pozycja,mapa);
			zmianaznaku = true;
			break;
		case eklu1:
		case eklu2: 
		case eklu3:
		case eklu4:
		case eklu5:
		case eklu6:
			wpisz(znak-eklu1+klu1, pozycja,mapa);
			zmianaznaku = true;
			break;
		case ezam1: 
		case ezam2:
		case ezam3: 
		case ezam4:
		case ezam5:
		case ezam6:
			wpisz(znak-ezam1+zam1, pozycja,mapa);
			zmianaznaku = true;
			break;
		case ewyjscie:
			wpisz(wyjscie, pozycja,mapa);
			zmianaznaku = true;
			break;
		case epotwor:
			wpisz(potwor, pozycja,mapa);
			dodprzec(przeciwnicy, pozycja, wktorastrone(), pus);
			zmianaznaku = true;
			break;
		case egracz: 
			if (*postac == NULL&&wczesniejczy!=gracz) {//czy nie stawiamy gracza na graczu
				*postac = malloc(sizeof(kordy));
				wpisz(gracz, pozycja,mapa);
				(*postac)->cordx = pozycja.cordx;
				(*postac)->cordy = pozycja.cordy;
				zmianaznaku = true;
			}
			break;
		case wyjsciezzapisem:
			zapiszmape(mapa,przeciwnicy,wiersze,kolumny,*postac);
			usuncalamape(mapa, wiersze, kolumny, przeciwnicy, postac);
			return;
		case wyjsciebezzapisu:
			usuncalamape(mapa, wiersze, kolumny, przeciwnicy, postac);
			return;
		}
		if (zmianaznaku == true) {
			if (wczesniejczy == gracz) {//gdy stawiamy coœ na graczu
				free(*postac);
				*postac = NULL;
			}
			else if (wczesniejczy == potwor) {//gdy stawiamy coœ na przeciwniku
				usunprzeciw(przeciwnicy, pozycja);
			}

		}
	}
}
