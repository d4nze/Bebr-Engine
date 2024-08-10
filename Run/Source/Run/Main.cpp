#include "Main.hpp"

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GL/Renderer.hpp>
#include <GL/Viewport.hpp>

#include <System/Log.hpp>

#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>

std::int32_t main()
{
    // Bebr.Window Module
    if (!Bebr::Window::API::Initialize())
    {
        Bebr::System::Logln("error initializing GLFW");
        return error;
    }
    Bebr::Window::BasicWindow window(640, 480, "Bebr Engine");
    window.MakeCurrentContext();

    // Bebr.GL Module
    Bebr::GL::API::SetExperimental(true);
    if (!Bebr::GL::API::Initialize())
    {
        Bebr::System::Logln("error initializing GLEW");
        Bebr::Window::API::Terminate();
        return error;
    }
    Bebr::GL::API::SetBlending(true);
    Bebr::GL::Blending::SetBlendFunction(Bebr::GL::Blending::Factor::SourceAlpha,
                                         Bebr::GL::Blending::Factor::OneMinusSourceAlpha);

    // Main Loop
    while (window.IsOpen())
    {
        Bebr::Window::API::PollEvents();

        Bebr::GL::Renderer::Clear();
        Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), window.GetSize());
        Bebr::GL::Renderer::ClearColor(Bebr::System::ColorF::green);

        window.SwapBuffers();
    }

    // Clean Up
    Bebr::Window::API::Terminate();
    return success;
}
