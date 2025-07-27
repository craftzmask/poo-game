#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	Goal(float in_x, float in_y);
	void Draw(Graphics& gfx) const;
	void Respawn(float xPos, float yPos);
	void UpdateColor();
	bool TestCollision(const Dude& dude) const;
private:
	float x;
	float y;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
	Color c = { 127, 0, 0 };
	bool isIncreasing = true;
};