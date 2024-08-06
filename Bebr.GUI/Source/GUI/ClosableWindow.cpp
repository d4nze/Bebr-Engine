#include "ClosableWindow.hpp"
#include <imgui/imgui.h>

Bebr::GUI::ClosableWindow::ClosableWindow(const std::string& name, bool open)
	: Window(name)
	, m_open(open)
{}

bool Bebr::GUI::ClosableWindow::Begin()
{
	return ImGui::Begin(m_name.c_str(), &m_open, m_flags);
}

bool Bebr::GUI::ClosableWindow::IsOpen() const
{
	return m_open;
}
