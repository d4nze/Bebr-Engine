#include "TreeNode.hpp"
#include <imgui/imgui.h>

Bebr::GUI::TreeNode::TreeNode(const std::string& name)
	: m_name	(name)
	, m_flags	(0)
{}

bool Bebr::GUI::TreeNode::Begin()
{
	return ImGui::TreeNodeEx(m_name.c_str(), m_flags);
}

void Bebr::GUI::TreeNode::End()
{
	ImGui::TreePop();
}

void Bebr::GUI::TreeNode::AddFlag(Flag flag)
{
	m_flags |= static_cast<std::int32_t>(flag);
}

void Bebr::GUI::TreeNode::RemoveFlag(Flag flag)
{
	m_flags &= ~static_cast<std::int32_t>(flag);
}
