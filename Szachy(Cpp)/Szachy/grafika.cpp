#include "grafika.h"

grafika::grafika()
{
	pionekbt.loadFromFile("bitmapy\\bpiob.png");//bia³y pionek
	pionekb.setTexture(pionekbt);

	pionekct.loadFromFile("bitmapy\\cpiob.png");//czarny pionek
	pionekc.setTexture(pionekct);

	wiebt.loadFromFile("bitmapy\\bwieb.png");//bia³a wie¿a
	wiezab.setTexture(wiebt);

	wiect.loadFromFile("bitmapy\\cwieb.png");//czarna wie¿a
	wiezac.setTexture(wiect);

	konbt.loadFromFile("bitmapy\\bkonb.png");//bia³y koñ
	konnb.setTexture(konbt);

	konct.loadFromFile("bitmapy\\ckonb.png");//czarny koñ
	konnc.setTexture(konct);

	gonbt.loadFromFile("bitmapy\\bgonb.png");//bia³y goniec
	goniecb.setTexture(gonbt);

	gonct.loadFromFile("bitmapy\\cgonb.png");//czarny goniec
	goniecc.setTexture(gonct);

	hetbt.loadFromFile("bitmapy\\bkrob.png");//bia³y hetman
	hetmanb.setTexture(hetbt);

	hetct.loadFromFile("bitmapy\\ckrob.png");//czarny hetman
	hetmanc.setTexture(hetct);

	krolbt.loadFromFile("bitmapy\\bkrolb.png");//bia³y król
	krolb.setTexture(krolbt);

	krolct.loadFromFile("bitmapy\\ckrolb.png");//czarny król
	krolc.setTexture(krolct);

	przyciskkt.loadFromFile("bitmapy\\przycisk.png");
	przyciskk.setTexture(przyciskkt);
	przyciskk.setPosition(500, 200);

	przyciskat.loadFromFile("bitmapy\\przyciskanuluj.png");
	przyciska.setTexture(przyciskat);
	przyciska.setPosition(500, 250);

	aktt.loadFromFile("bitmapy\\akt.png");
	akt.setTexture(aktt);
	akt.setPosition(490, 100);

	bialyt.loadFromFile("bitmapy\\bialy.png");
	bialys.setTexture(bialyt);
	bialys.setPosition(540, 150);

	czarnyt.loadFromFile("bitmapy\\czarny.png");
	czarnys.setTexture(czarnyt);
	czarnys.setPosition(540, 150);

	wygranat.loadFromFile("bitmapy\\wygrana.png");
	wygrana.setTexture(wygranat);
	wygrana.setPosition(100, 100);

	resett.loadFromFile("bitmapy\\reset.png");
	reset.setTexture(resett);
	reset.setPosition(500, 300);

	remist.loadFromFile("bitmapy\\remis.png");
	remis.setTexture(remist);
	remis.setPosition(100, 100);
}

grafika::~grafika()
{
}

Sprite grafika::getpb()
{
	return this->pionekb;
}

Sprite grafika::getpc()
{
	return this->pionekc;
}

Sprite grafika::getwb()
{
	return this->wiezab;
}

Sprite grafika::getwc()
{
	return this->wiezac;
}

Sprite grafika::getkb()
{
	return this->konnb;
}

Sprite grafika::getkc()
{
	return this->konnc;
}

Sprite grafika::getgb()
{
	return this->goniecb;
}

Sprite grafika::getgc()
{
	return this->goniecc;
}

Sprite grafika::gethb()
{
	return this->hetmanb;
}

Sprite grafika::gethc()
{
	return this->hetmanc;
}

Sprite grafika::getkrb()
{
	return this->krolb;
}

Sprite grafika::getkrc()
{
	return this->krolc;
}

Sprite grafika::getprzk()
{
	return przyciskk;
}

Sprite grafika::getprza()
{
	return przyciska;
}

Sprite grafika::getakt()
{
	return akt;
}

Sprite grafika::getbialys()
{
	return bialys;
}

Sprite grafika::getczarnys()
{
	return czarnys;
}

Sprite grafika::getwygrana()
{
	return wygrana;
}

Sprite grafika::getreset()
{
	return reset;
}

Sprite grafika::getremis()
{
	return remis;
}

void grafika::setkordbia(int x, int y)
{
	bialys.setPosition(float(x), float(y));
}

void grafika::setkordcz(int x, int y)
{
	czarnys.setPosition(float(x), float(y));
}
