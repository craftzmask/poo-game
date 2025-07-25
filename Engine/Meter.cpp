#include "Meter.h"

Meter::Meter(int in_x, int in_y)
	:
	x(in_x),
	y(in_y)
{
}

void Meter::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(x, y, level * scale, height, c);
}

void Meter::IncreaseLevel()
{
	if (level < maxLevel)
	{
		level++;
	}
}

int Meter::GetLevel() const
{
	return level;
}

int Meter::GetMaxLevel() const
{
	return maxLevel;
}

void Meter::ResetLevel()
{
	level = 0;
}
