#include "RenderComponent.hpp"

Bebr::Core::RenderComponent::RenderComponent(Instance& instance, Scene& scene)
    : Component (instance, scene)
    , m_priority(0)
{}

void Bebr::Core::RenderComponent::SetRenderPriority(std::int32_t priority)
{
    m_priority = priority;
}

std::int32_t Bebr::Core::RenderComponent::GetRenderPriority() const
{
    return m_priority;
}
