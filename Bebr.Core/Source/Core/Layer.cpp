#include "Layer.hpp"
#include "Scene.hpp"

Bebr::Core::Layer::Layer(Scene& scene, const std::string& name)
	: SceneCarrier	(scene)
	, m_name		(name)
{}

void Bebr::Core::Layer::SetName(const std::string& name)
{
	if (m_name == name)
	{
		return;
	}
	if (GetScene().HasLayer(name))
	{
		return;
	}
	m_name = name;
}

const std::string& Bebr::Core::Layer::GetName() const
{
	return m_name;
}
