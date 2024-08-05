#include "Main.hpp"
#include <GL/glew.h>
#include <chrono>

#include <GL/API.hpp>
#include <GL/Blending.hpp>
#include <GL/BufferLayout.hpp>
#include <GL/ElementBuffer.hpp>
#include <GL/Program.hpp>
#include <GL/Renderer.hpp>
#include <GL/VertexArray.hpp>
#include <GL/VertexBuffer.hpp>
#include <GL/Viewport.hpp>

#include <System/Color.hpp>
#include <System/Matrix.hpp>
#include <System/Log.hpp>

#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>
#include <Window/Keyboard.hpp>

class Timer
{
public:
    Timer()
    {
        Reset();
    }
    
public:
    void Reset()
    {
        m_startTime = std::chrono::high_resolution_clock::now();
    }
    float GetDeltaTime()
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::chrono::seconds::period> deltaTime = currentTime - m_startTime;
        Reset();
        return deltaTime.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
};

class Camera
{
public:
    Camera(float x, float y, float width, float height)
        : m_position(Bebr::System::CreateIdentityMatrix<float, 4>())
        , m_descale (Bebr::System::CreateIdentityMatrix<float, 4>())
    {
        m_position[3][0] = x;
        m_position[3][1] = y;
        m_descale[0][0] = 2.f / width;
        m_descale[1][1] = 2.f / height;
    }

public:
    Bebr::System::Matrix4_t<float> GetMatrix() const
    {
        return m_descale * m_position;
    }
    
private:
    Bebr::System::Matrix4_t<float> m_position;
    Bebr::System::Matrix4_t<float> m_descale;
};

template<typename T, std::uint32_t width, std::uint32_t height>
void PrintMatrix(const Bebr::System::Matrix<T, width, height>& matrix)
{
    for (std::uint32_t y = 0; y < height; y++)
    {
        for (std::uint32_t x = 0; x < width; x++)
        {
            Bebr::System::Log(matrix[x][y]);
            Bebr::System::Log(' ');
        }
        Bebr::System::Log('\n');
    }
    Bebr::System::Log('\n');
}

int main()
{
	if (!Bebr::Window::API::Initialize())
	{
		Bebr::System::Logln("error initializing GLFW");
		return -1;
	}

	Bebr::Window::BasicWindow window(640, 480, "Bebra window");
    Bebr::Window::Keyboard keyboard(window);
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

        static Timer timer;
        float deltaTime = timer.GetDeltaTime();
        float speed = deltaTime * 2.f;
        Bebr::System::Vector2F_t offset;
        if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Left))
            offset.x -= speed;
        if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Right))
            offset.x += speed;
        if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Up))
            offset.y += speed;
        if (keyboard.IsKeyDown(Bebr::Window::Keyboard::Key::Down))
            offset.y -= speed;
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

		window.SwapBuffers();
	}

	Bebr::Window::API::Terminate();
}
