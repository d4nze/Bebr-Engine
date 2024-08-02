#include "BufferLayout.hpp"
#include <GL/glew.h>

Bebr::GL::BufferLayout::BufferLayout() : m_strideSize(0)
{}

Bebr::GL::BufferLayout::~BufferLayout()
{
	for (Element* elem : m_elements)
		delete elem;
}

template<>
void Bebr::GL::BufferLayout::Push<float>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_FLOAT, count, normalized, sizeof(float) };
	Push(element);
}

void Bebr::GL::BufferLayout::Push(Element* element)
{
	if (element->count == 0)
	{
		delete element;
		return;
	}
	m_strideSize += element->count * element->typeSize;
	m_elements.push_back(element);
}

const std::vector<Bebr::GL::BufferLayout::Element*>& Bebr::GL::BufferLayout::GetElements() const
{
	return m_elements;
}

std::int32_t Bebr::GL::BufferLayout::GetStrideSize() const
{
	return m_strideSize;
}
