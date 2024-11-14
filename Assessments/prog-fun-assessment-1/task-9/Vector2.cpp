#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 temp = Vector2(x, y);

	temp.x += other.x;
	temp.y += other.y;

	return temp;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 temp = Vector2(x, y);

	temp.x += other.x;
	temp.y += other.y;

	return temp;
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator*(const Vector2& other)
{
	Vector2 temp = Vector2(x, y);

	temp.x *= other.x;
	temp.y *= other.y;

	return temp;
}

Vector2 Vector2::operator*(const float& other)
{
	Vector2 temp = Vector2(x, y);

	temp.x *= other;
	temp.y *= other;

	return temp;
}

Vector2& Vector2::operator=(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

std::ostream& operator<<(std::ostream& os, Vector2 const& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Vector2& v)
{
	char comma;
	is >> v.x >> comma >> v.y;

	if(comma != ',')
		is.setstate(std::ios::failbit); // Telling the user the input format is wrong

	return is;
}

float Vector2::Dot(const Vector2& vec1, const Vector2& vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

void Vector2::Normalize()
{
	float mag = this->Magnitude();
	x /= mag;
	y /= mag;
}

Vector2 Vector2::Normalized()
{
	float mag = this->Magnitude();
	float tempX = x / mag;
	float tempY = y / mag;
	return Vector2(tempX, tempY);
}

Vector2 Vector2::Distance(Vector2& vec1, Vector2& vec2)
{
	return (vec1 - vec2).Magnitude();
}
