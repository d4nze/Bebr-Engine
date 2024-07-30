#pragma once
#include <cstdint>

namespace Bebr
{
namespace System
{
template<typename T>
struct Vector3
{
    T x, y, z;

    Vector3();
    Vector3(T x, T y, T z);
    Vector3(const Vector3<T>& other);
    template<typename U>
    Vector3(const Vector3<U>& other);
};

typedef Vector3<float> Vector3F_t;
typedef Vector3<std::int32_t> Vector3I_t;
typedef Vector3<std::uint32_t> Vector3U_t;

template<typename T>
constexpr Vector3<T> operator-(Vector3<T> right);

template<typename T>
constexpr Vector3<T> operator+(Vector3<T> left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator-(Vector3<T> left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator*(Vector3<T> left, T right);
template<typename T>
constexpr Vector3<T> operator/(Vector3<T> left, T right);
template<typename T>
constexpr Vector3<T> operator*(T left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator/(T left, Vector3<T> right);

template<typename T>
constexpr Vector3<T> operator+=(Vector3<T> left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator-=(Vector3<T> left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator*=(Vector3<T> left, T right);
template<typename T>
constexpr Vector3<T> operator/=(Vector3<T> left, T right);
template<typename T>
constexpr Vector3<T> operator*=(T left, Vector3<T> right);
template<typename T>
constexpr Vector3<T> operator/=(T left, Vector3<T> right);

template<typename T>
constexpr bool operator==(Vector3<T> left, Vector3<T> right);
template<typename T>
constexpr bool operator!=(Vector3<T> left, Vector3<T> right);
}
}

#include <System/Vector3.inl>
