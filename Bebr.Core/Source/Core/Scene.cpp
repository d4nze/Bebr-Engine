#include "Scene.hpp"

Bebr::Core::Scene::~Scene()
{
    for (InstanceLayer* layer : m_instanceLayers)
    {
        delete layer;
    }
}

Bebr::Core::InstanceLayer* Bebr::Core::Scene::CreateInstanceLayer(const std::string& name)
{
    if (!HasInstanceLayer(name))
    {
        if (HasLayer(name))
        {
            return nullptr;
        }
        InstanceLayer* newLayer = new InstanceLayer(*this, name);
        m_instanceLayers.push_back(newLayer);
        m_layers.emplace_back(newLayer, LayerType::Instance);
        return newLayer;
    }
    return GetInstanceLayer(name);
}

void Bebr::Core::Scene::RemoveInstanceLayer(const std::string& name)
{
    if (!HasInstanceLayer(name))
    {
        return;
    }
    InstanceLayer* instanceLayer = GetInstanceLayer(name);
    m_instanceLayers.erase(std::find(m_instanceLayers.begin(), m_instanceLayers.end(), instanceLayer));
    auto layerIt = std::find_if(m_layers.begin(),
                                m_layers.end(),
                                [&name](LayerHandler handler) { return handler.layer->GetName() == name; });
    m_layers.erase(layerIt);
    delete instanceLayer;
}

Bebr::Core::InstanceLayer* Bebr::Core::Scene::GetInstanceLayer(const std::string& name) const
{
    auto it = std::find_if(m_instanceLayers.begin(),
                           m_instanceLayers.end(),
                           [&name](const InstanceLayer* layer) { return layer->GetName() == name; });
    if (it == m_instanceLayers.end())
    {
        return nullptr;
    }
    return *it;
}

bool Bebr::Core::Scene::HasInstanceLayer(const std::string& name) const
{
    auto it = std::find_if(m_instanceLayers.begin(),
                           m_instanceLayers.end(),
                           [&name](const InstanceLayer* layer) { return layer->GetName() == name; });
    return it != m_instanceLayers.end();
}

std::size_t Bebr::Core::Scene::GetInstanceLayerCount() const
{
    return m_instanceLayers.size();
}

Bebr::Core::Scene::LayerHandler Bebr::Core::Scene::GetLayer(const std::string& name) const
{
    auto it = std::find_if(m_layers.begin(),
                           m_layers.end(),
                           [&name](LayerHandler handler) { return handler.layer->GetName() == name; });
    if (it == m_layers.end())
    {
        return LayerHandler{ nullptr, LayerType::Null };
    }
    return *it;
}

bool Bebr::Core::Scene::HasLayer(const std::string name) const
{
    auto it = std::find_if(m_layers.begin(),
                           m_layers.end(),
                           [&name](LayerHandler handler) { return handler.layer->GetName() == name; });
    return it != m_layers.end();
}

std::size_t Bebr::Core::Scene::GetLayerCount() const
{
    return m_layers.size();
}

std::vector<Bebr::Core::Scene::LayerHandler>::iterator Bebr::Core::Scene::begin()
{
    return m_layers.begin();
}

std::vector<Bebr::Core::Scene::LayerHandler>::iterator Bebr::Core::Scene::end()
{
    return m_layers.end();
}

std::vector<Bebr::Core::Scene::LayerHandler>::const_iterator Bebr::Core::Scene::begin() const
{
    return m_layers.begin();
}

std::vector<Bebr::Core::Scene::LayerHandler>::const_iterator Bebr::Core::Scene::end() const
{
    return m_layers.end();
}

Bebr::Core::Scene::LayerHandler Bebr::Core::Scene::operator[](std::size_t index) const
{
    if (index < m_layers.size())
    {
        return m_layers[index];
    }
    return LayerHandler{ nullptr, LayerType::Null };
}
