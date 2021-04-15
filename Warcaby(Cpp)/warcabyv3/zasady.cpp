#include "zasady.h"

int zasady::getrodz() {
	return rodzaj;
};
int zasady::getroz() {
	return rozmiar;
};
bool zasady::getczydambit() {
	return czydambit;
};
bool zasady::getczydamwiel() {
	return czydamwiel;
};
bool zasady::getobbic() {
	return obbic;
};
bool zasady::getbicdot() {
	return bicdot;
};
bool zasady::getpolwdl() {
	return polwdl;
};
void zasady::setrodz(int a) {
	rodzaj = a;
};
void zasady::setroz(int a) {
	rozmiar = a;
};
void zasady::setczydambit(bool a) {
	czydambit = a;
};
void zasady::setczydamwiel(bool a) {
	czydamwiel = a;
};
void zasady::setobbic(bool a) {
	obbic = a;
};
void zasady::setbicdot(bool a) {
	bicdot = a;
};
void zasady::setpolwdl(bool a) {
	polwdl = a;
};



zasady* zasady::ustawzasady(int a) {
	switch (a) {
	case polskie:
		return new zasady(a,10, true, true, true, true,false );
		break;
	case angielskie:
		return new zasady(a,8, true, false, false, false, false);
		break;
	}
}


zasady::zasady(int rodz, int roz, bool dambit, bool damwiel, bool bic, bool dot, bool polwdl) {
	this->rodzaj = rodz;
	this->rozmiar = roz;
	this->czydambit = dambit;
	this->czydamwiel = damwiel;
	this->obbic = bic;
	this->bicdot = dot;
	this->polwdl = polwdl;

}