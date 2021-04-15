#pragma once
#include "podstawowy.h"

class kulka : public Drawable
{
	void draw(RenderTarget& target, RenderStates state) const;
	double vx, vy;
	CircleShape obrazek;
public:
	kulka();
	void setPosition(Vector2f wektor);
	Vector2f getPosition();
};

