#pragma once
#include <System/Vector2.hpp>

namespace Bebr
{
namespace GUI
{
class Layout
{
public:
	Layout() = delete;

public:
	static void SetCurrentPosition(float x, float y);
	static void SetCurrentPosition(const System::Vector2F_t& position);
};
}
}
