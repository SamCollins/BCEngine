#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../BCSim/Vector2.h"

namespace BCCore
{
	class Entity
	{
	public:
		Entity(std::string name, BCSim::Vector2 position, SDL_Texture* texture);

		void CalculatePosition(BCSim::Vector2 force, double deltaTime);
		void CalculatePosition(double deltaTime);
		bool CheckCollision(BCCore::Entity* other);

		std::string GetName();
		void SetName(std::string name);
		BCSim::Vector2& GetPosition();
		void SetPosition(BCSim::Vector2 position);
		BCSim::Vector2& GetVelocity();
		void SetVelocity(BCSim::Vector2 velocity);
		SDL_Rect GetCurrentFrame();
		SDL_Texture* GetTexture();
	private:
		std::string m_name;
		BCSim::Vector2 m_position;
		BCSim::Vector2 m_velocity;
		SDL_Rect m_currentFrame;
		SDL_Texture* m_texture;
	};
}