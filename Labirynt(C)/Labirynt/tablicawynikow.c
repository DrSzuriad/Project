#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"tablicawynikow.h"

void dodajwynik(tabwyn **pHead, tabwyn *nowy){
	if (*pHead == NULL) {
		*pHead = nowy;
	}
	else {
		tabwyn *aktualny = *pHead;
		while (aktualny->pNext!=NULL)
			aktualny = aktualny->pNext;
		aktualny->pNext = nowy;
	}
	return;
}

void tablicawynikow(tabwyn *pHead){
	czyszczenie();
	for (int i = 1; i <= 5 && pHead != NULL; i++) {
		printf(" %i. %s %i\n", i, pHead->nazwa, pHead->wynik);
		pHead = pHead->pNext;
	}
	printf(" Menu - nacisnij dowolny klawisz");
	czyszczeniebufora();
	dowolnyprzycisk();
}

void wipiszdotablicy(tabwyn **pHead, char imie[30], int ptk) {
	tabwyn *nowy = malloc(sizeof(tabwyn));
	strcpy(nowy->nazwa, imie);
	nowy->wynik = ptk;
	nowy->pNext = NULL;
	if (*pHead == NULL) {

	}
	if (*pHead == NULL || (*pHead)->wynik < ptk) {
		nowy->pNext = *pHead;
		*pHead = nowy;
	}
	else {
		tabwyn *aktualny = *pHead;
		while (aktualny->pNext != NULL&&aktualny->pNext->wynik > ptk)
			aktualny = aktualny->pNext;
		nowy->pNext = aktualny->pNext;
		aktualny->pNext = nowy;
	}
}

void zapisztablice(tabwyn *pHead) {
	FILE *plik = fopen("tablicawynikow.txt", "w");
	for (int i = 0; i<5 && pHead != NULL; i++) {
		fprintf(plik, "%s %i ", pHead->nazwa, pHead->wynik);
		pHead = pHead->pNext;
	}
	fclose(plik);
}