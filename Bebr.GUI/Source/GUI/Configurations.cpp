#include "Configurations.hpp"
#include <imgui/imgui.h>

void Bebr::GUI::Configurations::EnableFlag(Flag flag)
{
	ImGui::GetIO().ConfigFlags |= static_cast<ImGuiConfigFlags>(flag);
}

void Bebr::GUI::Configurations::DisableFlag(Flag flag)
{
	ImGui::GetIO().ConfigFlags &= ~static_cast<ImGuiConfigFlags>(flag);
}

void Bebr::GUI::Configurations::SetFlag(Flag flag, bool enabled)
{
	if (enabled)
	{
		EnableFlag(flag);
	}
	else
	{
		DisableFlag(flag);
	}
}

bool Bebr::GUI::Configurations::IsFlagEnabled(Flag flag)
{
	return ImGui::GetIO().ConfigFlags & static_cast<ImGuiConfigFlags>(flag);
}
