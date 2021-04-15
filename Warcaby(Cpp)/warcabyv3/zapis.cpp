#include "zapis.h"

void zapis::zapisz(zasady*& reguly, LPSTR &nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce){
	fstream plik;
	plik.open("zapis.txt", ios::out | ios::trunc);
	plik << miejsce << " " << reguly->getrodz() << " " << reguly->getroz() << " " << reguly->getczydambit() <<" " <<reguly->getczydamwiel() <<" "<<reguly->getobbic() <<" "<<reguly->getbicdot() <<" "<<reguly->getpolwdl() <<endl;//wypisanie regul
	int mie = plik.tellp();
	plik << nazwa1;
	if (mie == plik.tellp())
		plik << "unnamed";
	plik << endl;
	mie = plik.tellp();
	plik << nazwa1;
	if (mie == plik.tellp())
		plik << "unnamed";
	plik << endl;
	for (int x = 0; x < reguly->getroz(); x++) {
		for (int y = 0; y < reguly->getroz(); y++) {
			plik << mapa->getf(x, y)<<endl;
		}
	}
	plik.close();
}

void zapis::wczytaj(zasady*& reguly, LPSTR& nazwa1, LPSTR& nazwa2, plansza*& mapa, int& miejsce) {
	fstream plik;
	plik.open("zapis.txt", ios::in);
	if (plik.good() == false)
	{
		MessageBox(NULL, "Brak zapisanego pliku.", "B³¹d", MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		reguly == nullptr;
		return;
	}
	plik >> miejsce;
	int a,b;
	bool c, d, e, f, g;
	plik >> a>>b>>c>>d>>e>>f>>g;
	reguly= new zasady(a, b, c, d, e, f, g);
	plik >> nazwa1;
	plik >> nazwa2;
	mapa= new plansza(reguly->getroz(), reguly->getpolwdl());
	for (int x = 0; x < reguly->getroz(); x++) {
		for (int y = 0; y < reguly->getroz(); y++) {
			plik >> a;
			mapa->setf(x, y, a);
		}
	}
}