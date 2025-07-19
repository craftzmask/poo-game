#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int in_x, int in_y);
	void Draw(Graphics& gfx) const;
	void IncreaseLevel();
	int GetLevel() const;
	int GetMaxLevel() const;
	void ResetLevel();
private:
	int x;
	int y;
	int level;
	static constexpr Color c = Colors::Blue;
	static constexpr int maxLevel = 10;
	static constexpr int scale = 6;
	static constexpr int height = 12;
};