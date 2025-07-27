#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

void Poo::Init(float in_x, float in_y, float in_vx, float in_vy)
{
	assert(initialized == false);
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Poo::Update()
{
	assert(initialized);
	x += vx;
	y += vy;

	const float right = x + width;
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

	const float bottom = y + height;
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

bool Poo::TestCollision(const Dude& dude) const
{
	assert(initialized);
	const float right = x + width;
	const float bottom = y + height;
	const float dudeRight = dude.GetX() + dude.GetWidth();
	const float dudeBottom = dude.GetY() + dude.GetHeight();
	return x <= dudeRight && right >= dude.GetX() && y <= dudeBottom && bottom >= dude.GetY();
}

void Poo::Draw(Graphics& gfx) const
{
	assert(initialized);
	const int int_x = int(x);
	const int int_y = int(y);
	gfx.PutPixel(14 + int_x, 0 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 3 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 6 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 6 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 7 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 7 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 7 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 7 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 9 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 9 + int_y, 102, 57, 0);
	gfx.PutPixel(13 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 9 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 10 + int_y, 102, 57, 0);
	gfx.PutPixel(13 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 11 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 11 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 12 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 12 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 12 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 12 + int_y, 111, 62, 0);
	gfx.PutPixel(13 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(14 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(15 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(16 + int_x, 12 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 13 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 13 + int_y, 109, 61, 0);
	gfx.PutPixel(11 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 13 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 15 + int_y, 116, 65, 0);
	gfx.PutPixel(8 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(17 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(18 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 16 + int_y, 116, 65, 0);
	gfx.PutPixel(8 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 16 + int_y, 109, 61, 0);
	gfx.PutPixel(14 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 16 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(2 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(3 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(4 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(5 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 17 + int_y, 43, 24, 0);
	gfx.PutPixel(8 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 17 + int_y, 40, 22, 0);
	gfx.PutPixel(14 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 17 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 18 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(22 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(8 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 19 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(22 + int_x, 19 + int_y, 65, 36, 0);
	gfx.PutPixel(23 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(8 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 20 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(22 + int_x, 20 + int_y, 65, 36, 0);
	gfx.PutPixel(23 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(17 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(18 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(22 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 22 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(2 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(3 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(4 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(5 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(6 + int_x, 22 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 23 + int_y, 51, 28, 0);

}

void Poo::IncreaseSpeed()
{
	if (vx < 0)
	{
		--vx;
	}
	else
	{
		++vx;
	}

	if (vy < 0)
	{
		--vy;
	}
	else
	{
		++vy;
	}
}
