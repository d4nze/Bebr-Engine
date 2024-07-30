#include <Run/Main.hpp>
#include <System/Log.hpp>
#include <Window/API.hpp>
#include <Window/BasicWindow.hpp>

#include <iostream>

int main()
{
	if (!Bebr::Window::API::Initialize())
	{
		LOG("error initializing GLFW");
		return -1;
	}

	Bebr::Window::BasicWindow windows[2] = {
		{ 640, 480, "1" },
		{ 640, 480, "2" }
	};
	Bebr::System::Vector2I_t prevPosition[2];
	Bebr::System::Vector2I_t prevSize[2];
	bool close = false;
	do
	{
		Bebr::Window::API::PollEvents();
		for (int i = 0; i < 2; i++)
		{
			auto& window = windows[i];
			if (!window.IsOpen())
			{
				close = true;
				break;
			}
			window.SwapBuffers();
			Bebr::System::Vector2I_t newPosition = window.GetPosition();
			Bebr::System::Vector2I_t newSize = window.GetSize();
			bool printed = false;
			if (newPosition != prevPosition[i])
			{
				printed = true;
				std::cout << "Window: " << window.GetTitle() << ' ';
				std::cout << "New position: ";
				std::cout << newPosition.x << ' ' << newPosition.y << '\n';
				prevPosition[i] = newPosition;
			}
			if (newSize != prevSize[i])
			{
				if (!printed)
					std::cout << "Window: " << window.GetTitle() << ' ';
				std::cout << "New size: ";
				std::cout << newSize.x << ' ' << newSize.y << '\n';
				prevSize[i] = newSize;
			}
		}
	}
	while (!close);

	Bebr::Window::API::Terminate();
}
