#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <format>

#include "../BCUtils.h"

#include "Entity.h"

namespace BCCore
{
	//TODO: Figure out which of these can be const methods
	//Do testing on if stuff like TTF_CloseFont(debugFont) breaks const
	//Probably wont ever end up in a situation where theres a const GameWindow?? but should do const
	//stuff as a good practice
	class GameWindow
	{
	public:
		GameWindow(const std::string& windowTitle, int width, int height);

		void InitDebugFont(const std::string& fontPath, int fontSize);
		void CloseDebugFont();

		void ClearScreen();
		int GetRefreshRate();
		std::string GetFpsDisplay(int currentFrame, int fpsCap);
		void DisplayDebugInfo(int currentFrame);

		SDL_Texture* LoadTexture(const std::string& filePath);
		void RenderTexture(SDL_Texture* p_texture);
		void RenderEntity(const Entity& entity);
		void DisplayTextures();

		void CleanUp();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		//Debug Info
		TTF_Font* m_debugInfoFont;
	};
}