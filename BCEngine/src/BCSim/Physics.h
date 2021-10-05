#pragma once

#include <iostream>

namespace BCSim
{
	class Vector2
	{
	public:
		//Add some operator overloads in here (Adding/Subtracting for Env/Entity ApplyForce)
		Vector2();
		Vector2(double x, double y);
		void PrintData();
		double x, y;
	};
}
