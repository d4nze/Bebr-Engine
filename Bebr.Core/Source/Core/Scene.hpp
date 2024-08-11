#pragma once
#include "InstanceLayer.hpp"

namespace Bebr
{
namespace Core
{
class Scene
{
public: // Constructors and destructor
	Scene()				= default;
	Scene(const Scene&) = delete;
	~Scene();

public: // Local types
	enum class LayerType
	{
		Instance,
		Null
	};

	struct LayerHandler
	{
		Layer* layer;
		LayerType type;

		LayerHandler(Layer* layer, LayerType type) : layer(layer), type(type) {}
	};

public: // Methods
	InstanceLayer*	CreateInstanceLayer(const std::string& name);
	void			RemoveInstanceLayer(const std::string& name);
	InstanceLayer*	GetInstanceLayer(const std::string& name)	const;
	bool			HasInstanceLayer(const std::string& name)	const;
	std::size_t		GetInstanceLayerCount()						const;

	LayerHandler	GetLayer(const std::string& name)			const;
	bool			HasLayer(const std::string name)			const;
	std::size_t		GetLayerCount()								const;

public: // Iterators
	std::vector<LayerHandler>::iterator			begin();
	std::vector<LayerHandler>::iterator			end();
	std::vector<LayerHandler>::const_iterator	begin()	const;
	std::vector<LayerHandler>::const_iterator	end()	const;

public: // Operators
	LayerHandler operator[](std::size_t index) const;

private: // Members
	std::vector<InstanceLayer*>	m_instanceLayers;
	std::vector<LayerHandler>	m_layers;
};
}
}
