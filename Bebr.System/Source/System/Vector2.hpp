#pragma once
#include <cstdint>

namespace Bebr
{
namespace System
{
template<typename T>
struct Vector2
{
	T x, y;

	Vector2();
	Vector2(T x, T y);
	Vector2(const Vector2<T>& other);
	template<typename U>
	Vector2(const Vector2<U>& other);
};

typedef Vector2<float> Vector2F_t;
typedef Vector2<std::int32_t> Vector2I_t;
typedef Vector2<std::uint32_t> Vector2U_t;

template<typename T>
constexpr Vector2<T> operator-(Vector2<T> right);

template<typename T>
constexpr Vector2<T> operator+(Vector2<T> left, Vector2<T> right);
template<typename T>
constexpr Vector2<T> operator-(Vector2<T> left, Vector2<T> right);
template<typename T>
constexpr Vector2<T> operator*(Vector2<T> left, T right);
template<typename T>
constexpr Vector2<T> operator/(Vector2<T> left, T right);
template<typename T>
constexpr Vector2<T> operator*(T left, Vector2<T> right);
template<typename T>
constexpr Vector2<T> operator/(T left, Vector2<T> right);

template<typename T>
constexpr Vector2<T>& operator+=(Vector2<T>& left, Vector2<T> right);
template<typename T>
constexpr Vector2<T>& operator-=(Vector2<T>& left, Vector2<T> right);
template<typename T>
constexpr Vector2<T>& operator*=(Vector2<T>& left, T right);
template<typename T>
constexpr Vector2<T>& operator/=(Vector2<T>& left, T right);
template<typename T>
constexpr Vector2<T>& operator*=(T left, Vector2<T>& right);
template<typename T>
constexpr Vector2<T>& operator/=(T left, Vector2<T>& right);

template<typename T>
constexpr bool operator==(Vector2<T> left, Vector2<T> right);
template<typename T>
constexpr bool operator!=(Vector2<T> left, Vector2<T> right);
}
}

#include <System/Vector2.inl>
