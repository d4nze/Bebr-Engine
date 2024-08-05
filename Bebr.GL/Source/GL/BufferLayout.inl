#pragma once
#include "BufferLayout.hpp"

template<typename T>
inline void Bebr::GL::BufferLayout::Push(bool normalized, std::uint32_t count)
{}

template<>
void Bebr::GL::BufferLayout::Push<std::int8_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<std::int16_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<std::int32_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<std::uint8_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<std::uint16_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<std::uint32_t>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<float>(bool normalized, std::uint32_t count);
template<>
void Bebr::GL::BufferLayout::Push<double>(bool normalized, std::uint32_t count);
