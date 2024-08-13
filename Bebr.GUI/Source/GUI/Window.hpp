#pragma once
#include <System/Vector2.hpp>
#include <string>

namespace Bebr
{
namespace GUI
{
class Window
{
public:
	Window(const std::string& name);
	Window(const Window&) = default;
	~Window() = default;

public:
    enum class Flag
    {
        None = 0,
        NoTitleBar = 1 << 0,
        NoResize = 1 << 1,
        NoMove = 1 << 2,
        NoScrollbar = 1 << 3,
        NoScrollWithMouse = 1 << 4,
        NoCollapse = 1 << 5,
        AlwaysAutoResize = 1 << 6,
        NoBackground = 1 << 7,
        NoSavedSettings = 1 << 8,
        NoMouseInputs = 1 << 9,
        MenuBar = 1 << 10,
        HorizontalScrollbar = 1 << 11,
        NoFocusOnAppearing = 1 << 12,
        NoBringToFrontOnFocus = 1 << 13,
        AlwaysVerticalScrollbar = 1 << 14,
        AlwaysHorizontalScrollbar = 1 << 15,
        NoNavInputs = 1 << 16,
        NoNavFocus = 1 << 17,
        UnsavedDocument = 1 << 18,
        NoDocking = 1 << 19,
        NoNav = NoNavInputs | NoNavFocus,
        NoDecoration = NoTitleBar | NoResize | NoScrollbar | NoCollapse,
        NoInputs = NoMouseInputs | NoNavInputs | NoNavFocus
    };

public:
	bool Begin();
	void End();

    void AddFlag(Flag flag);
    void RemoveFlag(Flag flag);

    System::Vector2F_t GetSize() const;

    const std::string& GetName() const;

protected:
	std::string m_name;
    std::int32_t m_flags;
};

class ClosableWindow : public Window
{
public:
    ClosableWindow(const std::string& name, bool open = true);
    ClosableWindow(const ClosableWindow&) = default;
    ~ClosableWindow() = default;

public:
    bool Begin();

    void Close();
    void Open();
    bool IsOpen() const;

private:
    bool m_open;
};
}
}
