#include "DragDrop.hpp"
#include <imgui/imgui.h>

Bebr::GUI::DragDrop::Source::Source() : m_flags(0)
{}

bool Bebr::GUI::DragDrop::Source::Begin()
{
    return ImGui::BeginDragDropSource(m_flags);
}

void Bebr::GUI::DragDrop::Source::End()
{
    ImGui::EndDragDropSource();
}

void Bebr::GUI::DragDrop::Source::SetPayload(const char* tag, const void* data, std::size_t size)
{
    ImGui::SetDragDropPayload(tag, data, size);
}

void Bebr::GUI::DragDrop::Source::AddFlag(Flag flag)
{
    m_flags |= static_cast<std::int32_t>(flag);
}

void Bebr::GUI::DragDrop::Source::RemoveFlag(Flag flag)
{
    m_flags &= ~static_cast<std::int32_t>(flag);
}

Bebr::GUI::DragDrop::Target::Target() : m_flags(0)
{}

bool Bebr::GUI::DragDrop::Target::Begin()
{
    return ImGui::BeginDragDropTarget();
}

void Bebr::GUI::DragDrop::Target::End()
{
    ImGui::EndDragDropTarget();
}

void* Bebr::GUI::DragDrop::Target::AcceptPayload(const char* tag)
{
    if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(tag, m_flags))
    {
        return payload->Data;
    }
    return nullptr;
}

void Bebr::GUI::DragDrop::Target::AddFlag(Flag flag)
{
    m_flags |= static_cast<std::int32_t>(flag);
}

void Bebr::GUI::DragDrop::Target::RemoveFlag(Flag flag)
{
    m_flags &= ~static_cast<std::int32_t>(flag);
}
