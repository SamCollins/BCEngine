#include "EntityDemo.h"

namespace Demos
{
	EntityDemo::EntityDemo()
		:g_showFpsInfo(false), g_showInputInfo(false), g_currentFrame(0), g_playableEntity(NULL)
	{}

	void EntityDemo::ToggleFpsInfo()
	{
		g_showFpsInfo = !g_showFpsInfo;
		std::cout << "FPS Counter: " << (g_showFpsInfo ? "ON" : "OFF") << std::endl;
	}

	void EntityDemo::ToggleInputInfo()
	{
		g_showInputInfo = !g_showInputInfo;
		std::cout << "Input/Output Logging: " << (g_showInputInfo ? "ON" : "OFF") << std::endl;
	}

	void EntityDemo::ResolveInput()
	{
		SDL_Keycode keyCode = g_inputBuffer.GetInputFromBuffer();
		if (g_showInputInfo)
			std::cout << "Current Frame: " << g_currentFrame << " Output: " << SDL_GetKeyName(keyCode) << std::endl;
		switch (keyCode)
		{
		case SDLK_F3:
			ToggleFpsInfo();
			break;
		case SDLK_F4:
			ToggleInputInfo();
			break;
		case SDLK_F5:
			g_inputBuffer.PrintBufferContents();
			break;
		case SDLK_F6:
			g_inputBuffer.ClearBuffer();
			break;

		case SDLK_UP:
			g_playableEntity->SetVelocity(BCSim::Vector2(0, -100));
			break;
		case SDLK_DOWN:
			g_playableEntity->SetVelocity(BCSim::Vector2(0, 100));
			break;
		case SDLK_LEFT:
			g_playableEntity->SetVelocity(BCSim::Vector2(-100, 0));
			break;
		case SDLK_RIGHT:
			g_playableEntity->SetVelocity(BCSim::Vector2(100, 0));
			break;
		default:
			break;
		}
	}

	/*TODO List
	- Make Collected Header Files (Ex. BCCore.h with all BCCore headers in it)
	- Seperate out Init stuff into function (Maybe Init debug info for font path?)
	- Make Component system (Maybe from SDL Tutorial, maybe from Cherno)
	- Make seperate Demo file that can be easily swapped in main.cpp (Will be used for doing 
	calculations/testing, maybe making sure Vector2/eventual physics calculations are correct)
	*/
	void EntityDemo::Start()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		if (TTF_Init() == -1)
			std::cout << "TTF Failed to Initialize: " << TTF_GetError() << std::endl;

		const int WINDOW_WIDTH = 512;
		const int WINDOW_HEIGHT = 512;
		const int FONT_SIZE = 16;

		BCCore::GameWindow gameWindow("Entities Demo", WINDOW_WIDTH, WINDOW_HEIGHT);
		gameWindow.InitDebugFont("src/res/fonts/OpenSans-Regular.ttf", FONT_SIZE);

		//TODO: Make better way of knowing size of tile/texture
		int grassWidth = 32;
		int grassHeight = 32;
		int floorHeight = WINDOW_HEIGHT - grassHeight;

		const int num_tiles = WINDOW_WIDTH / grassWidth;

		SDL_Texture* grassTexture = gameWindow.LoadTexture("src/res/gfx/ground_grass_1.png");
		SDL_Texture* boxTexture = gameWindow.LoadTexture("src/res/gfx/box_1.png");
		SDL_Texture* stoneTexture = gameWindow.LoadTexture("src/res/gfx/stone_1.png");

		BCSim::Environment enviro(0, 0, 0);

		std::vector<BCCore::Entity> grassTiles;
		for (int i = 0; i < num_tiles; i++)
		{
			grassTiles.push_back(BCCore::Entity("Grass", BCSim::Vector2(grassWidth * i, floorHeight), grassTexture));
		}

		for (auto& grassEntity : grassTiles)
			enviro.AddEntity(&grassEntity, false);

		BCCore::Entity stone1("Stone", BCSim::Vector2(300.0, 250.0), stoneTexture);
		enviro.AddEntity(&stone1, false);
		BCCore::Entity stone2("Stone", BCSim::Vector2(100.0, 400.0), stoneTexture);
		enviro.AddEntity(&stone2, false);

		BCCore::Entity box("Box", BCSim::Vector2(200.0, 200.0), boxTexture);
		g_playableEntity = &box;
		
		enviro.AddEntity(&box, true);

		enviro.PrintEntities();

		bool gameRunning = true;
		SDL_Event event;

		while (gameRunning)
		{
			int currentFps = gameWindow.GetRefreshRate();
			//int currentFps = 1;
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
					g_inputBuffer.AddToBuffer(event.key.keysym.sym);
					if (g_showInputInfo) std::cout << "Input Added: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
				}
			}

			if (g_inputBuffer.HasInputs())
				ResolveInput();

			enviro.UpdateEntities(deltaTime);
			//box.GetPosition().PrintData();

			//box.UpdatePosition(deltaTime);
			//box.GetPosition().PrintData();

			gameWindow.ClearScreen();

			for (auto& tile : grassTiles)
			{
				gameWindow.RenderEntity(tile);
			}

			gameWindow.RenderEntity(stone1);
			gameWindow.RenderEntity(stone2);

			gameWindow.RenderEntity(box);

			if (g_showFpsInfo)
				gameWindow.DisplayDebugInfo(g_currentFrame);

			gameWindow.DisplayTextures();

			g_currentFrame++;

			if (g_currentFrame >= currentFps)
				g_currentFrame = 0;

			int frameTicks = SDL_GetTicks() - startTicks;

			if (frameTicks < ticksPerFrame)
			{
				SDL_Delay(ticksPerFrame - frameTicks);
			}
		}

		gameWindow.CleanUp();
	}
}