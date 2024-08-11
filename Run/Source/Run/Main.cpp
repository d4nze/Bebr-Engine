#include "Main.hpp"
#include <Engine/Application.hpp>

std::int32_t main()
{
    try
    {
        Bebr::Engine::Application application;
        while (application.IsRunning())
        {
            application.Update();
            application.Render();
        }
    }
    catch (Bebr::Engine::InitializeException initException)
    {
        initException.LogErrorMessage();
        return error;
    }
    catch (...)
    {
        return error;
    }
    return success;
}
