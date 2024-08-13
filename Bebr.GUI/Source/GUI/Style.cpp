#include "Style.hpp"
#include <imgui/imgui.h>

void Bebr::GUI::Style::SetLightTheme()
{
	ImGui::StyleColorsLight();
}

void Bebr::GUI::Style::SetDarkTheme()
{
	ImGui::StyleColorsDark();
}

void Bebr::GUI::Style::SetClassicTheme()
{
	ImGui::StyleColorsClassic();
}

void Bebr::GUI::Style::BeginDisabled(bool disabled)
{
	ImGui::BeginDisabled(disabled);
}

void Bebr::GUI::Style::EndDisabled()
{
	ImGui::EndDisabled();
}
