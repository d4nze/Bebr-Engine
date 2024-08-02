#include "VertexBuffer.hpp"
#include <GL/glew.h>

void Bebr::GL::VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void Bebr::GL::VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Bebr::GL::VertexBuffer::BufferData(const void* data, Size_t size)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Bebr::GL::VertexBuffer::BufferSubData(const void* data, Size_t size, Size_t offset)
{
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}
