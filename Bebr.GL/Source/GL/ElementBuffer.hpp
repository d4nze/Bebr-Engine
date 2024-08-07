#pragma once
#include "Buffer.hpp"
#include "DataUsage.hpp"
#include "Size.hpp"

namespace Bebr
{
namespace GL
{
class ElementBuffer : public Buffer
{
public:
	ElementBuffer();
	ElementBuffer(const ElementBuffer&) = default;
	~ElementBuffer() = default;

public:
	void Bind();
	void Unbind();

	std::uint32_t GetGLType() const;

	template<typename T>
	void BufferData(T* data, Size_t size, DataUsage usage = DataUsage::StaticDraw);
	template<typename T>
	void BufferSubData(T* data, Size_t size, Size_t offset = 0);

private:
	std::uint32_t m_glType;
};
}
}

#include "ElementBuffer.inl"
