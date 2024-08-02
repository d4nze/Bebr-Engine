#include "Main.hpp"
#include <GL/glew.h>

#include <GL/API.hpp>
#include <GL/Program.hpp>
#include <GL/VertexArray.hpp>
#include <GL/VertexBuffer.hpp>
#include <GL/BufferLayout.hpp>

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

    Bebr::GL::Program shaderProgram("Resources/vertex shader.glsl",
                                    "Resources/fragment shader.glsl");

    float vertices[] = {
        // Позиции          // Цвета
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Верхняя       вершина (красная)
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Левая  нижняя вершина (зелёная)
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Правая нижняя вершина (синяя)
    };

    Bebr::GL::BufferLayout bufferLayout;
    bufferLayout.Push<float>(false, 3); // Position
    bufferLayout.Push<float>(false, 3); // Color
    Bebr::GL::VertexBuffer vertexBuffer;
    vertexBuffer.Bind();
    vertexBuffer.BufferData(vertices, sizeof(vertices));
    vertexBuffer.Unbind();
    Bebr::GL::VertexArray vertexArray;
    vertexArray.Bind();
    vertexArray.SetAttributes(vertexBuffer, bufferLayout);
    vertexArray.Unbind();

	while (window.IsOpen())
	{
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();
        {
            vertexArray.Bind();
            glDrawArrays(GL_TRIANGLES, 0, 3);
            vertexArray.Unbind();
        }
        shaderProgram.Deactivate();

		Bebr::Window::API::PollEvents();
		window.SwapBuffers();
	}

	Bebr::Window::API::Terminate();
}
