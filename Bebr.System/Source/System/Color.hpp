#pragma once
#include <cstdint>

namespace Bebr
{
namespace System
{
struct ColorF;

struct ColorU
{
	std::uint8_t r, g, b, a;

	ColorU();
	ColorU(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 0xFF);
	ColorU(const ColorF& colorF);
	ColorU(const ColorU&) = default;

	static const ColorU black;
	static const ColorU white;
	static const ColorU red;
	static const ColorU green;
	static const ColorU blue;
	static const ColorU yellow;
	static const ColorU pink;
	static const ColorU cyan;
	static const ColorU transperent;
};

struct ColorF
{
	float r, g, b, a;

	ColorF();
	ColorF(float r, float g, float b, float a = 1.f);
	ColorF(const ColorU& colorU);
	ColorF(const ColorF&) = default;

	static const ColorF black;
	static const ColorF white;
	static const ColorF red;
	static const ColorF green;
	static const ColorF blue;
	static const ColorF yellow;
	static const ColorF pink;
	static const ColorF cyan;
	static const ColorF transperent;
};
}
}
