#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "BCUtils.h"

#include "Engine.h"
#include "Physics.h"
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
	if (TTF_Init() == -1)
		std::cout << "TTF Failed to Initialize: " <<  TTF_GetError() << std::endl;

	const int WINDOW_WIDTH = 512;
	const int WINDOW_HEIGHT = 512;

	BCEngine::RenderWindow renderWindow("Texture Demo", WINDOW_WIDTH, WINDOW_HEIGHT);
	//int windowRefreshRate = renderWindow.GetRefreshRate();

	//TODO: Make better way of knowing size of tile/texture
	float grassWidth = 32;
	float grassHeight = 32;
	float floorHeight = WINDOW_HEIGHT - grassHeight;

	const int num_tiles = WINDOW_WIDTH / grassWidth;

	SDL_Texture* grassTexture = renderWindow.LoadTexture("src/res/gfx/ground_grass_1.png");

	/*std::array<BCEngine::Entity, num_tiles> grassTiles = {
		BCEngine::Entity(0, 100, grassTexture),
		BCEngine::Entity(50, 100, grassTexture),
		BCEngine::Entity(75, 100, grassTexture),
		BCEngine::Entity(100, 100, grassTexture)
	};*/

	std::vector<BCEngine::Entity> grassTiles;

	for (int i = 0; i < num_tiles; i++)
	{
		grassTiles.push_back(BCEngine::Entity(BCEngine::Vector2f(grassWidth * i, floorHeight), grassTexture));
	}

	bool gameRunning = true;
	SDL_Event event;

	bool showDebugInfo = false;

	//timeStep == deltaTime
	//const float timeStep = 0.01f;
	//float accumulator = 0.0f;
	//float currentTime = BCUtils::TimeInSeconds();

	int ticksPerFrame = 1000 / renderWindow.GetRefreshRate();

	int frameCount = 0;

	while (gameRunning)
	{
		int startTicks = SDL_GetTicks();

		//float newTime = BCUtils::TimeInSeconds();
		//float frameTime = newTime - currentTime;

		//currentTime = newTime;
		//accumulator += frameTime;

		//while (accumulator >= timeStep)
		//{
		//	//PollEvent loop here
		//	accumulator -= timeStep;
		//}

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_F3:
					showDebugInfo = !showDebugInfo;
					break;
				default:
					break;
				}
			}
		}

		//const float alpha = accumulator / timeStep; //What % of a timeStep has accumulated

		//std::cout << "alpha: " << alpha << std::endl;

		renderWindow.ClearScreen();

		//renderWindow.RenderTexture(grassTexture);
		//renderWindow.RenderEntity(platform_0);

		for (auto& tile: grassTiles)
		{
			renderWindow.RenderEntity(tile);
		}

		//TODO: Make this input less cringe/maybe move file back into function
		//Maybe make fonts folder in Engine project? Needs to be generic to not be gross
		if (showDebugInfo)
			renderWindow.DisplayDebugInfo("src/res/fonts/OpenSans-Regular.ttf", frameCount);

		//std::cout << BCUtils::TimeInSeconds() << std::endl;

		renderWindow.DisplayTextures();

		//std::cout << "Frame Number: " << frameNum << " Current Time: " << BCUtils::TimeInSeconds() << std::endl;

		frameCount++;

		//std::cout << "Frame: " << frameCount << "/" << windowRefreshRate << std::endl;

		if (frameCount >= renderWindow.GetRefreshRate())
			frameCount = 0;

		int frameTicks = SDL_GetTicks() - startTicks;

		if (frameTicks < ticksPerFrame)
		{
			SDL_Delay(ticksPerFrame - frameTicks);
		}
	}

	renderWindow.CleanUp();
}

/*Misc TODO List :
 - Reorganize file structure in BCEngine (Folders, etc)
 - Move RectDemo somewhere else
 - There's a memory leak somewhere (RAM usage constantly goes up)
   maybe need to free entity textures? maybe coming from debug info function
*/
int main(int argc, char* argv[])
{
	//RectDemo();
	TextureDemo();

	return 0;
}