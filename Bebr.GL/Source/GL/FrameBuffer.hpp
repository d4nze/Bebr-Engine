#pragma once
#include "Buffer.hpp"

namespace Bebr
{
namespace GL
{
class FrameBuffer : public Buffer
{
public:
	FrameBuffer() = default;
	FrameBuffer(const FrameBuffer&) = default;
	~FrameBuffer() = default;

public:
	void Bind();
	void Unbind();
};
}
}
