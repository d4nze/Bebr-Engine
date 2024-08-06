#pragma once

namespace Bebr
{
namespace GUI
{
class Configuration
{
public:
	Configuration() = delete;

public:
    enum class Flag
    {
        None = 0,
        NavEnableKeyboard = 1 << 0,
        NavEnableGamepad = 1 << 1,
        NavEnableSetMousePos = 1 << 2,
        NavNoCaptureKeyboard = 1 << 3,
        NoMouse = 1 << 4,
        NoMouseCursorChange = 1 << 5,
        NoKeyboard = 1 << 6,
        DockingEnable = 1 << 7,
        ViewportsEnable = 1 << 10,
        DpiEnableScaleViewports = 1 << 14,  
        DpiEnableScaleFonts = 1 << 15,
        IsSRGB = 1 << 20,
        IsTouchScreen = 1 << 21,
    };

public:
    static void EnableFlag(Flag flag);
    static void DisableFlag(Flag flag);
    static void SetFlag(Flag flag, bool enabled);
    static bool IsFlagEnabled(Flag flag);
};
}
}
