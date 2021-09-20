#include "Entity.h";

namespace BCCore
{
	Entity::Entity(BCSim::Vector2d position, SDL_Texture* texture)
		:m_position(position), m_texture(texture)
	{
		SDL_Point textureSize;
		SDL_QueryTexture(texture, NULL, NULL, &textureSize.x, &textureSize.y);

		m_currentFrame.x = 0;
		m_currentFrame.y = 0;
		m_currentFrame.w = textureSize.x;
		m_currentFrame.h = textureSize.y;
	}

	#pragma region Getters

	/*double Entity::GetXPosition()
	{
		return x_pos;
	}

	double Entity::GetYPosition()
	{
		return y_pos;
	}*/

	BCSim::Vector2d& Entity::GetPosition()
	{
		return m_position;
	}

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

	void Entity::UpdatePosition(BCSim::Vector2d position)
	{
		position = position;
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