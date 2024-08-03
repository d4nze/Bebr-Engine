#pragma once
#include <System/Vector2.hpp>

namespace Bebr
{
namespace GL
{
class Viewport
{
public:
	Viewport() = delete;

public:
	static void SetRectangle(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height);
	static void SetRectangle(const System::Vector2I_t& position, const System::Vector2I_t& size);

	static void UpdateX(std::int32_t x);
	static void UpdateY(std::int32_t y);
	static void UpdateWidth(std::int32_t width);
	static void UpdateHeight(std::int32_t height);
	static void UpdatePosition(std::int32_t x, std::int32_t y);
	static void UpdatePosition(const System::Vector2I_t& position);
	static void UpdateSize(std::int32_t width, std::int32_t height);
	static void UpdateSize(const System::Vector2I_t& size);

	static std::int32_t GetX();
	static std::int32_t GetY();
	static std::int32_t GetWidth();
	static std::int32_t GetHeight();
	static const System::Vector2I_t& GetPosition();
	static const System::Vector2I_t& GetSize();
};
}
}
