#include "Goal.h"

void Goal::Respawn(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Goal::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

bool Goal::IsCollected(const Dude& dude) const
{
	const int right = x + width;
	const int bottom = y + height;
	const int dudeRight = dude.GetX() + Dude::width;
	const int dudeBottom = dude.GetY() + Dude::height;

	return
		right >= dude.GetX() &&
		x <= dudeRight &&
		y <= dudeBottom &&
		bottom >= dude.GetY();
}

int Goal::GetX() const
{
	return x;
}

int Goal::GetY() const
{
	return y;
}