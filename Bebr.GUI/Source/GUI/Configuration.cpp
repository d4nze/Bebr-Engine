#include "Configuration.hpp"
#include <imgui/imgui.h>

void Bebr::GUI::Configuration::EnableFlag(Flag flag)
{
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags(flag);
}
