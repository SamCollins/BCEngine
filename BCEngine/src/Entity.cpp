#include "Entity.h";

namespace BCEngine
{
	Entity::Entity(Vector2f position, SDL_Texture* texture)
		:position(position), texture(texture)
	{
		//TODO: Make this better, maybe pass Rect in through params
		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 32;
		currentFrame.h = 32;
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

	Vector2f& Entity::GetPosition()
	{
		return position;
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