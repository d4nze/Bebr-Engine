#include <Run/Main.hpp>
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
	while (window.IsOpen())
	{
		Bebr::Window::API::PollEvents();
		window.SwapBuffers();
	}

	Bebr::Window::API::Terminate();
}
