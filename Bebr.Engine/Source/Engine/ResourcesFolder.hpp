#pragma once
#include "Inspector.hpp"
#include <GUI/Window.hpp>
#include <filesystem>

namespace Bebr
{
namespace Engine
{
class ResourcesFolder : public GUI::ClosableWindow
{
public:
	ResourcesFolder();
	ResourcesFolder(const ResourcesFolder&) = delete;
	~ResourcesFolder()						= default;

public:
	void Render();

	bool		IsUpdated()			const;
	Inspectable GetInspectable()	const;

private:
	void RenderDirectory(const std::filesystem::path& dirPath);

private:
	const std::string	m_folderName;
	bool				m_updated;
	void*				m_selected;
	Inspectable			m_inspectable;
};
}
}
