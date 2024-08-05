#pragma once
#include "Buffer.hpp"
#include "Size.hpp"

namespace Bebr
{
namespace GL
{
class ElementBuffer : public Buffer
{
public:
	ElementBuffer();
	ElementBuffer(const ElementBuffer&) = default;
	~ElementBuffer() = default;

public:
	void Bind();
	void Unbind();

	std::uint32_t GetGLType() const;

	template<typename T>
	void BufferData(T* data, Size_t size);
	template<typename T>
	void BufferSubData(T* data, Size_t size, Size_t offset = 0);

private:
	std::uint32_t m_glType;
};
}
}

template<typename T>
inline void Bebr::GL::ElementBuffer::BufferData(T* data, Size_t size)
{}

template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint8_t>(std::uint8_t* data, Size_t size);
template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint16_t>(std::uint16_t* data, Size_t size);
template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint32_t>(std::uint32_t* data, Size_t size);

template<typename T>
inline void Bebr::GL::ElementBuffer::BufferSubData(T* data, Size_t size, Size_t offset)
{}

template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint8_t>(std::uint8_t* data, Size_t size, Size_t start);
template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint16_t>(std::uint16_t* data, Size_t size, Size_t start);
template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint32_t>(std::uint32_t* data, Size_t size, Size_t start);
