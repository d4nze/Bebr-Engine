#pragma once
#include "BufferLayout.hpp"

template<typename T>
inline void Bebr::GL::BufferLayout::Push(bool normalized, std::uint32_t count)
{}

template<>
void Bebr::GL::BufferLayout::Push<float>(bool normalized, std::uint32_t count);
