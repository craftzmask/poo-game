#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Update(Keyboard& kbd);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	float x = 400;
	float y = 300;
	static constexpr float width = 20;
	static constexpr float height = 20;
};