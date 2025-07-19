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

void Goal::UpdateColor()
{
	if (isIncreasing)
	{
		if (c.GetR() >= 253)
		{
			isIncreasing = false;
		}
		else
		{
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else
	{
		if (c.GetR() <= 127)
		{
			isIncreasing = true;
		}
		else
		{
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
}

bool Goal::TestColliding(const Dude& dude) const
{
	const int right = x + width;
	const int bottom = y + height;
	const int dudeRight = dude.GetX() + dude.GetWidth();
	const int dudeBottom = dude.GetY() + dude.GetHeight();
	return (x <= dudeRight && right >= dude.GetX() && y <= dudeBottom && bottom >= dude.GetY());
}
