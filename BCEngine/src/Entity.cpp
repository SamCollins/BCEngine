#include "Entity.h";

namespace BCEngine
{
	Entity::Entity(double x_pos, double y_pos, SDL_Texture* texture)
		:x_pos(x_pos), y_pos(y_pos), texture(texture)
	{
		//TODO: Make this better, maybe pass Rect in through params
		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 32;
		currentFrame.h = 32;
	}

	#pragma region Getters

	double Entity::GetXPosition()
	{
		return x_pos;
	}

	double Entity::GetYPosition()
	{
		return y_pos;
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