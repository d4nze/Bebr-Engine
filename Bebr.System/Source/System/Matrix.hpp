#pragma once
#include <array>
#include "Vector2.hpp"

namespace Bebr
{
namespace System
{
template<typename T>
class Column
{
public:
	Column(T* data);
	Column(const Column&) = default;
	~Column() = default;

public:
	T& operator[](int index);

private:
	T* m_data;
};

template<typename T>
class ConstColumn
{
public:
	ConstColumn(const T* data);
	~ConstColumn() = default;

public:
	const T& operator[](int index) const;

private:
	const T* m_data;
};

template<typename T, std::uint32_t width, std::uint32_t height>
class Matrix
{
public:
	Matrix(T value = 0);
	Matrix(const std::array<T, width* height>& data);
	Matrix(const Matrix& other) = default;
	~Matrix() = default;

public:
	void Fill(T value);

	std::uint32_t	GetWidth()	const;
	std::uint32_t	GetHeight() const;
	Vector2U_t		GetSize()	const;
	const T*		GetData()	const;

public:
	Column<T> operator[](int index);
	const ConstColumn<T> operator[](int index) const;

private:
	T m_data[width][height];
};

template<typename T>
using Matrix2_t		= Matrix<T, 2, 2>;
template<typename T>
using Matrix2x3_t	= Matrix<T, 2, 3>;
template<typename T>
using Matrix2x4_t	= Matrix<T, 2, 4>;
template<typename T>
using Matrix3x2_t	= Matrix<T, 3, 2>;
template<typename T>
using Matrix3_t		= Matrix<T, 3, 3>;
template<typename T>
using Matrix3x4_t	= Matrix<T, 3, 4>;
template<typename T>
using Matrix4x2_t	= Matrix<T, 4, 2>;
template<typename T>
using Matrix4x3_t	= Matrix<T, 4, 3>;
template<typename T>
using Matrix4_t		= Matrix<T, 4, 4>;

template<typename T, std::uint32_t size>
Matrix<T, size, size> CreateDiagonalMatrix(T value);
template<typename T, std::uint32_t size>
Matrix<T, size, size> CreateIdentityMatrix();

template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator-(const Matrix<T, width, height>& right);

template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator+(const Matrix<T, width, height>& left, const Matrix<T, width, height>& right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator-(const Matrix<T, width, height>& left, const Matrix<T, width, height>& right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator*(const Matrix<T, width, height> left, T right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator/(const Matrix<T, width, height> left, T right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height> operator*(T left, const Matrix<T, width, height> right);
template<typename T, std::uint32_t width, std::uint32_t height, std::uint32_t otherWidth>
Matrix<T, otherWidth, height> operator*(const Matrix<T, width, height>& left, const Matrix<T, otherWidth, width>& right);

template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height>& operator+=(Matrix<T, width, height>& left, const Matrix<T, width, height>& right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height>& operator-=(Matrix<T, width, height>& left, const Matrix<T, width, height>& right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height>& operator*=(Matrix<T, width, height>& left, T right);
template<typename T, std::uint32_t width, std::uint32_t height>
Matrix<T, width, height>& operator/=(Matrix<T, width, height>& left, T right);
template<typename T, std::uint32_t size>
Matrix<T, size, size>& operator*=(Matrix<T, size, size>& left, const Matrix<T, size, size>& right);
}
}

#include "Matrix.inl"
