#include "InstanceLayer.hpp"
#include <algorithm>

Bebr::Core::InstanceLayer::InstanceLayer(Scene& scene, const std::string& name) : Layer(scene, name)
{}

Bebr::Core::InstanceLayer::~InstanceLayer()
{
	for (Instance* instance : m_instances)
	{
		delete instance;
	}
}

Bebr::Core::Instance& Bebr::Core::InstanceLayer::CreateInstance(const std::string& name)
{
	Instance* newInstance = new Instance(GetScene(), *this, name);
	m_instances.push_back(newInstance);
	return *newInstance;
}

void Bebr::Core::InstanceLayer::RemoveInstance(Instance& instance)
{
	if (HasInstance(instance))
	{
		m_removes.push(&instance);
	}
}

bool Bebr::Core::InstanceLayer::HasInstance(Instance& instance) const
{
	return std::find(m_instances.begin(), m_instances.end(), &instance) != m_instances.end();
}

std::size_t Bebr::Core::InstanceLayer::GetSize() const
{
	return m_instances.size();
}

std::vector<Bebr::Core::Instance*>::iterator Bebr::Core::InstanceLayer::begin()
{
	return m_instances.begin();
}

std::vector<Bebr::Core::Instance*>::iterator Bebr::Core::InstanceLayer::end()
{
	return m_instances.end();
}

std::vector<Bebr::Core::Instance*>::const_iterator Bebr::Core::InstanceLayer::begin() const
{
	return m_instances.begin();
}

std::vector<Bebr::Core::Instance*>::const_iterator Bebr::Core::InstanceLayer::end() const
{
	return m_instances.end();
}

Bebr::Core::Instance* Bebr::Core::InstanceLayer::operator[](std::size_t index) const
{
	if (index < m_instances.size())
	{
		return m_instances[index];
	}
	return nullptr;
}

void Bebr::Core::InstanceLayer::ClearRemoves()
{
	while (!m_removes.empty())
	{
		auto it = std::find(m_instances.begin(), m_instances.end(), m_removes.front());
		m_removes.pop();
		m_instances.erase(it);
	}
}
