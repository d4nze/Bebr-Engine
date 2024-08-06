#pragma once
#include "Window.hpp"

namespace Bebr
{
namespace GUI
{
class ClosableWindow : public Window
{
public:
	ClosableWindow(const std::string& name, bool open = true);
	ClosableWindow(const ClosableWindow&) = default;
	~ClosableWindow() = default;

public:
	bool Begin();

	bool IsOpen() const;

private:
	bool m_open;
};
}
}
