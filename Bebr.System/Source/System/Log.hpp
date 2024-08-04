#pragma once

#ifdef DEBUG
#include <iostream>
#define LOG(message) std::cout << message
#else
#define LOG(message)
#endif
#define LOGLN(message) LOG(message); LOG('\n');

namespace Bebr
{
namespace System
{
template<typename T>
void Log(T first)
{
	LOG(first);
}
template<typename T, typename... Args>
void Log(T first, Args... args)
{
	LOG(first);
	LOG(' ');
	Log(args...);
}
template<typename T>
void Logln(T first)
{
	LOGLN(first);
}
template<typename T, typename... Args>
void Logln(T first, Args... args)
{
	LOGLN(first);
	Logln(args...);
}
}
}
