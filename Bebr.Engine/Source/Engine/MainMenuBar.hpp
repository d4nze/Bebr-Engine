#pragma once
#include "FileBar.hpp"
#include "WindowBar.hpp"

namespace Bebr
{
namespace Engine
{
class MainMenuBar
{
public:
	MainMenuBar();
	~MainMenuBar() = default;

public:
	void Render();

	const FileBar&	GetFileBar() const;
	WindowBar&		GetWindowBar();

private:
	FileBar		m_fileBar;
	WindowBar	m_windowBar;
};
}
}
