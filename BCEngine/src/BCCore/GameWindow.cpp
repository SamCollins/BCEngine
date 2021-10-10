#include "GameWindow.h"

namespace BCCore
{
	GameWindow::GameWindow(const std::string& windowTitle, int width, int height)
		:m_window(NULL), m_renderer(NULL), m_debugInfoFont(NULL)
	{
		m_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_SHOWN);

		if (m_window == NULL)
			std::cout << "Window Initialization Failed. Error: " << SDL_GetError() << std::endl;

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

		if (m_renderer == NULL)
			std::cout << "Renderer Initialization Failed. Error: " << SDL_GetError() << std::endl;
	}

	void GameWindow::InitDebugFont(const std::string& fontPath, int fontSize)
	{
		m_debugInfoFont = TTF_OpenFont(fontPath.c_str(), fontSize);

		if (m_debugInfoFont == NULL)
			std::cout << "Font Error: " << TTF_GetError() << std::endl;
	}

	void GameWindow::CloseDebugFont()
	{
		TTF_CloseFont(m_debugInfoFont);
	}

	void GameWindow::ClearScreen()
	{
		SDL_RenderClear(m_renderer);
	}

	int GameWindow::GetRefreshRate()
	{
		int displayIndex = SDL_GetWindowDisplayIndex(m_window);
		SDL_DisplayMode mode;
		SDL_GetDisplayMode(displayIndex, 0, &mode);

		return mode.refresh_rate;
	}

	std::string GameWindow::GetFpsDisplay(int currentFrame, int fpsCap)
	{
		std::string displayFrame = std::to_string(currentFrame);
		std::string displayFpsCap = std::to_string(fpsCap);

		if (currentFrame < 10)
			return std::format("00{}/{}", displayFrame, displayFpsCap);
		else if (currentFrame < 100)
			return std::format("0{}/{}", displayFrame, displayFpsCap);
		else
			return std::format("{}/{}", displayFrame, displayFpsCap);
	}

	void GameWindow::DisplayDebugInfo(int currentFrame)
	{
		int refreshRate = GetRefreshRate();
		std::string displayRefreshRate = "Refresh Rate: " + std::to_string(refreshRate);
		std::string displayFps = "FPS: " + GetFpsDisplay(currentFrame, refreshRate);
		std::string displayTime = "Time: " + std::to_string(BCUtils::TimeInSeconds());
		std::string debugInfo = displayRefreshRate + "|" + displayFps + "|" + displayTime;

		SDL_Color White = { 255, 255, 255 };
		SDL_Surface* surfaceMessage =
			TTF_RenderText_Solid(m_debugInfoFont, debugInfo.c_str(), White);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);

		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 0;  //controls the rect's x coordinate 
		Message_rect.y = 0; // controls the rect's y coordinte
		Message_rect.w = 400; // controls the width of the rect
		Message_rect.h = 40; // controls the height of the rect

		SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
	}

	SDL_Texture* GameWindow::LoadTexture(const std::string& filePath)
	{
		SDL_Texture* texture = NULL;
		texture = IMG_LoadTexture(m_renderer, filePath.c_str());

		if (texture == NULL)
		{
			std::cout << "Failed to load texture. SDL Error: " << SDL_GetError() << std::endl;
			std::cout << "Failed to load texture. IMG Error: " << IMG_GetError() << std::endl;
		}

		return texture;
	}

	//Maybe keep this around for backgrounds?
	void GameWindow::RenderTexture(SDL_Texture* p_texture)
	{
		SDL_Rect textureSrc;
		textureSrc.x = 0;
		textureSrc.y = 0;
		textureSrc.w = 32;
		textureSrc.h = 32;

		SDL_Rect textureDest;
		textureDest.x = 0;
		textureDest.y = 0;
		textureDest.w = 32;
		textureDest.h = 32;

		SDL_RenderCopy(m_renderer, p_texture, &textureSrc, &textureDest);
	}

	void GameWindow::RenderEntity(const Entity& entity)
	{
		SDL_Rect entityCurrentFrame = entity.GetCurrentFrame();
		int sizeMultiplier = 1;

		SDL_Rect entitySrc;
		entitySrc.x = entityCurrentFrame.x;
		entitySrc.y = entityCurrentFrame.y;
		entitySrc.w = entityCurrentFrame.w;
		entitySrc.h = entityCurrentFrame.h;

		//TODO: Make GetPosition better, getting member variable off function call is cringe
		//Also figure out best way of rounding (Maybe floor?) to convert from position double to rect int
		SDL_Rect entityDest;
		entityDest.x = entity.GetPosition().x * sizeMultiplier;
		entityDest.y = entity.GetPosition().y * sizeMultiplier;
		entityDest.w = entityCurrentFrame.w * sizeMultiplier;
		entityDest.h = entityCurrentFrame.h * sizeMultiplier;

		SDL_RenderCopy(m_renderer, entity.GetTexture(), &entitySrc, &entityDest);
	}

	void GameWindow::DisplayTextures()
	{
		SDL_RenderPresent(m_renderer);
	}

	void GameWindow::CleanUp()
	{
		CloseDebugFont();

		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
	}
}