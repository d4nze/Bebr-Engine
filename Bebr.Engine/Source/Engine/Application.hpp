#pragma once
#include "Initializer.hpp"
#include <Window/BasicWindow.hpp>
#include "MainMenuBar.hpp"
#include "Hierarchy.hpp"

namespace Bebr
{
namespace Engine
{
class Application
{
public:
	Application();
	~Application() = default;

public:
	bool IsRunning() const;
	void Update();
	void Render();

private:
	GLFWInitializer				m_glfwInitializer;
	Bebr::Window::BasicWindow	m_window;
	GLInitializer				m_glInitializer;
	GUIInitializer				m_guiInitialize;

	MainMenuBar					m_mainMenuBar;
	Hierarchy					m_hierarchy;
};
}
}
