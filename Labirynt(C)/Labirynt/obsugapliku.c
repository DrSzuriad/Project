#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"obslugapliku.h"
#include"przeciwnicy.h"
#include"tablicawynikow.h"

void zczytajtablice(tabwyn **pHead) {
	FILE *plik = fopen("tablicawynikow.txt", "a+");
	while (getc(plik)!=EOF) {
		fseek(plik, -1, 1);
		tabwyn *nowy = malloc(sizeof(tabwyn));
		fscanf(plik, " %s", nowy->nazwa);
		fscanf(plik, "%i", &nowy->wynik);
		nowy->pNext = NULL;
		dodajwynik(pHead, nowy);
		fseek(plik, 1, 1);//przeskakuje spacje ktora jest wpisywana po kazdym z wynikow
	}
	fclose(plik);
}

bool zczytaj(wskpole tablica, wrog **przeciwnicy, int *wysokosc, int *szerokosc, kordy **postac, char *nazwa) {
	FILE *plik = fopen(nazwa, "rb");
	if (plik == NULL) {
		printf(" Nie znaleziono pliku.\n Bledna nazwa.\n");
		return false;
	}
	fread(wysokosc, sizeof(int), 1, plik);
	fread(szerokosc, sizeof(int), 1, plik);
	(*tablica) = malloc((*wysokosc) * sizeof(pole**));
	if (*szerokosc > 200 || *szerokosc < 0 || *wysokosc > 200 || *wysokosc<0) {//czy mapa jest poprawna, czy ktoœ nie probowal jej modyfikowac za pomoca notatnika
		printf(" Blad odczytu.\n");
		return false;
	}
	for (int i = 0; i < (*wysokosc); i++) {
		(*tablica)[i] = malloc((*szerokosc) * sizeof(pole*));
		for (int o = 0; o < (*szerokosc); o++) {
			(*tablica)[i][o] = malloc(sizeof(pole));
			fread(&(*tablica)[i][o]->obraz, sizeof(int), 1, plik);
			if (((*tablica))[i][o]->obraz == glr || (*tablica)[i][o]->obraz == gpr || (*tablica)[i][o]->obraz == dpr || (*tablica)[i][o]->obraz == dlr || (*tablica)[i][o]->obraz == pio || (*tablica)[i][o]->obraz == poz || (*tablica)[i][o]->obraz == lsc || (*tablica)[i][o]->obraz == psc || (*tablica)[i][o]->obraz == dsc || (*tablica)[i][o]->obraz == gsc || (*tablica)[i][o]->obraz == sro || (*tablica)[i][o]->obraz == kro)
				(*tablica)[i][o]->wejscie = nie;
			else if ((*tablica)[i][o]->obraz >= zam1 && (*tablica)[i][o]->obraz <= zam6)
				(*tablica)[i][o]->wejscie = drz;
			else if ((*tablica)[i][o]->obraz == wyjscie)
				(*tablica)[i][o]->wejscie = kon;
			else
				(*tablica)[i][o]->wejscie = tak;
		}
	}
	int co = 0;
	fread(&co, sizeof(int), 1, plik);
	if (!feof(plik)) {//jezeli na mapie jest gracz lub przeciwnicy
		if (co == gracz) {//jezeli jest gracz
			*postac = malloc(sizeof(kordy));
			fread(&(*postac)->cordx, sizeof(int), 1, plik);
			fread(&(*postac)->cordy, sizeof(int), 1, plik);
			(*tablica)[(*postac)->cordx][(*postac)->cordy]->obraz = gracz;
			fread(&co, sizeof(int), 1, plik);//wczytuje znak przeciwnika lub koniec pliku
		}
		kordy gdzie;
		int kierunek;
		fread(&gdzie.cordx, sizeof(int), 1, plik);
		fread(&gdzie.cordy, sizeof(int), 1, plik);
		fread(&kierunek, sizeof(int), 1, plik);
		while (!feof(plik)) {//zakonczy sie od razu jesli nie bedzie przeciwnikow
			int miejsce =pus;
			(*tablica)[gdzie.cordx][gdzie.cordy]->obraz = potwor;
			dodprzec(przeciwnicy, gdzie, kierunek, miejsce);
			fread(&gdzie.cordx, sizeof(int), 1, plik);//gdy brakinie przecinikow to while zostanie zakonczony
			fread(&gdzie.cordy, sizeof(int), 1, plik);
			fread(&kierunek, sizeof(int), 1, plik);
		}
	}
	fclose(plik);
	return true;

};

bool czytaniemapy(wskpole tab, wrog **przeciwnicy, int *wysokosc, int *szerokosc, kordy **postac) {
	char nazwa[256];
	czyszczenie();
	printf(" 9. Powrot\n Podaj nazwe mapy:\n ");
	scanf("%s", nazwa);
	czyszczenie();
	if (nazwa[0] == '9'&&nazwa[1] == '\0')
		return false;
	while (!zczytaj(tab, przeciwnicy, wysokosc, szerokosc, postac, nazwa)) {
		printf(" 9. Powrot\n Podaj nazwe mapy:\n ");
		scanf("%s", nazwa);
		czyszczenie();
		if (nazwa[0] == '9'&&nazwa[1] == '\0')//jesli gracz wpisal 9 by zakonczyc
			return false;
	}
	return true;
}

void zapiszmape(wskpole mapa, wrog **przeciwnicy, int  wiersze, int  kolumny, kordy *postac) {
	czyszczenie();
	printf(" Podaj nazwe pliku, w ktorym ma zostac zapisana mapa (jesli nie istnieje zostanie utworzny nowy):\n ");
	char nazwa[250];
	scanf("%s", nazwa);
	FILE *plik = fopen(nazwa, "wb");
	fwrite(&wiersze, sizeof(int), 1, plik);
	fwrite(&kolumny, sizeof(int), 1, plik);
	for (int i = 0; i < wiersze; i++) {
		for (int o = 0; o<kolumny; o++)
			fwrite(&(*mapa)[i][o]->obraz, sizeof(int), 1, plik);
	}
	int znak = gracz;
	if (postac != NULL) {
		fwrite(&znak, sizeof(int), 1, plik);
		fwrite(&postac->cordx, sizeof(int), 1, plik);
		fwrite(&postac->cordy, sizeof(int), 1, plik);
	}
	if (*przeciwnicy != NULL) {
		znak = potwor;
		fwrite(&znak, sizeof(int), 1, plik);
		wrog *aktualny = *przeciwnicy;
		while (aktualny != NULL) {
			fwrite(&aktualny->pozycja.cordx, sizeof(int), 1, plik);
			fwrite(&aktualny->pozycja.cordy, sizeof(int), 1, plik);
			fwrite(&aktualny->kierunek, sizeof(int), 1, plik);
			aktualny = aktualny->pNext;
		}
	}
	fclose(plik);
}
 