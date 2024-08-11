#pragma once
#include "Initializer.hpp"
#include "MainMenuBar.hpp"
#include "SceneHierarchy.hpp"
#include "Inspector.hpp"
#include "ResourcesFolder.hpp"
#include <Window/BasicWindow.hpp>

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
	void RenderGUI();

private:
	GLFWInitializer				m_glfwInitializer;
	Bebr::Window::BasicWindow	m_window;
	GLInitializer				m_glInitializer;
	GUIInitializer				m_guiInitialize;

	MainMenuBar					m_mainMenuBar;
	SceneHierarchy				m_sceneHierarchy;
	Inspector					m_inspector;
	ResourcesFolder				m_resources;
};
}
}
