#pragma once
#include <cstdint>

namespace Bebr
{
namespace GL
{
class PixelFormat
{
public:
    enum class Base
    {
        Red = 0x1903,
        RG = 0x8227,
        RGB = 0x1907,
        BGR = 0x80E0,
        RGBA = 0x1908,
        BGRA = 0x80E1,
        Luminance = 0x1909,
        LuminanceAlpha = 0x190A
    };

    enum class Sized
    {
        R8 = 0x8229,
        R8SNorm = 0x8F94,
        R16 = 0x822A,
        R16SNorm = 0x8F98,
        RG8 = 0x822B,
        RG8SNorm = 0x8F95,
        RG16 = 0x822C,
        RG16SNorm = 0x8F99,
        R3G3B2 = 0x2A10,
        RGB4 = 0x804F,
        RGB5 = 0x8050,
        RGB8 = 0x8051,
        RGB8SNorm = 0x8F96,
        RGB10 = 0x8052,
        RGB12 = 0x8053,
        RGB16 = 0x8054,
        RGB16SNorm = 0x8F9A,
        RGBA2 = 0x8055,
        RGBA4 = 0x8056,
        RGB5A1 = 0x8057,
        RGBA8 = 0x8058,
        RGBA8_SNorm = 0x8F97,
        RGB10A2 = 0x8059,
        RGB10_A2UI = 0x906F,
        RGBA12 = 0x805A,
        RGBA16 = 0x805B,
        RGBA16SNorm = 0x8F9B,
        SRGB8 = 0x8C41,
        SRGB8Alpha8 = 0x8C43,
        R16F = 0x822D,
        RG16F = 0x822F,
        RGB16F = 0x881B,
        RGBA16F = 0x881A,
        R32F = 0x822E,
        RG32F = 0x8230,
        RGB32F = 0x8815,
        RGBA32F = 0x8814,
        R11FG11FB10F = 0x8C3A,
        RGB9E5 = 0x8C3D,
        R8I = 0x8231,
        R8UI = 0x8232,
        R16I = 0x8233,
        R16UI = 0x8234,
        R32I = 0x8235,
        R32UI = 0x8236,
        RG8I = 0x8237,
        RG8UI = 0x8238,
        RG16I = 0x8239,
        RG16UI = 0x823A,
        RG32I = 0x823B,
        RG32UI = 0x823C,
        RGB8I = 0x8D8F,
        RGB8UI = 0x8D7D,
        RGB16I = 0x8D89,
        RGB16UI = 0x8D77,
        RGB32I = 0x8D83,
        RGB32UI = 0x8D71,
        RGBA8I = 0x8D8E,
        RGBA8UI = 0x8D7C,
        RGBA16I = 0x8D88,
        RGBA16UI = 0x8D76,
        RGBA32I = 0x8D82,
        RGBA32UI = 0x8D70
    };

    enum class Compressed
    {
        CompressedRed = 0x8225,
        CompressedRG = 0x8226,
        CompressedRGB = 0x84ED,
        CompressedRGBA = 0x84EE,
        CompressedSRGB = 0x8C48,
        CompressedSRGBAlpha = 0x8C49,
        CompressedRedRGTC1 = 0x8DBB,
        CompressedSignedRedRGTC1 = 0x8DBC,
        CompressedRGRGTC2 = 0x8DBD,
        CompressedSignedRGRGTC2 = 0x8DBE,
        CompressedRGBABPTCUNorm = 0x8E8C,
        CompressedSRGBAlphaBPTCUNorm = 0x8E8D,
        CompressedRGBBPTCSignedFloat = 0x8E8E,
        CompressedRGBBPTCUnsignedFloat = 0x8E8F,
    };

public:
    PixelFormat(Base format);
    PixelFormat(Sized format);
    PixelFormat(Compressed format);

public:
    inline operator std::uint32_t() const   { return m_format; }
    inline operator std::int32_t()  const   { return static_cast<std::int32_t>(m_format); }

private:
    std::uint32_t m_format;
};
}
}
