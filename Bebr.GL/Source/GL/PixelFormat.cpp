#include "PixelFormat.hpp"

Bebr::GL::PixelFormat::PixelFormat(Base format) : m_format(static_cast<std::uint32_t>(format))
{}

Bebr::GL::PixelFormat::PixelFormat(Sized format) : m_format(static_cast<std::uint32_t>(format))
{}

Bebr::GL::PixelFormat::PixelFormat(Compressed format) : m_format(static_cast<std::uint32_t>(format))
{}
