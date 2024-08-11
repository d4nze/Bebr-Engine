#pragma once

namespace Bebr
{
namespace Core
{
class Scene;

class SceneCarrier
{
public:
	SceneCarrier(Scene& scene);
	SceneCarrier(const SceneCarrier&)	= default;
	~SceneCarrier()						= default;

public:
	Scene& GetScene() const;

private:
	Scene& m_scene;
};
}
}
