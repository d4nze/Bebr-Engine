#include "Component.hpp"

Bebr::Core::Component::Component(Instance& instance, Scene& scene)
	: SceneCarrier	(scene)
	, m_instance	(instance)
{}

Bebr::Core::Instance& Bebr::Core::Component::GetInstance() const
{
	return m_instance;
}
