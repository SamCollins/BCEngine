#include "Entity.h";

namespace BCCore
{
	Entity::Entity(BCSim::Vector2f position, SDL_Texture* texture)
		:position(position), texture(texture)
	{
		SDL_Point textureSize;
		SDL_QueryTexture(texture, NULL, NULL, &textureSize.x, &textureSize.y);

		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = textureSize.x;
		currentFrame.h = textureSize.y;
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

	BCSim::Vector2f& Entity::GetPosition()
	{
		return position;
	}

	void Entity::UpdatePosition(float deltaTime)
	{
		float speed = 2 * deltaTime;
		position.y += position.y * speed;
	}

	SDL_Rect Entity::GetCurrentFrame()
	{
		return currentFrame;
	}

	SDL_Texture* Entity::GetTexture()
	{
		return texture;
	}

	#pragma endregion
}