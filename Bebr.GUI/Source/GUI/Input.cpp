#include "Input.hpp"
#include <imgui/imgui.h>
#include <cstring>

Bebr::GUI::InputText::InputText(const std::string& name, const std::string& text, std::size_t bufferSize)
	: m_name(name)
	, m_data(nullptr)
	, m_size(bufferSize)
	, m_flags(0)
{
	m_data = new char[text.size() + 1];
	std::strcpy(m_data, text.c_str());
}

bool Bebr::GUI::InputText::Render()
{
	return ImGui::InputText(m_name.c_str(), m_data, m_size);
}

void Bebr::GUI::InputText::AddFlag(Flag flag)
{
	m_flags |= static_cast<std::int32_t>(flag);
}

void Bebr::GUI::InputText::RemoveFlag(Flag flag)
{
	m_flags &= ~static_cast<std::int32_t>(flag);
}

std::string Bebr::GUI::InputText::GetData() const
{
	return std::string(m_data);
}
