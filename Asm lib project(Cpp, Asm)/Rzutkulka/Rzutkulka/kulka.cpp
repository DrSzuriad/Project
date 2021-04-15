#include "kulka.h"

void kulka::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(obrazek, state);
}



kulka::kulka() {
	obrazek.setFillColor(Color::Black);
	obrazek.setRadius(10);
	obrazek.setPosition(300, 590);
	obrazek.setOrigin(10, 10);
	vx = 0;
	vy = 0;
}

void kulka::setPosition(Vector2f wektor)
{
	obrazek.setPosition(wektor);
}

Vector2f kulka::getPosition()
{
	return obrazek.getPosition();
}
