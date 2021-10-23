#include "Environment.h"

namespace BCSim
{
	Environment::Environment(int width, int height, int floorHeight)
		:m_width(width), m_height(height), m_floorHeight(floorHeight)
	{
		//Vector2 m_gravity(0.0, 2.0);
		m_gravity = Vector2(0, 50);
		m_friction = Vector2(0.9, 0.9);
	}

	void Environment::ApplyFriction(BCCore::Entity* entity)
	{
		Vector2 currentVelocity = entity->GetVelocity();
		Vector2 newVelocity = currentVelocity * m_friction;

		if (std::abs(newVelocity.x) > 0 && std::abs(newVelocity.x) < 0.1)
			newVelocity.x = 0;

		if (std::abs(newVelocity.y) > 0 && std::abs(newVelocity.y) < 0.1)
			newVelocity.y = 0;

		entity->SetVelocity(newVelocity);
	}

	void Environment::SetGravity(const Vector2& gravityValue)
	{
		m_gravity = gravityValue;
	}

	void Environment::AddEntity(BCCore::Entity* entity, bool applyGravity)
	{
		if (applyGravity)
			entity->SetVelocity(m_gravity);

		m_entities.push_back(entity);
	}

	void Environment::UpdateEntities(double deltaTime)
	{
		for (auto& entity : m_entities)
		{
			/*Vector2 test = entity->GetVelocity();
			entity->SetVelocity(test * m_friction);*/
			ApplyFriction(entity);
			entity->CalculatePosition(deltaTime);
			CheckCollisions(entity);
		}
	}

	void Environment::CheckCollisions(BCCore::Entity* entity)
	{
		for (auto other : m_entities)
		{
			//Need Vector2 == operator overload so this isn't cringe
			if (entity->GetPosition().x != other->GetPosition().x 
				&& entity->GetPosition().y != other->GetPosition().y)
			{
				if (entity->CheckCollision(*other))
				{
					//std::cout << entity->GetName() << " & " << other->GetName() << " Hit" << std::endl;
					//entity->SetVelocity(BCSim::Vector2(0, 0));
					ResolveCollision(entity, other);
				}
				else
				{
					//std::cout << "No Collision" << std::endl;
				}
			}
		}
	}

	void Environment::ResolveCollision(BCCore::Entity* entity, BCCore::Entity* other)
	{
		entity->SetVelocity(BCSim::Vector2(0, 0));
	}

	void Environment::PrintEntities() const
	{
		for (auto entity : m_entities)
		{
			entity->GetPosition().PrintData();
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