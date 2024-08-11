#pragma once
#include <string>

namespace Bebr
{
namespace GUI
{
class Separator
{
public:
	Separator() = delete;

public:
	static void Line();
	static void LineWText(const std::string& text);
};
}
}
