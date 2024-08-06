#include "Main.hpp"
#include "Camera.hpp"
#include "Timer.hpp"

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GL/BufferLayout.hpp>
#include <GL/ElementBuffer.hpp>
#include <GL/Program.hpp>
#include <GL/Renderer.hpp>
#include <GL/VertexArray.hpp>
#include <GL/VertexBuffer.hpp>
#include <GL/Viewport.hpp>

#include <GUI/API.hpp>
#include <GUI/Button.hpp>
#include <GUI/ClosableWindow.hpp>
#include <GUI/Configurations.hpp>
#include <GUI/Style.hpp>
#include <GUI/Text.hpp>
#include <GUI/Window.hpp>

#include <System/Color.hpp>
#include <System/Matrix.hpp>
#include <System/Log.hpp>

#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>

#define INIT_MODULE(initFunc) if (std::int32_t error = initFunc()) return error

std::int32_t InitializeOpenGL()
{
    Bebr::GL::API::SetExperimental(true);
    if (!Bebr::GL::API::Initialize())
    {
        Bebr::System::Logln("error initializing GLEW");
        Bebr::Window::API::Terminate();
        return ERROR;
    }
    Bebr::GL::API::SetBlending(true);
    Bebr::GL::Blending::SetBlendFunction(Bebr::GL::Blending::Factor::SourceAlpha,
                                         Bebr::GL::Blending::Factor::OneMinusSourceAlpha);
    return SUCCESS;
}

std::int32_t InitializeImGui()
{
    if (!Bebr::GUI::API::InitializeMain())
    {
        Bebr::System::Logln("error initializing ImGui");
        return ERROR;
    }
    Bebr::GUI::Style::SetClassicTheme();
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::NavEnableKeyboard);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::NavEnableGamepad);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::ViewportsEnable);
    Bebr::GUI::Configurations::EnableFlag(Bebr::GUI::Configurations::Flag::DockingEnable);
    if (!Bebr::GUI::API::InitializeBackend())
    {
        Bebr::System::Logln("error initializing backend for ImGui");
        return ERROR;
    }
    return SUCCESS;
}

Bebr::System::Vector2F_t CalculateOffset(Bebr::Window::Keyboard& keyboard)
{
    static Timer timer;
    Bebr::System::Vector2F_t offset;
    const float speed = timer.GetDeltaTime() * 2.f;
    if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Left))
    {
        offset.x -= speed;
    }
    if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Right))
    {
        offset.x += speed;
    }
    if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Up))
    {
        offset.y += speed;
    }
    if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Down))
    {
        offset.y -= speed;
    }
    return offset;
}

std::int32_t main()
{
    if (!Bebr::Window::API::Initialize())
    {
        Bebr::System::Logln("error initializing GLFW");
        return ERROR;
    }

    Bebr::Window::BasicWindow window(640, 480, "Bebra window");
    Bebr::Window::Keyboard keyboard(window);
    window.MakeCurrentContext();

    INIT_MODULE(InitializeOpenGL);
    INIT_MODULE(InitializeImGui);

    float vertices[] = {
        // Position        // Color
       +0.5f, +0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.f, // Top-Right
       -0.5f, +0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.f, // Top-left
       -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.f, // Bottom-left
       +0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.f, // Bottom-right
    };
    std::uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    Bebr::System::Matrix4_t<float> position = Bebr::System::CreateIdentityMatrix<float, 4>();
    Camera camera(0.f, 0.f, 4.f, 4.f);

    Bebr::GL::Program shaderProgram("Resources/vertex shader.glsl",
                                    "Resources/fragment shader.glsl");
    Bebr::GL::BufferLayout bufferLayout;
    bufferLayout.Push<float>(false, 3); // Position
    bufferLayout.Push<float>(false, 4); // Color
    Bebr::GL::VertexBuffer vertexBuffer;
    vertexBuffer.Bind();
    vertexBuffer.BufferData(vertices, sizeof(vertices));
    vertexBuffer.Unbind();
    Bebr::GL::ElementBuffer indexBuffer;
    indexBuffer.Bind();
    indexBuffer.BufferData(indices, sizeof(indices));
    indexBuffer.Unbind();
    Bebr::GL::VertexArray vertexArray;
    vertexArray.Bind();
    vertexArray.SetAttributes(vertexBuffer, bufferLayout);
    vertexArray.Unbind();

    while (window.IsOpen())
    {
        Bebr::Window::API::PollEvents();
        keyboard.Update();

        Bebr::System::Vector2F_t offset = CalculateOffset(keyboard);
        position[3][0] += offset.x;
        position[3][1] += offset.y;

        Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), window.GetSize());
        Bebr::GL::Renderer::Clear();
        Bebr::GL::Renderer::ClearColor();

        shaderProgram.Activate();
        shaderProgram.SetUniform("uModel", position);
        shaderProgram.SetUniform("uCamera", camera.GetMatrix());
        Bebr::GL::Renderer::Render(vertexArray, indexBuffer, Bebr::GL::Renderer::Mode::Triangles, 6);
        shaderProgram.Deactivate();

        Bebr::GUI::API::CreateFrame();
        Bebr::GUI::API::DockspaceOverViewport();
        static Bebr::GUI::ClosableWindow subwindow1("gui window");
        static Bebr::GUI::ClosableWindow subwindow2("im window");
        if (subwindow1.IsOpen())
        {
            if (subwindow1.Begin())
            {
                static Bebr::GUI::Button button("gui button");
                if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Escape))
                {
                    button.Render(200.f, 40.f);
                }
                else
                {
                    button.Render();
                }
            }
            subwindow1.End();
        }
        if (subwindow2.IsOpen())
        {
            if (subwindow2.Begin())
            {
                static Bebr::GUI::Text text("gui text");
                text.Render();
            }
            subwindow2.End();
        }
        Bebr::GUI::API::Render();

        window.SwapBuffers();
    }

    Bebr::Window::API::Terminate();
    return SUCCESS;
}
