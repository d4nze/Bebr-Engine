#include "FrameBuffer.hpp"
#include "RenderBuffer.hpp"
#include "Texture.hpp"
#include <GL/glew.h>

Bebr::GL::FrameBuffer::FrameBuffer(Target target)
	: Buffer()
	, m_target(target)
{}

void Bebr::GL::FrameBuffer::Bind()
{
	glBindFramebuffer(static_cast<std::uint32_t>(m_target), m_id);
}

void Bebr::GL::FrameBuffer::Unbind()
{
	glBindFramebuffer(static_cast<std::uint32_t>(m_target), 0);
}

void Bebr::GL::FrameBuffer::AttachRenderBuffer(const RenderBuffer& renderBuffer, Attachment attachment)
{
	glFramebufferRenderbuffer(static_cast<std::uint32_t>(m_target),
							  static_cast<std::uint32_t>(attachment),
							  GL_RENDERBUFFER, renderBuffer.GetID());
}

void Bebr::GL::FrameBuffer::AttachTexture(const Texture& texture, Attachment attachment)
{
	glFramebufferTexture2D(static_cast<std::uint32_t>(m_target),
						   static_cast<std::uint32_t>(attachment),
						   static_cast<std::uint32_t>(texture.GetTarget()),
						   texture.GetID(), 0);
}

Bebr::GL::FrameBuffer::Status Bebr::GL::FrameBuffer::GetStatus() const
{
	return static_cast<Status>(glCheckFramebufferStatus(static_cast<GLenum>(m_target)));
}

bool Bebr::GL::FrameBuffer::IsComplete() const
{
	return GetStatus() == Status::Complete;
}
