#include "EntityDemo.h"

namespace Demos
{
	EntityDemo::EntityDemo()
	{}

	/*TODO List
	- Figure out better way of passinf fontPath into constructor
	- Seperate out Init stuff into function (Maybe Init debug info for font path?)
	*/
	void EntityDemo::Start()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		if (TTF_Init() == -1)
			std::cout << "TTF Failed to Initialize: " << TTF_GetError() << std::endl;

		const int WINDOW_WIDTH = 512;
		const int WINDOW_HEIGHT = 512;

		BCEngine::RenderWindow renderWindow("Texture Demo", WINDOW_WIDTH, WINDOW_HEIGHT, "src/res/fonts/OpenSans-Regular.ttf");

		//TODO: Make better way of knowing size of tile/texture
		float grassWidth = 32;
		float grassHeight = 32;
		float floorHeight = WINDOW_HEIGHT - grassHeight;

		const int num_tiles = WINDOW_WIDTH / grassWidth;

		SDL_Texture* grassTexture = renderWindow.LoadTexture("src/res/gfx/ground_grass_1.png");

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

			renderWindow.ClearScreen();

			for (auto& tile : grassTiles)
			{
				renderWindow.RenderEntity(tile);
			}

			if (showDebugInfo)
				renderWindow.DisplayDebugInfo(frameCount);

			renderWindow.DisplayTextures();

			frameCount++;

			if (frameCount >= renderWindow.GetRefreshRate())
				frameCount = 0;

			int frameTicks = SDL_GetTicks() - startTicks;

			std::cout << "Ticks taken this frame: " << frameTicks << std::endl;

			if (frameTicks < ticksPerFrame)
			{
				SDL_Delay(ticksPerFrame - frameTicks);
			}
		}

		renderWindow.CleanUp();
	}
}