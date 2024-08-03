#include "VertexArray.hpp"
#include <GL/glew.h>

Bebr::GL::VertexArray::VertexArray() : Resource()
{
	glGenVertexArrays(1, &m_id);
}

Bebr::GL::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_id);
}

void Bebr::GL::VertexArray::Bind()
{
	glBindVertexArray(m_id);
}

void Bebr::GL::VertexArray::Unbind()
{
	#ifdef DEBUG
	glBindVertexArray(0);
	#endif
}

void Bebr::GL::VertexArray::SetAttributes(VertexBuffer& vertexBuffer, const BufferLayout& layout)
{
	vertexBuffer.Bind();
	const std::vector<BufferLayout::Element*>& elements = layout.GetElements();
	const std::size_t elementsSize = elements.size();
	const std::int32_t strideSize = layout.GetStrideSize();
	std::uint32_t attributeOffset = 0;
	for (std::size_t i = 0; i < elementsSize; i++)
	{
		const BufferLayout::Element& element = *elements[i];
		const std::uint32_t index = static_cast<std::uint32_t>(i);
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, element.count, element.type, element.normalized,
							  strideSize, reinterpret_cast<void*>(attributeOffset));
		attributeOffset += element.count * element.typeSize;
	}
	vertexBuffer.Unbind();
}
