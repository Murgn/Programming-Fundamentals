#pragma once
#include <ostream>

class Vector2
{
public:
	int x;
	int y;

	Vector2(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	// Copy Constructor
	Vector2(const Vector2& vector2)
	{
		this->x = vector2.x;
		this->y = vector2.y;
	}

	Vector2 operator+(const Vector2& other);

	Vector2 operator-(const Vector2& other);

	Vector2 operator-();

	Vector2 operator*(const Vector2& other);

	Vector2 operator*(const float& other);

	// Copy assignment
	Vector2& operator=(const Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, Vector2 const& v);

	static float Dot(const Vector2& vec1, const Vector2& vec2);

	float Magnitude();

	void Normalize();

	Vector2 Normalized();

	static Vector2 Distance(Vector2& vec1, Vector2& vec2);
};