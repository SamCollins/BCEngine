#include "EntityDemo.h"

namespace Demos
{
	EntityDemo::EntityDemo()
	{}

	/*TODO List
	- Figure out better way of passing fontPath into constructor
	- Seperate out Init stuff into function (Maybe Init debug info for font path?)
	*/
	void EntityDemo::Start()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		if (TTF_Init() == -1)
			std::cout << "TTF Failed to Initialize: " << TTF_GetError() << std::endl;

		const int WINDOW_WIDTH = 512;
		const int WINDOW_HEIGHT = 512;

		BCEngine::RenderWindow renderWindow("Entities Demo", WINDOW_WIDTH, WINDOW_HEIGHT, "src/res/fonts/OpenSans-Regular.ttf");

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
		int frameCount = 0;

		BCEngine::InputBuffer inputBuffer;

		while (gameRunning)
		{
			int currentFps = renderWindow.GetRefreshRate();
			//int currentFps = 10;
			int ticksPerFrame = 1000 / currentFps;
			double deltaTime = 1.0 / currentFps;

			//Deleted all the accumulator/timestep stuff from tutorial
			//TODO: Rework to account for variable frame rates (Not locked at refresh rate)
			int startTicks = SDL_GetTicks();

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					gameRunning = false;

				if (event.type == SDL_KEYDOWN)
				{
					inputBuffer.AddToBuffer(event.key.keysym.sym);

					switch (event.key.keysym.sym)
					{
					case SDLK_F3:
						showDebugInfo = !showDebugInfo;
						break;
					case SDLK_F5:
						inputBuffer.PrintBufferContents();
						break;
					case SDLK_F6:
						inputBuffer.ClearBuffer();
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

			if (frameCount >= currentFps)
				frameCount = 0;

			int frameTicks = SDL_GetTicks() - startTicks;

			//std::cout << "Ticks taken this frame: " << frameTicks << std::endl;

			if (frameTicks < ticksPerFrame)
			{
				SDL_Delay(ticksPerFrame - frameTicks);
			}
		}

		renderWindow.CleanUp();
	}
}