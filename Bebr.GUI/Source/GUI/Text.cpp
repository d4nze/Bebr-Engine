#include "Text.hpp"
#include <imgui/imgui.h>

Bebr::GUI::Text::Text(const std::string& data) : m_data(data)
{}

void Bebr::GUI::Text::Render()
{
	ImGui::Text(m_data.c_str());
}
