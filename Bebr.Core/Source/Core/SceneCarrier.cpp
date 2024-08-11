#include "SceneCarrier.hpp"

Bebr::Core::SceneCarrier::SceneCarrier(Scene& scene) : m_scene(scene)
{}

Bebr::Core::Scene& Bebr::Core::SceneCarrier::GetScene() const
{
	return m_scene;
}
