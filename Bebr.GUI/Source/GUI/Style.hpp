#pragma once

namespace Bebr
{
namespace GUI
{
class Style
{
public:
	Style() = delete;

public:
	static void SetLightTheme();
	static void SetDarkTheme();
	static void SetClassicTheme();

	static void BeginDisabled(bool disabled = true);
	static void EndDisabled();
};
}
}
