#include "RenderWindow.h"

namespace BCEngine
{
	RenderWindow::RenderWindow(const char* windowTitle, int width, int height)
		:m_window(NULL), m_renderer(NULL), m_rect()
	{
		m_window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_SHOWN);

		if (m_window == NULL)
			std::cout << "Window Initialization Failed. Error: " << SDL_GetError() << std::endl;

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

		if (m_renderer == NULL)
			std::cout << "Renderer Initialization Failed. Error: " << SDL_GetError() << std::endl;
	}

	void RenderWindow::ClearScreen()
	{
		SDL_RenderClear(m_renderer);
	}

	int RenderWindow::GetRefreshRate()
	{
		int displayIndex = SDL_GetWindowDisplayIndex(m_window);

		SDL_DisplayMode mode;

		SDL_GetDisplayMode(displayIndex, 0, &mode);

		return mode.refresh_rate;
	}

	void RenderWindow::DisplayDebugInfo(const char* fontPath)
	{
		int refreshRate = GetRefreshRate();
		std::string displayRefreshRate = "Refresh Rate: " + std::to_string(refreshRate);

		//TODO: Make surface/message member variables (Make toggleable debug info)
		TTF_Font* font = TTF_OpenFont(fontPath, 24);

		if (font == NULL)
			std::cout << "Font Error: " << TTF_GetError() << std::endl;

		SDL_Color White = { 255, 255, 255 };
		SDL_Surface* surfaceMessage =
			TTF_RenderText_Solid(font, displayRefreshRate.c_str(), White);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);

		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 0;  //controls the rect's x coordinate 
		Message_rect.y = 0; // controls the rect's y coordinte
		Message_rect.w = 120; // controls the width of the rect
		Message_rect.h = 40; // controls the height of the rect

		SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
	}

	SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
	{
		SDL_Texture* texture = NULL;
		texture = IMG_LoadTexture(m_renderer, filePath);

		if (texture == NULL)
		{
			std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
			std::cout << "Failed to load texture. Error: " << IMG_GetError() << std::endl;
		}
			

		return texture;
	}

	void RenderWindow::RenderTexture(SDL_Texture* p_texture)
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

	void RenderWindow::RenderEntity(Entity& entity)
	{
		SDL_Rect entityCurrentFrame = entity.GetCurrentFrame();
		int sizeMultiplier = 1;

		SDL_Rect entitySrc;
		entitySrc.x = entityCurrentFrame.x;
		entitySrc.y = entityCurrentFrame.y;
		entitySrc.w = entityCurrentFrame.w;
		entitySrc.h = entityCurrentFrame.h;

		//TODO: Make GetPosition better, getting member variable off function call is cringe
		SDL_Rect entityDest;
		entityDest.x = entity.GetPosition().x * sizeMultiplier;
		entityDest.y = entity.GetPosition().y * sizeMultiplier;
		entityDest.w = entityCurrentFrame.w * sizeMultiplier;
		entityDest.h = entityCurrentFrame.h * sizeMultiplier;

		SDL_RenderCopy(m_renderer, entity.GetTexture(), &entitySrc, &entityDest);
	}

	void RenderWindow::DisplayTextures()
	{
		SDL_RenderPresent(m_renderer);
	}

	void RenderWindow::CleanUp()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
	}

	#pragma region Rect Demo Functions

	void RenderWindow::DrawBackground()
	{
		SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
		SDL_RenderClear(m_renderer);
		SDL_RenderPresent(m_renderer);
	}

	void RenderWindow::InitRect(int x_pos, int y_pos, int width, int height)
	{
		m_rect.x = x_pos;
		m_rect.y = y_pos;
		m_rect.w = width;
		m_rect.h = height;
	}

	void RenderWindow::MoveRect(int x_pos, int y_pos)
	{
		m_rect.x = x_pos;
		m_rect.y = y_pos;
	}


	void RenderWindow::DrawRect()
	{
		SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(m_renderer, &m_rect);
		SDL_RenderPresent(m_renderer);
	}

	#pragma endregion

}