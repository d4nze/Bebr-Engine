#include "Resource.hpp"

Bebr::GL::Resource::Resource() : m_id(0)
{}

Bebr::GL::Resource::Resource(std::uint32_t id) : m_id(id)
{}

std::uint32_t Bebr::GL::Resource::GetID() const
{
	return m_id;
}
