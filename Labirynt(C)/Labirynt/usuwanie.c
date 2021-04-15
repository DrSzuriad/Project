#include<stdlib.h>
#include"usuwanie.h"

void usuntablice(tabwyn **lista) {
	tabwyn *aktualny = *lista;
	tabwyn *tymczasowy = NULL;
	while (aktualny != NULL) {
		tymczasowy = aktualny->pNext;
		free(aktualny);
		aktualny = tymczasowy;
	}
	lista = NULL;
}

void usunmape(wskpole mapa,int wiersze, int kolumny) {
	for (int i = 0; i < wiersze; i++) {
		for (int o = 0; o < kolumny; o++) {
			free((*mapa)[i][o]);
		}
		free((*mapa)[i]);
	}
	free(*mapa);
	*mapa = NULL;
}

void usunliste(wrog **przeciwnik) {
	wrog *usuwany = *przeciwnik;
	while (usuwany!=NULL){
		*przeciwnik = usuwany->pNext;
		free(usuwany);
		usuwany = *przeciwnik;
	}
	*przeciwnik = NULL;
}

void usuncalamape(wskpole mapa, int wiersze, int kolumny,wrog **przeciwnik, kordy **postac) {
	if(*mapa!=NULL)
		usunmape(mapa, wiersze, kolumny);
	if (*przeciwnik!=NULL)
		usunliste(przeciwnik);
	if (*postac != NULL) {
		free(*postac);
		postac = NULL;
	}
}

void usunekwipunek(Ekwipunekstr **pHeadekw) {
	Ekwipunekstr *usuwany = *pHeadekw;
	while (usuwany!=NULL) {
		*pHeadekw = usuwany->pNext;
		free(usuwany);
		usuwany = *pHeadekw;
	}
}

void usunnazwe(char **nazwa) {
	free(*nazwa);
	*nazwa = NULL;
}