#include "BasicWindow.hpp"
#include <unordered_map>
#include <glfw3.h>

Bebr::Window::BasicWindow::BasicWindow(const std::string& title) : m_title(title)
{
	m_handler = glfwCreateWindow(640, 640,
								 m_title.c_str(),
								 nullptr, nullptr);
	glfwMaximizeWindow(m_handler);
	InitializeCallbacks();
	glfwGetWindowPos(m_handler, &m_position.x, &m_position.y);
	glfwGetWindowSize(m_handler, &m_size.x, &m_size.y);
	MakeCurrentContext();
}

Bebr::Window::BasicWindow::BasicWindow(int width, int height, const std::string& title) : m_title(title)
{
	m_handler = glfwCreateWindow(width, height,
								 m_title.c_str(),
								 nullptr, nullptr);
	InitializeCallbacks();
	glfwGetWindowPos(m_handler, &m_position.x, &m_position.y);
	glfwGetWindowSize(m_handler, &m_size.x, &m_size.y);
	MakeCurrentContext();
}

Bebr::Window::BasicWindow::BasicWindow(const System::Vector2I_t& size, const std::string& title) : m_title(title)
{
	m_handler = glfwCreateWindow(size.x, size.y,
								 m_title.c_str(),
								 nullptr, nullptr);
	InitializeCallbacks();
	glfwGetWindowPos(m_handler, &m_position.x, &m_position.y);
	glfwGetWindowSize(m_handler, &m_size.x, &m_size.y);
	MakeCurrentContext();
}

Bebr::Window::BasicWindow::~BasicWindow()
{
	glfwDestroyWindow(m_handler);
}

void Bebr::Window::BasicWindow::MakeCurrentContext()
{
	glfwMakeContextCurrent(m_handler);
}

void Bebr::Window::BasicWindow::SwapBuffers()
{
	glfwSwapBuffers(m_handler);
}

bool Bebr::Window::BasicWindow::IsOpen() const
{
	return !glfwWindowShouldClose(m_handler);
}

void Bebr::Window::BasicWindow::Close()
{
	glfwSetWindowShouldClose(m_handler, GLFW_TRUE);
}

void Bebr::Window::BasicWindow::SetTitle(const std::string& title)
{
	m_title = title;
	glfwSetWindowTitle(m_handler, m_title.c_str());
}

void Bebr::Window::BasicWindow::SetPosition(int x, int y)
{
	glfwSetWindowPos(m_handler, x, y);
	m_position.x = x;
	m_position.y = y;
}

void Bebr::Window::BasicWindow::SetPosition(const System::Vector2I_t & position)
{
	glfwSetWindowPos(m_handler, position.x, position.y);
	m_position.x = position.x;
	m_position.y = position.y;
}

void Bebr::Window::BasicWindow::SetSize(int width, int height)
{
	glfwSetWindowSize(m_handler, width, height);
	m_size.x = width;
	m_size.y = height;
}

void Bebr::Window::BasicWindow::SetSize(const System::Vector2I_t & size)
{
	glfwSetWindowSize(m_handler, size.x, size.y);
	m_size.x = size.x;
	m_size.y = size.y;
}

const std::string& Bebr::Window::BasicWindow::GetTitle() const
{
	return m_title;
}

const Bebr::System::Vector2I_t& Bebr::Window::BasicWindow::GetPosition() const
{
	return m_position;
}

const Bebr::System::Vector2I_t& Bebr::Window::BasicWindow::GetSize() const
{
	return m_size;
}

void Bebr::Window::BasicWindow::InitializeCallbacks()
{
	static std::unordered_map<GLFWwindow*, BasicWindow*> handlers;
	handlers[m_handler] = this;
	glfwSetWindowPosCallback(m_handler, [](GLFWwindow* handler, int x, int y)
	{
		BasicWindow* basicWindow = handlers[handler];
		basicWindow->SetPosition(x, y);
	});
	glfwSetWindowSizeCallback(m_handler, [](GLFWwindow* handler, int width, int height)
	{
		BasicWindow* basicWindow = handlers[handler];
		basicWindow->SetSize(width, height);
	});
}
