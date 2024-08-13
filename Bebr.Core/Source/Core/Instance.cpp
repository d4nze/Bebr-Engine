#include "Instance.hpp"
#include "Scene.hpp"

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

void Bebr::Core::Instance::SetLayer(const std::string& name)
{
    if (m_layer->GetName() == name)
    {
        return;
    }
    if (InstanceLayer* layer = GetScene().GetInstanceLayer(name))
    {
        SetLayer(*layer);
    }
}

void Bebr::Core::Instance::SetLayer(InstanceLayer& layer)
{
    if (&layer == m_layer)
    {
        return;
    }
    for (auto it = m_layer->m_instances.begin(); it != m_layer->m_instances.end(); it++)
    {
        if (*it == this)
        {
            m_layer->m_instances.erase(it);
            break;
        }
    }
    layer.m_instances.push_back(this);
    m_layer = &layer;
}

Bebr::Core::InstanceLayer& Bebr::Core::Instance::GetLayer() const
{
    return *m_layer;
}
