#include "SceneHierarchy.hpp"
#include <GUI/TreeNode.hpp>
#include <GUI/Text.hpp>

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
	if (Begin())
	{
		for (Core::Scene::LayerHandler handler : m_scene)
		{
			if (handler.type == Core::Scene::LayerType::Instance)
			{
				Core::InstanceLayer& instanceLayer = *reinterpret_cast<Core::InstanceLayer*>(handler.layer);
				GUI::TreeNode layerNode(instanceLayer.GetName());
				layerNode.AddFlag(GUI::TreeNode::Flag::OpenOnArrow);
				layerNode.AddFlag(GUI::TreeNode::Flag::OpenOnDoubleClick);
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
					for (Core::Instance* instance : instanceLayer)
					{
						GUI::TreeNode instanceNode(instance->GetName());
						instanceNode.AddFlag(GUI::TreeNode::Flag::Bullet);
						if (instance == m_selected)
						{
							instanceNode.AddFlag(GUI::TreeNode::Flag::Selected);
						}
						if (instanceNode.Begin())
						{
							instanceNode.End();
						}
						if (instanceNode.IsClicked())
						{
							m_selected = instance;
							m_updated = true;
							m_inspectable = Inspectable(Inspectable::Type::Instance, instance);
						}
					}
					layerNode.End();
				}
				if (layerNode.IsClicked())
				{
					m_selected = &instanceLayer;
					m_updated = true;
					m_inspectable = Inspectable(Inspectable::Type::InstanceLayer, &instanceLayer);
				}
			}
		}
	}
	End();
}

bool Bebr::Engine::SceneHierarchy::IsUpdated() const
{
	return m_updated;
}

Bebr::Engine::Inspectable Bebr::Engine::SceneHierarchy::GetInspectable() const
{
	return m_inspectable;
}
