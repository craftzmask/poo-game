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

void Goal::Glow()
{
	if (isRedIncreasing)
	{
		if (c.GetR() > 250)
		{
			isRedIncreasing = false;
		}
		else
		{
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else
	{
		if (c.GetR() < 130)
		{
			isRedIncreasing = true;
		}
		else
		{
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
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