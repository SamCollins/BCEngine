#include "Environment.h"

namespace BCSim
{
	Environment::Environment(int width, int height, int floorHeight)
		:m_width(width), m_height(height), m_floorHeight(floorHeight)
	{
		//Vector2d m_gravity(0.0, 2.0);
		m_gravity = Vector2d(-10, 10);
	}

	void Environment::SetGravity(Vector2d gravityValue)
	{
		m_gravity = gravityValue;
	}

	void Environment::AddEntity(BCCore::Entity* entity)
	{
		m_entities.push_back(entity);
	}

	void Environment::UpdateEntities(double deltaTime)
	{
		for (auto entity : m_entities)
		{
			entity->CalculatePosition(m_gravity, deltaTime);
		}
	}

	/*Environment::~Environment()
	{
		for (auto entity : m_entities)
		{
			delete entity;
		}
	}*/
}