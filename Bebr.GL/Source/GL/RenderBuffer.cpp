#include "RenderBuffer.hpp"
#include <GL/glew.h>

Bebr::GL::RenderBuffer::InternalFormat::InternalFormat(PixelFormat format) : m_format(format)
{}

Bebr::GL::RenderBuffer::InternalFormat::InternalFormat(Base format) : m_format(static_cast<std::uint32_t>(format))
{}

Bebr::GL::RenderBuffer::InternalFormat::InternalFormat(Sized format) : m_format(static_cast<std::uint32_t>(format))
{}

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

void Bebr::GL::RenderBuffer::Create(std::int32_t width, std::int32_t height, InternalFormat internalFormat)
{
	glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
}
