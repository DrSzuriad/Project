#include<time.h>
#include <stdio.h>
#include<conio.h>
#include"Header.h"
#include<windows.h>
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void czyszczenie() {
	system("CLS");
}
void czyszczeniebufora() {
	fseek(stdin, 0, 2);
	return;
}

void podmien(int wiersz, int kolumna, int znak,int wysokosc) {
	gotoxy(kolumna, wiersz);
	printf("%c", znak);
	gotoxy(0, wysokosc + 1);//przeniesienie na dó³ mapy

}

void dowolnyprzycisk() {
	int a = _getch();
	if (a == zkps || a == zkps0) 
		_getch();
}