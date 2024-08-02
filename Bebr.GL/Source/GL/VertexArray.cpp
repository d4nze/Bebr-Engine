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
	glBindVertexArray(0);
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
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, strideSize, (void*)(attributeOffset));
		attributeOffset += element.count * element.typeSize;
	}
	vertexBuffer.Unbind();
}
