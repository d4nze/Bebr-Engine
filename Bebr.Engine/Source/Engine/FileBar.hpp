#pragma once
#include <GUI/MenuItem.hpp>

namespace Bebr
{
namespace Engine
{
class FileBar
{
public:
	FileBar();
	FileBar(const FileBar&) = delete;
	~FileBar()				= default;

public:
	void Render();

	const GUI::MenuItem& GetSaveItem()	const;
	const GUI::MenuItem& GetOpenItem()	const;
	const GUI::MenuItem& GetCloseItem() const;

private:
	std::string		m_name;
	GUI::MenuItem	m_save;
	GUI::MenuItem	m_open;
	GUI::MenuItem	m_close;
};
}
}
