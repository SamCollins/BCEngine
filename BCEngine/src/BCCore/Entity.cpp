#include "Entity.h";

namespace BCCore
{
	Entity::Entity(const std::string& name, const BCSim::Vector2& position, SDL_Texture* texture)
		:m_name(name), m_position(position), m_velocity(BCSim::Vector2(0, 0)), m_maxVelocity(BCSim::Vector2(40, 40)),
		m_texture(texture)
	{
		SDL_Point textureSize;
		SDL_QueryTexture(texture, NULL, NULL, &textureSize.x, &textureSize.y);

		m_currentFrame.x = 0;
		m_currentFrame.y = 0;
		m_currentFrame.w = textureSize.x;
		m_currentFrame.h = textureSize.y;
	}

	//Add ApplyForce method here (Add external force to current velocity)

	void Entity::CalculatePosition(BCSim::Vector2 force, double deltaTime)
	{
		//TODO: Figure out what to do here

		double horizontalForce = force.x * deltaTime;
		double verticalForce = force.y * deltaTime;

		//This rapidly accelerates
		/*m_position.x += m_position.x * horizontalForce;
		m_position.y += m_position.y * verticalForce;*/

		m_position.x += horizontalForce;
		m_position.y += verticalForce;

		//Vector2 newPostion();
	}

	void Entity::CalculatePosition(double deltaTime)
	{
		double horizontalForce = m_velocity.x * deltaTime;
		double verticalForce = m_velocity.y * deltaTime;

		m_position.x += horizontalForce;
		m_position.y += verticalForce;
	}

	void Entity::AddForce(const BCSim::Vector2& force)
	{
		if (m_velocity.x < m_maxVelocity.x || m_velocity.y < m_maxVelocity.y)
			m_velocity += force;

		if (m_velocity.x > m_maxVelocity.x)
			m_velocity.x = m_maxVelocity.x;

		if (m_velocity.y > m_maxVelocity.y)
			m_velocity.y = m_maxVelocity.y;
	}

	//TODO: Make method for figuring out what direction collision is happening
	//Also maybe enum class for collision directions?
	//Then make method for zeroing out velocity in certain direction like v * Vec2(0, 1)
	//to keep one direction the same but get rid of direction where coll is

	bool Entity::CheckCollision(const BCCore::Entity& other) const
	{
		BCSim::Vector2 otherPos = other.GetPosition();
		SDL_Rect otherFrame = other.GetCurrentFrame();

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

	#pragma region Getters/Setters

	std::string Entity::GetName() const
	{
		return m_name;
	}

	void Entity::SetName(const std::string& name)
	{
		m_name = name;
	}

	BCSim::Vector2 Entity::GetPosition() const
	{
		return m_position;
	}

	void Entity::SetPosition(const BCSim::Vector2& position)
	{
		m_position = position;
	}

	BCSim::Vector2 Entity::GetVelocity() const
	{
		return m_velocity;
	}

	void Entity::SetVelocity(const BCSim::Vector2& velocity)
	{
		m_velocity = velocity;
	}

	SDL_Rect Entity::GetCurrentFrame() const
	{
		return m_currentFrame;
	}

	SDL_Texture* Entity::GetTexture() const
	{
		return m_texture;
	}

	#pragma endregion

}