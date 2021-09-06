#pragma once

#include <SDL.h>
#include <SDL_image.h>

namespace BCEngine
{
	class Entity
	{
	public:
		Entity(double x_pos, double y_pos, SDL_Texture* texture);

		double GetXPosition();
		double GetYPosition();
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		double x_pos, y_pos;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
	};
}