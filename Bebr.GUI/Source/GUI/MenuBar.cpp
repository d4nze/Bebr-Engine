#include "MenuBar.hpp"
#include <imgui/imgui.h>

bool Bebr::GUI::MainMenuBar::Begin()
{
    return ImGui::BeginMainMenuBar();
}

void Bebr::GUI::MainMenuBar::End()
{
    ImGui::EndMainMenuBar();
}

bool Bebr::GUI::MenuBar::Begin()
{
    return ImGui::BeginMenuBar();
}

void Bebr::GUI::MenuBar::End()
{
    ImGui::EndMenuBar();
}

bool Bebr::GUI::MenuBar::BeginMenu(const std::string& name)
{
    return ImGui::BeginMenu(name.c_str());
}

void Bebr::GUI::MenuBar::EndMenu()
{
    ImGui::EndMenu();
}
