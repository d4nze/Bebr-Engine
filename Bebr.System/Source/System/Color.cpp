#include "Color.hpp"

const Bebr::System::ColorU Bebr::System::ColorU::black		(0x00, 0x00, 0x00);
const Bebr::System::ColorU Bebr::System::ColorU::white		(0xFF, 0xFF, 0xFF);
const Bebr::System::ColorU Bebr::System::ColorU::red		(0xFF, 0x00, 0x00);
const Bebr::System::ColorU Bebr::System::ColorU::green		(0x00, 0xFF, 0x00);
const Bebr::System::ColorU Bebr::System::ColorU::blue		(0x00, 0x00, 0xFF);
const Bebr::System::ColorU Bebr::System::ColorU::yellow		(0xFF, 0xFF, 0x00);
const Bebr::System::ColorU Bebr::System::ColorU::pink		(0xFF, 0x00, 0xFF);
const Bebr::System::ColorU Bebr::System::ColorU::cyan		(0x00, 0xFF, 0xFF);
const Bebr::System::ColorU Bebr::System::ColorU::transperent(0x00, 0x00, 0x00, 0x00);

const Bebr::System::ColorF Bebr::System::ColorF::black		(0.f, 0.f, 0.f);
const Bebr::System::ColorF Bebr::System::ColorF::white		(1.f, 1.f, 1.f);
const Bebr::System::ColorF Bebr::System::ColorF::red		(1.f, 0.f, 0.f);
const Bebr::System::ColorF Bebr::System::ColorF::green		(0.f, 1.f, 0.f);
const Bebr::System::ColorF Bebr::System::ColorF::blue		(0.f, 0.f, 1.f);
const Bebr::System::ColorF Bebr::System::ColorF::yellow		(1.f, 1.f, 0.f);
const Bebr::System::ColorF Bebr::System::ColorF::pink		(1.f, 0.f, 1.f);
const Bebr::System::ColorF Bebr::System::ColorF::cyan		(0.f, 1.f, 1.f);
const Bebr::System::ColorF Bebr::System::ColorF::transperent(0.f, 0.f, 0.f, 0.f);

Bebr::System::ColorU::ColorU() : r(0x00), g(0x00), b(0x00), a(0x00)
{}

Bebr::System::ColorU::ColorU(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) : r(r), g(g), b(b), a(a)
{}

Bebr::System::ColorU::ColorU(const ColorF& colorF)
	: r(static_cast<std::uint8_t>(colorF.r * 255.f))
	, g(static_cast<std::uint8_t>(colorF.g * 255.f))
	, b(static_cast<std::uint8_t>(colorF.b * 255.f))
	, a(static_cast<std::uint8_t>(colorF.a * 255.f))
{}

Bebr::System::ColorF::ColorF() : r(0.f), g(0.f), b(0.f), a(0.f)
{}

Bebr::System::ColorF::ColorF(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
{}

Bebr::System::ColorF::ColorF(const ColorU& colorU)
	: r(static_cast<float>(colorU.r) / 255.f)
	, g(static_cast<float>(colorU.g) / 255.f)
	, b(static_cast<float>(colorU.b) / 255.f)
	, a(static_cast<float>(colorU.a) / 255.f)
{}
