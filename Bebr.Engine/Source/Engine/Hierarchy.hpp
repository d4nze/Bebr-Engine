#pragma once
#include <GUI/TreeNode.hpp>
#include <GUI/Window.hpp>
#include <Core/Scene.hpp>

namespace Bebr
{
namespace Engine
{
class Hierarchy : public GUI::ClosableWindow
{
public:
	Hierarchy();
	Hierarchy(const Hierarchy&) = delete;
	~Hierarchy()				= default;

public:
	void Render();

private:
	Core::Scene m_scene;
};
}
}
