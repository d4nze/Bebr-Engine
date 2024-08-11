#pragma once
#include <GUI/Window.hpp>
#include <Core/Instance.hpp>
#include <Core/InstanceLayer.hpp>

namespace Bebr
{
namespace Engine
{
class Inspectable
{
public:
	enum class Type
	{
		Nothing,
		InstanceLayer,
		Instance
	};

public:
	Inspectable(Type type, void* data = nullptr);
	Inspectable(const Inspectable&) = default;
	~Inspectable()					= default;

public:
	Type	GetType() const;
	void*	GetData() const;

private:
	Type	m_type;
	void*	m_data;
};

class Inspector : public GUI::ClosableWindow
{
public:
	Inspector();
	Inspector(const Inspector&) = delete;
	~Inspector()				= default;

public:
	void Render();
	void SetInspectable(const Inspectable& inspectable);

private:
	void InspectNothing();
	void InspectInstance(Core::Instance* instance);
	void InspectInstanceLayer(Core::InstanceLayer* instanceLayer);

private:
	Inspectable m_inspectable;
};
}
}
