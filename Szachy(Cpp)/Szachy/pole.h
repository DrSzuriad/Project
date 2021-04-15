
#pragma once



#include <SFML/Graphics.hpp>
#include"enum.h"
#include "grafika.h"



using namespace sf;
using namespace std;



class pole :
	public Drawable
{
private:
	sf::RectangleShape prost;


	void draw(RenderTarget& target, RenderStates state) const;//Funkcja rysuje prostok�t
public:
	pole(float x, float y,float h,float w, Color kol,int fig);//Konstruktor
	float getx();//Zwraca pozycj� w poziomie
	void setx(float korx);//Ustawia pozycj� w poziomie
	float gety();//Zwraca pozycj� w pionie
	void sety(float kory);//Ustawia pozycj� w pionie
};

