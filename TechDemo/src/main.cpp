#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "Engine.h"
#include "RenderWindow.h"
#include "Entity.h"

void RectDemo()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	BCEngine::RenderWindow renderWindow("Rect Demo", 600, 600);

	bool gameRunning = true;
	SDL_Event event;

	renderWindow.InitRect(200, 200, 200, 200);

	int x_pos = 0, y_pos = 0;
	int moveSpeed = 10;

	while (gameRunning)
	{
		renderWindow.DrawBackground();
		renderWindow.MoveRect(x_pos, y_pos);
		renderWindow.DrawRect();

		//x_pos++;

		if (x_pos == 600) x_pos = 0;
		if (y_pos == 600) y_pos = 0;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					y_pos -= moveSpeed;
					break;
				case SDLK_DOWN:
					y_pos += moveSpeed;
					break;
				case SDLK_LEFT:
					x_pos -= moveSpeed;
					break;
				case SDLK_RIGHT:
					x_pos += moveSpeed;
					break;
				default:
					break;
				}
			}
		}

		std::cout << "x:" << x_pos << "y:" << y_pos << std::endl;
	}

	renderWindow.CleanUp();
}

void TextureDemo()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	const int WINDOW_WIDTH = 512;
	const int WINDOW_HEIGHT = 512;

	BCEngine::RenderWindow renderWindow("Texture Demo", WINDOW_WIDTH, WINDOW_HEIGHT);

	//TODO: Make better way of knowing size of tile/texture
	int grassWidth = 32;
	int grassHeight = 32;
	int floorHeight = WINDOW_HEIGHT - grassHeight;

	const int num_tiles = WINDOW_WIDTH / grassWidth;

	SDL_Texture* grassTexture = renderWindow.LoadTexture("src/res/gfx/ground_grass_1.png");

	BCEngine::Entity platform_0(100, 100, grassTexture);

	/*std::array<BCEngine::Entity, num_tiles> grassTiles = {
		BCEngine::Entity(0, 100, grassTexture),
		BCEngine::Entity(50, 100, grassTexture),
		BCEngine::Entity(75, 100, grassTexture),
		BCEngine::Entity(100, 100, grassTexture)
	};*/

	std::vector<BCEngine::Entity> grassTiles;

	for (int i = 0; i < num_tiles; i++)
	{
		grassTiles.push_back(BCEngine::Entity(grassWidth * i, floorHeight, grassTexture));
	}

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		renderWindow.ClearScreen();

		//renderWindow.RenderTexture(grassTexture);
		//renderWindow.RenderEntity(platform_0);

		for (auto& tile: grassTiles)
		{
			renderWindow.RenderEntity(tile);
		}

		renderWindow.DisplayTextures();
	}

	renderWindow.CleanUp();
}

int main(int argc, char* argv[])
{
	//RectDemo();
	TextureDemo();

	return 0;
}