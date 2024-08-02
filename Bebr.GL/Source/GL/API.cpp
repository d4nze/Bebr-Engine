#include "API.hpp"
#include <GL/glew.h>

static bool initialized = false;

static GLboolean GetGLBoolean(bool enabled)
{
	return enabled ? GL_TRUE : GL_FALSE;
}

void Bebr::GL::API::SetExperimental(bool enabled)
{
	glewExperimental = GetGLBoolean(enabled);
}

bool Bebr::GL::API::IsExperimental()
{
	return glewExperimental;
}

bool Bebr::GL::API::Initialize()
{
	initialized = (glewInit() == GLEW_OK);
	return true;
}

bool Bebr::GL::API::IsInitialized()
{
	return initialized;
}
