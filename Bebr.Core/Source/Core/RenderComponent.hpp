#pragma once
#include "Instance.hpp"
#include "SceneCarrier.hpp"

namespace Bebr
{
namespace Core
{
class RenderTarget;

class RenderComponent : public SceneCarrier
{
public:
	RenderComponent(Instance& instance, Scene& scene);
	RenderComponent(const RenderComponent&) = delete;
	~RenderComponent()						= default;

public:
	virtual void Render(RenderTarget& renderTarget) = 0;

	Instance& GetInstance() const;

private:
	Instance& m_instance;
};
}
}
