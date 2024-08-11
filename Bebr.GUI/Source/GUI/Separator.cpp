#include "Separator.hpp"
#include <imgui/imgui.h>

void Bebr::GUI::Separator::Line()
{
	ImGui::Separator();
}

void Bebr::GUI::Separator::LineWText(const std::string & text)
{
	ImGui::SeparatorText(text.c_str());
}
