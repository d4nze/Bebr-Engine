#include "Instance.hpp"

Bebr::Core::Instance::Instance(Scene& scene, InstanceLayer& layer, const std::string& name)
    : SceneCarrier  (scene)
    , m_name        (name)
    , m_layer       (&layer)
{}

void Bebr::Core::Instance::SetName(const std::string& name)
{
    m_name = name;
}

const std::string& Bebr::Core::Instance::GetName() const
{
    return m_name;
}

Bebr::Core::InstanceLayer& Bebr::Core::Instance::GetLayer() const
{
    return *m_layer;
}
