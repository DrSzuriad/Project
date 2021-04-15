#include "grafika.h"

void grafika::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(przy1, state);
	target.draw(przy2, state);
	target.draw(przy4, state);
	target.draw(przyasm, state);
	target.draw(przyc, state);
	target.draw(przystart, state);
	target.draw(przystop, state);
	target.draw(wybwat, state);
	target.draw(jezyk, state);

	target.draw(*pole1, state);
	target.draw(*pole2, state);
	target.draw(*pole3, state);
	target.draw(*pole4, state);
	target.draw(*pole5, state);
	target.draw(*pole6, state);

	target.draw(tekstpol1, state);
	target.draw(tekstpol2, state);
	target.draw(tekstpol3, state);
	target.draw(tekstpol4, state);
	target.draw(tekstpol5, state);
	target.draw(tekstpol6, state);

	target.draw(obiekt, state);
	target.draw(zegarek, state);
	target.draw(czas, state);
	target.draw(iloscpowt, state);
	target.draw(liczbapowt, state);
	target.draw(sredniczas, state);
	target.draw(sredniczasliczba, state);

	target.draw(czaspo, state);
	target.draw(sredni100, state);
	target.draw(prey, state);
	target.draw(prex, state);
	target.draw(pozx, state);
	target.draw(pozy, state);
	target.draw(pozxt, state);
	target.draw(pozyt, state);
	target.draw(preyt, state);
	target.draw(prext, state);


}

grafika::grafika()
{
	//font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
	font.loadFromFile("arial.ttf");
	kordx = 0;
	kordy = 0;
	przy1.setall(115, 8, 50, 20, font, "1",15,Color::Black,22);
	przy2.setall(165, 8, 50, 20, font, "2", 15, Color::Black, 22);
	przy4.setall(215, 8, 50, 20, font, "4", 15, Color::Black, 22);

	przyasm.setall(62, 33, 50, 20, font, "asm", 15, Color::Black,9);
	przyc.setall(112, 33, 50, 20, font, "c++", 15, Color::Black,10);

	przystart.setall(60, 58, 50, 20, font, "start", 15, Color::Black,6);
	przystop.setall(140, 58, 50, 20, font, "stop", 15, Color::Black,8);
	
	settext(wybwat, 17, L"Iloœæ w¹tków:", 5, 5);
	settext(jezyk, 17, L"Jêzyk:", 5, 30);
	
	przy1.setkol(true);
	przystop.setkol(true);
	przyc.setkol(true);

	pole1 = new poletekstowe();
	pole1->setall(516, 8, 83, 20, font, 15, double(0.5) ,1);
	pole2 = new poletekstowe();
	pole2->setall(516, 33, 83, 20, font, 15, double(45) ,2);
	pole3 = new poletekstowe();
	pole3->setall(516, 58, 83, 20, font, 15, double(150) ,3);
	pole4 = new poletekstowe();
	pole4->setall(516, 83, 83, 20, font, 15, double(0.3) ,4);
	pole5 = new poletekstowe();
	pole5->setall(516, 108, 83, 20, font, 15, double(2) ,5);
	pole6 = new poletekstowe();
	pole6->setall(516, 133, 83, 20, font, 15, double(0.6) ,6);
	
	settext(tekstpol1, 17, L"Masa:", 463, 5);
	settext(tekstpol2, 17, L"K¹t rzutu:", 434, 30);
	settext(tekstpol3, 17, L"Prêdkoœæ pocz¹tkowa:", 334, 55);
	settext(tekstpol4, 17, L"Wspó³czynnik oporu powietrza:", 268, 80);
	settext(tekstpol5, 17, L"Prêdkoœæ wiatru:", 381, 105);
	settext(tekstpol6, 17, L"Wspó³czynnik oporu wiatru:", 298, 130);

	zegarek.setfont(font);
	settext(czas, 17, L"Czas:", 5, 150);
	settext(iloscpowt, 17, L"Iloœæ obliczeñ pozycji:", 5, 175);
	settext(liczbapowt, 17, L"0", 177, 175);
	settext(sredniczas, 17, L"Œredni czas:", 5, 200);
	settext(sredniczasliczba, 17, L"0", 103, 200);

	settext(czaspo, 17, L"0", 192, 225);
	settext(sredni100, 17, L"Œredni czas (100 tików):", 5, 225);
	settext(prex, 17, L"0", 97, 250);
	settext(prey, 17, L"0", 97, 275);
	settext(prext, 17, L"Prêdkoœæ x:", 5, 250);
	settext(preyt, 17, L"Prêdkoœæ y:", 5, 275);
	settext(pozx, 17, L"0", 87, 300);
	settext(pozy, 17, L"0", 87, 325);
	settext(pozxt, 17, L"Pozycja x:", 5, 300);
	settext(pozyt, 17, L"Pozycja y:", 5, 325);
}

void grafika::setx(int a)
{
	kordx = a;
}

void grafika::sety(int a)
{
	kordy = a;
}

void grafika::setxy(int a, int b)
{
	kordx = a;
	kordy = b;
}

int grafika::getx()
{
	return kordx;
}

int grafika::gety()
{
	return kordy;
}

void grafika::getxy(int& a, int& b)
{
	a = kordx;
	b = kordy;
}

void grafika::transpoz()
{
	if (kordx >= 115 && kordx < 165 && kordy >= 8 && kordy < 28)
		kordx = przycisk1;
	else if (kordx >= 165 && kordx < 215 && kordy >= 8 && kordy < 28)
		kordx = przycisk2;
	else if (kordx >= 215 && kordx < 265 && kordy >= 8 && kordy < 28)
		kordx = przycisk4;

	else if (kordx >= 62 && kordx < 112 && kordy >= 33 && kordy < 53)
		kordx = przyciskasm;
	else if (kordx >= 112 && kordx < 162 && kordy >= 33 && kordy < 53)
		kordx = przyciskc;

	else if (kordx >= 60 && kordx < 110 && kordy >= 58 && kordy < 78)
		kordx = przyciskstart;
	else if (kordx >= 140 && kordx < 190 && kordy >= 58 && kordy < 78)
		kordx = przyciskstop;

	else if (kordx >= 516 && kordx < 600 && kordy >= 8 && kordy < 28)
		kordx = poletek1;
	else if (kordx >= 516 && kordx < 600 && kordy >= 33 && kordy < 53)
		kordx = poletek2;
	else if (kordx >= 516 && kordx < 600 && kordy >= 58 && kordy < 78)
		kordx = poletek3;
	else if (kordx >= 516 && kordx < 600 && kordy >= 83 && kordy < 103)
		kordx = poletek4;
	else if (kordx >= 516 && kordx < 600 && kordy >= 108 && kordy < 128)
		kordx = poletek5;
	else if (kordx >= 516 && kordx < 600 && kordy >= 133 && kordy < 153)
		kordx = poletek6;
	
	else
		kordx = nic;
}




Font grafika::getfont()
{
	return font;
}

void grafika::setkolprzy(int ktory, bool kol)
{
	switch (ktory)
	{
	case przycisk1:
		przy1.setkol(kol);
		break;
	case przycisk2:
		przy2.setkol(kol);
		break;
	case przycisk4:
		przy4.setkol(kol);
		break;
	case przyciskasm:
		przyasm.setkol(kol);
		break;
	case przyciskc:
		przyc.setkol(kol);
		break;
	case przyciskstart:
		przystart.setkol(kol);
		break;
	case przyciskstop:
		przystop.setkol(kol);
		break;

	}
}

void grafika::obs³ugaklawiszy(int znak)
{
	if (poleakt != NULL) {
		if (znak < 128) {

			char zna = znak;
			poleakt->wpisywanie(zna);
		}
	}
}

void grafika::wyborpola(int ktore)
{
	switch (ktore) {
	case poletek1:
		poleakt = pole1;
		break;
	case poletek2:
		poleakt = pole2;
		break;
	case poletek3:
		poleakt = pole3;
		break;
	case poletek4:
		poleakt = pole4;
		break;
	case poletek5:
		poleakt = pole5;
		break;
	case poletek6:
		poleakt = pole6;
		break;
	}

	pole1->setkol(false);
	pole2->setkol(false);
	pole3->setkol(false);
	pole4->setkol(false);
	pole5->setkol(false);
	pole6->setkol(false);
	poleakt->setkol(true);

}

void grafika::settext(Text &zmieniany, int rozmiar, wstring tekst, int posx, int posy)
{
	zmieniany.setFont(font);
	zmieniany.setCharacterSize(rozmiar);
	zmieniany.setString(tekst);
	zmieniany.setPosition(float(posx), float(posy));
	zmieniany.setFillColor(Color::Black);

}

void grafika::obliczruch(double x, double y,double vx, double vy)
{
		obiekt.setPosition(Vector2f(float(x),float(y)));
		powtorzenia++;
		liczbapowt.setString(to_string(powtorzenia));
		zegarek.settekst();
		sredniczasliczba.setString(to_string( zegarek.gettime()/ powtorzenia));
		prey.setString(to_string(vy));
		prex.setString(to_string(vx));
		pozx.setString(to_string(x-300));
		pozy.setString(to_string(590-y));
		if (licznik == 100) {
			czaspo.setString(to_string((zegarek.gettime() - aktpop)/100));
			aktpop = zegarek.gettime();
			licznik = 1;
		}
		else
			licznik++;

}

void grafika::resetsym()
{
	zegarek.reset();
	powtorzenia = 0;
	obiekt.setPosition(Vector2f(float(300), float(590)));
}

void grafika::getzmienne(double& m, double& cd, double& gamma, double& prepocz, double& t, double&tpop, double& cw, double& vw)
{
	m = pole1->getwar();
	gamma = pole2->getwar();
	prepocz = pole3->getwar();
	cd = pole4->getwar();
	vw = pole5->getwar();
	cw = pole6->getwar();
	tpop = t;
	t = zegarek.gettimes();
}

double grafika::getczas()
{
	return zegarek.gettimes();
}
