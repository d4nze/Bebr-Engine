#include "Buffer.hpp"
#include <GL/glew.h>

Bebr::GL::Buffer::Buffer() : Resource()
{
	glGenBuffers(1, &m_id);
}

Bebr::GL::Buffer::~Buffer()
{
	glDeleteBuffers(1, &m_id);
}
