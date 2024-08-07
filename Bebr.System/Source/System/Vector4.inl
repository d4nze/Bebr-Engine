#include "Vector4.hpp"

template<typename T>
inline Bebr::System::Vector4<T>::Vector4()
    : x(static_cast<T>(0))
    , y(static_cast<T>(0))
    , z(static_cast<T>(0))
    , w(static_cast<T>(0))
{}

template<typename T>
inline Bebr::System::Vector4<T>::Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
{}

template<typename T>
inline Bebr::System::Vector4<T>::Vector4(const Vector4<T>& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(other.w)
{}

template<typename T>
template<typename U>
inline Bebr::System::Vector4<T>::Vector4(const Vector4<U>& other)
    : x(static_cast<T>(other.x))
    , y(static_cast<T>(other.y))
    , z(static_cast<T>(other.z))
    , w(static_cast<T>(other.w))
{}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator-(Vector4<T> right)
{
    return Vector4<T>(-right.x, -right.y, -right.z, -right.w);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator+(Vector4<T> left, Vector4<T> right)
{
    return Vector4<T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator-(Vector4<T> left, Vector4<T> right)
{
    return Vector4<T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator*(Vector4<T> left, T right)
{
    return Vector4<T>(left.x * right, left.y * right, left.z * right, left.w * right);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator/(Vector4<T> left, T right)
{
    return Vector4<T>(left.x / right, left.y / right, left.z / right, left.w / right);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator*(T left, Vector4<T> right)
{
    return Vector4<T>(left * right.x, left * right.y, left * right.z, left * right.w);
}

template<typename T>
constexpr Bebr::System::Vector4<T> Bebr::System::operator/(T left, Vector4<T> right)
{
    return Vector4<T>(left / right.x, left / right.y, left / right.z, left / right.w);
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator+=(Vector4<T>& left, Vector4<T> right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator-=(Vector4<T>& left, Vector4<T> right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator*=(Vector4<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator/=(Vector4<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator*=(T left, Vector4<T>& right)
{
    right.x *= left;
    right.y *= left;
    right.z *= left;
    right.w *= left;
    return right;
}

template<typename T>
constexpr Bebr::System::Vector4<T>& Bebr::System::operator/=(T left, Vector4<T>& right)
{
    right.x /= left;
    right.y /= left;
    right.z /= left;
    right.w /= left;
    return right;
}

template<typename T>
constexpr bool Bebr::System::operator==(Vector4<T> left, Vector4<T> right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

template<typename T>
constexpr bool Bebr::System::operator!=(Vector4<T> left, Vector4<T> right)
{
    return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w;
}
