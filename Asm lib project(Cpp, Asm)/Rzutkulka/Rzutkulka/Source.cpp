#include "Header.h"
#include <Windows.h>


int main(){
	
	RenderWindow okno(VideoMode(600, 600, 32), "Symulator rzutu z wiatrem i oporem powietrza");	
	gra granie;
	grafika graf;


	while (okno.isOpen()) {
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie)) {
			obslugazdarzenia(zdarzenie, okno, graf, granie);
		}
		okno.clear(Color::White);
		granie.obliczeniepozycji(graf);
		okno.draw(graf);
		okno.display();

	}

	return 0;
}

void obslugazdarzenia(Event &zdarz, Window &okno, grafika &graf, gra &granie) {
	switch (zdarz.type)
	{
	case Event::Closed:
		okno.close();
		break;
	case Event::TextEntered:
		if (granie.getstan()==stop)
		graf.obs³ugaklawiszy(zdarz.text.unicode);
		break;
	case  Event::MouseButtonPressed:
		if (zdarz.mouseButton.button == Mouse::Left) {
			graf.setxy(zdarz.mouseButton.x, zdarz.mouseButton.y);
			graf.transpoz();
			int tym = graf.getx();
			if (granie.getstan() == stop) {//gdy kulka nie leci
				if (tym <= przycisk4) {//wybor watkow
					if (tym == przycisk1) {
						granie.setwatki(jeden);
						graf.setkolprzy(przycisk1, true);
						graf.setkolprzy(przycisk2, false);
						graf.setkolprzy(przycisk4, false);
					}
					else if (tym == przycisk2) {
						granie.setwatki(dwa);
						graf.setkolprzy(przycisk1, false);
						graf.setkolprzy(przycisk2, true);
						graf.setkolprzy(przycisk4, false);
					}
					else if (tym == przycisk4) {
						granie.setwatki(cztery);
						graf.setkolprzy(przycisk1, false);
						graf.setkolprzy(przycisk2, false);
						graf.setkolprzy(przycisk4, true);
					}

				}
				else if (tym == przyciskasm) {//wybor jezyka
					granie.setjezyk(asembler);
					graf.setkolprzy(przyciskasm, true);
					graf.setkolprzy(przyciskc, false);
				}
				else if (tym == przyciskc) {
					granie.setjezyk(cplusplus);
					graf.setkolprzy(przyciskasm, false);
					graf.setkolprzy(przyciskc, true);
				}
				else if (tym == przyciskstart) {//odpalenie symulacji
					granie.setstan(start);
					graf.setkolprzy(przyciskstop, false);
					graf.setkolprzy(przyciskstart, true);
					graf.resetsym();
					granie.setzmienne(graf);
				}
				else if (tym >= poletek1)
					graf.wyborpola(tym);
			}
			else if (tym == przyciskstop) {//zakoñczenie symulacji
				granie.setstan(stop);
				graf.setkolprzy(przyciskstop, true);
				graf.setkolprzy(przyciskstart, false);
			}



		}
		break;
	}


}