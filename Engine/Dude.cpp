#include "Dude.h"

void Dude::Update(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;
	}
}
