#include "Texture.hpp"
#include <GL/glew.h>

static constexpr std::uint32_t GetTargetUI(Bebr::GL::Texture::Target target)
{
	return static_cast<std::uint32_t>(target);
}

Bebr::GL::Texture::Texture(Target target)
	: Resource()
	, m_target(target)
{
	glGenTextures(1, &m_id);
}

Bebr::GL::Texture::~Texture()
{
	glDeleteTextures(1, &m_id);
}

void Bebr::GL::Texture::Bind(std::uint32_t unit)
{
	glActiveTexture(unit);
	glBindTexture(GetTargetUI(m_target), m_id);
}

void Bebr::GL::Texture::Unbind()
{
	#ifdef DEBUG
	glBindTexture(GetTargetUI(m_target), 0);
	#endif
}

void Bebr::GL::Texture::Create(std::int32_t level, std::int32_t width, std::int32_t height,
							   PixelFormat internalFormat, PixelFormat format, const std::uint8_t* pixels)
{
	glTexImage2D(GetTargetUI(m_target), level, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
}

void Bebr::GL::Texture::SetMinFilter(Filter filter)
{
	glTexParameteri(GetTargetUI(m_target), GL_TEXTURE_MIN_FILTER, static_cast<std::int32_t>(filter));
}

void Bebr::GL::Texture::SetMagFilter(Filter filter)
{
	glTexParameteri(GetTargetUI(m_target), GL_TEXTURE_MAG_FILTER, static_cast<std::int32_t>(filter));
}

Bebr::GL::Texture::Filter Bebr::GL::Texture::GetMinFilter() const
{
	std::int32_t filter;
	glGetTexParameteriv(GetTargetUI(m_target), GL_TEXTURE_MIN_FILTER, &filter);
	return static_cast<Filter>(filter);
}

Bebr::GL::Texture::Filter Bebr::GL::Texture::GetMaxFilter() const
{
	std::int32_t filter;
	glGetTexParameteriv(GetTargetUI(m_target), GL_TEXTURE_MAG_FILTER, &filter);
	return static_cast<Filter>(filter);
}

void Bebr::GL::Texture::SetWrapX(Wrap wrap)
{
	glTexParameteri(GetTargetUI(m_target), GL_TEXTURE_WRAP_S, static_cast<std::int32_t>(wrap));
}

void Bebr::GL::Texture::SetWrapY(Wrap wrap)
{
	glTexParameteri(GetTargetUI(m_target), GL_TEXTURE_WRAP_T, static_cast<std::int32_t>(wrap));
}

void Bebr::GL::Texture::SetWrap(Wrap wrapX, Wrap wrapY)
{
	SetWrapX(wrapX);
	SetWrapY(wrapY);
}

Bebr::GL::Texture::Wrap Bebr::GL::Texture::GetWrapX() const
{
	std::int32_t wrap;
	glGetTexParameteriv(GetTargetUI(m_target), GL_TEXTURE_WRAP_S, &wrap);
	return static_cast<Wrap>(wrap);
}

Bebr::GL::Texture::Wrap Bebr::GL::Texture::GetWrapY() const
{
	std::int32_t wrap;
	glGetTexParameteriv(GetTargetUI(m_target), GL_TEXTURE_WRAP_T, &wrap);
	return static_cast<Wrap>(wrap);
}

Bebr::GL::Texture::Target Bebr::GL::Texture::GetTarget() const
{
	return m_target;
}
