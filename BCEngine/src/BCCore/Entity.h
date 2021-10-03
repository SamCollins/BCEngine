#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../BCSim/Physics.h"

namespace BCCore
{
	class Entity
	{
	public:
		Entity(std::string name, BCSim::Vector2d position, SDL_Texture* texture);

		std::string GetName();
		BCSim::Vector2d& GetPosition();
		void CalculatePosition(BCSim::Vector2d force, double deltaTime);
		void CalculatePosition(double deltaTime);
		void UpdatePosition(BCSim::Vector2d position);
		bool CheckCollision(BCCore::Entity* other);
		BCSim::Vector2d& GetVelocity();
		void SetVelocity(BCSim::Vector2d velocity);
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		//double x_pos, y_pos;
		std::string m_name;
		BCSim::Vector2d m_position;
		BCSim::Vector2d m_velocity;
		SDL_Rect m_currentFrame;
		SDL_Texture* m_texture;
	};
}