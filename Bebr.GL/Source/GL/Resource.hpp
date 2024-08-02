#pragma once
#include <cstdint>

namespace Bebr
{
namespace GL
{
class Resource
{
public:
	Resource();
	Resource(std::uint32_t id);
	Resource(const Resource&) = default;
	~Resource() = default;

public:
	std::uint32_t GetID() const;

protected:
	std::uint32_t m_id;
};
}
}
