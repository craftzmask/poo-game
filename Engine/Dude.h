#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	Dude();
	Dude(int x, int y);
	void Update(const Keyboard& kbd);
	void Draw(Graphics& gfx) const;
	void ClampToScreen();
	int GetX() const;
	int GetY() const;
private:
	int x;
	int y;
public:
	static constexpr int width = 20;
	static constexpr int height = 20;
};