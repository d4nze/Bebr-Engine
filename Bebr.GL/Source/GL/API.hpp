#pragma once

// function.h
// void function(int number);

// function.cpp
// void function(int number) { ... }

namespace Bebr
{
namespace GL
{
class API
{
public:
	API() = delete;

public:
	static void SetBlending(bool enabled);
	static bool IsBlending();

	static void SetExperimental(bool enabled);
	static bool IsExperimental();

	static bool Initialize();
	static bool IsInitialized();
};
}
}
