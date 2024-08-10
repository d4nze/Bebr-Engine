#pragma once
#include "Buffer.hpp"

namespace Bebr
{
namespace GL
{
class RenderBuffer;
class Texture;

class FrameBuffer : public Buffer
{
public:
    enum class Target
    {
        Framebuffer             = 0x8D40,
        DrawFramebuffer         = 0x8CA9,
        ReadFramebuffer         = 0x8CA8
    };

    enum class Attachment
    {
        ColorAttachment0        = 0x8CE0,
        ColorAttachment1,
        ColorAttachment2,
        ColorAttachment3,
        ColorAttachment4,
        ColorAttachment5,
        ColorAttachment6,
        ColorAttachment7,
        ColorAttachment8,
        ColorAttachment9,
        ColorAttachment10,
        ColorAttachment11,
        ColorAttachment12,
        ColorAttachment13,
        ColorAttachment14,
        ColorAttachment15,
        ColorAttachment16,
        DepthAttachment         = 0x8D00,
        StencilAttachment       = 0x8D20,
        DepthStencilAttachment  = 0x821A
    };

    enum class Status
    {
        Complete = 0x8CD5,
        Undefined = 0x8219,
        IncompleteAttachment = 0x8CD6,
        IncompleteMissingAttachment = 0x8CD7,
        IncompleteDrawBuffer = 0x8CDB,
        IncompleteReadBuffer = 0x8CDC,
        Unsupported = 0x8CDD,
        IncompleteMultisample = 0x8D56,
        IncompleteLayerTargets = 0x8DA8
    };

public:
	FrameBuffer(Target target = Target::Framebuffer);
	FrameBuffer(const FrameBuffer&) = default;
	~FrameBuffer() = default;

public:
	void Bind();
	void Unbind();

	void AttachRenderBuffer(const RenderBuffer& renderBuffer, Attachment attachment);
	void AttachTexture(const Texture& texture, Attachment attachment);

    Status GetStatus() const;
    bool IsComplete() const;

private:
    Target m_target;
};
}
}
