#pragma once

#include <iostream>

namespace BCSim
{
	//TODO: Rename this (Maybe Double_Vector? will get confusing with actual 2D vector)
	//Or rework to use doubles, going back to Vector2f for now
	class Vector2f
	{
	public:
		Vector2f();
		Vector2f(float x, float y);
		void PrintData();
		float x, y;
	};
}
