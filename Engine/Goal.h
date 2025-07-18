#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	Goal(int in_x, int in_y);
	void Draw(Graphics& gfx) const;
	void Respawn(int xPos, int yPos);
	bool TestColliding(const Dude& dude) const;
private:
	int x;
	int y;
	static constexpr int width = 20;
	static constexpr int height = 20;
	Color c = Colors::Red;
};