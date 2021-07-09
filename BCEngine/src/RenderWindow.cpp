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

	void RenderWindow::CleanUp()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
	}
}