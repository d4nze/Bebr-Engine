#pragma once
#include "Resource.hpp"

namespace Bebr
{
namespace GL
{
class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexArray&) = default;
	~VertexArray();

public:
	void Bind();
	void Unbind();
};
}
}
