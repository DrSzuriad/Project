#pragma once
#include "podstawowy.h"
#include "grafika.h"
#include <math.h>
#include "cpplib.h"
#include <thread>
#include <Windows.h>

typedef double(_fastcall* asmobliczvxp)(double*);
typedef double(_fastcall* asmobliczvyp)(double*);
typedef double(_fastcall* asmobliczsxp)(double*);
typedef double(_fastcall* asmobliczsyp)(double*);



class gra
{
	int stangry;
	int watki;
	int jezyk;
	double e= double(2.718281828459);
	double m;
	double cd;
	double gamma;
	double vx;
	double vy;
	double t;
	double tpop;
	double cw;
	double vw;
	double g= double(9.80665);
	double x;
	double y;
	HINSTANCE dllHandle;
	asmobliczvxp asmobliczvx;
	asmobliczvyp asmobliczvy;
	asmobliczsyp asmobliczsy;
	asmobliczsxp asmobliczsx;

public:
	gra();
	void setstan(int stan);
	int getstan();
	void setwatki(int a);
	int getwatki();
	void setjezyk(int a);
	int getjezyk();
	void setzmienne(grafika &graf);
	void obliczeniepozycji(grafika &graf);


	void cppwyliczx(double m, double cd, double e, double t, double cw, double vw, double vx, double& sx);
	void cppwyliczy(double vy, double m, double g, double& sy, double cd, double e, double t);
	void cppwyliczvx(double cd, double e, double cw, double vw, double& vx);
	void cppwyliczvy(double cd, double m, double& vy, double g, double e);
	void cppwyliczxvx(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx);
	void cppwyliczyvy(double& vy, double m, double g, double& sy, double cd, double e, double t);
	void cppwyliczwszystko(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx, double& vy, double g, double& sy);

	void asmwyliczx(double m, double cd, double e, double t, double cw, double vw, double vx, double& sx);
	void asmwyliczy(double vy, double m, double g, double& sy, double cd, double e, double t);
	void asmwyliczvx(double cd, double e, double cw, double vw, double& vx);
	void asmwyliczvy(double cd, double m, double& vy, double g, double e);
	void asmwyliczxvx(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx);
	void asmwyliczyvy(double& vy, double m, double g, double& sy, double cd, double e, double t);
	void asmwyliczwszystko(double cd, double e, double t, double cw, double vw, double& vx, double m, double& sx, double& vy, double g, double& sy);
};