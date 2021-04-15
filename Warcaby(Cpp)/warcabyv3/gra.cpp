#include "gra.h"

void gra::klikniecie(int x, int y, plansza* mapa, int& kiedy, zasady* reguly, listazmian*& zmianyusu, listazmian*& zmianynieusu, int& popx, int& popy, bool& czybic) {
	int rozmia = reguly->getroz();

	if (x < rozmia && y < rozmia && x >= 0 && y >= 0) {
		if (kiedy == biagrabp) {////////////////////////////////////////////////bialy
			if (mapa->getf(x, y) == pionekbia) {
				gdzieruch(x, y, mapa, zmianynieusu, reguly, kiedy);
				kiedy = biagrabw;
				popx = x;
				popy = y;
			}
			else if (mapa->getf(x, y) == damabia) {
				gdzieruchdam(x, y, mapa, zmianynieusu, reguly, kiedy);
				kiedy = biagrabw;
				popx = x;
				popy = y;
			}
		}
		else if (kiedy == biagrabw) {
			if (popx == x && popy == y && czybic == false) {//kiedy gracz kliknie tego samego pionka
				zmianyusu = zmianynieusu;
				zmianynieusu = NULL;
				zmianyusu->podnamap(mapa, zmianyusu);
				kiedy = biagrabp;
			}
			else {
				listazmian* tym = zmianynieusu;
				while (tym != NULL) {
					int kolx = tym->getx();
					int koly = tym->gety();
					if (kolx == x && koly == y && popx != x && popy != y) {
						if (mapa->getf(popx, popy) == pionekbia) {
							mapa->setf(x, y, pionekbia);
							mapa->setf(popx, popy, nic);
							if ((popx - x) % 2 == 0 && (popy - y) % 2 == 0) {

								czybic = true;
								mapa->setf((x + popx) / 2, (y + popy) / 2, nic);
								zmianynieusu->wstaw((x + popx) / 2, (y + popy) / 2, nic, zmianynieusu);
								zmianyusu = zmianynieusu;
								zmianynieusu = NULL;
								zmianyusu->podnamap(mapa, zmianyusu);
								gdzieruch(x, y, mapa, zmianynieusu, reguly, kiedy);
								if (zmianynieusu->getpNext() == NULL)
									zmianynieusu->usun(zmianynieusu);
								if (zmianynieusu == NULL)//nie mozna bic dalej
									kiedy = biagrakon;
								popx = x;
								popy = y;
								break;
							}
							zmianyusu = zmianynieusu;
							zmianynieusu = NULL;
							zmianyusu->podnamap(mapa, zmianyusu);
							kiedy = biagrakon;
							break;
						}
						else {
							mapa->setf(x, y, damabia);
							mapa->setf(popx, popy, nic);
							if (czydambil(mapa, zmianynieusu, x, y,rozmia)) {//czy dama bila
								czybic = true;
								int wktx = x - popx;
								int wkty = y - popy;
								if (wktx > 0 && wkty > 0) {
									zmianynieusu->wstaw(x - 1, y - 1, nic, zmianynieusu);
									mapa->setf(x-1, y-1, nic);
								}
								else if (wktx < 0 && wkty > 0) {
									zmianynieusu->wstaw(x + 1, y - 1, nic, zmianynieusu);
									mapa->setf(x + 1, y - 1, nic);
								}
								else if (wktx < 0 && wkty < 0) {
									zmianynieusu->wstaw(x + 1, y + 1, nic, zmianynieusu);
									mapa->setf(x + 1, y + 1, nic);
								}
								else if (wktx > 0 && wkty < 0) {
									zmianynieusu->wstaw(x - 1, y + 1, nic, zmianynieusu);
									mapa->setf(x - 1, y + 1, nic);
								}
								zmianyusu = zmianynieusu;
								zmianynieusu = NULL;
								zmianyusu->podnamap(mapa, zmianyusu);
								gdzieruchdam(x, y, mapa, zmianynieusu, reguly, kiedy);
								if (zmianynieusu->getpNext() == NULL)
									zmianynieusu->usun(zmianynieusu);
								if (zmianynieusu == NULL)//nie mozna bic dalej
									kiedy = biagrakon;
								popx = x;
								popy = y;
								break;
							}
							zmianyusu = zmianynieusu;
							zmianynieusu = NULL;
							zmianyusu->podnamap(mapa, zmianyusu);
							kiedy = czagrakon;
							break;
						}
					}
					tym = tym->getpNext();
				}
			}
		}
		if (kiedy == czagrabp) { ///////////////////////////////////////////czarny
			if (mapa->getf(x, y) == pionekcza) {
				gdzieruch(x, y, mapa, zmianynieusu, reguly, kiedy);
				kiedy = czagrabw;
				popx = x;
				popy = y;
			}
			else if (mapa->getf(x, y) == damacza) {
				gdzieruchdam(x, y, mapa, zmianynieusu, reguly, kiedy);
				kiedy = czagrabw;
				popx = x;
				popy = y;
			}
		}
		else if (kiedy == czagrabw) {
			if (popx == x && popy == y && czybic == false) {//kiedy gracz kliknie tego samego pionka
				zmianyusu = zmianynieusu;
				zmianynieusu = NULL;
				zmianyusu->podnamap(mapa, zmianyusu);
				kiedy = czagrabp;
			}
			else {
				listazmian* tym = zmianynieusu;
				while (tym != NULL) {
					int kolx = tym->getx();
					int koly = tym->gety();
					if (kolx == x && koly == y && popx != x && popy != y) {
						if (mapa->getf(popx, popy) == pionekcza) {
							mapa->setf(x, y, pionekcza);
							mapa->setf(popx, popy, nic);
							if ((popx - x) % 2 == 0 && (popy - y) % 2 == 0) {
								czybic = true;
								mapa->setf((x + popx) / 2, (y + popy) / 2, nic);
								zmianynieusu->wstaw((x + popx) / 2, (y + popy) / 2, nic, zmianynieusu);
								zmianyusu = zmianynieusu;
								zmianynieusu = NULL;
								zmianyusu->podnamap(mapa, zmianyusu);
								gdzieruch(x, y, mapa, zmianynieusu, reguly, kiedy);
								if (zmianynieusu->getpNext() == NULL)
									zmianynieusu->usun(zmianynieusu);
								if (zmianynieusu == NULL)//nie mozna bic dalej
									kiedy = czagrakon;
								popx = x;
								popy = y;
								break;
							}
							zmianyusu = zmianynieusu;
							zmianynieusu = NULL;
							zmianyusu->podnamap(mapa, zmianyusu);
							kiedy = czagrakon;
							break;
						}

						else {
							mapa->setf(x, y, damacza);
							mapa->setf(popx, popy, nic);
							if (czydambil(mapa, zmianynieusu, x, y,rozmia)) {//czy dama bila
								czybic = true;
								int wktx = x - popx;
								int wkty = y - popy;
								if (wktx > 0 && wkty > 0) {
									zmianynieusu->wstaw(x - 1, y - 1, nic, zmianynieusu);
									mapa->setf(x - 1, y - 1, nic);
								}
								else if (wktx < 0 && wkty > 0) {
									zmianynieusu->wstaw(x + 1, y - 1, nic, zmianynieusu);
									mapa->setf(x + 1, y - 1, nic);
								}
								else if (wktx < 0 && wkty < 0) {
									zmianynieusu->wstaw(x + 1, y + 1, nic, zmianynieusu);
									mapa->setf(x + 1, y + 1, nic);
								}
								else if (wktx > 0 && wkty < 0) {
									zmianynieusu->wstaw(x - 1, y + 1, nic, zmianynieusu);
									mapa->setf(x - 1, y + 1, nic);
								}
								zmianyusu = zmianynieusu;
								zmianynieusu = NULL;
								zmianyusu->podnamap(mapa, zmianyusu);
								gdzieruchdam(x, y, mapa, zmianynieusu, reguly, kiedy);
								if (zmianynieusu->getpNext() == NULL)
									zmianynieusu->usun(zmianynieusu);
								if (zmianynieusu == NULL)//nie mozna bic dalej
									kiedy = czagrakon;
								popx = x;
								popy = y;
								break;
							}
							zmianyusu = zmianynieusu;
							zmianynieusu = NULL;
							zmianyusu->podnamap(mapa, zmianyusu);
							kiedy = czagrakon;
							break;
						}
					}
					tym = tym->getpNext();
				}
			}
		}
	}
}


void gra::gdzieruch(int x, int y, plansza* mapa, listazmian*& zmianynieusu, zasady* reguly, int& kiedy) {

	int rozmiar = reguly->getroz();
	zmianynieusu->wstaw(x, y, czer, zmianynieusu);
	if (kiedy == biagrabp || kiedy == biagrabw || kiedy== biagraspr) { // bialy

		if (x - 1 >= 0 && y - 1 >= 0) {//czy nie wychodzi za plansze

			if (mapa->getf(x - 1, y - 1) == nic && kiedy != biagrabw)//ruch w lewo przod i czy nie jest to po biciu 
				zmianynieusu->wstaw(x - 1, y - 1, ziel, zmianynieusu);

			else if (mapa->getf(x - 1, y - 1) == pionekcza && x - 2 >= 0 && y - 2 >= 0 && mapa->getf(x - 2, y - 2) == nic) //bicie w lewo przod
				zmianynieusu->wstaw(x - 2, y - 2, ziel, zmianynieusu);


		}
		if (x + 1 < rozmiar && y - 1 >= 0) {//czy nie wychodzi za plansze
			if (mapa->getf(x + 1, y - 1) == nic && kiedy != biagrabw)//ruch w prawo przod i czy nie jest to po biciu 
				zmianynieusu->wstaw(x + 1, y - 1, ziel, zmianynieusu);

			else if (mapa->getf(x + 1, y - 1) == pionekcza && x + 2 < rozmiar && y - 2 >= 0 && mapa->getf(x + 2, y - 2) == nic) //bicie w prawo przod
				zmianynieusu->wstaw(x + 2, y - 2, ziel, zmianynieusu);


		}
		if (reguly->getbicdot() == true) {//czy mozna bic do tylu pionkiem

			if (x - 1 >= 0 && y + 1 < rozmiar && mapa->getf(x - 1, y + 1) == pionekcza && x - 2 >= 0 && y + 2 < rozmiar && mapa->getf(x - 2, y + 2) == nic) //bicie w lewo tyl
				zmianynieusu->wstaw(x - 2, y + 2, ziel, zmianynieusu);

			if (x + 1 < rozmiar && y + 1 < rozmiar && mapa->getf(x + 1, y + 1) == pionekcza && x + 2 < rozmiar && y + 2 < rozmiar && mapa->getf(x + 2, y + 2) == nic) //bicie w prawo tyl
				zmianynieusu->wstaw(x + 2, y + 2, ziel, zmianynieusu);

		}
	}
	else if (kiedy == czagrabp || kiedy == czagrabw|| kiedy==czagraspr) { // czarny

		if (x + 1 < rozmiar && y + 1 < rozmiar) {//czy nie wychodzi za plansze
			if (mapa->getf(x + 1, y + 1) == nic && kiedy != czagrabw)//ruch w lewo przod i czy nie jest to po biciu 
				zmianynieusu->wstaw(x + 1, y + 1, ziel, zmianynieusu);

			else if (mapa->getf(x + 1, y + 1) == pionekbia && x + 2 < rozmiar && y + 2 < rozmiar && mapa->getf(x + 2, y + 2) == nic) {// bicie w lewo przod
				zmianynieusu->wstaw(x + 2, y + 2, ziel, zmianynieusu);
			}
		}
		if (x - 1 >= 0 && y + 1 < rozmiar) {//czy nie wychodzi za plansze
			if (mapa->getf(x - 1, y + 1) == nic && kiedy != czagrabw)//ruch w prawo przod  i czy nie jest to po biciu 
				zmianynieusu->wstaw(x - 1, y + 1, ziel, zmianynieusu);

			else if (mapa->getf(x - 1, y + 1) == pionekbia && x - 2 >= 0 && y + 2 < rozmiar && mapa->getf(x - 2, y + 2) == nic) {// bicie w prawo przod
				zmianynieusu->wstaw(x - 2, y + 2, ziel, zmianynieusu);
			}
		}
		if (reguly->getbicdot() == true) {//czy mozna bic do tylu pionkiem

			if (x - 1 >= 0 && y - 1 >= 0 && mapa->getf(x - 1, y - 1) == pionekbia && x - 2 >= 0 && y - 2 >= 0 && mapa->getf(x - 2, y - 2) == nic)
				zmianynieusu->wstaw(x - 2, y - 2, ziel, zmianynieusu);

			if (x + 1 < rozmiar && y - 1 >= 0 && mapa->getf(x + 1, y - 1) == pionekbia && x + 2 < rozmiar && y - 2 >= 0 && mapa->getf(x + 2, y - 2) == nic)
				zmianynieusu->wstaw(x + 2, y - 2, ziel, zmianynieusu);

		}
	}
}


bool gra::czymozeruszyc(int kiedy, plansza* mapa, zasady* reguly) {
	for (int x = 0; x < reguly->getroz(); x++) {
		for (int y=0; y < reguly->getroz(); y++) {
			if (mapa->getf(x, y) == pionekbia && kiedy== biagraspr) {//dla pionkow bialych
				listazmian *lista = NULL;
				gdzieruch(x, y, mapa, lista, reguly, kiedy);
				if (lista != NULL) {
					while (lista != NULL) 
						lista->usun(lista);
					return true;
				}
			}
			else if (mapa->getf(x, y) == pionekcza && kiedy == czagraspr) {//dla pionkow czarnych
				listazmian* lista = NULL;
				gdzieruch(x, y, mapa, lista, reguly, kiedy);
				if (lista != NULL) {
					while (lista != NULL)
						lista->usun(lista);
					return true;
				}
			}
			else if (mapa->getf(x, y) == damabia && kiedy == biagraspr) {
				listazmian* lista = NULL;
				gdzieruchdam(x, y, mapa, lista, reguly, kiedy);
				if (lista != NULL) {
					while (lista != NULL)
						lista->usun(lista);
					return true;
				}

			}
			else if (mapa->getf(x, y) == damacza && kiedy == czagraspr) {
				listazmian* lista = NULL;
				gdzieruchdam(x, y, mapa, lista, reguly, kiedy);
				if (lista != NULL) {
					while (lista != NULL)
						lista->usun(lista);
					return true;
				}

			}

		}
	}

	return false;
}

void gra::gdzieruchdam(int x, int y, plansza* mapa, listazmian*& zmianynieusu, zasady* reguly, int& kiedy) {
	int rozmiar = reguly->getroz();
	zmianynieusu->wstaw(x, y, czer, zmianynieusu);
	if (kiedy == biagrabp || kiedy == biagrabw || kiedy == biagraspr) {///bialy
		if (reguly->getczydamwiel() == true) {//czy moze poruszc sie wiele pol
			int kolx = x - 1;
			int koly = y - 1;
			while (kolx >= 0 && koly >= 0 && mapa->getf(kolx, koly) == nic) {//lewo gora
				if (kiedy != biagrabw){
				zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}
				kolx--;
				koly--;
			}
			if (kolx >= 0 && koly >= 0 && (mapa->getf(kolx, koly) == damacza || mapa->getf(kolx, koly) == pionekcza) && kolx - 1 >= 0 && koly - 1 >= 0 && mapa->getf(kolx - 1, koly - 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx - 1, koly - 1, ziel, zmianynieusu);
			}

			kolx = x + 1;
			koly = y - 1;
			while (kolx < rozmiar && koly >= 0 && mapa->getf(kolx, koly) == nic ) {//prawo gora
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx++;
				koly--;
			}
			if (kolx >= 0 && koly >= 0 && (mapa->getf(kolx, koly) == damacza || mapa->getf(kolx, koly) == pionekcza) && kolx + 1 >= 0 && koly - 1 >= 0 && mapa->getf(kolx + 1, koly - 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx + 1, koly - 1, ziel, zmianynieusu);
			}

			kolx = x + 1;
			koly = y + 1;
			while (kolx < rozmiar && koly < rozmiar && mapa->getf(kolx, koly) == nic ) {//prawo dol
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx++;
				koly++;
			}
			if (kolx < rozmiar && koly < rozmiar && (mapa->getf(kolx, koly) == damacza || mapa->getf(kolx, koly) == pionekcza) && kolx + 1 < rozmiar && koly + 1 < rozmiar && mapa->getf(kolx + 1, koly + 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx + 1, koly + 1, ziel, zmianynieusu);
			}

			kolx = x - 1;
			koly = y + 1;
			while (kolx >= 0 && koly < rozmiar && mapa->getf(kolx, koly) == nic) {//prawo lewo
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}
				kolx--;
				koly++;
			}
			if (kolx >= 0 && koly < rozmiar && (mapa->getf(kolx, koly) == damacza || mapa->getf(kolx, koly) == pionekcza) && kolx - 1 >= 0 && koly + 1 < rozmiar && mapa->getf(kolx - 1, koly + 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx - 1, koly + 1, ziel, zmianynieusu);
			}




		}
		else {

			if (x - 1 >= 0 && y - 1 >= 0 && mapa->getf(x - 1, y - 1) == nic) {//lewo gora
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x - 1, y - 1, ziel, zmianynieusu);
			}
			if (x - 1 >= 0 && y - 1 >= 0 && (mapa->getf(x - 1, y - 1) == damacza || mapa->getf(x - 1, y - 1) == pionekcza) && x - 2 >= 0 && y - 2 >= 0 && mapa->getf(x - 2, y - 2) == nic) {//bicie
				zmianynieusu->wstaw(x - 2, y - 2, ziel, zmianynieusu);
			}

			if (x + 1 < rozmiar && y - 1 >= 0 && mapa->getf(x + 1, y - 1) == nic) {//prawo gora
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x + 1, y - 1, ziel, zmianynieusu);
			}
			if (x + 1 >= 0 && y - 1 >= 0 && (mapa->getf(x + 1, y - 1) == damacza || mapa->getf(x + 1, y - 1) == pionekcza) && x + 2 >= 0 && y - 2 >= 0 && mapa->getf(x + 2, y -2) == nic) {//bicie
				zmianynieusu->wstaw(x + 2, y - 2, ziel, zmianynieusu);
			}

			if (x + 1 < rozmiar && y + 1 < rozmiar && mapa->getf(x + 1, y + 1) == nic) {//prawo dol
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x + 1, y + 1, ziel, zmianynieusu);
			}
			if (x + 1 < rozmiar && y + 1 < rozmiar && (mapa->getf(x + 1, y + 1) == damacza || mapa->getf(x + 1, y + 1) == pionekcza) && x + 2 < rozmiar && y + 2 < rozmiar && mapa->getf(x + 2, y + 2) == nic) {//bicie
				zmianynieusu->wstaw(x + 2, y + 2, ziel, zmianynieusu);
			}

			if (x - 1 >= 0 && y + 1 < rozmiar && mapa->getf(x - 1, y + 1) == nic) {//prawo lewo
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x - 1, y + 1, ziel, zmianynieusu);
			}
			if (x - 1 >= 0 && y + 1 < rozmiar && (mapa->getf(x - 1, y + 1) == damacza || mapa->getf(x - 1, y + 1) == pionekcza) && x - 2 >= 0 && y + 2 < rozmiar && mapa->getf(x - 2, y + 2) == nic) {//bicie
				zmianynieusu->wstaw(x - 2, y + 2, ziel, zmianynieusu);
			}

		}


	}
	else if (kiedy == czagrabp || kiedy == czagrabw || kiedy == czagraspr) {//czarny
		if (reguly->getczydamwiel() == true) {//czy moze poruszc sie wiele pol
			int kolx = x - 1;
			int koly = y - 1;
			while (kolx >= 0 && koly >= 0 && mapa->getf(kolx, koly) == nic && kiedy != czagrabw) {//lewo gora
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx--;
				koly--;
			}
			if (kolx >= 0 && koly >= 0 && (mapa->getf(kolx, koly) == damabia || mapa->getf(kolx, koly) == pionekbia) && kolx - 1 >= 0 && koly - 1 >= 0 && mapa->getf(kolx - 1, koly - 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx - 1, koly - 1, ziel, zmianynieusu);
			}

			kolx = x + 1;
			koly = y - 1;
			while (kolx < rozmiar && koly >= 0 && mapa->getf(kolx, koly) == nic && kiedy != czagrabw) {//prawo gora
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx++;
				koly--;
			}
			if (kolx >= 0 && koly >= 0 && (mapa->getf(kolx, koly) == damabia || mapa->getf(kolx, koly) == pionekbia) && kolx + 1 >= 0 && koly - 1 >= 0 && mapa->getf(kolx + 1, koly - 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx + 1, koly - 1, ziel, zmianynieusu);
			}

			kolx = x + 1;
			koly = y + 1;
			while (kolx < rozmiar && koly < rozmiar && mapa->getf(kolx, koly) == nic && kiedy != czagrabw) {//prawo dol
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx++;
				koly++;
			}
			if (kolx < rozmiar && koly < rozmiar && (mapa->getf(kolx, koly) == damabia || mapa->getf(kolx, koly) == pionekbia) && kolx + 1 < rozmiar && koly + 1 < rozmiar && mapa->getf(kolx + 1, koly + 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx + 1, koly + 1, ziel, zmianynieusu);
			}

			kolx = x - 1;
			koly = y + 1;
			while (kolx >= 0 && koly < rozmiar && mapa->getf(kolx, koly) == nic && kiedy != czagrabw) {//prawo lewo
				if (kiedy != biagrabw) {
					zmianynieusu->wstaw(kolx, koly, ziel, zmianynieusu);
				}				kolx--;
				koly++;
			}
			if (kolx >= 0 && koly < rozmiar && (mapa->getf(kolx, koly) == damabia || mapa->getf(kolx, koly) == pionekbia) && kolx - 1 >= 0 && koly + 1 < rozmiar && mapa->getf(kolx - 1, koly + 1) == nic) {//bicie
				zmianynieusu->wstaw(kolx - 1, koly + 1, ziel, zmianynieusu);
			}




		}
		else {//tylko jedno

			if (x - 1 >= 0 && y - 1 >= 0 && mapa->getf(x - 1, y - 1) == nic && kiedy != czagrabw) {//lewo gora
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x - 1, y - 1, ziel, zmianynieusu);
			}
			if (x - 1 >= 0 && y - 1 >= 0 && (mapa->getf(x - 1, y - 1) == damabia || mapa->getf(x - 1, y - 1) == pionekbia) && x - 2 >= 0 && y - 2 >= 0 && mapa->getf(x-1, y-1) == nic) {//bicie
				zmianynieusu->wstaw(x - 2, y - 2, ziel, zmianynieusu);
			}

			if (x + 1 < rozmiar && y - 1 >= 0 && mapa->getf(x + 1, y - 1) == nic && kiedy != czagrabw) {//prawo gora
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x + 1, y - 1, ziel, zmianynieusu);
			}
			if (x + 1 >= 0 && y - 1 >= 0 && (mapa->getf(x + 1, y - 1) == damabia || mapa->getf(x + 1, y - 1) == pionekbia) && x + 2 >= 0 && y - 2 >= 0 && mapa->getf(x+1, y-1) == nic) {//bicie
				zmianynieusu->wstaw(x + 2, y - 2, ziel, zmianynieusu);
			}

			if (x + 1 < rozmiar && y + 1 < rozmiar && mapa->getf(x + 1, y + 1) == nic && kiedy != czagrabw) {//prawo dol
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x + 1, y + 1, ziel, zmianynieusu);
			}
			if (x + 1 < rozmiar && y + 1 < rozmiar && (mapa->getf(x + 1, y + 1) == damabia || mapa->getf(x + 1, y + 1) == pionekbia) && x + 2 < rozmiar && y + 2 < rozmiar && mapa->getf(x+1, y+1) == nic) {//bicie
				zmianynieusu->wstaw(x + 2, y + 2, ziel, zmianynieusu);
			}

			if (x - 1 >= 0 && y + 1 < rozmiar && mapa->getf(x - 1, y + 1) == nic && kiedy != czagrabw) {//prawo lewo
				if (kiedy != biagrabw)
				zmianynieusu->wstaw(x - 1, y + 1, ziel, zmianynieusu);
			}
			if (x - 1 >= 0 && y + 1 < rozmiar && (mapa->getf(x - 1, y + 1) == damabia || mapa->getf(x - 1, y + 1) == pionekbia) && x - 2 >= 0 && y + 2 < rozmiar && mapa->getf(x-1, y+1) == nic) {//bicie
				zmianynieusu->wstaw(x - 2, y + 2, ziel, zmianynieusu);
			}

		}



	}


}

bool gra::czydambil(plansza* mapa, listazmian* zmianynieusu, int x, int y, int rozmiar) {
	listazmian* zmiany = zmianynieusu;
	
	if (x - 1 >= 0 && y - 1 >= 0) {
		while (zmiany != nullptr) {
			if (zmiany->getx() == x - 1 && zmiany->gety() == y - 1)
				return false;
			zmiany = zmiany->getpNext();
		}
	}

	zmiany = zmianynieusu;
	if (x + 1 < rozmiar && y - 1 >= 0) {
		while (zmiany != nullptr) {
			if (zmiany->getx() == x + 1 && zmiany->gety() == y - 1)
				return false;
			zmiany = zmiany->getpNext();
		}
	}

	zmiany = zmianynieusu;
	if (x - 1 >= 0 && y < rozmiar) {
		while (zmiany != nullptr) {
			if (zmiany->getx() == x - 1 && zmiany->gety() == y + 1)
				return false;
			zmiany = zmiany->getpNext();
		}
	}

	zmiany = zmianynieusu;
	if (x + 1 < rozmiar && y + 1 < rozmiar) {
		while (zmiany != nullptr) {
			if (zmiany->getx() == x + 1 && zmiany->gety() == y + 1)
				return false;
			zmiany = zmiany->getpNext();
		}
	}

	return true;

}

void gra::zmianadam(plansza* mapa, listazmian* & zmianyusu, int rozmiar) {
	for (int x = 0; x < rozmiar; x++) {
		if (mapa->getf(x, 0) == pionekbia) {
			mapa->setf(x, 0, damabia);
			if (mapa->getc(x, 0) == true)
				zmianyusu->wstaw(x, 0, dbnb, zmianyusu);
			else
				zmianyusu->wstaw(x, 0, dbnc, zmianyusu);
		}
	}
	for (int x = 0; x < rozmiar; x++) {
		if (mapa->getf(x, rozmiar) == pionekcza) {
			mapa->setf(x, rozmiar,damacza);
			if (mapa->getc(x, rozmiar) == true)
				zmianyusu->wstaw(x, rozmiar, dcnb, zmianyusu);
			else
				zmianyusu->wstaw(x, rozmiar, dcnc, zmianyusu);
		}
	}

}