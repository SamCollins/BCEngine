#include <SDL.h>

#include <stdio.h>
#include <iostream>

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

	BCEngine::RenderWindow renderWindow("Texture Demo", 600, 600);

	SDL_Texture* grassTexture = renderWindow.LoadTexture("src/res/gfx/ground_grass_1.png");

	BCEngine::Entity platform_0(100, 100, grassTexture);

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
		renderWindow.RenderEntity(platform_0);

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