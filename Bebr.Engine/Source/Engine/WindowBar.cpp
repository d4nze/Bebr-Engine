#include "WindowBar.hpp"
#include <GUI/MenuBar.hpp>
#include <GUI/Style.hpp>

Bebr::Engine::WindowBar::WindowBar()
	: m_name				("Windows")
	, m_openSceneHierarchy	("Scene hierarchy")
	, m_openResourceFolder	("Resources folder")
	, m_openInspector		("Inspector")
{}

void Bebr::Engine::WindowBar::Render()
{
    if (GUI::MenuBar::BeginMenu(m_name))
    {
		m_openSceneHierarchy.Render();
		m_openResourceFolder.Render();
		m_openInspector		.Render();
        GUI::MenuBar::EndMenu();
    }
}

void Bebr::Engine::WindowBar::ProcessWindow(GUI::TogglableMenuItem& menuItem, GUI::ClosableWindow& window)
{
	if (menuItem.IsPressed())
	{
		if (!window.IsOpen())
		{
			window.Open();
		}
	}
	else
	{
		menuItem.SetToggleMode(window.IsOpen());
	}
}

Bebr::GUI::TogglableMenuItem& Bebr::Engine::WindowBar::GetOpenSceneHierarchy()
{
	return m_openSceneHierarchy;
}

Bebr::GUI::TogglableMenuItem& Bebr::Engine::WindowBar::GetOpenResourceFolder()
{
	return m_openResourceFolder;
}

Bebr::GUI::TogglableMenuItem& Bebr::Engine::WindowBar::GetOpenInspector()
{
	return m_openInspector;
}
