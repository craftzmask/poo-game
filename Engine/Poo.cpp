#include "Poo.h"
#include "Graphics.h"

void Poo::Update()
{
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 1 - width;
		vx = -vx;
	}

	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 1 - height;
		vy = -vy;
	}
}

void Poo::ProcessConsumption(int dudeX, int dudeY, int dudeWidth, int dudeHeight)
{
	const int right = x + width;
	const int bottom = y + height;
	const int dudeRight = dudeX + dudeWidth;
	const int dudeBottom = dudeY + dudeHeight;

	if (x <= dudeRight && right >= dudeX && y <= dudeBottom && bottom >= dudeY)
	{
		isEaten = true;
	}
}
