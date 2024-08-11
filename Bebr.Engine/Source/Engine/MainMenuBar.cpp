#include "MainMenuBar.hpp"
#include <GUI/MenuBar.hpp>

Bebr::Engine::MainMenuBar::MainMenuBar()
{}

void Bebr::Engine::MainMenuBar::Render()
{
	if (GUI::MainMenuBar::Begin())
	{
		m_fileBar.Render();
		GUI::MainMenuBar::End();
	}
}

const Bebr::Engine::FileBar& Bebr::Engine::MainMenuBar::GetFileBar() const
{
	return m_fileBar;
}
