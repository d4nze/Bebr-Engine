#pragma once
#include "Component.hpp"

namespace Bebr
{
namespace Core
{
class RenderTarget;

class RenderComponent : public Component
{
public:
	RenderComponent(Instance& instance, Scene& scene);
	RenderComponent(const RenderComponent&) = delete;
	~RenderComponent()						= default;

public:
	virtual void Render(RenderTarget& renderTarget) = 0;

	void SetRenderPriority(std::int32_t priority);
	std::int32_t GetRenderPriority() const;

private:
	std::int32_t m_priority;
};
}
}
