#include "gra.h"

gra::gra()
{
	stangry = stop;
	watki = jeden;
	jezyk = cplusplus;
	cd = 0;
	cw = 0;
	vx = 0;
	vy = 0;
	t = 0;
	tpop = 0;
	gamma = 0;
	m = 0;
	vw = 0;
	x = 300;
	y = 590;
	dllHandle = LoadLibrary(L"asmlib.dll");
	asmobliczvx = (asmobliczvxp)GetProcAddress(dllHandle, "asmobliczvx");
	asmobliczvy = (asmobliczvyp)GetProcAddress(dllHandle, "asmobliczvy");
	asmobliczsx = (asmobliczsxp)GetProcAddress(dllHandle, "asmobliczsx");
	asmobliczsy = (asmobliczsyp)GetProcAddress(dllHandle, "asmobliczsy");
}


void gra::setstan(int stan)
{
	stangry = stan;
}

int gra::getstan()
{
	return stangry;
}

void gra::setwatki(int a)
{
	watki = a;
}

int gra::getwatki()
{
	return watki;
}

void gra::setjezyk(int a)
{
	jezyk = a;
}

int gra::getjezyk()
{
	return jezyk;
}

void gra::setzmienne(grafika &graf)
{
	double prepocz = 0;
	graf.getzmienne(m,cd,gamma,prepocz,t,tpop,cw,vw);
	vx = prepocz*cos(gamma*3.14159265/180);
	vy = prepocz*sin(gamma*3.14159265/180);
	x = 300;
	y = 590;
}

void gra::obliczeniepozycji(grafika& graf)
{	
	if (stangry == start) {
		tpop = t;
		t = graf.getczas();
		double tym = t - tpop;
		double ex = exp(-(cd / m) * tym);
		if (jezyk == cplusplus) { //dla cplusplusa
			if (watki == jeden) {
				//thread t1(&gra::cppwyliczwszystko, this, cd, ex, tym, cw, vw, ref(vx), m, ref(x), ref(vy), g, ref(y));
				cppwyliczwszystko(cd, ex, tym, cw, vw, vx, m, x, vy, g, y);
				//t1.join();
			}
			else if (watki == dwa) {
				thread t1(&gra::cppwyliczxvx,this,cd,ex, tym,cw,vw,ref(vx),m,ref(x));
				thread t2(&gra::cppwyliczyvy,this, ref(vy), m, g, ref(y), cd, ex, tym);
				t1.join();
				t2.join();
			}
			else {
				thread t1(&gra::cppwyliczx,this, m, cd, ex, tym, cw, vw, vx, ref(x));
				thread t2(&gra::cppwyliczy,this, vy, m, g, ref(y), cd, ex, tym);
				thread t3(&gra::cppwyliczvx, this, cd, ex, cw, vw, ref(vx));
				thread t4(&gra::cppwyliczvy,this,cd, m, ref(vy), g, ex);
				t1.join();
				t2.join();
				t3.join();
				t4.join();
			}
		}

		else {
			if (watki == jeden) {//asm
				thread t1(&gra::asmwyliczwszystko, this, cd, ex, tym, cw, vw, ref(vx), m, ref(x), ref(vy), g, ref(y));
				t1.join();
			}
			else if (watki == dwa) {
				thread t1(&gra::asmwyliczxvx, this, cd, ex, tym, cw, vw, ref(vx), m, ref(x));
				thread t2(&gra::asmwyliczyvy, this, ref(vy), m, g, ref(y), cd, ex, tym);
				t1.join();
				t2.join();
			}
			else {
				thread t1(&gra::asmwyliczx, this, m, cd, ex, tym, cw, vw, vx, ref(x));
				thread t2(&gra::asmwyliczy, this, vy, m, g, ref(y), cd, ex, tym);
				thread t3(&gra::asmwyliczvx, this, cd, ex, cw, vw, ref(vx));
				thread t4(&gra::asmwyliczvy, this, cd, m, ref(vy), g, ex);
				t1.join();
				t2.join();
				t3.join();
				t4.join();

			}

		}


		if (y > 590) {
			stangry = stop;
			graf.setkolprzy(przyciskstop, true);
			graf.setkolprzy(przyciskstart, false);
		}
		graf.obliczruch(x, y,vx,vy);
	}
}

void gra::cppwyliczx(double m, double cd, double e, double t, double cw, double vw, double vx, double& sx)
{
	double tab[] = { m,cd,e,t,cw,vw,vx,sx };
	sx = cppobliczsx(tab);
}

void gra::cppwyliczy(double vy, double m, double g, double& sy, double cd, double e, double t)
{
	double tab[] = { vy,m,g,sy,cd,e,t };
	sy = cppobliczsy(tab);
}

void gra::cppwyliczvx(double cd, double e, double cw, double vw, double& vx)
{
	double tab[] = { cd,e,cw,vw,vx };
	vx = cppobliczvx(tab);
}

void gra::cppwyliczvy(double cd, double m, double& vy, double g, double e)
{
	double tab[] = { cd,m,vy,g,e };
	vy = cppobliczvy(tab);
}

void gra::cppwyliczxvx(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx)
{
	double tab[] = { m,cd,e,t,cw,vw,vx,sx };
	sx = cppobliczsx(tab);
	double tab1[] = { cd,e,cw,vw,vx };
	vx = cppobliczvx(tab1);
}

void gra::cppwyliczyvy(double& vy, double m, double g, double& sy, double cd, double e, double t)
{
	double tab[] = { vy,m,g,sy,cd,e,t };
	sy = cppobliczsy(tab);
	double tab1[] = { cd,m,vy,g,e };
	vy = cppobliczvy(tab1);
}

void gra::cppwyliczwszystko(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx, double& vy, double g, double& sy)
{
	double tab[] = { m,cd,e,t,cw,vw,vx,sx };
	sx = cppobliczsx(tab);
	double tab1[] = { cd,e,cw,vw,vx };
	vx = cppobliczvx(tab1);
	double tab2[] = { vy,m,g,sy,cd,e,t };
	sy = cppobliczsy(tab2);
	double tab3[] = { cd,m,vy,g,e };
	vy = cppobliczvy(tab3);
}

void gra::asmwyliczx(double m, double cd, double e, double t, double cw, double vw, double vx, double& sx)
{
	double tab[] = {m,cd,e,t,cw,vw,vx,sx};
	sx = asmobliczsx(tab);
}

void gra::asmwyliczy(double vy, double m, double g, double& sy, double cd, double e, double t)
{
	double tab[] = {vy,m,g,sy,cd,e,t};
	sy = asmobliczsy(tab);
}

void gra::asmwyliczvx(double cd, double e, double cw, double vw, double& vx)
{
	double tab[] = { cd,e,cw,vw,vx };
	vx = asmobliczvx(tab);
}

void gra::asmwyliczvy(double cd, double m, double& vy, double g, double e)
{
	double tab[] = { cd,m,vy,g,e };
	vy = asmobliczvy(tab);
}

void gra::asmwyliczxvx(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx)
{
	double tab[] = { m,cd,e,t,cw,vw,vx,sx };
	sx = asmobliczsx(tab);
	double tab1[] = { cd,e,cw,vw,vx };
	vx = asmobliczvx(tab1);
}

void gra::asmwyliczyvy(double& vy, double m, double g, double& sy, double cd, double e, double t)
{
	double tab[] = { vy,m,g,sy,cd,e,t };
	sy = asmobliczsy(tab);
	double tab1[] = { cd,m,vy,g,e };
	vy = asmobliczvy(tab1);
}

void gra::asmwyliczwszystko(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx, double& vy, double g, double& sy)
{
	double tab[] = { m,cd,e,t,cw,vw,vx,sx };
	sx = asmobliczsx(tab);
	double tab1[] = { cd,e,cw,vw,vx };
	vx = asmobliczvx(tab1);
	double tab2[] = { vy,m,g,sy,cd,e,t };
	sy = asmobliczsy(tab2);
	double tab3[] = { cd,m,vy,g,e };
	vy = asmobliczvy(tab3);
}


