#include "UpdateComponent.hpp"

Bebr::Core::UpdateComponent::UpdateComponent(Instance& instance, Scene& scene)
    : Component (instance, scene)
    , m_priority(0)
{}

void Bebr::Core::UpdateComponent::SetUpdatePriority(std::int32_t priority)
{
    m_priority = priority;
}

std::int32_t Bebr::Core::UpdateComponent::GetUpdatePriority() const
{
    return m_priority;
}
