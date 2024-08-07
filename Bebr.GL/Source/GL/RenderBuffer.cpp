#include "RenderBuffer.hpp"
#include <GL/glew.h>

void Bebr::GL::RenderBuffer::Bind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, m_id);
}

void Bebr::GL::RenderBuffer::Unbind()
{
	#ifdef DEBUG
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	#endif
}
