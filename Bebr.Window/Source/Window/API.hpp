#pragma once

int main();

namespace Bebr
{
namespace Window
{
class API
{
public:
	API() = delete;

public:
	static bool Initialize();
	static bool IsInitialized();
	static void Terminate();

	static void PollEvents();
};
}
}
