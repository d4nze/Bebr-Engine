#pragma once
#include "Buffer.hpp"
#include "DataUsage.hpp"
#include "Size.hpp"

namespace Bebr
{
namespace GL
{
class VertexBuffer : public Buffer
{
public:
	VertexBuffer() = default;
	VertexBuffer(const VertexBuffer&) = default;
	~VertexBuffer() = default;

public:
	void Bind();
	void Unbind();

	void BufferData(const void* data, Size_t size, DataUsage usage = DataUsage::StaticDraw);
	void BufferSubData(const void* data, Size_t size, Size_t offset = 0);
};
}
}
