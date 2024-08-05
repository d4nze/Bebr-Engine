#include "ElementBuffer.hpp"
#include <GL/glew.h>

static void BufferData(void* data, Bebr::GL::Size_t size)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

static void BufferSubData(void* data, Bebr::GL::Size_t size, Bebr::GL::Size_t start)
{
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, start, size, data);
}

Bebr::GL::ElementBuffer::ElementBuffer()
	: Buffer()
	, m_glType(0)
{}

void Bebr::GL::ElementBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void Bebr::GL::ElementBuffer::Unbind()
{
	#ifdef DEBUG
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	#endif
}

std::uint32_t Bebr::GL::ElementBuffer::GetGLType() const
{
	return m_glType;
}

template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint8_t>(std::uint8_t* data, Size_t size)
{
	m_glType = GL_UNSIGNED_BYTE;
	::BufferData(data, size);
}

template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint16_t>(std::uint16_t* data, Size_t size)
{
	m_glType = GL_UNSIGNED_SHORT;
	::BufferData(data, size);
}

template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint32_t>(std::uint32_t* data, Size_t size)
{
	m_glType = GL_UNSIGNED_INT;
	::BufferData(data, size);
}

template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint8_t>(std::uint8_t* data, Size_t size, Size_t start)
{
	::BufferSubData(data, size, start);
}

template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint16_t>(std::uint16_t* data, Size_t size, Size_t start)
{
	::BufferSubData(data, size, start);
}

template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint32_t>(std::uint32_t* data, Size_t size, Size_t start)
{
	::BufferSubData(data, size, start);
}
