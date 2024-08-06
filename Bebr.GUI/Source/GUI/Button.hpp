#pragma once
#include <System/Vector2.hpp>
#include <string>

namespace Bebr
{
namespace GUI
{
class Button
{
public:
	Button(const std::string& name);
	Button(const Button&) = default;
	~Button() = default;

public:
	void Render();
	void Render(float temporaryWidth, float temporaryHeight);
	void Render(const System::Vector2F_t& temporarySize);

private:
	std::string m_name;
};
}
}
