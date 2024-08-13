#pragma once
#include "Component.hpp"

namespace Bebr
{
namespace Core
{
class UpdateComponent : public Component
{
public:
	UpdateComponent(Instance& instance, Scene& scene);
	UpdateComponent(const UpdateComponent&) = delete;
	~UpdateComponent() = default;

public:
	virtual void Update() = 0;

	void SetUpdatePriority(std::int32_t priority);
	std::int32_t GetUpdatePriority() const;

private:
	std::int32_t m_priority;
};
}
}
