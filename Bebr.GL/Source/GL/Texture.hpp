#pragma once
#include "Resource.hpp"
#include <System/Vector2.hpp>

namespace Bebr
{
namespace GL
{
class Texture : public Resource
{
public:
	Texture();
	Texture(const Texture&) = default;
	~Texture();

public:
	enum class InternalFormat
	{
		R8				= 0x8229,
		RG8				= 0x822B,
		RGB8			= 0x8051,
		RGBA8			= 0x8058,
		R16				= 0x822A,
		RG16			= 0x822C,
		RGB16			= 0x8054,
		RGBA16			= 0x805B,
	};

	enum class Format
	{
		Red				= 0x1903,
		RG				= 0x8227,
		RGB				= 0x1907,
		BGR				= 0x80E0,
		RGBA			= 0x1908,
		BGRA			= 0x80E1,
		RedInteger		= 0x8D94,
		RGInteger		= 0x8228,
		RGBInteger		= 0x8D98,
		BGRInteger		= 0x8D9A,
		RGBAInteger		= 0x8D99,
		BGRAInteger		= 0x8D9B,
		StencilIndex	= 0x1901,
		DepthComponent	= 0x1902,
		DepthStencil	= 0x84F9
	};

	enum class Filter
	{
		Nearest					= 0x2600,
		Linear					= 0x2601,
		NearestMipmapNearest	= 0x2700,
		LinearMipmapNearest		= 0x2701,
		NearestMipmapLinear		= 0x2702,
		LinearMipmapLinear		= 0x2703
	};

	enum class Wrap
	{
		Clamp	= 0x2900,
		Repeat	= 0x2901
	};

public:
	void Bind(std::uint32_t unit = 0);
	void Unbind();

	void Create(std::int32_t level, std::int32_t width, std::int32_t height,
				InternalFormat internalFormat, Format format, const std::uint8_t* pixels = nullptr);

	void SetMinFilter(Filter filter);
	void SetMagFilter(Filter filter);
	Filter GetMinFilter() const;
	Filter GetMaxFilter() const;

	void SetWrapX(Wrap wrap);
	void SetWrapY(Wrap wrap);
	void SetWrap(Wrap wrapX, Wrap wrapY);
	Wrap GetWrapX() const;
	Wrap GetWrapY() const;

	const System::Vector2I_t& GetSize() const;

private:
	System::Vector2I_t m_size;
};
}
}
