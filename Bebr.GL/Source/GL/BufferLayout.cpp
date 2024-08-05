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
void Bebr::GL::BufferLayout::Push<std::int8_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_BYTE, count, normalized, sizeof(std::int8_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<std::int16_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_SHORT, count, normalized, sizeof(std::int16_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<std::int32_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_INT, count, normalized, sizeof(std::int32_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<std::uint8_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_UNSIGNED_BYTE, count, normalized, sizeof(std::uint8_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<std::uint16_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_UNSIGNED_SHORT, count, normalized, sizeof(std::uint16_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<std::uint32_t>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_UNSIGNED_INT, count, normalized, sizeof(std::uint32_t) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<float>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_FLOAT, count, normalized, sizeof(float) };
	Push(element);
}

template<>
void Bebr::GL::BufferLayout::Push<double>(bool normalized, std::uint32_t count)
{
	Element* element = new Element{ GL_DOUBLE, count, normalized, sizeof(double) };
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
