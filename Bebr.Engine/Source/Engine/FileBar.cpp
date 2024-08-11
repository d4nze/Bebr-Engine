#include "FileBar.hpp"
#include <GUI/MenuBar.hpp>

Bebr::Engine::FileBar::FileBar()
    : m_name    ("File")
    , m_save    ("Save", "Ctrl+S")
    , m_open    ("Open")
    , m_close   ("Close", "Alt+F4")
{}

void Bebr::Engine::FileBar::Render()
{
    if (GUI::MenuBar::BeginMenu(m_name))
    {
        m_save.Render();
        m_open.Render();
        m_close.Render();
        GUI::MenuBar::EndMenu();
    }
}

const Bebr::GUI::MenuItem& Bebr::Engine::FileBar::GetSaveItem() const
{
    return m_save;
}

const Bebr::GUI::MenuItem& Bebr::Engine::FileBar::GetOpenItem() const
{
    return m_open;
}

const Bebr::GUI::MenuItem& Bebr::Engine::FileBar::GetCloseItem() const
{
    return m_close;
}
