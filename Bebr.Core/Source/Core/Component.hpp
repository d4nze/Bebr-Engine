#pragma once
#include "Instance.hpp"
#include "SceneCarrier.hpp"

namespace Bebr
{
namespace Core
{
class Component : public SceneCarrier
{
public:
	Component(Instance& instance, Scene& scene);
	Component(const Component&) = delete;
	~Component()				= default;

public:
	Instance& GetInstance() const;

private:
	Instance& m_instance;
};
}
}
