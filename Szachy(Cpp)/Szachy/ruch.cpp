#include "ruch.h"


void ruch::czymozruch(deque<int> &lista, plansza &plan, const bool& gracz)
{	
	for (int korx = 0; korx < 8; korx++) {
		for (int kory = 0; kory < 8; kory++) {
			figura* akt = plan.getfig(korx, kory);
			if (akt!=nullptr && akt->getkol() == gracz && akt->mozrusz(plan.getbierki(),plan.getzmienne(),korx,kory)) {//czy jakaœ bierka stoi na tym polu i czy to bierka aktualnego gracza i czy mo¿e siê ruszyæ
				lista.push_back(korx);
				lista.push_back(kory);
			}
		}
	}
}

bool ruch::gdzieruch(deque<int> & listafig,deque<int>& listamiej, plansza& plan, const bool& gracz, int x , int y)
{
	for (size_t i = 0; i < listafig.size(); i += 2) {
		if (x == listafig[i] && y == listafig[i + 1]) {//czy ta bierka mo¿e siê ruszyæ
			figura *akt= plan.getfig(x, y);
			akt->gdzierusz(plan.getbierki(), plan.getzmienne(), x, y, listamiej);
			return true;
		}
	}
	return false;
}

bool ruch::ruszaniesie(deque<int>& listamiejsc,int popx,int popy ,int x, int y, plansza& plan)
{
	for (size_t i = 0; i < listamiejsc.size(); i += 2) {
		if (x == listamiejsc[i] && y == listamiejsc[i + 1]) {//dobre  miejsce ruchu
			figura* przen = plan.getfig(popx, popy);
			if (przen->ruchspecjalny(popx, popy, x, y, plan.getbierki(),plan.getzmienne())) {
				
			}
			else {
				figura* akt = plan.getfig(x, y);
				delete(akt);
				plan.setfig(przen, x, y);
				plan.setfig(nullptr, popx, popy);
			}
			return true;
		}
	}

	return false;
}

