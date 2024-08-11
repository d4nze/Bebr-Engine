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

	if (m_sceneHierarchy.IsUpdated())
	{
		m_inspector.SetInspectable(m_sceneHierarchy.GetInspectable());
	}
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
	m_sceneHierarchy.Render();
	m_inspector.Render();
	m_resources.Render();
}
