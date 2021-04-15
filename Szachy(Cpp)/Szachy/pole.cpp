#include "pole.h"

pole::pole(float x, float y, float h, float w, Color kol,int fig)
{	
	prost.setPosition(x, y);
	prost.setSize(Vector2f{ h,w });
	prost.setFillColor(kol);
}


float pole::getx()
{
	 Vector2f tym=prost.getPosition();
	 return tym.x;
}

void pole::setx(float korx)
{
	prost.setPosition(korx, this->gety());
}

float pole::gety()
{
	Vector2f tym = prost.getPosition();
	return tym.y;
}

void pole::sety(float kory)
{
	prost.setPosition(this->getx(),kory);
}

void pole::draw(RenderTarget& target, RenderStates state) const
{

	target.draw(this->prost, state);

}