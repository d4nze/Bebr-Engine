#pragma once
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

private:
	std::string m_data;
};
}
}
