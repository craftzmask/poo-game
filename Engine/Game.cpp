/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);
	std::uniform_int_distribution<int> yDist(0, 570);
	poo0.x = xDist(rng);
	poo0.y = yDist(rng);
	poo0.vx = 1;
	poo0.vy = -1;

	poo1.x = xDist(rng);
	poo1.y = yDist(rng);
	poo1.vx = -1;
	poo1.vy = -1;

	poo2.x = xDist(rng);
	poo2.y = yDist(rng);
	poo2.vx = 1;
	poo2.vy = 1;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (isGameStarted)
	{
		dude.Update(wnd.kbd);

		if (IsEaten(dude.x, dude.y, Dude::width, Dude::height, poo0.x, poo0.y, Poo::width, Poo::height))
		{
			poo0.isEaten = true;
		}
		if (IsEaten(dude.x, dude.y, Dude::width, Dude::height, poo1.x, poo1.y, Poo::width, Poo::height))
		{
			poo1.isEaten = true;
		}
		if (IsEaten(dude.x, dude.y, Dude::width, Dude::height, poo2.x, poo2.y, Poo::width, Poo::height))
		{
			poo2.isEaten = true;
		}
	
		poo0.Update();
		poo1.Update();
		poo2.Update();

		dude.ClampToScreen();
	}
	else
	{
		isGameStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

bool Game::IsEaten(int x0, int y0, int width0, int height0, int x1, int y1, int width1, int height1)
{
	const int right0 = x0 + width0;
	const int bottom0 = y0 + height0;
	const int right1 = x1 + width1;
	const int bottom1 = y1 + height1;

	return
		right0 >= x1 &&
		x0 <= right1 &&
		y0 <= bottom1 &&
		bottom0 >= y1;
}

void Game::ComposeFrame()
{
	dude.Draw(gfx);

	if (isGameStarted)
	{
		if (!poo0.isEaten)
		{
			poo0.Draw(gfx);
		}
		if (!poo1.isEaten)
		{
			poo1.Draw(gfx);
		}
		if (!poo2.isEaten)
		{
			poo2.Draw(gfx);
		}

		if (poo0.isEaten && poo1.isEaten && poo2.isEaten)
		{
			Sprite::DrawGameOver(gfx, 358, 268);
		}
	}
	else
	{
		Sprite::DrawGameTitle(gfx, 325, 212);
	}
}
