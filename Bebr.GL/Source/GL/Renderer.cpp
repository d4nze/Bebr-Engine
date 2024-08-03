#include "Renderer.hpp"
#include <GL/glew.h>

void Bebr::GL::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Bebr::GL::Renderer::ClearColor(const System::ColorF & color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void Bebr::GL::Renderer::Render(VertexArray& vertexArray, Mode mode, std::int32_t first, std::int32_t count)
{
	vertexArray.Bind();
	glDrawArrays(static_cast<std::uint32_t>(mode), first, count);
	vertexArray.Unbind();
}
