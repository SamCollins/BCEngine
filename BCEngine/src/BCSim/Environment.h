#pragma once

#include <SDL.h>
#include <vector>

#include "Vector2.h"

#include "../BCCore/Entity.h"

namespace BCSim
{
	//TODO: Possible memory leak in entities vector
	//Also should figure out how to use references instead of pointers
	//Maybe convert to smart pointers??
	class Environment
	{
	public:
		Environment(int width, int height, int floorHeight);

		void SetGravity(const Vector2& gravityValue);
		void AddEntity(BCCore::Entity* entity, bool applyGravity);
		void UpdateEntities(double deltaTime);
		void CheckCollisions(BCCore::Entity* entity);
		void ResolveCollision(BCCore::Entity* entity, BCCore::Entity* other);

		void PrintEntities() const;

		//~Environment();
	private:
		int m_width;
		int m_height;
		int m_floorHeight;
		Vector2 m_gravity;
		std::vector<BCCore::Entity*> m_entities;
	};
}