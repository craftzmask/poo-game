#pragma once
class Poo
{
public:
	void Update();
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
	static constexpr int width = 24;
	static constexpr int height = 24;
};