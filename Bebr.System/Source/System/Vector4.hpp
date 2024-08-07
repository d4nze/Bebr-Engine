#pragma once
#include <cstdint>

namespace Bebr
{
namespace System
{
template<typename T>
struct Vector4
{
    T x, y, z, w;

    Vector4();
    Vector4(T x, T y, T z, T w);
    Vector4(const Vector4<T>& other);
    template<typename U>
    Vector4(const Vector4<U>& other);
};

typedef Vector4<float> Vector4F_t;
typedef Vector4<std::int32_t> Vector4I_t;
typedef Vector4<std::uint32_t> Vector4U_t;

template<typename T>
constexpr Vector4<T> operator-(Vector4<T> right);

template<typename T>
constexpr Vector4<T> operator+(Vector4<T> left, Vector4<T> right);
template<typename T>
constexpr Vector4<T> operator-(Vector4<T> left, Vector4<T> right);
template<typename T>
constexpr Vector4<T> operator*(Vector4<T> left, T right);
template<typename T>
constexpr Vector4<T> operator/(Vector4<T> left, T right);
template<typename T>
constexpr Vector4<T> operator*(T left, Vector4<T> right);
template<typename T>
constexpr Vector4<T> operator/(T left, Vector4<T> right);

template<typename T>
constexpr Vector4<T>& operator+=(Vector4<T>& left, Vector4<T> right);
template<typename T>
constexpr Vector4<T>& operator-=(Vector4<T>& left, Vector4<T> right);
template<typename T>
constexpr Vector4<T>& operator*=(Vector4<T>& left, T right);
template<typename T>
constexpr Vector4<T>& operator/=(Vector4<T>& left, T right);
template<typename T>
constexpr Vector4<T>& operator*=(T left, Vector4<T>& right);
template<typename T>
constexpr Vector4<T>& operator/=(T left, Vector4<T>& right);

template<typename T>
constexpr bool operator==(Vector4<T> left, Vector4<T> right);
template<typename T>
constexpr bool operator!=(Vector4<T> left, Vector4<T> right);
}
}

#include <System/Vector4.inl>