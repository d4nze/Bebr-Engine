#include "Matrix.hpp"

template<typename T>
inline Bebr::System::Column<T>::Column(T* data) : m_data(data)
{}

template<typename T>
inline T& Bebr::System::Column<T>::operator[](int index)
{
	return m_data[index];
}

template<typename T>
inline Bebr::System::ConstColumn<T>::ConstColumn(const T* data) : m_data(data)
{}

template<typename T>
inline const T& Bebr::System::ConstColumn<T>::operator[](int index) const
{
	return m_data[index];
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline Bebr::System::Matrix<T, width, height>::Matrix(T value)
{
	Fill(value);
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline Bebr::System::Matrix<T, width, height>::Matrix(const std::array<T, width* height>& data)
{

	const std::uint32_t size = width * height;
	for (std::uint32_t i = 0; i < size; i++)
	{
		std::uint32_t x = i % width;
		std::uint32_t y = i / width;
		m_data[x][y] = data[i];
	}
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline void Bebr::System::Matrix<T, width, height>::Fill(T value)
{
	for (auto& column : m_data)
	{
		for (auto& element : column)
		{
			element = value;
		}
	}
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline std::uint32_t Bebr::System::Matrix<T, width, height>::GetWidth() const
{
	return width;
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline std::uint32_t Bebr::System::Matrix<T, width, height>::GetHeight() const
{
	return height;
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline Bebr::System::Vector2U_t Bebr::System::Matrix<T, width, height>::GetSize() const
{
	return Vector2U_t(width, height);
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline const T* Bebr::System::Matrix<T, width, height>::GetData() const
{
	return &m_data[0][0];
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline Bebr::System::Column<T> Bebr::System::Matrix<T, width, height>::operator[](int index)
{
	return Column<T>(m_data[index]);
}

template<typename T, std::uint32_t width, std::uint32_t height>
inline const Bebr::System::ConstColumn<T> Bebr::System::Matrix<T, width, height>::operator[](int index) const
{
	return ConstColumn<T>(m_data[index]);
}

template<typename T, std::uint32_t size>
Bebr::System::Matrix<T, size, size> Bebr::System::CreateDiagonalMatrix(T value)
{
	Matrix<T, size, size> matrix;
	for (std::uint32_t i = 0; i < size; i++)
		matrix[i][i] = value;
	return matrix;
}

template<typename T, std::uint32_t size>
Bebr::System::Matrix<T, size, size> Bebr::System::CreateIdentityMatrix()
{
	return CreateDiagonalMatrix<T, size>(1);
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator-(const Matrix<T, width, height>& right)
{
	Bebr::System::Matrix<T, width, height> result;
	for (std::uint32_t x = 0; x < width; x++)
	{
		for (std::uint32_t y = 0; y < height; y++)
			result[x][y] = -right[x][y];
	}
	return result;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator+(const Matrix<T, width, height>& left,
															   const Matrix<T, width, height>& right)
{
	Matrix<T, width, height> result;
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			result[x][y] = left[x][y] + right[x][y];
	}
	return result;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator-(const Matrix<T, width, height>& left,
															   const Matrix<T, width, height>& right)
{
	Matrix<T, width, height> result;
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			result[x][y] = left[x][y] - right[x][y];
	}
	return result;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator*(const Matrix<T, width, height> left, T right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] *= right;
	}
	return left;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator/(const Matrix<T, width, height> left, T right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] /= right;
	}
	return left;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height> Bebr::System::operator*(T left, const Matrix<T, width, height> right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			right[x][y] *= left;
	}
	return right;
}

template<typename T, std::uint32_t width, std::uint32_t height, std::uint32_t otherWidth>
Bebr::System::Matrix<T, otherWidth, height> Bebr::System::operator*(const Matrix<T, width, height>& left,
																	const Matrix<T, otherWidth, width>& right)
{
	Matrix<T, otherWidth, height> result;
	for (std::uint32_t i = 0; i < height; i++)
	{
		for (std::uint32_t j = 0; j < otherWidth; j++)
		{
			T sum = 0;
			for (std::uint32_t k = 0; k < width; k++)
			{
				sum += left[k][i] * right[j][k];
			}
			result[j][i] = sum;
		}
	}
	return result;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height>& Bebr::System::operator+=(Matrix<T, width, height>& left,
																 const Matrix<T, width, height>& right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] += right[x][y];
	}
	return left;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height>& Bebr::System::operator-=(Matrix<T, width, height>& left,
																 const Matrix<T, width, height>& right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] -= right[x][y];
	}
	return left;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height>& Bebr::System::operator*=(Matrix<T, width, height>& left, T right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] *= right;
	}
	return left;
}

template<typename T, std::uint32_t width, std::uint32_t height>
Bebr::System::Matrix<T, width, height>& Bebr::System::operator/=(Matrix<T, width, height>& left, T right)
{
	for (std::size_t x = 0; x < width; x++)
	{
		for (std::size_t y = 0; y < height; y++)
			left[x][y] /= right;
	}
	return left;
}

template<typename T, std::uint32_t size>
Bebr::System::Matrix<T, size, size>& Bebr::System::operator*=(Matrix<T, size, size>& left,
															  const Matrix<T, size, size>& right)
{
	left = left * right;
	return left;
}
