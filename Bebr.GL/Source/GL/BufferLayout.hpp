#pragma once
#include <cstdint>
#include <vector>

namespace Bebr
{
namespace GL
{
class BufferLayout
{
public:
	BufferLayout();
	~BufferLayout();

public:
	struct Element
	{
		std::uint32_t	type;
		std::uint32_t	count;
		std::uint8_t	normalized;
		std::uint32_t	typeSize;
	};

public:
	template<typename T>
	void Push(bool normalized, std::uint32_t count = 1);
	const std::vector<Element*>& GetElements() const;

private:
	void Push(Element* element);

private:
	std::int32_t m_strideSize;
	std::vector<Element*> m_elements;
};
}
}

#include "BufferLayout.inl"
