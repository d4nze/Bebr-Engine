#include "Main.hpp"
#ifdef RELEASE
#include <Windows.h>
static std::int32_t WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    return main();
}
#endif
