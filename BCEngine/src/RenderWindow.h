#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>

#include "Entity.h";

namespace BCEngine
{
	class RenderWindow
	{
	public:
		RenderWindow(const char* windowTitle, int width, int height);

		//Texture Functions
		void ClearScreen();
		int GetRefreshRate();
		void DisplayDebugInfo(const char* fontPath);

		SDL_Texture* LoadTexture(const char* filePath);
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
	};
}