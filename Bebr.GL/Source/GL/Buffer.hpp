#pragma once
#include "Resource.hpp"

namespace Bebr
{
namespace GL
{
class Buffer : public Resource
{
public:
	Buffer();
	Buffer(const Buffer&) = default;
	~Buffer();
};
}
}
