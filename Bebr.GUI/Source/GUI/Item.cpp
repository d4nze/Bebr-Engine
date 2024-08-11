#include "Item.hpp"
#include <imgui/imgui.h>

bool Bebr::GUI::Item::IsClicked() const
{
    return ImGui::IsItemClicked();
}

bool Bebr::GUI::Item::IsDeactivatedAfterEdit() const
{
    return ImGui::IsItemDeactivatedAfterEdit();
}
