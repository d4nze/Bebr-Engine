#include "Layout.hpp"
#include <imgui/imgui.h>

void Bebr::GUI::Layout::SetCurrentPosition(float x, float y)
{
	ImGui::SetCursorPos({ x, y });
}

void Bebr::GUI::Layout::SetCurrentPosition(const System::Vector2F_t& position)
{
	ImGui::SetCursorPos({ position.x, position.y });
}
