#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "cpplib.h"

double cppobliczvx(double *tab)
{
	return (1 / tab[0]) * (tab[1] * (tab[2] * tab[3] + tab[0] * tab[4]) - (tab[2] * tab[3]));
}
double cppobliczvy(double* tab)
{

	return  (1 / tab[0]) * tab[4] * (tab[0] * tab[2] + tab[1] * tab[3]) - (tab[1] * tab[3]) / tab[0];
}
double cppobliczsx(double* tab)
{
	return (tab[0]/ tab[1]) * tab[2] * (-tab[4] * tab[5] / tab[1] - tab[6]) - (tab[4] * tab[5] * tab[3] / tab[1]) - (tab[0] / tab[1]) * (-tab[4] * tab[5] / tab[1] - tab[6]) + tab[7];
}
double cppobliczsy(double* tab)
{
	return  tab[3] - ((-(tab[0] + (tab[1] * tab[2]) / tab[4]) * (tab[1] / tab[4]) * tab[5] - tab[6] * tab[1] * tab[2] / tab[4]) + ((tab[1] / tab[4]) * (tab[0] + tab[1] * tab[2] / tab[4])));
}
