#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../BCSim/Physics.h"

namespace BCCore
{
	class Entity
	{
	public:
		Entity(BCSim::Vector2f position, SDL_Texture* texture);

		/*double GetXPosition();
		double GetYPosition();*/
		BCSim::Vector2f& GetPosition();
		void UpdatePosition(float deltaTime);
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		//double x_pos, y_pos;
		BCSim::Vector2f position;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
	};
}