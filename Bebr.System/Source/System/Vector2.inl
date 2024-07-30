#include "Vector2.hpp"

template<typename T>
inline Bebr::System::Vector2<T>::Vector2()
	: x(static_cast<T>(0))
	, y(static_cast<T>(0))
{}

template<typename T>
inline Bebr::System::Vector2<T>::Vector2(T x, T y) : x(x), y(y)
{}

template<typename T>
inline Bebr::System::Vector2<T>::Vector2(const Vector2<T>& other)
	: x(other.x)
	, y(other.y)
{}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator-(Vector2<T> right)
{
	return Vector2<T>(-right.x, -right.y);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator+(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator-(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator*(Vector2<T> left, T right)
{
	return Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator/(Vector2<T> left, T right)
{
	return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator*(T left, Vector2<T> right)
{
	return Vector2<T>(left * right.x, left * right.y);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator/(T left, Vector2<T> right)
{
	return Vector2<T>(left / right.x, left / right.y);
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator+=(Vector2<T> left, Vector2<T> right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator-=(Vector2<T> left, Vector2<T> right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator*=(Vector2<T> left, T right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator/=(Vector2<T> left, T right)
{
	return Vector2<T>();
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator*=(T left, Vector2<T> right)
{
	right.x *= left;
	right.y *= left;
	return right;
}

template<typename T>
constexpr Bebr::System::Vector2<T> Bebr::System::operator/=(T left, Vector2<T> right)
{
	right.x /= left;
	right.y /= left;
	return right;
}

template<typename T>
constexpr bool Bebr::System::operator==(Vector2<T> left, Vector2<T> right)
{
	return left.x == right.x && left.y == right.y;
}

template<typename T>
constexpr bool Bebr::System::operator!=(Vector2<T> left, Vector2<T> right)
{
	return left.x != right.x || left.y != right.y;
}
