#include<stdio.h>
#include"wypisywanie.h"

void wypiszekw(Ekwipunekstr *pGlowa) {
	printf(" Ekwipunek: ");
	Ekwipunekstr *aktualny = pGlowa;
	while (aktualny != NULL) { //wypisanie poszczegulnych elementow ekwipunku
		printf("%c ", aktualny->przedmiot);
		aktualny = aktualny->pNext;
	}
	printf(" ");//kiedy usuwam przedmiot muszê zamazac ostatni elemnet po przesunieciu tablicy

}

void wypiszmapiekw(pole ***tablica, int wiersze, int kolumny, Ekwipunekstr *ekw) {
	czyszczenie();
	wypiszmapa(tablica, wiersze, kolumny);
	wypiszekw(ekw);
	gotoxy(kolumny + 1, 0);
	printf(" 9. Wyjscie do menu");
	gotoxy(0, wiersze + 1);
}

void wypiszmapa(pole ***tablica, int wiersze, int kolumny) {
	gotoxy(0, 0);
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			printf("%c", tablica[i][j]->obraz);
		gotoxy(0, i + 1);
	}
}

void wypiszpomoc(int szerokosc) {
	int i = 0;
	gotoxy(szerokosc + 1, i++);
	printf(" Wpisanie kazdego znaku potwierdzic enterem.");
	gotoxy(szerokosc + 1, i++);
	printf(" Legenda:");
	gotoxy(szerokosc + 1, i++);
	printf(" 1. Tryb przemieszczania sie.");
	gotoxy(szerokosc + 1, i++);
	printf(" 2. %c", glr);
	gotoxy(szerokosc + 1, i++);
	printf(" 3. %c", gpr);
	gotoxy(szerokosc + 1, i++);
	printf(" 4. %c", dlr);
	gotoxy(szerokosc + 1, i++);
	printf(" 5. %c", dpr);
	gotoxy(szerokosc + 1, i++);
	printf(" 6. %c", poz);
	gotoxy(szerokosc + 1, i++);
	printf(" 7. %c", pio);
	gotoxy(szerokosc + 1, i++);
	printf(" 8. %c", lsc);
	gotoxy(szerokosc + 1, i++);
	printf(" 9. %c", psc);
	gotoxy(szerokosc + 1, i++);
	printf(" 10. %c", gsc);
	gotoxy(szerokosc + 1, i++);
	printf(" 11. %c", dsc);
	gotoxy(szerokosc + 1, i++);
	printf(" 12. %c", sro);
	gotoxy(szerokosc + 1, i++);
	printf(" 13. %c", kro);
	gotoxy(szerokosc + 1, i++);
	printf(" 14. puste pole");
	gotoxy(szerokosc + 1, i++);
	printf(" 15-20. Klucze do drzwi ( a, b, c )");
	gotoxy(szerokosc + 1, i++);
	printf(" 21-26. Drzwi ( A, B, C )");
	gotoxy(szerokosc + 1, i++);
	printf(" 27. %c - wyjscie z labiryntu", wyjscie);
	gotoxy(szerokosc + 1, i++);
	printf(" 28. %c - potwor,", potwor);
	gotoxy(szerokosc + 1, i++);
	printf(" po wstawieniu, nalezy raz przycisnac strzalke,");
	gotoxy(szerokosc + 1, i++);
	printf(" aby okreslic kierunek poruszania potwora.");
	gotoxy(szerokosc + 1, i++);
	printf(" 29. %c - gracz, mozna wstawic tylko raz na mapie.", gracz);
	gotoxy(szerokosc + 1, i++);
	printf(" 30. Zapisz i wyjdz.");
	gotoxy(szerokosc + 1, i++);
	printf(" 31. Wyjdz bez zapisu.");
}

void wypiszpomchodzenie(int kolumny) {
	int i = 0;
	gotoxy(kolumny + 1, i++);
	printf(" Porusznie odbywa sie za pomoca strzalek.");
	gotoxy(kolumny + 1, i++);
	printf(" Aby wrocic do wpisywania znakow nacisnij '1'.");
}