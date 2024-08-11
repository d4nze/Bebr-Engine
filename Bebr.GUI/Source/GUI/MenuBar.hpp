#pragma once
#include <string>

namespace Bebr
{
namespace GUI
{
class MenuBar
{
public:
	MenuBar() = delete;

public:
	static bool Begin();
	static void End();

	static bool BeginMenu(const std::string& name);
	static void EndMenu();
};

class MainMenuBar : public MenuBar
{
public:
	MainMenuBar() = delete;

public:
	static bool Begin();
	static void End();
};
}
}
