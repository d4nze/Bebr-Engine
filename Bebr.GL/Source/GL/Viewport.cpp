#include "Viewport.hpp"
#include <GL/glew.h>

static Bebr::System::Vector2I_t s_position, s_size;

static void UpdateViewport()
{
    glViewport(s_position.x, s_position.y, s_size.x, s_size.y);
}

void Bebr::GL::Viewport::SetRectangle(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height)
{
    s_position.x = x;
    s_position.y = y;
    s_size.x = width;
    s_size.y = height;
    UpdateViewport();
}

void Bebr::GL::Viewport::SetRectangle(const System::Vector2I_t& position, const System::Vector2I_t& size)
{
    s_position = position;
    s_size = size;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateX(std::int32_t x)
{
    s_position.x = x;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateY(std::int32_t y)
{
    s_position.y = y;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateWidth(std::int32_t width)
{
    s_size.x = width;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateHeight(std::int32_t height)
{
    s_size.y = height;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdatePosition(std::int32_t x, std::int32_t y)
{
    s_position.x = x;
    s_position.y = y;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdatePosition(const System::Vector2I_t& position)
{
    s_position = position;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateSize(std::int32_t width, std::int32_t height)
{
    s_size.x = width;
    s_size.y = height;
    UpdateViewport();
}

void Bebr::GL::Viewport::UpdateSize(const System::Vector2I_t& size)
{
    s_size = size;
    UpdateViewport();
}

std::int32_t Bebr::GL::Viewport::GetX()
{
    return s_position.x;
}

std::int32_t Bebr::GL::Viewport::GetY()
{
    return s_position.y;
}

std::int32_t Bebr::GL::Viewport::GetWidth()
{
    return s_size.x;
}

std::int32_t Bebr::GL::Viewport::GetHeight()
{
    return s_size.y;
}

const Bebr::System::Vector2I_t& Bebr::GL::Viewport::GetPosition()
{
    return s_position;
}

const Bebr::System::Vector2I_t& Bebr::GL::Viewport::GetSize()
{
    return s_size;
}
