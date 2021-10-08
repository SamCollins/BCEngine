#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../BCSim/Vector2.h"

namespace BCCore
{
	class Entity
	{
	public:
		Entity(const std::string& name, const BCSim::Vector2& position, SDL_Texture* texture);

		//Might delete this, maybe just changed a lot, do const & for force
		void CalculatePosition(BCSim::Vector2 force, double deltaTime);
		void CalculatePosition(double deltaTime);
		bool CheckCollision(const BCCore::Entity& other);

		std::string GetName() const;
		void SetName(const std::string& name);
		BCSim::Vector2 GetPosition() const;
		void SetPosition(const BCSim::Vector2& position);
		BCSim::Vector2 GetVelocity() const;
		void SetVelocity(const BCSim::Vector2& velocity);
		SDL_Rect GetCurrentFrame() const;
		SDL_Texture* GetTexture() const;
	private:
		std::string m_name;
		BCSim::Vector2 m_position;
		BCSim::Vector2 m_velocity;
		SDL_Rect m_currentFrame;
		SDL_Texture* m_texture;
	};
}