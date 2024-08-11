#include "RenderComponent.hpp"

Bebr::Core::RenderComponent::RenderComponent(Instance& instance, Scene& scene)
    : SceneCarrier  (scene)
    , m_instance    (instance)
{}

Bebr::Core::Instance& Bebr::Core::RenderComponent::GetInstance() const
{
    return m_instance;
}
