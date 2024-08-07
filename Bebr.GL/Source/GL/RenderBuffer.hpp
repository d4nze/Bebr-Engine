#pragma once
#include "Buffer.hpp"

namespace Bebr
{
namespace GL
{
class RenderBuffer : public Buffer
{
public:
	RenderBuffer() = default;
	RenderBuffer(const RenderBuffer&) = default;
	~RenderBuffer() = default;

public:
	void Bind();
	void Unbind();
};
}
}
