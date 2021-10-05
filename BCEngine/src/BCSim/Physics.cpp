#include "Physics.h"

namespace BCSim
{
	Vector2::Vector2()
		:x(0.0), y(0.0)
	{}

	Vector2::Vector2(double x, double y)
		:x(x), y(y)
	{}

	void Vector2::PrintData()
	{
		std::cout << x << ", " << y << std::endl;
	}
}