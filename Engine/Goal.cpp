#include "Goal.h"

Goal::Goal(float in_x, float in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(int(x), int(y), int(width), int(height), c);
}

void Goal::Respawn(float xPos, float yPos)
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

bool Goal::TestCollision(const Dude& dude) const
{
	const float right = x + width;
	const float bottom = y + height;
	const float dudeRight = dude.GetX() + dude.GetWidth();
	const float dudeBottom = dude.GetY() + dude.GetHeight();
	return (x <= dudeRight && right >= dude.GetX() && y <= dudeBottom && bottom >= dude.GetY());
}
