#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Physics.h"

namespace BCEngine
{
	class Entity
	{
	public:
		Entity(Vector2f position, SDL_Texture* texture);

		/*double GetXPosition();
		double GetYPosition();*/
		Vector2f& GetPosition();
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		//double x_pos, y_pos;
		Vector2f position;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
	};
}