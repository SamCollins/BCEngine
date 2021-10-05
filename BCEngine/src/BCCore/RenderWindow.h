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
	class RenderWindow
	{
	public:
		RenderWindow(std::string windowTitle, int width, int height);

		void InitDebugFont(std::string fontPath, int fontSize);
		void CloseDebugFont();

		void ClearScreen();
		int GetRefreshRate();
		std::string GetFpsDisplay(int currentFrame, int fpsCap);
		void DisplayDebugInfo(int currentFrame);

		SDL_Texture* LoadTexture(std::string filePath);
		void RenderTexture(SDL_Texture* p_texture);
		void RenderEntity(Entity& entity);
		void DisplayTextures();

		void CleanUp();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		//Debug Info
		TTF_Font* m_debugInfoFont;
	};
}