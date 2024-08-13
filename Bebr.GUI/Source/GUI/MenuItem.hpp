#pragma once
#include "Item.hpp"
#include <string>

namespace Bebr
{
namespace GUI
{
class MenuItem : public Item
{
public:
	MenuItem(const std::string& name);
	MenuItem(const std::string& name, const std::string& hotkey);
	MenuItem(const MenuItem&)	= default;
	~MenuItem()					= default;

public:
	void Render();
	bool IsPressed() const;

	void disable();
	void enable();
	bool isEnabled() const;

protected:
	std::string m_name;
	std::string m_hotkey;
	bool		m_pressed;
	bool		m_enabled;
};

class TogglableMenuItem : public MenuItem
{
public:
	TogglableMenuItem(const std::string& name, bool toggled = true);
	TogglableMenuItem(const std::string& name, const std::string& hotkey, bool toggled = true);
	TogglableMenuItem(const TogglableMenuItem&) = default;
	~TogglableMenuItem() = default;

public:
	void Render();

	void SetToggleMode(bool enabled);
	bool IsToggled() const;

private:
	bool m_toggled;
};
}
}
