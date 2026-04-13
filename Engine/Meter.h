#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int x, int y);
	void Draw(Graphics& gfx) const;
	void LevelUp();

private:
	int x;
	int y;
	int width = 40;
	int height = 10;
	int level = 0;
	int levelWidth = 10;
	Color c = Colors::Blue;
	static constexpr int maxLevel = 20;
};