#include "Button.hpp"
#include <imgui/imgui.h>

Bebr::GUI::Button::Button(const std::string& name) : m_name(name)
{}

void Bebr::GUI::Button::Render()
{
	ImGui::Button(m_name.c_str());
}

void Bebr::GUI::Button::Render(float temporaryWidth, float temporaryHeight)
{
	ImGui::Button(m_name.c_str(), { temporaryWidth, temporaryHeight });
}

void Bebr::GUI::Button::Render(const System::Vector2F_t& temporarySize)
{
	ImGui::Button(m_name.c_str(), { temporarySize.x, temporarySize.y });
}
