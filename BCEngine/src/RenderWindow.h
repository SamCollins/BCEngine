#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <format>

#include "BCUtils.h"

#include "Entity.h";

namespace BCEngine
{
	class RenderWindow
	{
	public:
		RenderWindow(std::string windowTitle, int width, int height, std::string debugInfoFontPath);

		void ClearScreen();
		int GetRefreshRate();
		std::string GetFpsDisplay(int currentFrame, int fpsCap);
		void DisplayDebugInfo(int currentFrame);

		SDL_Texture* LoadTexture(std::string filePath);
		void RenderTexture(SDL_Texture* p_texture);
		void RenderEntity(Entity& entity);
		void DisplayTextures();

		void CleanUp();

		//Test Rect Functions
		void DrawBackground();
		void InitRect(int x_pos, int y_pos, int width, int height);
		void MoveRect(int x_pos, int y_pos);
		void DrawRect();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		SDL_Rect m_rect;

		//Debug Info
		TTF_Font* m_debugInfoFont;
	};
}