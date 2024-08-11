#pragma once
#include "FileBar.hpp"

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

	const FileBar& GetFileBar() const;

private:
	FileBar m_fileBar;
};
}
}
