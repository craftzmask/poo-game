#include "Meter.h"

Meter::Meter(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Meter::Draw(Graphics& gfx) const
{
	gfx.DrawRect(x, y, x + level * levelWidth, y + height, c);
}

void Meter::LevelUp()
{
	if (level < maxLevel)
	{
		level++;
	}
}
