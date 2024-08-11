#pragma once
#include <exception>
#include <string>

namespace Bebr
{
namespace Engine
{
class InitializeException : public std::exception
{
public:
	InitializeException(const std::string& message);

public:
	void LogErrorMessage() const;

private:
	const std::string m_message;
};

class GLFWInitializer
{
public:
	GLFWInitializer();
	~GLFWInitializer();
};

class GLInitializer
{
public:
	GLInitializer();
	~GLInitializer() = default;
};

class GUIInitializer
{
public:
	GUIInitializer();
	~GUIInitializer() = default;
};
}
}
