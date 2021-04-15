#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"Header.h"
#include"usuwanie.h"
#include"tablicawynikow.h"
#include"gra.h"
#include"edytormap.h"
#include"obslugapliku.h"


int main(int argc, char* argv[]) {
	char *nazwa;
	if (argc > 1) {
		nazwa = malloc(strlen(argv[1])+1);
		strcpy(nazwa, argv[1]);
	}
	else {
		nazwa = malloc(11 * sizeof(char));
		strcpy(nazwa, "anonymous");
	}
	printf("%s", nazwa);
	tabwyn *tabwynikow = NULL;
	zczytajtablice(&tabwynikow);
	while (true) {
		czyszczenie();
		printf(" Gra Labirynt\n");
		printf(" 1. Graj\n");
		printf(" 2. Edytor map\n");
		printf(" 3. Tabela wynikow\n");
		printf(" 4. Wyjscie\n ");
		int a = 0;
		if (scanf("%i", &a)) {
			if (a > 0 && a < 5) {
				switch (a) {
				case 1:
					gra(&tabwynikow, nazwa);
					break;
				case 2:
					edytormap();
					break;
				case 3:
					tablicawynikow(tabwynikow);
					break;
				case 4:
					zapisztablice(tabwynikow);
					usuntablice(&tabwynikow);
					usunnazwe(&nazwa);
					return;
					break;
				}
			}
			else
				czyszczeniebufora();
		}
		else {
			czyszczeniebufora();
		}
	}
}
