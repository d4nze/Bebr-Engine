#include "Hierarchy.hpp"
#include <GUI/Text.hpp>

Bebr::Engine::Hierarchy::Hierarchy() : ClosableWindow("Scene hierarchy")
{
	Core::InstanceLayer* instanceLayer1 = m_scene.CreateInstanceLayer("instance layer 1");
	Core::InstanceLayer* instanceLayer2 = m_scene.CreateInstanceLayer("instance layer 2");
	instanceLayer1->CreateInstance("instance 1");
	instanceLayer1->CreateInstance("instance 2");
	instanceLayer1->CreateInstance("instance 3");
	instanceLayer2->CreateInstance("instance 4");
	instanceLayer2->CreateInstance("instance 5");
}

void Bebr::Engine::Hierarchy::Render()
{
	if (Begin())
	{
		for (Core::Scene::LayerHandler handler : m_scene)
		{
			GUI::Text layerText(handler.layer->GetName());
			layerText.Render();
			if (handler.type == Core::Scene::LayerType::Instance)
			{
				Core::InstanceLayer& instanceLayer = *reinterpret_cast<Core::InstanceLayer*>(handler.layer);
				for (Core::Instance* instance : instanceLayer)
				{
					GUI::Text instanceButton(instance->GetName());
					instanceButton.Render();
				}
			}
		}
	}
	End();
}
