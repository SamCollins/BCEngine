#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../BCSim/Physics.h"

namespace BCCore
{
	class Entity
	{
	public:
		Entity(BCSim::Vector2d position, SDL_Texture* texture);

		/*double GetXPosition();
		double GetYPosition();*/
		BCSim::Vector2d& GetPosition();
		void CalculatePosition(BCSim::Vector2d force, double deltaTime);
		void UpdatePosition(BCSim::Vector2d position);
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		//double x_pos, y_pos;
		BCSim::Vector2d m_position;
		SDL_Rect m_currentFrame;
		SDL_Texture* m_texture;
	};
}