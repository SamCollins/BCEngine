#pragma once

#include <SDL.h>
#include <vector>

#include "Physics.h"

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

		void SetGravity(Vector2d gravityValue);
		void AddEntity(BCCore::Entity* entity);
		void UpdateEntities(double deltaTime);

		//~Environment();
	private:
		int m_width;
		int m_height;
		int m_floorHeight;
		Vector2d m_gravity;
		std::vector<BCCore::Entity*> m_entities;
	};
}