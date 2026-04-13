#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	void Respawn(int x, int y);
	void Draw(Graphics& gfx);
	void Glow();
	bool IsCollected(const Dude& dude) const;
	int GetX() const;
	int GetY() const;
private:
	int x;
	int y;
	Color c{ 127, 0, 0 };
	bool isRedIncreasing = true;
public:
	static constexpr int width = 20;
	static constexpr int height = 20;
};