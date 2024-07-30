#include "Vector3.hpp"

template<typename T>
inline Bebr::System::Vector3<T>::Vector3()
    : x(static_cast<T>(0))
    , y(static_cast<T>(0))
    , z(static_cast<T>(0))
{}

template<typename T>
inline Bebr::System::Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z)
{}

template<typename T>
inline Bebr::System::Vector3<T>::Vector3(const Vector3<T>& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
{}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator-(Vector3<T> right)
{
    return Vector3<T>(-right.x, -right.y, -right.z);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator+(Vector3<T> left, Vector3<T> right)
{
    return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator-(Vector3<T> left, Vector3<T> right)
{
    return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator*(Vector3<T> left, T right)
{
    return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator/(Vector3<T> left, T right)
{
    return Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator*(T left, Vector3<T> right)
{
    return Vector3<T>(left * right.x, left * right.y, left * right.z);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator/(T left, Vector3<T> right)
{
    return Vector3<T>(left / right.x, left / right.y, left / right.z);
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator+=(Vector3<T> left, Vector3<T> right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator-=(Vector3<T> left, Vector3<T> right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator*=(Vector3<T> left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator/=(Vector3<T> left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator*=(T left, Vector3<T> right)
{
    right.x *= left;
    right.y *= left;
    right.z *= left;
    return right;
}

template<typename T>
constexpr Bebr::System::Vector3<T> Bebr::System::operator/=(T left, Vector3<T> right)
{
    right.x /= left;
    right.y /= left;
    right.z /= left;
    return right;
}

template<typename T>
constexpr bool Bebr::System::operator==(Vector3<T> left, Vector3<T> right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

template<typename T>
constexpr bool Bebr::System::operator!=(Vector3<T> left, Vector3<T> right)
{
    return left.x != right.x || left.y != right.y || left.z != right.z;
}
