#pragma once
#include <GUI/TreeNode.hpp>
#include <GUI/Window.hpp>
#include <Core/Scene.hpp>
#include <queue>
#include "Inspector.hpp"

namespace Bebr
{
namespace Engine
{
class SceneHierarchy : public GUI::ClosableWindow
{
public:
	SceneHierarchy();
	SceneHierarchy(const SceneHierarchy&)	= delete;
	~SceneHierarchy()						= default;

public:
	void Render();

	bool		IsUpdated()			const;
	Inspectable GetInspectable()	const;

private:
	void RenderInstanceLayer(Core::InstanceLayer& instanceLayer);
	void RenderInstance(Core::Instance& instance);
	
	void InstanceLayerTarget(Core::InstanceLayer& instanceLayer);

private:
	bool		m_updated;
	void*		m_selected;
	Inspectable m_inspectable;
	Core::Scene m_scene;
	std::queue<std::pair<Core::Instance*, Core::InstanceLayer*>> m_instancesDrag;
};
}
}
