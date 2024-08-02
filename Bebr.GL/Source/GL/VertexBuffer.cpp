#include "VertexBuffer.hpp"
#include <GL/glew.h>

Bebr::GL::VertexBuffer::VertexBuffer(const void* data, Size_t size) : Resource()
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	Unbind();
}

Bebr::GL::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void Bebr::GL::VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void Bebr::GL::VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
