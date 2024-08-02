#include "Keyboard.hpp"
#include "BasicWindow.hpp"
#include <glfw3.h>

Bebr::Window::Keyboard::Keyboard(const BasicWindow& window)
    : m_handler(window.m_handler)
    , m_states()
{}

bool Bebr::Window::Keyboard::IsKeyDown(Key key) const
{
    const KeyState& state = GetKeyState(key);
    return state == KeyState::Down || state == KeyState::Pressed;
}

bool Bebr::Window::Keyboard::IsKeyUp(Key key) const
{
    const KeyState& state = GetKeyState(key);
    return state == KeyState::Up || state == KeyState::Released;
}

bool Bebr::Window::Keyboard::IsKeyPressed(Key key) const
{
    return GetKeyState(key) == KeyState::Pressed;
}

bool Bebr::Window::Keyboard::IsKeyReleased(Key key) const
{
    return GetKeyState(key) == KeyState::Released;
}

Bebr::Window::Keyboard::KeyState Bebr::Window::Keyboard::GetKeyState(Key key) const
{
    return m_states[static_cast<unsigned int>(key)];
}

void Bebr::Window::Keyboard::Update()
{
    const unsigned int size = static_cast<unsigned int>(Key::Count);
    for (unsigned int i = 0; i < size; i++)
    {
        int key = glfwGetKey(m_handler, i);
        KeyState& state = m_states[i];
        if (key == GLFW_PRESS)
        {
            if (state == KeyState::Pressed)
                state = KeyState::Down;
            else if (state != KeyState::Down)
                state = KeyState::Pressed;
        }
        else if (key == GLFW_RELEASE)
        {
            if (state == KeyState::Released)
                state = KeyState::Up;
            else if (state != KeyState::Up)
                state = KeyState::Released;
        }
    }
}
