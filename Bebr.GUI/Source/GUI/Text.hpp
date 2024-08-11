#pragma once
#include <System/Vector2.hpp>
#include <string>

namespace Bebr
{
namespace GUI
{
class Text
{
public:
	Text(const std::string& data);
	Text(const Text&) = default;
	~Text() = default;

public:
	void Render();

	System::Vector2F_t GetSize() const;

private:
	std::string m_data;
};
}
}
