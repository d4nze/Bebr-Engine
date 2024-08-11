#include "MenuItem.hpp"
#include <imgui/imgui.h>

Bebr::GUI::MenuItem::MenuItem(const std::string& name)
	: m_name	(name)
	, m_hotkey	()
	, m_pressed	(false)
	, m_enabled	(true)
{}

Bebr::GUI::MenuItem::MenuItem(const std::string& name, const std::string& hotkey)
	: m_name	(name)
	, m_hotkey	(hotkey)
	, m_pressed	(false)
	, m_enabled	(true)
{}

void Bebr::GUI::MenuItem::Render()
{
	const char* hotkeyStr = nullptr;
	if (!m_hotkey.empty())
	{
		hotkeyStr = m_hotkey.c_str();
	}
	m_pressed = ImGui::MenuItem(m_name.c_str(), hotkeyStr, nullptr, m_enabled);
}

bool Bebr::GUI::MenuItem::Pressed() const
{
	return m_pressed;
}

void Bebr::GUI::MenuItem::disable()
{
	m_enabled = false;
}

void Bebr::GUI::MenuItem::enable()
{
	m_enabled = true;
}

bool Bebr::GUI::MenuItem::isEnabled() const
{
	return m_enabled;
}

Bebr::GUI::TogglableMenuItem::TogglableMenuItem(const std::string& name, bool toggled)
	: MenuItem	(name)
	, m_toggled	(toggled)
{}

Bebr::GUI::TogglableMenuItem::TogglableMenuItem(const std::string& name, const std::string& hotkey, bool toggled)
	: MenuItem	(name, hotkey)
	, m_toggled	(toggled)
{}

void Bebr::GUI::TogglableMenuItem::Render()
{
	const char* hotkeyStr = nullptr;
	if (!m_hotkey.empty())
	{
		hotkeyStr = m_hotkey.c_str();
	}
	m_pressed = ImGui::MenuItem(m_name.c_str(), hotkeyStr, m_toggled, m_enabled);
	if (m_pressed)
	{
		m_toggled = !m_toggled;
	}
}

void Bebr::GUI::TogglableMenuItem::SetToggleMode(bool enabled)
{
	m_toggled = enabled;
}

bool Bebr::GUI::TogglableMenuItem::IsToggled() const
{
	return m_toggled;
}
