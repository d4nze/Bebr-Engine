#pragma once
#include "SceneCarrier.hpp"
#include <string>

namespace Bebr
{
namespace Engine
{
class Inspector;
}
namespace Core
{
class InstanceLayer;

class Instance : public SceneCarrier
{
public:
	Instance(Scene& scene, InstanceLayer& layer, const std::string& name);
	Instance(const Instance&) = delete;
	~Instance() = default;

public:
	void SetName(const std::string& name);
	const std::string& GetName() const;

	InstanceLayer& GetLayer() const;

private:
	std::string		m_name;
	InstanceLayer*	m_layer; // Guaranteed to be not null

	friend Engine::Inspector;
};
}
}
