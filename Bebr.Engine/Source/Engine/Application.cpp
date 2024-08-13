#include "Application.hpp"
#include <GL/Renderer.hpp>
#include <GL/Viewport.hpp>
#include <GUI/API.hpp>
#include <Window/API.hpp>

Bebr::Engine::Application::Application()
	: m_glfwInitializer	()
	, m_window			("Bebr Engine")
	, m_glInitializer	()
	, m_guiInitialize	()

	, m_mainMenuBar		()
	, m_sceneHierarchy	()
	, m_inspector		()
	, m_resources		()
{}

bool Bebr::Engine::Application::IsRunning() const
{
	return m_window.IsOpen();
}

void Bebr::Engine::Application::Update()
{
	Bebr::Window::API::PollEvents();

	if (m_mainMenuBar.GetFileBar().GetCloseItem().IsPressed())
	{
		m_window.Close();
	}

	if (m_sceneHierarchy.IsUpdated())
	{
		m_inspector.SetInspectable(m_sceneHierarchy.GetInspectable());
	}

	Bebr::Engine::WindowBar& windowBar = m_mainMenuBar.GetWindowBar();
	windowBar.GetOpenSceneHierarchy().SetToggleMode(m_sceneHierarchy.IsOpen());
	windowBar.GetOpenResourceFolder().SetToggleMode(m_resources.IsOpen());
	windowBar.GetOpenInspector().SetToggleMode(m_inspector.IsOpen());
}

void Bebr::Engine::Application::Render()
{
	Bebr::GL::Renderer::Clear();
	Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), m_window.GetSize());
	Bebr::GL::Renderer::ClearColor();

	Bebr::GUI::API::CreateFrame();
	Bebr::GUI::API::DockspaceOverViewport();
	RenderGUI();
	Bebr::GUI::API::Render();

	m_window.SwapBuffers();
}

void Bebr::Engine::Application::RenderGUI()
{
	m_mainMenuBar.Render();

	Bebr::Engine::WindowBar& windowBar = m_mainMenuBar.GetWindowBar();
	if (windowBar.GetOpenSceneHierarchy().IsToggled())
	{
		m_sceneHierarchy.Open();
	}
	if (windowBar.GetOpenResourceFolder().IsToggled())
	{
		m_resources.Open();
	}
	if (windowBar.GetOpenInspector().IsToggled())
	{
		m_inspector.Open();
	}

	if (m_sceneHierarchy.IsOpen())
	{
		m_sceneHierarchy.Render();
	}
	if (m_inspector.IsOpen())
	{
		m_inspector.Render();
	}
	if (m_resources.IsOpen())
	{
		m_resources.Render();
	}
}
