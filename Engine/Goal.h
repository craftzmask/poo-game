#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	void Respawn(int x, int y);
	void Draw(Graphics& gfx);
	bool IsCollected(const Dude& dude) const;
	int GetX() const;
	int GetY() const;
private:
	int x;
	int y;
	Color c = Colors::Red;
public:
	static constexpr int width = 20;
	static constexpr int height = 20;
};