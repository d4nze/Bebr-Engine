#pragma once

namespace Bebr
{
namespace GUI
{
class API
{
public:
	API() = delete;

public:
	static bool InitializeMain();
	static bool InitializeBackend();

	static void CreateFrame();
	static void Render();

	static void DockspaceOverViewport();
	static void DemoWindow();
};
}
}
