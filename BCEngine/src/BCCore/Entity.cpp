#include "Entity.h";

namespace BCCore
{
	Entity::Entity(std::string name, BCSim::Vector2d position, SDL_Texture* texture)
		:m_name(name), m_position(position), m_velocity(BCSim::Vector2d(0, 0)), m_texture(texture)
	{
		SDL_Point textureSize;
		SDL_QueryTexture(texture, NULL, NULL, &textureSize.x, &textureSize.y);

		m_currentFrame.x = 0;
		m_currentFrame.y = 0;
		m_currentFrame.w = textureSize.x;
		m_currentFrame.h = textureSize.y;
	}

	#pragma region Getters

	std::string Entity::GetName()
	{
		return m_name;
	}

	BCSim::Vector2d& Entity::GetPosition()
	{
		return m_position;
	}
	
	//Add ApplyForce method here (Add external force to current velocity)

	void Entity::CalculatePosition(BCSim::Vector2d force, double deltaTime)
	{
		//TODO: Figure out what to do here

		double horizontalForce = force.x * deltaTime;
		double verticalForce = force.y * deltaTime;

		//This rapidly accelerates
		/*m_position.x += m_position.x * horizontalForce;
		m_position.y += m_position.y * verticalForce;*/

		m_position.x += horizontalForce;
		m_position.y += verticalForce;

		//Vector2d newPostion();
	}

	void Entity::CalculatePosition(double deltaTime)
	{
		double horizontalForce = m_velocity.x * deltaTime;
		double verticalForce = m_velocity.y * deltaTime;

		m_position.x += horizontalForce;
		m_position.y += verticalForce;
	}

	void Entity::UpdatePosition(BCSim::Vector2d position)
	{
		position = position;
	}

	bool Entity::CheckCollision(BCCore::Entity* other)
	{
		BCSim::Vector2d otherPos = other->GetPosition();
		SDL_Rect otherFrame = other->GetCurrentFrame();

		bool collDetected =
			m_position.x < otherPos.x + otherFrame.w &&
			m_position.x + m_currentFrame.w > otherPos.x &&
			m_position.y < otherPos.y + otherFrame.h &&
			m_position.y + m_currentFrame.h > otherPos.y;

		//bool horizontalColl = (m_position.x + m_currentFrame.w) - (otherPos.x + otherFrame.w) <= 0;
		//bool verticalColl = (m_position.y + m_currentFrame.h) - (otherPos.y + otherFrame.h) <= 0;

		//return horizontalColl || verticalColl;
		return collDetected;
	}

	BCSim::Vector2d& Entity::GetVelocity()
	{
		return m_velocity;
	}

	void Entity::SetVelocity(BCSim::Vector2d velocity)
	{
		m_velocity = velocity;
	}

	SDL_Rect Entity::GetCurrentFrame()
	{
		return m_currentFrame;
	}

	SDL_Texture* Entity::GetTexture()
	{
		return m_texture;
	}

	#pragma endregion
}