#include "SceneHierarchy.hpp"
#include <GUI/DragDrop.hpp>
#include <GUI/TreeNode.hpp>
#include <GUI/Text.hpp>
#include <System/Log.hpp>

Bebr::Engine::SceneHierarchy::SceneHierarchy()
	: ClosableWindow("Scene hierarchy")
	, m_updated		(false)
	, m_selected	(nullptr)
	, m_inspectable	(Inspectable::Type::Nothing)
{
	Core::InstanceLayer* instanceLayer1 = m_scene.CreateInstanceLayer("instance layer 1");
	Core::InstanceLayer* instanceLayer2 = m_scene.CreateInstanceLayer("instance layer 2");
	Core::InstanceLayer* instanceLayer3 = m_scene.CreateInstanceLayer("instance layer 3");
	instanceLayer1->CreateInstance("instance 1");
	instanceLayer1->CreateInstance("instance 2");
	instanceLayer1->CreateInstance("instance 3");
	instanceLayer2->CreateInstance("instance 4");
	instanceLayer2->CreateInstance("instance 5");
}

void Bebr::Engine::SceneHierarchy::Render()
{
	m_updated = false;
	if (!Begin())
	{
		End();
		return;
	}
	for (Core::Scene::LayerHandler handler : m_scene)
	{
		if (handler.type == Core::Scene::LayerType::Instance)
		{
			RenderInstanceLayer(*reinterpret_cast<Core::InstanceLayer*>(handler.layer));
		}
	}
	End();

	while (!m_instancesDrag.empty())
	{
		auto pair = m_instancesDrag.front();
		m_instancesDrag.pop();
		pair.first->SetLayer(*pair.second);
	}
}

bool Bebr::Engine::SceneHierarchy::IsUpdated() const
{
	return m_updated;
}

Bebr::Engine::Inspectable Bebr::Engine::SceneHierarchy::GetInspectable() const
{
	return m_inspectable;
}

void Bebr::Engine::SceneHierarchy::RenderInstanceLayer(Core::InstanceLayer& instanceLayer)
{
	GUI::TreeNode layerNode(instanceLayer.GetName());
	layerNode.AddFlag(GUI::TreeNode::Flag::OpenOnArrow);
	layerNode.AddFlag(GUI::TreeNode::Flag::OpenOnDoubleClick);
	layerNode.AddFlag(GUI::TreeNode::Flag::DefaultOpen);
	if (instanceLayer.GetSize() == 0)
	{
		layerNode.AddFlag(GUI::TreeNode::Flag::Bullet);
	}
	if (&instanceLayer == m_selected)
	{
		layerNode.AddFlag(GUI::TreeNode::Flag::Selected);
	}

	if (layerNode.Begin())
	{
		InstanceLayerTarget(instanceLayer);
		if (layerNode.IsClicked())
		{
			m_selected = &instanceLayer;
			m_updated = true;
			m_inspectable = Inspectable(Inspectable::Type::InstanceLayer, &instanceLayer);
		}
		for (Core::Instance* instance : instanceLayer)
		{
			RenderInstance(*instance);
		}
		layerNode.End();
	}
	else if (layerNode.IsClicked())
	{
		m_selected = &instanceLayer;
		m_updated = true;
		m_inspectable = Inspectable(Inspectable::Type::InstanceLayer, &instanceLayer);
	}
	else
	{
		InstanceLayerTarget(instanceLayer);
	}
}

void Bebr::Engine::SceneHierarchy::RenderInstance(Core::Instance& instance)
{
	GUI::TreeNode instanceNode(instance.GetName());
	instanceNode.AddFlag(GUI::TreeNode::Flag::Bullet);
	if (&instance == m_selected)
	{
		instanceNode.AddFlag(GUI::TreeNode::Flag::Selected);
	}
	if (instanceNode.Begin())
	{
		instanceNode.End();
	}
	if (instanceNode.IsClicked())
	{
		m_selected = &instance;
		m_updated = true;
		m_inspectable = Inspectable(Inspectable::Type::Instance, &instance);
	}

	GUI::DragDrop::Source source;
	if (source.Begin())
	{
		GUI::Text sourceText(instance.GetName());
		sourceText.Render();
		source.SetPayload<Core::Instance*>("instance ref", &instance);
		source.End();
	}
}

void Bebr::Engine::SceneHierarchy::InstanceLayerTarget(Core::InstanceLayer& instanceLayer)
{
	GUI::DragDrop::Target target;
	if (target.Begin())
	{
		if (Core::Instance* instance = target.AcceptPayload<Core::Instance*>("instance ref"))
		{
			this->m_instancesDrag.push({ instance, &instanceLayer });
		}
		target.End();
	}
}
