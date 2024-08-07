#include "FrameBuffer.hpp"
#include <GL/glew.h>

void Bebr::GL::FrameBuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void Bebr::GL::FrameBuffer::Unbind()
{
	#ifdef DEBUG
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	#endif
}
