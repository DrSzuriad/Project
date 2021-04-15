
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


	void draw(RenderTarget& target, RenderStates state) const;//Funkcja rysuje prostok¹t
public:
	pole(float x, float y,float h,float w, Color kol,int fig);//Konstruktor
	float getx();//Zwraca pozycjê w poziomie
	void setx(float korx);//Ustawia pozycjê w poziomie
	float gety();//Zwraca pozycjê w pionie
	void sety(float kory);//Ustawia pozycjê w pionie
};

