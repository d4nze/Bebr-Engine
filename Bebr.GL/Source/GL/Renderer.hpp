#pragma once
#include "VertexArray.hpp"
#include "ElementBuffer.hpp"
#include <System/Color.hpp>
#include <cstdint>

namespace Bebr
{
namespace GL
{
class Renderer
{
public:
	Renderer() = delete;

public:
	enum class Mode
	{
		Points = 0,
		Lines,
		LineLoop,
		LineStrip,
		Triangles,
		TriangleStrip,
		TriangleFan,
		Quads,
		QuadStrip,
		Polygon,
		PolygonStrip,
		LinesAdjacency,
		LineStripAdjacency,
		TrianglesAdjacency,
		TriangleStripAdjacency,
		Patches
	};

public:
	static void Clear();
	static void ClearColor(const System::ColorF& color = System::ColorF::black);

	static void Render(VertexArray& vertexArray, Mode mode, std::int32_t first, std::int32_t count);
	static void Render(VertexArray& vertexArray, ElementBuffer& indexBuffer, Mode mode, std::int32_t count, const void* indices = nullptr);
};
}
}
