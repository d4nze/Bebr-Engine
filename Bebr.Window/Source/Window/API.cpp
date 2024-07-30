#include "API.hpp"
#include <glfw3.h>

static bool initialized = false;

bool Bebr::Window::API::Initialize()
{
    initialized = (glfwInit() != 0);
    if (initialized)
    {
        glfwSetTime(0.0);
    }
    return initialized;
}

bool Bebr::Window::API::IsInitialized()
{
    return initialized;
}

void Bebr::Window::API::Terminate()
{
    glfwTerminate();
}

void Bebr::Window::API::PollEvents()
{
    glfwPollEvents();
}
