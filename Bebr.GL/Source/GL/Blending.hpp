#pragma once

namespace Bebr
{
namespace GL
{
class Blending
{
public:
	Blending() = delete;

public:
	enum class Factor
	{
		Zero						= 0,
		One							= 1,
		SourceColor					= 0x0300,
		OneMinusSourceColor			= 0x0301,
		DestinationColor			= 0x0306,
		OneMinusDestinationColor	= 0x0307,
		SourceAlpha					= 0x0302,
		OneMinusSourceAlpha			= 0x0303,
		DestinationAlpha			= 0x0304,
		OneMinusDestinationAlpha	= 0x0305,
		ConstantColor				= 0x8001,
		OneMinusConstantColor		= 0x8002,
		ConstantAlpha				= 0x8003,
		OneMinusConstantAlpha		= 0x8004,
		SourceAlphaSaturate			= 0x0308,
		Source1Color				= 0x88F9,
		OneMinusSource1Color		= 0x88FA,
		Source1Alpha				= 0x8589,
		OneMinusSource1Alpha		= 0x88FB
	};

	enum class EquationMode
	{
		FunctionAdd = 0x8006,
		FunctionSubstruct = 0x800A,
		FunctionReverseSubstruct = 0x800B,
		Min = 0x8007,
		Max = 0x8008
	};

public:
	static void SetBlendFunction(Factor sourceFactor, Factor destinationFactor);
	static void UpdateSourceBlendFunction(Factor sourceFactor);
	static void UpdateDestinationBlendFunction(Factor destinationFactor);
	static Factor GetSourceFactor();
	static Factor GetDestinationFactor();

	static void SetEquationMode(EquationMode rgba);
	static void SetEquationMode(EquationMode rgb, EquationMode alpha);
	static void UpdateRGBEquationMode(EquationMode rgb);
	static void UpdateAlphaEquationMode(EquationMode alpha);
	static EquationMode GetRGBAMode();
	static EquationMode GetRGBMode();
	static EquationMode GetAlphaMode();
};
}
}
