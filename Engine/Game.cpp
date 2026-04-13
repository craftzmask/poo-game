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
	gfx( wnd ),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	meter(30, 30)
{
	std::uniform_int_distribution<int> vDist(-1, 1);
	for (int i = 0; i < nPoo; i++)
	{
		poos[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	}

	goal.Respawn(xDist(rng), yDist(rng));
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
	goal.Glow();
	if (isGameStarted)
	{
		if (!isGameOver)
		{
			dude.Update(wnd.kbd);
			dude.ClampToScreen();

			if (goal.IsCollected(dude))
			{
				goal.Respawn(xDist(rng), yDist(rng));
				meter.LevelUp();
			}

			for (int i = 0; i < nPoo; i++)
			{
				poos[i].Update();
				poos[i].ProcessConsumption(dude);
			}
		}
	}
	else
	{
		isGameStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (isGameStarted)
	{
		meter.Draw(gfx);
		dude.Draw(gfx);
		goal.Draw(gfx);

		for (int i = 0; i < nPoo; i++)
		{
			if (poos[i].IsEaten())
			{
				isGameOver = true;
			}
			else
			{
				poos[i].Draw(gfx);
			}
		}
	

		if (isGameOver)
		{
			Sprite::DrawGameOver(gfx, 358, 268);
		}
	}
	else
	{
		Sprite::DrawGameTitle(gfx, 325, 212);
	}
}
