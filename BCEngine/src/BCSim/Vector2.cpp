#include "Vector2.h"

namespace BCSim
{
	Vector2::Vector2()
		:x(0.0), y(0.0)
	{}

	Vector2::Vector2(double x, double y)
		: x(x), y(y)
	{}

	#pragma region Binary Arithmetic Operator Methods

	//Methods return *this because by default 'this' in cpp returns a pointer to the current object
	//so by dereferencing it you get a reference to the current object instead which is what we want

	Vector2& Vector2::Add(const Vector2& vec)
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vector2& Vector2::Subtract(const Vector2& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	Vector2& Vector2::Multiply(const Vector2& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;

		return *this;
	}

	Vector2& Vector2::Divide(const Vector2& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;

		return *this;
	}

	#pragma endregion

	#pragma region Binary/Compound Arithmetic Operator Overloads (+-*/=)

	//Maybe switch these to use same code as above?
	//Code duplication is cringe but so is doing a ton of function calls during basic operations
	//that'll need to be done thousands of times per second

	Vector2& operator+(Vector2& vec1, const Vector2& vec2)
	{
		return vec1.Add(vec2);
	}

	Vector2& operator-(Vector2& vec1, const Vector2& vec2)
	{
		return vec1.Subtract(vec2);
	}

	Vector2& operator*(Vector2& vec1, const Vector2& vec2)
	{
		return vec1.Multiply(vec2);
	}

	Vector2& operator/(Vector2& vec1, const Vector2& vec2)
	{
		return vec1.Divide(vec2);
	}

	Vector2& Vector2::operator+=(const Vector2& vec)
	{
		return this->Add(vec);
	}

	Vector2& Vector2::operator-=(const Vector2& vec)
	{
		return this->Subtract(vec);
	}

	Vector2& Vector2::operator*=(const Vector2& vec)
	{
		return this->Multiply(vec);
	}

	Vector2& Vector2::operator/=(const Vector2& vec)
	{
		return this->Divide(vec);
	}

	#pragma endregion

	#pragma region Integer Scaling Operator Overloads

	Vector2& Vector2::operator*(const int& i)
	{
		this->x *= i;
		this->y *= i;

		return *this;
	}

	Vector2& Vector2::operator/(const int& i)
	{
		this->x /= i;
		this->y /= i;

		return *this;
	}

	#pragma endregion

	Vector2& Vector2::Zero()
	{
		this->x = 0;
		this->y = 0;

		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
	{
		stream << "(" << vec.x << ", " << vec.y << ")";
		return stream;
	}

	void Vector2::PrintData()
	{
		std::cout << *this << std::endl;
	}
}