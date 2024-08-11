#include "ResourcesFolder.hpp"
#include <GUI/TreeNode.hpp>

Bebr::Engine::ResourcesFolder::ResourcesFolder()
    : GUI::ClosableWindow   ("Resources Folder")
    , m_folderName          ("Resources")
    , m_updated             (false)
    , m_selected            (nullptr)
    , m_inspectable         (Inspectable::Type::Nothing)
{}

void Bebr::Engine::ResourcesFolder::Render()
{
    if (Begin())
    {
        Bebr::GUI::TreeNode node(m_folderName);
        node.AddFlag(GUI::TreeNode::Flag::OpenOnArrow);
        node.AddFlag(GUI::TreeNode::Flag::OpenOnDoubleClick);
        if (node.Begin())
        {
            RenderDirectory(m_folderName);
            node.End();
        }
    }
    End();
}

bool Bebr::Engine::ResourcesFolder::IsUpdated() const
{
    return false;
}

Bebr::Engine::Inspectable Bebr::Engine::ResourcesFolder::GetInspectable() const
{
    return m_inspectable;
}

void Bebr::Engine::ResourcesFolder::RenderDirectory(const std::filesystem::path& dirPath)
{
    for (const auto& entry : std::filesystem::directory_iterator(dirPath))
    {
        Bebr::GUI::TreeNode node(entry.path().filename().string().c_str());
        if (entry.is_directory())
        {
            node.AddFlag(GUI::TreeNode::Flag::OpenOnArrow);
            node.AddFlag(GUI::TreeNode::Flag::OpenOnDoubleClick);
            if (node.Begin())
            {
                RenderDirectory(entry.path());
                node.End();
            }
        }
        else
        {
            node.AddFlag(Bebr::GUI::TreeNode::Flag::Leaf);
            node.AddFlag(Bebr::GUI::TreeNode::Flag::NoTreePushOnOpen);
            node.Begin();
        }
    }
}
