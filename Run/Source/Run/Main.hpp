#pragma once
#include <cstdint>
#include <System/Vector2.hpp>
#include <Window/Keyboard.hpp>

const std::int32_t ERROR	= -1;
const std::int32_t SUCCESS	= 0;

std::int32_t InitializeOpenGL();
std::int32_t InitializeImGui();

Bebr::System::Vector2F_t CalculateOffset(Bebr::Window::Keyboard& keyboard);

std::int32_t main();
