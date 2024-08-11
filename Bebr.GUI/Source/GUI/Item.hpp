#pragma once

namespace Bebr
{
namespace GUI
{
class Item
{
public:
	Item() = default;
	Item(const Item&) = default;
	~Item() = default;

public:
	bool IsClicked() const;
	
	bool IsDeactivatedAfterEdit() const;
};
}
}
