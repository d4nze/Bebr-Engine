#pragma once
#include <GUI/MenuItem.hpp>
#include <GUI/Window.hpp>

namespace Bebr
{
namespace Engine
{
class WindowBar
{
public:
	WindowBar();
	WindowBar(const WindowBar&) = delete;
	~WindowBar() = default;

public:
	void Render();
	void ProcessWindow(GUI::TogglableMenuItem& menuItem, GUI::ClosableWindow& window);

	GUI::TogglableMenuItem& GetOpenSceneHierarchy();
	GUI::TogglableMenuItem& GetOpenResourceFolder();
	GUI::TogglableMenuItem& GetOpenInspector();

private:
	std::string		m_name;
	GUI::TogglableMenuItem	m_openSceneHierarchy;
	GUI::TogglableMenuItem	m_openResourceFolder;
	GUI::TogglableMenuItem	m_openInspector;
};
}
}
