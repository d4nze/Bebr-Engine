#include "Blending.hpp"
#include <GL/glew.h>
#include <cstdint>

static Bebr::GL::Blending::Factor s_source, s_destination;
static Bebr::GL::Blending::EquationMode s_rgba, s_rgb, s_alpha;

static void UpdateBlendFunc()
{
    glBlendFunc(static_cast<unsigned int>(s_source),
                static_cast<unsigned int>(s_destination));
}

static void UpdateEquationMode()
{
    glBlendEquationSeparate(static_cast<std::uint32_t>(s_rgb),
                            static_cast<std::uint32_t>(s_alpha));
}

void Bebr::GL::Blending::SetBlendFunction(Factor sourceFactor, Factor destinationFactor)
{
    s_source = sourceFactor;
    s_destination = destinationFactor;
    UpdateBlendFunc();
}

void Bebr::GL::Blending::UpdateSourceBlendFunction(Factor sourceFactor)
{
    s_source = sourceFactor;
    UpdateBlendFunc();
}

void Bebr::GL::Blending::UpdateDestinationBlendFunction(Factor destinationFactor)
{
    s_destination = destinationFactor;
    UpdateBlendFunc();
}

Bebr::GL::Blending::Factor Bebr::GL::Blending::GetSourceFactor()
{
    return s_source;
}

Bebr::GL::Blending::Factor Bebr::GL::Blending::GetDestinationFactor()
{
    return s_destination;
}

void Bebr::GL::Blending::SetEquationMode(EquationMode rgba)
{
    s_rgba = rgba;
    glBlendEquation(static_cast<std::uint32_t>(rgba));
}

void Bebr::GL::Blending::SetEquationMode(EquationMode rgb, EquationMode alpha)
{
    s_rgb = rgb;
    s_alpha = alpha;
    UpdateEquationMode();
}

void Bebr::GL::Blending::UpdateRGBEquationMode(EquationMode rgb)
{
    s_rgb = rgb;
    UpdateEquationMode();
}

void Bebr::GL::Blending::UpdateAlphaEquationMode(EquationMode alpha)
{
    s_alpha = alpha;
    UpdateEquationMode();
}

Bebr::GL::Blending::EquationMode Bebr::GL::Blending::GetRGBAMode()
{
    return s_rgba;
}

Bebr::GL::Blending::EquationMode Bebr::GL::Blending::GetRGBMode()
{
    return s_rgb;
}

Bebr::GL::Blending::EquationMode Bebr::GL::Blending::GetAlphaMode()
{
    return s_alpha;
}
