#include "Main.hpp"
#include <GL/glew.h>

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GL/BufferLayout.hpp>
#include <GL/Program.hpp>
#include <GL/Renderer.hpp>
#include <GL/VertexArray.hpp>
#include <GL/VertexBuffer.hpp>
#include <GL/Viewport.hpp>

#include <System/Color.hpp>
#include <System/Log.hpp>

#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>

int main()
{
	if (!Bebr::Window::API::Initialize())
	{
		Bebr::System::Logln("error initializing GLFW");
		return -1;
	}

	Bebr::Window::BasicWindow window(640, 480, "Bebra window");
	window.MakeCurrentContext();

	Bebr::GL::API::SetExperimental(true);
	if (!Bebr::GL::API::Initialize())
	{
		Bebr::System::Logln("error initializing GLEW");
		Bebr::Window::API::Terminate();
		return -1;
	}
    Bebr::GL::API::SetBlending(true);
    Bebr::GL::Blending::SetBlendFunction(Bebr::GL::Blending::Factor::SourceAlpha,
                                         Bebr::GL::Blending::Factor::OneMinusSourceAlpha);

    Bebr::GL::Program shaderProgram("Resources/vertex shader.glsl",
                                    "Resources/fragment shader.glsl");

    float vertices[] = {
        // Position        // Color
        0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, // Top
       -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, // Bottom-left
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, // Bottom-right
    };

    Bebr::GL::BufferLayout bufferLayout;
    bufferLayout.Push<float>(false, 3); // Position
    bufferLayout.Push<float>(false, 4); // Color
    Bebr::GL::VertexBuffer vertexBuffer;
    vertexBuffer.Bind();
    vertexBuffer.BufferData(vertices, sizeof(vertices));
    vertexBuffer.Unbind();
    Bebr::GL::VertexArray vertexArray;
    vertexArray.Bind();
    vertexArray.SetAttributes(vertexBuffer, bufferLayout);
    vertexArray.Unbind();

    const Bebr::System::ColorF clearColor(1.f, 0.f, 0.f);

	while (window.IsOpen())
	{
        Bebr::GL::Viewport::SetRectangle(Bebr::System::Vector2F_t(), window.GetSize());
        Bebr::GL::Renderer::Clear();
        Bebr::GL::Renderer::ClearColor(clearColor);

        shaderProgram.Activate();
        Bebr::GL::Renderer::Render(vertexArray, Bebr::GL::Renderer::Mode::Triangles, 0, 3);
        shaderProgram.Deactivate();

		Bebr::Window::API::PollEvents();
		window.SwapBuffers();
	}

	Bebr::Window::API::Terminate();
}
