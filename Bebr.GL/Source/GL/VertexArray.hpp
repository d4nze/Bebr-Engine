#pragma once
#include "VertexBuffer.hpp"
#include "BufferLayout.hpp"

namespace Bebr
{
namespace GL
{
class VertexArray : public Resource
{
public:
	VertexArray();
	VertexArray(const VertexArray&) = default;
	~VertexArray();

public:
	void Bind();
	void Unbind();

	void SetAttributes(VertexBuffer& vertexBuffer, const BufferLayout& layout);
};
}
}
