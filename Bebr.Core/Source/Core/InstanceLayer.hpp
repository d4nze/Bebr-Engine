#pragma once
#include "Layer.hpp"
#include "Instance.hpp"
#include <vector>
#include <queue>

namespace Bebr
{
namespace Core
{
class InstanceLayer : public Layer
{
public:
	InstanceLayer(Scene& scene, const std::string& name);
	InstanceLayer(const InstanceLayer&) = delete;
	~InstanceLayer();

public:
	Instance&	CreateInstance(const std::string& name = "instance");
	void		RemoveInstance(Instance& instance);
	bool		HasInstance(Instance& instance) const;

	std::size_t GetSize() const;

public:
	std::vector<Instance*>::iterator		begin();
	std::vector<Instance*>::iterator		end();
	std::vector<Instance*>::const_iterator	begin()	const;
	std::vector<Instance*>::const_iterator	end()	const;

public:
	Instance* operator[](std::size_t index) const;

private:
	void ClearRemoves();

	friend Scene;
	
private:
	std::vector<Instance*>	m_instances;
	std::queue<Instance*>	m_removes;

	friend Instance;
};
}
}
