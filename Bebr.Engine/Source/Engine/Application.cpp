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
	, m_hierarchy		()
{}

bool Bebr::Engine::Application::IsRunning() const
{
	return m_window.IsOpen();
}

void Bebr::Engine::Application::Update()
{
	Bebr::Window::API::PollEvents();
}

void Bebr::Engine::Application::Render()
{
	Bebr::GL::Renderer::Clear();
	Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), m_window.GetSize());
	Bebr::GL::Renderer::ClearColor();

	Bebr::GUI::API::CreateFrame();
	Bebr::GUI::API::DockspaceOverViewport();
	m_mainMenuBar.Render();
	m_hierarchy.Render();
	Bebr::GUI::API::Render();

	m_window.SwapBuffers();
}
