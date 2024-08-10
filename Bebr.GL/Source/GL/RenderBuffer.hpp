#pragma once
#include "Buffer.hpp"
#include "PixelFormat.hpp"

namespace Bebr
{
namespace GL
{
class RenderBuffer : public Buffer
{
public:
	RenderBuffer()						= default;
	RenderBuffer(const RenderBuffer&)	= default;
	~RenderBuffer()						= default;

public:
	class InternalFormat
	{
	public:
		enum class Base
		{
			DepthComponent		= 0x1902,
			DepthStencil		= 0x84F9,
			StencilIndex		= 0x1901,
		};

		enum class Sized
		{
			DepthComponent16	= 0x81A5,
			DepthComponent24	= 0x81A6,
			DepthComponent32	= 0x81A7,
			DepthComponent32F	= 0x8CAC,
			Depth24Stencil8		= 0x88F0,
			Depth32FStencil8	= 0x8CAD,
			StencilIndex1		= 0x8D46,
			StencilIndex4		= 0x8D47,
			StencilIndex8		= 0x8D48,
			StencilIndex16		= 0x8D49
		};

	public:
		InternalFormat(PixelFormat	format);
		InternalFormat(Base			format);
		InternalFormat(Sized		format);

	public:
		inline operator std::uint32_t() const { return m_format; }

	private:
		std::uint32_t m_format;
	};

public:
	void Bind();
	void Unbind();

	void Create(std::int32_t width, std::int32_t height, InternalFormat internalFormat);
};
}
}
