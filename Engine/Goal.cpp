#include "Goal.h"

Goal::Goal(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Goal::Respawn(int xPos, int yPos)
{
	x = xPos;
	y = yPos;
}

bool Goal::TestColliding(const Dude& dude) const
{
	const int right = x + width;
	const int bottom = y + height;
	const int dudeRight = dude.GetX() + dude.GetWidth();
	const int dudeBottom = dude.GetY() + dude.GetHeight();
	return (x <= dudeRight && right >= dude.GetX() && y <= dudeBottom && bottom >= dude.GetY());
}
