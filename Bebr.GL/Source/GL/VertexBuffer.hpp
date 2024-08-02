#pragma once
#include "Resource.hpp"
#include "Size.hpp"

namespace Bebr
{
namespace GL
{
class VertexBuffer : public Resource
{
public:
	VertexBuffer(const void* data, Size_t size);
	VertexBuffer(const VertexBuffer&) = default;
	~VertexBuffer();

public:
	void Bind();
	void Unbind();
};
}
}
