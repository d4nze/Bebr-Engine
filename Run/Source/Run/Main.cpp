#include "Main.hpp"
#include "Camera.hpp"
#include "Timer.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GL/BufferLayout.hpp>
#include <GL/ElementBuffer.hpp>
#include <GL/Program.hpp>
#include <GL/Renderer.hpp>
#include <GL/Texture.hpp>
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

void InitializeTexture(Bebr::GL::Texture& texture)
{
    stbi_set_flip_vertically_on_load(1);
    int width, height, colors;
    const std::uint8_t* data = stbi_load("Resources/image.jpg", &width, &height, &colors, 4);

    texture.Bind();
    texture.SetMinFilter(Bebr::GL::Texture::Filter::Linear);
    texture.SetMagFilter(Bebr::GL::Texture::Filter::Linear);
    texture.SetWrapX(Bebr::GL::Texture::Wrap::Repeat);
    texture.SetWrapY(Bebr::GL::Texture::Wrap::Repeat);
    texture.Create(0, width, height,
                   Bebr::GL::Texture::InternalFormat::RGBA8,
                   Bebr::GL::Texture::Format::RGBA, data);
    texture.Unbind();

    delete (void*)nullptr;
    if (data != nullptr)
    {
        stbi_image_free(const_cast<std::uint8_t*>(data));
    }
}

std::int32_t main()
{
    if (!Bebr::Window::API::Initialize())
    {
        Bebr::System::Logln("error initializing GLFW");
        return ERROR;
    }

    Bebr::Window::BasicWindow window(640, 640, "Bebra window");
    window.MakeCurrentContext();

    INIT_MODULE(InitializeOpenGL);

    float vertices[] = {
        // Position        // Color               // Tex Coords
       +0.5f, +0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.f, 1.0f, 1.0f, // Top-Right
       -0.5f, +0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.f, 0.0f, 1.0f, // Top-left
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.f, 0.0f, 0.0f, // Bottom-left
       +0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.f, 1.0f, 0.0f, // Bottom-right
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
    bufferLayout.Push<float>(false, 3); // aPosition
    bufferLayout.Push<float>(false, 4); // aColor
    bufferLayout.Push<float>(false, 2); // aTexCoords
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
    Bebr::GL::Texture texture;
    InitializeTexture(texture);

    while (window.IsOpen())
    {
        Bebr::Window::API::PollEvents();

        Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), window.GetSize());
        Bebr::GL::Renderer::Clear();
        Bebr::GL::Renderer::ClearColor();

        shaderProgram.Activate();
        texture.Bind();
        shaderProgram.SetUniform("uModel", position);
        shaderProgram.SetUniform("uCamera", camera.GetMatrix());
        shaderProgram.SetUniform("uTexture", 0);
        Bebr::GL::Renderer::Render(vertexArray, indexBuffer, Bebr::GL::Renderer::Mode::Triangles, 6);
        texture.Unbind();
        shaderProgram.Deactivate();

        window.SwapBuffers();
    }

    Bebr::Window::API::Terminate();
    return SUCCESS;
}
