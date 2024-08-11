#pragma once
#include "Item.hpp"
#include <string>

namespace Bebr
{
namespace GUI
{
enum class InputFlag
{
	None                    = 0,
	Repeat                  = 1 << 0, 
	RouteActive             = 1 << 10,
	RouteFocused            = 1 << 11,
	RouteGlobal             = 1 << 12,
	RouteAlways             = 1 << 13,
	RouteOverFocused        = 1 << 14,
	RouteOverActive         = 1 << 15,
	RouteUnlessBgFocused    = 1 << 16,
	RouteFromRootWindow     = 1 << 17,
	Tooltip                 = 1 << 18,
};

class InputText : public Item
{
public:
	InputText(const std::string& name, const std::string& text, std::size_t bufferSize = 256);
	InputText(const InputText&)	= delete;
	~InputText()				= default;

public:
	enum class Flag
	{
		None                = 0,
		CharsDecimal        = 1 << 0,
		CharsHexadecimal    = 1 << 1,
		CharsScientific     = 1 << 2,
		CharsUppercase      = 1 << 3,
		CharsNoBlank        = 1 << 4,
		AllowTabInput       = 1 << 5, 
		EnterReturnsTrue    = 1 << 6, 
		EscapeClearsAll     = 1 << 7, 
		CtrlEnterForNewLine = 1 << 8,
		ReadOnly            = 1 << 9, 
		Password            = 1 << 10,
		AlwaysOverwrite     = 1 << 11,
		AutoSelectAll       = 1 << 12,
		ParseEmptyRefVal    = 1 << 13,
		DisplayEmptyRefVal  = 1 << 14,
		NoHorizontalScroll  = 1 << 15,
		NoUndoRedo          = 1 << 16,
		CallbackCompletion  = 1 << 17,
		CallbackHistory     = 1 << 18,
		CallbackAlways      = 1 << 19,
		CallbackCharFilter  = 1 << 20,
		CallbackResize      = 1 << 21,
		CallbackEdit        = 1 << 22,
	};

public:
	bool Render();

	void AddFlag(Flag flag);
	void RemoveFlag(Flag flag);

	std::string GetData() const;

private:
	std::string		m_name;
	char*			m_data;
	std::size_t		m_size;
	std::int32_t	m_flags;
};
}
}
