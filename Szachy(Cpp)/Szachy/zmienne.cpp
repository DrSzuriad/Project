#include "zmienne.h"

bool zmienne::getbprze(int  x, int y)
{
	if (bialyprzelot.size() != 0 && bialyprzelot[0] == x && bialyprzelot[1] == y)
		return true;
	return false;
}

bool zmienne::getcprze(int  x,int y)
{
	if (czarnyprzelot.size() != 0 && czarnyprzelot[0] == x && czarnyprzelot[1] == y)
		return true;
	return false;
}

bool zmienne::getrobi0()
{
	return roszadabial0;
}

bool zmienne::getrobi7()
{
	return roszadabial7;
}

bool zmienne::getrocz0()
{
	return roszadaczar0;
}

bool zmienne::getrocz7()
{
	return roszadaczar7;
}



void zmienne::setrobi0(bool war)
{
	roszadabial0 = war;
}

void zmienne::setrobi7(bool war)
{
	roszadabial7 = war;
}

void zmienne::setrocz0(bool war)
{
	roszadaczar0 = war;
}

void zmienne::setrocz7(bool war)
{
	roszadaczar7 = war;
}

void zmienne::setkorbia(int x, int y)
{
	bialyprzelot.push_back(x);
	bialyprzelot.push_back(y);
}

void zmienne::setkorcza(int x, int y)
{
	czarnyprzelot.push_back(x);
	czarnyprzelot.push_back(y);
}

void zmienne::usunczprze()
{
	czarnyprzelot.clear();
}

void zmienne::usunbiprze()
{
	bialyprzelot.clear();
}

void zmienne::setkrbia(int x, int y)
{
	if (bialykrol.size() > 0) {
		bialykrol[0] = x;
		bialykrol[1] = y;
	}
	else {
		bialykrol.push_back(x);
		bialykrol.push_back(y);
	}
}

void zmienne::getkrbia(int& x, int& y)
{
	x = bialykrol[0];
	y = bialykrol[1];
}

void zmienne::setkrcza(int x, int y)
{
	if (czarnykrol.size() > 0) {
		czarnykrol[0] = x;
		czarnykrol[1] = y;
	}
	else {
		czarnykrol.push_back(x);
		czarnykrol.push_back(y);
	}
}

void zmienne::getkrcza(int& x, int& y)
{
	x = czarnykrol[0];
	y = czarnykrol[1];
}

