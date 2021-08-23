#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

namespace BCEngine
{
	class RenderWindow
	{
	public:
		RenderWindow(const char* windowTitle, int width, int height);
		SDL_Texture* LoadTexture(const char* filePath);

		//Test Rect Functions
		void DrawBackground();
		void InitRect(int x_pos, int y_pos, int width, int height);
		void MoveRect(int x_pos, int y_pos);
		void DrawRect();

		void CleanUp();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		SDL_Rect m_rect;
	};
}