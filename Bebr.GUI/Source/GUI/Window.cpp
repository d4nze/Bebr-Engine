#include "Window.hpp"
#include <imgui/imgui.h>

Bebr::GUI::Window::Window(const std::string& name)
    : m_name(name)
    , m_flags(0)
{}

bool Bebr::GUI::Window::Begin()
{
    return ImGui::Begin(m_name.c_str(), nullptr, m_flags);
}

void Bebr::GUI::Window::End()
{
    ImGui::End();
}

void Bebr::GUI::Window::AddFlag(Flag flag)
{
    m_flags |= static_cast<std::int32_t>(flag);
}

void Bebr::GUI::Window::RemoveFlag(Flag flag)
{
    m_flags &= ~static_cast<std::int32_t>(flag);
}

Bebr::System::Vector2F_t Bebr::GUI::Window::GetSize() const
{
    ImVec2 size = ImGui::GetWindowSize();
    return System::Vector2F_t(size.x, size.y);
}

const std::string& Bebr::GUI::Window::GetName() const
{
    return m_name;
}

Bebr::GUI::ClosableWindow::ClosableWindow(const std::string& name, bool open)
    : Window(name)
    , m_open(open)
{}

bool Bebr::GUI::ClosableWindow::Begin()
{
    return ImGui::Begin(m_name.c_str(), &m_open, m_flags);
}

void Bebr::GUI::ClosableWindow::Close()
{
    m_open = false;
}

void Bebr::GUI::ClosableWindow::Open()
{
    m_open = true;
}

bool Bebr::GUI::ClosableWindow::IsOpen() const
{
    return m_open;
}
