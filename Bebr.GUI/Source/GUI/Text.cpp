#include "Text.hpp"
#include <imgui/imgui.h>

Bebr::GUI::Text::Text(const std::string& data) : m_data(data)
{}

void Bebr::GUI::Text::Render()
{
	ImGui::Text(m_data.c_str());
}

Bebr::System::Vector2F_t Bebr::GUI::Text::GetSize() const
{
	ImVec2 size = ImGui::CalcTextSize(m_data.c_str());
	return System::Vector2F_t(size.x, size.y);
}
