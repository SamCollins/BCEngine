#pragma once

#include <iostream>

namespace BCSim
{
	class Vector2
	{
	public:
		double x;
		double y;

		Vector2();
		Vector2(double x, double y);

		Vector2& Add(const Vector2& vec);
		Vector2& Subtract(const Vector2& vec);
		Vector2& Multiply(const Vector2& vec);
		Vector2& Divide(const Vector2& vec);

		//TODO: Maybe change these to be lhs_vec/rhs_vec or something other than 1,2
		friend Vector2& operator+(Vector2& vec1, const Vector2& vec2);
		friend Vector2& operator-(Vector2& vec1, const Vector2& vec2);
		friend Vector2& operator*(Vector2& vec1, const Vector2& vec2);
		friend Vector2& operator/(Vector2& vec1, const Vector2& vec2);

		Vector2& operator+=(const Vector2& vec);
		Vector2& operator-=(const Vector2& vec);
		Vector2& operator*=(const Vector2& vec);
		Vector2& operator/=(const Vector2& vec);

		//Maybe add +- here if applicable, */ used for scaling purposes
		Vector2& operator*(const int& i);
		Vector2& operator/(const int& i);

		Vector2& Zero();

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);

		void PrintData();
	};
}
