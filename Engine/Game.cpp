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
	poo0(xDist(rng), yDist(rng), 1, -1),
	poo1(xDist(rng), yDist(rng), -1, -1),
	poo2(xDist(rng), yDist(rng), 1, 1)
{
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
		dude.ClampToScreen();
	
		poo0.Update();
		poo1.Update();
		poo2.Update();

		poo0.ProcessConsumption(dude);
		poo1.ProcessConsumption(dude);
		poo2.ProcessConsumption(dude);
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
		dude.Draw(gfx);
		if (!poo0.IsEaten())
		{
			poo0.Draw(gfx);
		}
		if (!poo1.IsEaten())
		{
			poo1.Draw(gfx);
		}
		if (!poo2.IsEaten())
		{
			poo2.Draw(gfx);
		}

		if (poo0.IsEaten() && poo1.IsEaten() && poo2.IsEaten())
		{
			Sprite::DrawGameOver(gfx, 358, 268);
		}
	}
	else
	{
		Sprite::DrawGameTitle(gfx, 325, 212);
	}
}
