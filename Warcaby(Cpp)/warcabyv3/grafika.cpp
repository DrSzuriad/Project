#include "grafika.h"
//#include "vld.h"

HWND grafika::przycisk1 = NULL;
HWND grafika::przycisk2 = NULL;
HWND grafika::przycisk3 = NULL;
zasady* grafika::reguly = nullptr;
okna* grafika::listaokien = new okna(nullptr,nullptr);
plansza* grafika::mapa = nullptr;
int grafika::miejsce = menu;
HINSTANCE grafika::hInstance = NULL;
HWND grafika::tekst1 = NULL;
HWND grafika::tekst2 = NULL;
HWND grafika::tekst3 = NULL;
HWND grafika::poltekst1 = NULL;
HWND grafika::poltekst2 = NULL;
HWND grafika::lista = NULL;
LPCSTR grafika::NazwaKlasy = "Okno";
MSG grafika::Komunikat;
HBRUSH grafika::g_hBrush = CreateSolidBrush(RGB(255, 255, 255));
HBRUSH grafika::g_hBrush1 = CreateSolidBrush(RGB(220, 220, 220));
LPSTR grafika::nazwa1 = (LPSTR)GlobalAlloc(GPTR, 10);
LPSTR grafika::nazwa2 = (LPSTR)GlobalAlloc(GPTR, 10);
HDC grafika::pbianacz = NULL;
HDC	grafika::pbianabia = NULL;
HDC grafika::pcznacz = NULL;
HDC grafika::pcznabia = NULL;
HDC grafika::dbianacz = NULL;
HDC	grafika::dbianabia = NULL;
HDC grafika::dcznacz = NULL;
HDC grafika::dcznabia = NULL;
HDC grafika::bialy = NULL;
HDC grafika::czarny = NULL;
HDC grafika::zielony = NULL;
HDC grafika::czerwony = NULL;
HDC grafika::pionowy = NULL;
HDC grafika::poziomy = NULL;
HDC grafika::dograf = NULL;
listazmian* grafika::zmianyusu=NULL;
listazmian* grafika::zmianynieusu = NULL;
int grafika::popx=-1;
int grafika::popy=-1;
bool grafika::czybic=false;
int grafika::remis = 0;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	grafika::miejsce = menu;
	WNDCLASSEX winclass;
	winclass = grafika::stwkla();
	RegisterClassEx(&winclass);
	// TWORZENIE OKNA
	HWND hwnd = CreateWindowEx(WS_EX_DLGMODALFRAME, grafika::NazwaKlasy, "Warcaby", WS_OVERLAPPEDWINDOW | WS_MAXIMIZE, 600, 250, 650, 640, NULL, NULL, grafika::hInstance, NULL);
	grafika::dograf = GetDC(hwnd);
	grafika::bitmapy();
	grafika::wypiszm(hwnd);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Pętla komunikatów
	while (GetMessage(&grafika::Komunikat, NULL, 0, 0))
	{
		TranslateMessage(&grafika::Komunikat);
		DispatchMessage(&grafika::Komunikat);
		UpdateWindow(hwnd);
	}

	
	grafika::usuwaniegrafiki(hwnd);


}


LRESULT CALLBACK grafika::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		if (miejsce == biagrabp || miejsce == biagrabw || miejsce == biagrakon || miejsce == czagrabp || miejsce == czagrabw || miejsce == czagrakon)
			wypiszplansze(mapa, reguly->getroz(), hwnd);

		EndPaint(hwnd, &ps);
		break;
	}
	case WM_CTLCOLORSTATIC:
	{

		if ((HWND)lParam == grafika::tekst1 || (HWND)lParam == grafika::tekst2 || (HWND)lParam == grafika::tekst3)
		{
			SetBkMode((HDC)wParam, TRANSPARENT);
			SetTextColor((HDC)wParam, RGB(0, 0, 0));
			return(LRESULT)grafika::g_hBrush;
		}
		break;
	}
	case WM_CTLCOLOREDIT: {
		if ((HWND)lParam == grafika::poltekst1 || (HWND)lParam == grafika::poltekst2) {
			SetBkMode((HDC)wParam, TRANSPARENT);
			SetTextColor((HDC)wParam, RGB(0, 0, 0));
			return(LRESULT)grafika::g_hBrush1;
		}}
						break;

	case WM_COMMAND: {
		if ((HWND)lParam == grafika::przycisk1) {
			if ((miejsce == biagrabw || miejsce == czagrabw) && reguly->getobbic() == false && czybic == true) {
				zmianynieusu->podnamap(mapa, zmianynieusu);
				grafika::wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
				while (zmianynieusu != NULL) {
					zmianynieusu->usun(zmianynieusu);
				}
				while (zmianyusu != NULL) {
					zmianyusu->usun(zmianyusu);
				}
				if (miejsce == biagrabw) {
					if (!czymozeruszyc(czagraspr, mapa, reguly)) {
						MessageBox(NULL, "Gratulacje!\nWygrał gracz biały.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
						powdomen(listaokien, hwnd, miejsce, mapa, reguly->getroz());
					}
					else {
						zmianadam(mapa, zmianyusu, reguly->getroz());
						wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
						MessageBox(NULL, "Ruch czarnych.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
						miejsce = czagrabp;
					}
				}
				else if (miejsce == czagrabw) {
					if (!czymozeruszyc(czagraspr, mapa, reguly)) {
						MessageBox(NULL, "Gratulacje!\nWygrał gracz czarny.", "Zwycięstwo", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
						powdomen(listaokien, hwnd, miejsce, mapa, reguly->getroz());
					}
					else {
						wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
						zmianadam(mapa, zmianyusu, reguly->getroz());
						MessageBox(NULL, "Ruch białych.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
						miejsce = biagrabp;
					}
				}
				czremis(remis, hwnd, listaokien, czybic, miejsce, mapa, reguly->getroz());
				break;
			}
			else if (grafika::miejsce == biagrabp || grafika::miejsce == czagrabp || grafika::miejsce == biagrabw || grafika::miejsce == czagrabw) {
				MessageBox(NULL, "Nie został wykonany ruch!", "Powiadomienie", MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
				break;
			}
			else if (miejsce == biagrakon) {
				if (!czymozeruszyc(czagraspr, mapa, reguly)) {
					MessageBox(NULL, "Gratulacje!\nWygrał gracz biały.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
					powdomen(listaokien, hwnd, miejsce, mapa, reguly->getroz());
				}
				else {
					miejsce = czagrabp;
					zmianadam(mapa, zmianyusu, reguly->getroz());
					wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
					MessageBox(NULL, "Ruch czarnych.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
					czremis(remis, hwnd, listaokien, czybic, miejsce, mapa, reguly->getroz());
				}
				break;
			}
			else if (miejsce == czagrakon) {
				if (!czymozeruszyc(biagraspr, mapa, reguly)) {
					MessageBox(NULL, "Gratulacje!\nWygrał gracz czarny.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
					powdomen(listaokien, hwnd, miejsce, mapa, reguly->getroz());
				}
				else {
					miejsce = biagrabp;
					zmianadam(mapa, zmianyusu, reguly->getroz());
					wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
					MessageBox(NULL, "Ruch białych.", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
					czremis(remis, hwnd, listaokien, czybic, miejsce, mapa, reguly->getroz());
				}
				break;
			}
			else if (miejsce == menu) {
				grafika::wypisznaz(hwnd);
				break;
			}
			else if (miejsce == wpinazw) {
				if (ComboBox_GetCurSel(grafika::lista) == CB_ERR) {
					MessageBox(NULL, "Wybierz wersje warcab!", "", MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
					UpdateWindow(hwnd);
					break;
				}
				else {
					grafika::reguly = grafika::reguly->ustawzasady(ComboBox_GetCurSel(grafika::lista));
					GetWindowText(grafika::poltekst1, grafika::nazwa1, 10);
					GetWindowText(grafika::poltekst2, grafika::nazwa2, 10);
					--* listaokien;
					grafika::wypiszgre(hwnd);
					break;
				}
			}
		}
		else if ((HWND)lParam == grafika::przycisk2) {
			if (miejsce == biagrabp || miejsce == czagrabp) {
				zapisz(reguly, nazwa1, nazwa2, mapa, miejsce);



			}
			else if (miejsce == biagrabw || miejsce == biagrakon || miejsce == czagrabw || miejsce == czagrakon) {
				MessageBox(NULL, "Nie można teraz zapisać", "", MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
			}
			else if (miejsce == menu) {
				wczytaj(reguly, nazwa1, nazwa2, mapa, miejsce);
				if (reguly != nullptr) {
					--* listaokien;
					grafika::wypiszgre(hwnd);
				}
			}
			break;
		}
		else if ((HWND)lParam == grafika::przycisk3) {
			if (miejsce == menu) {
				grafika::WndProc(hwnd, WM_CLOSE, wParam, lParam);
				break;
			}
			else if (miejsce == biagrabp || miejsce == czagrabp|| miejsce == biagrabw || miejsce == biagrakon || miejsce == czagrabw || miejsce == czagrakon){
				powdomen(listaokien, hwnd, miejsce, mapa, reguly->getroz());
			}
		};
	}
	case WM_LBUTTONDOWN: {
		if (miejsce == biagrabp || miejsce == biagrabw || miejsce == czagrabp || miejsce == czagrabw) {
			//	HDC hdc = GetDC(hwnd);
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);
			grafika::pozycja(x, y);
			grafika::klikniecie(x, y, grafika::mapa, grafika::miejsce, reguly, zmianyusu, zmianynieusu, popx, popy,czybic);
			grafika::wypiszzmiany(zmianynieusu, zmianyusu, hwnd);
			UpdateWindow(hwnd);
			//	ReleaseDC(hwnd, hdc);
		}
		break;
	}
	case WM_RBUTTONDOWN: {////////////////////////////////////////////////////////////////////////////////////////////////////
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		grafika::pozycja(x, y);
		if (mapa->getf(x, y) == nic)
			mapa->setf(x, y, pionekbia);
		else if (mapa->getf(x, y) == pionekbia)
			mapa->setf(x, y, pionekcza);
		else if (mapa->getf(x, y) == pionekcza)
			mapa->setf(x, y, damabia);
		else if (mapa->getf(x, y) == damabia)
			mapa->setf(x, y, damacza);
		else if (mapa->getf(x, y) == damacza)
			mapa->setf(x, y, nic);
		wypiszplansze(mapa, reguly->getroz(), hwnd);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


WNDCLASSEX grafika::stwkla() {
	WNDCLASSEX winclass;
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = 0;
	winclass.lpfnWndProc = grafika::WndProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = grafika::hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = grafika::NazwaKlasy;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	return winclass;
}

void grafika::wypiszm(HWND hwnd) {
	grafika::tekst1 = CreateWindowEx(0, "STATIC", "MENU", WS_CHILD | WS_VISIBLE | SS_CENTER, 255, 0, 100, 16, hwnd, NULL, grafika::hInstance, NULL);
	*listaokien +=&tekst1;
	grafika::przycisk1 = CreateWindowEx(0, "BUTTON", "Gra", WS_CHILD | WS_VISIBLE, 230, 20, 150, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk1;
	grafika::przycisk2 = CreateWindowEx(0, "BUTTON", "Wczytaj", WS_CHILD | WS_VISIBLE, 230, 55, 150, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk2;
	grafika::przycisk3 = CreateWindowEx(0, "BUTTON", "Wyjdź", WS_CHILD | WS_VISIBLE, 230, 90, 150, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk3;
	UpdateWindow(hwnd);

}

void grafika::wypisznaz(HWND hwnd) {
	--* listaokien;
	grafika::miejsce = wpinazw;
	grafika::tekst1 = CreateWindowEx(0, "STATIC", "Nazwa pierwszego gracza (maksymalnie 10 znaków):", WS_CHILD | WS_VISIBLE | SS_LEFT, 5, 0, 400, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &tekst1;
	grafika::poltekst1 = CreateWindowEx(0, "EDIT", 0, WS_CHILD | WS_VISIBLE | SS_LEFT, 5, 20, 250, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &poltekst1;
	grafika::tekst2 = CreateWindowEx(0, "STATIC", "Nazwa drugiego gracza:", WS_CHILD | WS_VISIBLE | SS_LEFT, 5, 40, 180, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &tekst2;
	grafika::poltekst2 = CreateWindowEx(0, "EDIT", 0, WS_CHILD | WS_VISIBLE | SS_LEFT, 5, 60, 250, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &poltekst2;
	grafika::tekst3 = CreateWindowEx(0, "STATIC", "Wybierz wersje warcab", WS_CHILD | WS_VISIBLE | SS_LEFT, 5, 80, 400, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &tekst3;
	grafika::lista = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST, 5, 100, 150, 200, hwnd, NULL, grafika::hInstance, NULL);
	SendMessage(grafika::lista, CB_ADDSTRING, 0, (LPARAM)"polskie");
	SendMessage(grafika::lista, CB_ADDSTRING, 0, (LPARAM)"angielskie");
	(*listaokien) += &lista;
	grafika::przycisk1= CreateWindowEx(0, "BUTTON", "Dalej", WS_CHILD | WS_VISIBLE, 230, 130, 150, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk1;

	UpdateWindow(hwnd);
}


void grafika::wypiszgre(HWND hwnd) {

	grafika::miejsce = biagrabp;
	int wielkosc = grafika::reguly->getroz();
	mapa=new plansza(wielkosc, grafika::reguly->getpolwdl());
	grafika::mapa->wpiszf(grafika::reguly->getrodz());
	grafika::wypiszmape(grafika::mapa,wielkosc,hwnd);

}

void grafika::bitmapy() {
	
	HBITMAP obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\pbianabia.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::pbianabia = CreateCompatibleDC(NULL);
	SelectObject(grafika::pbianabia, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\pbianacz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::pbianacz = CreateCompatibleDC(NULL);
	SelectObject(grafika::pbianacz, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\pcznabia.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::pcznabia = CreateCompatibleDC(NULL);
	SelectObject(grafika::pcznabia, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\pcznacz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::pcznacz = CreateCompatibleDC(NULL);
	SelectObject(grafika::pcznacz,obrazek);
	DeleteObject(obrazek);

	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\dbianabia.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::dbianabia = CreateCompatibleDC(NULL);
	SelectObject(grafika::dbianabia, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\dbianacz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::dbianacz = CreateCompatibleDC(NULL);
	SelectObject(grafika::dbianacz, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\dcznabia.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::dcznabia = CreateCompatibleDC(NULL);
	SelectObject(grafika::dcznabia,obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\dcznacz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::dcznacz = CreateCompatibleDC(NULL);
	SelectObject(grafika::dcznacz, obrazek);

	DeleteObject(obrazek);
	obrazek=(HBITMAP)LoadImage(NULL, "bitmapy\\cz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::czarny = CreateCompatibleDC(NULL);
	SelectObject(grafika::czarny, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\bia.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::bialy = CreateCompatibleDC(NULL);
	SelectObject(grafika::bialy,obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\pio.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::pionowy = CreateCompatibleDC(NULL);
	SelectObject(grafika::pionowy,obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\poz.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::poziomy = CreateCompatibleDC(NULL);
	SelectObject(grafika::poziomy,obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\ziel.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::zielony = CreateCompatibleDC(NULL);
	SelectObject(grafika::zielony, obrazek);
	DeleteObject(obrazek);
	obrazek = (HBITMAP)LoadImage(NULL, "bitmapy\\czer.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	grafika::czerwony = CreateCompatibleDC(NULL);
	SelectObject(grafika::czerwony, obrazek);

	DeleteObject(obrazek);
}

void grafika::wyswbit(int co, int x, int y,HWND hwnd) {
	switch (co) {
	case cz:
		BitBlt(dograf, x, y, 50, 50, grafika::czarny, 0, 0, SRCCOPY);
		break;
	case bia:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::bialy, 0, 0, SRCCOPY);
		break;
	case pcnc:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::pcznacz, 0, 0, SRCCOPY);
		break;
	case pcnb:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::pcznabia, 0, 0, SRCCOPY);
		break;
	case pbnb:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::pbianabia, 0, 0, SRCCOPY);
		break;
	case pbnc:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::pbianacz, 0, 0, SRCCOPY);
		break;
	case dcnc:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::dcznacz, 0, 0, SRCCOPY);
		break;
	case dcnb:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::dcznabia, 0, 0, SRCCOPY);
		break;
	case dbnb:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::dbianabia, 0, 0, SRCCOPY);
		break;
	case dbnc:
		BitBlt(grafika::dograf, x, y, 50, 50, grafika::dbianacz, 0, 0, SRCCOPY);
		break;
	case pio:
		BitBlt(grafika::dograf, x, y, 2, 54, grafika::pionowy, 0, 0, SRCCOPY);
		break;
	case poz:
		BitBlt(grafika::dograf, x, y, 54, 2, grafika::poziomy, 0, 0, SRCCOPY);
		break;
	case czer:
		BitBlt(grafika::dograf, x, y, 10, 10, grafika::czerwony, 0, 0, SRCCOPY);
		break;
	case ziel:
		BitBlt(grafika::dograf, x, y, 10, 10, grafika::zielony, 0, 0, SRCCOPY);
		break;
	}
}

void grafika::wypiszmape(plansza* mapa1, int roz, HWND hwnd) {
	grafika::tekst1 = CreateWindowEx(0, "STATIC", grafika::nazwa1, WS_CHILD | WS_VISIBLE | SS_CENTER, roz * 25, 0, 100, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &tekst1;
	grafika::tekst2 = CreateWindowEx(0, "STATIC", grafika::nazwa2, WS_CHILD | WS_VISIBLE | SS_CENTER, roz * 25, 20 + 2 + 2 + roz * 50, 100, 16, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &tekst2;
	grafika::przycisk1 = CreateWindowEx(0, "BUTTON", "Koniec", WS_CHILD | WS_VISIBLE, 50 * roz + 60, 7 + 50 * (roz / 2), 60, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk1;
	grafika::przycisk2 = CreateWindowEx(0, "BUTTON", "Zapisz", WS_CHILD | WS_VISIBLE, 50 * roz + 60, 45 + 50 * (roz / 2), 60, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk2;
	grafika::przycisk3 = CreateWindowEx(0, "BUTTON", "Wyjście", WS_CHILD | WS_VISIBLE, 50 * roz + 60, 83 + 50 * (roz / 2), 60, 30, hwnd, NULL, grafika::hInstance, NULL);
	(*listaokien) += &przycisk3;
	wypiszplansze(mapa1, roz, hwnd);
}

void grafika::wypiszplansze(plansza *mapa1, int roz, HWND hwnd) {
	for (int i = 0; i < roz; i++) {
		wyswbit(poz, 48 + i * 50, 20, hwnd);
		wyswbit(poz, 48 + i * 50, 22 + 50 * roz, hwnd);
		wyswbit(pio, 48, 20 + i * 50, hwnd);
		wyswbit(pio, 50 + roz * 50, 20 + i * 50, hwnd);
	}
	for (int i = 0; i < roz; i++)
		for (int a = 0; a < roz; a++) {

			switch (mapa1->getf(i, a)) {
			case nic:
				if (mapa1->getc(i, a) == false)
					wyswbit(cz, 50 + i * 50, 22 + 50 * a, hwnd);
				else
					wyswbit(bia, 50 + i * 50, 22 + 50 * a, hwnd);
				break;
			case pionekbia:
				if (mapa1->getc(i, a) == false)
					wyswbit(pbnc, 50 + i * 50, 22 + 50 * a, hwnd);
				else
					wyswbit(pbnb, 50 + i * 50, 22 + 50 * a, hwnd);
				break;
			case pionekcza:
				if (mapa1->getc(i, a) == false)
					wyswbit(pcnc, 50 + i * 50, 22 + 50 * a, hwnd);
				else
					wyswbit(pcnb, 50 + i * 50, 22 + 50 * a, hwnd);
				break;
			case damabia:
				if (mapa1->getc(i, a) == false)
					wyswbit(dbnc, 50 + i * 50, 22 + 50 * a, hwnd);
				else
					wyswbit(dbnb, 50 + i * 50, 22 + 50 * a, hwnd);
				break;
			case damacza:
				if (mapa1->getc(i, a) == false)
					wyswbit(dcnc, 50 + i * 50, 22 + 50 * a, hwnd);
				else
					wyswbit(dcnb, 50 + i * 50, 22 + 50 * a, hwnd);
				break;
			}
		}

}

void grafika::wypiszzmiany(listazmian* listanieusu, listazmian*& listausu, HWND hwnd) {

	while (listausu != NULL) {
		int x = (listausu->getx() * 50) + 50;
		int y = (listausu->gety() * 50) + 22;
		wyswbit(listausu->getobr(), x, y, hwnd);
		listausu->usun(listausu);
	}
	while (listanieusu != NULL) {
		int x = (listanieusu->getx() * 50) + 50;
		int y = (listanieusu->gety() * 50) + 22;
		wyswbit(listanieusu->getobr(), x, y, hwnd);
		listanieusu = listanieusu->getpNext();
	}

}

void grafika::powdomen(okna* lista, HWND hwnd, int& kiedy, plansza*& mapa, int rozmiar) {

	kiedy = menu;
	--* listaokien;
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 15; y++) {
			wyswbit(bia, x*50, y*50, hwnd);
		}
	}
	mapa->usun(rozmiar);
	delete(mapa);
	mapa = nullptr;
	wypiszm(hwnd);
	UpdateWindow(hwnd);
	delete(reguly);
	reguly = nullptr;
}

void grafika::czremis(int& remi, HWND hwnd, okna* lista, bool& bic, int& kiedy, plansza* mapa, int rozmiar) {
	if (bic == true)
		remi = 0;
	else {
		remi++;
		if (remi > 30) {
			MessageBox(NULL, "Remis", "Powiadomienie", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			powdomen(lista, hwnd, kiedy,mapa,rozmiar);
		}
	}
	bic = false;
}

void grafika::usuwaniegrafiki(HWND& hwnd) {

	DeleteObject(grafika::g_hBrush);
	DeleteObject(grafika::g_hBrush1);
	GlobalFree(grafika::nazwa1);
	GlobalFree(grafika::nazwa2);
	DeleteDC(grafika::bialy);
	DeleteDC(grafika::czarny);
	DeleteDC(grafika::zielony);
	DeleteDC(grafika::czerwony);
	DeleteDC(grafika::pionowy);
	DeleteDC(grafika::poziomy);
	DeleteDC(grafika::dcznabia);
	DeleteDC(grafika::dcznacz);
	DeleteDC(grafika::dbianabia);
	DeleteDC(grafika::dbianacz);
	DeleteDC(grafika::pbianabia);
	DeleteDC(grafika::pbianacz);
	DeleteDC(grafika::pcznacz);
	DeleteDC(grafika::pcznabia);
	ReleaseDC(hwnd, grafika::dograf);
	grafika::zmianynieusu->usunliste(grafika::zmianynieusu);
	grafika::zmianyusu->usunliste(grafika::zmianyusu);
	--* listaokien;
	delete(listaokien);
	listaokien = nullptr;
}