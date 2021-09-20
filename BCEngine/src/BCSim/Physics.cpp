#include "Physics.h"

namespace BCSim
{
	Vector2d::Vector2d()
		:x(0.0f), y(0.0f)
	{}

	Vector2d::Vector2d(float x, float y)
		:x(x), y(y)
	{}

	void Vector2d::PrintData()
	{
		std::cout << x << ", " << y << std::endl;
	}
}