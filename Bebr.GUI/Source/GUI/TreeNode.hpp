#pragma once
#include "Item.hpp"
#include <string>
#include <vector>

namespace Bebr
{
namespace GUI
{
class TreeNode : public Item
{
public:
	TreeNode(const std::string& name);
    TreeNode(const TreeNode&)   = delete;
    ~TreeNode()                 = default;

public:
    enum class Flag
    {
        None                    = 0,
        Selected                = 1 << 0,
        Framed                  = 1 << 1,
        AllowOverlap            = 1 << 2,
        NoTreePushOnOpen        = 1 << 3,
        NoAutoOpenOnLog         = 1 << 4,
        DefaultOpen             = 1 << 5,
        OpenOnDoubleClick       = 1 << 6,
        OpenOnArrow             = 1 << 7,
        Leaf                    = 1 << 8,
        Bullet                  = 1 << 9,
        FramePadding            = 1 << 10,
        SpanAvailWidth          = 1 << 11,
        SpanFullWidth           = 1 << 12,
        SpanTextWidth           = 1 << 13,
        SpanAllColumns          = 1 << 14,
        NavLeftJumpsBackHere    = 1 << 15
    };

public:
    bool Begin();
    void End();

    void AddFlag(Flag flag);
    void RemoveFlag(Flag flag);

private:
    std::string     m_name;
    std::int32_t    m_flags;
};
}
}
