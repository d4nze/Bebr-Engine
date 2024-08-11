#include "Initializer.hpp"

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GUI/API.hpp>
#include <GUI/Configurations.hpp>
#include <GUI/Style.hpp>
#include <System/Log.hpp>
#include <Window/API.hpp>

Bebr::Engine::InitializeException::InitializeException(const std::string& message) : m_message(message)
{}

void Bebr::Engine::InitializeException::LogErrorMessage() const
{
    Bebr::System::Logln(m_message);
}

Bebr::Engine::GLFWInitializer::GLFWInitializer()
{
    if (!Bebr::Window::API::Initialize())
    {
        throw InitializeException("error initializing GLFW");
    }
}

Bebr::Engine::GLFWInitializer::~GLFWInitializer()
{
    Bebr::Window::API::Terminate();
}

Bebr::Engine::GLInitializer::GLInitializer()
{
    Bebr::GL::API::SetExperimental(true);
    if (!Bebr::GL::API::Initialize())
    {
        Bebr::Window::API::Terminate();
        throw InitializeException("error initializing GLEW");
    }
    Bebr::GL::API::SetBlending(true);
    Bebr::GL::Blending::SetBlendFunction(Bebr::GL::Blending::Factor::SourceAlpha,
                                         Bebr::GL::Blending::Factor::OneMinusSourceAlpha);
}

Bebr::Engine::GUIInitializer::GUIInitializer()
{
    if (!Bebr::GUI::API::InitializeMain())
    {
        Bebr::Window::API::Terminate();
        throw InitializeException("error initializing ImGui");
    }
    Bebr::GUI::Style::SetClassicTheme();
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::NavEnableKeyboard);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::NavEnableGamepad);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::ViewportsEnable);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::DockingEnable);
    if (!Bebr::GUI::API::InitializeBackend())
    {
        Bebr::Window::API::Terminate();
        throw InitializeException("error initializing backend for ImGui");
    }
}
