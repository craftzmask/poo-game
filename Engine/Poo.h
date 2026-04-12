#pragma once
#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Update();
	void Draw(Graphics& gfx) const;
	void ProcessConsumption(const Dude& dude);
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
	static constexpr int width = 24;
	static constexpr int height = 24;
};