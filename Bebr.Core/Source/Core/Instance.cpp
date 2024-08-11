#include "Instance.hpp"

Bebr::Core::Instance::Instance(Scene& scene, InstanceLayer& layer, const std::string& name)
    : SceneCarrier  (scene)
    , m_name        (name)
    , m_layer       (&layer)
{}

const std::string& Bebr::Core::Instance::GetName() const
{
    return m_name;
}

Bebr::Core::InstanceLayer& Bebr::Core::Instance::GetLayer() const
{
    return *m_layer;
}
