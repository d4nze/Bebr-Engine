#include <GL/API.hpp>
#include <GL/Program.hpp>
#include <GL/VertexBuffer.hpp>
#include <GL/BufferLayout.hpp>

#include <Run/Main.hpp>
#include <System/Log.hpp>
#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>

#include <GL/glew.h>

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

    Bebr::GL::Program shaderProgram("Resources/vertex shader.glsl", "Resources/fragment shader.glsl");

    GLfloat vertices[] = {
        // Позиции          // Цвета
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Верхняя вершина       (красная)
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Левая нижняя вершина  (зелёная)
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Правая нижняя вершина (синяя)
    };

    Bebr::GL::BufferLayout bufferLayout;
    bufferLayout.Push<float>(false, 3); // Position
    bufferLayout.Push<float>(false, 3); // Color

    Bebr::GL::VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    vertexBuffer.Bind();

    GLboolean;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    vertexBuffer.Unbind();
    glBindVertexArray(0);

	while (window.IsOpen())
	{
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

		Bebr::Window::API::PollEvents();
		window.SwapBuffers();
	}

	Bebr::Window::API::Terminate();
}
