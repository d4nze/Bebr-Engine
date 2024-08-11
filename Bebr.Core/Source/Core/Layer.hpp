#pragma once
#include "SceneCarrier.hpp"
#include <string>

namespace Bebr
{
namespace Core
{
class Scene;

class Layer : public SceneCarrier
{
public:
	Layer(Scene& scene, const std::string& name);
	Layer(const Layer&) = default;
	~Layer() = default;

public:
	void SetName(const std::string& name);
	const std::string& GetName() const;

private:
	std::string m_name;
};
}
}
