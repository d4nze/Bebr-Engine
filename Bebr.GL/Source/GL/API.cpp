#include "API.hpp"
#include <GL/glew.h>

static bool initialized = false;

static GLboolean GetGLBoolean(bool enabled)
{
	return enabled ? GL_TRUE : GL_FALSE;
}

static void GLOption(bool enabled, unsigned int cap)
{
	if (enabled)
		glEnable(cap);
	else
		glDisable(cap);
}

void Bebr::GL::API::SetBlending(bool enabled)
{
	GLOption(enabled, GL_BLEND);
}

bool Bebr::GL::API::IsBlending()
{
	return glIsEnabled(GL_BLEND) == GL_TRUE;
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
