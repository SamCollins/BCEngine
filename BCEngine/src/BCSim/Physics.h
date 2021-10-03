#pragma once

#include <iostream>

namespace BCSim
{
	//TODO: Rename this (Maybe Double_Vector? will get confusing with actual 2D vector)
	//Or rework to use doubles, going back to Vector2f for now
	class Vector2d
	{
	public:
		//Add some operator overloads in here (Adding/Subtracting for Env/Entity ApplyForce)
		Vector2d();
		Vector2d(float x, float y);
		void PrintData();
		float x, y;
	};
}
