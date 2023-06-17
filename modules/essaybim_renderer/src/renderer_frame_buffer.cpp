#include "renderer_frame_buffer.h"

#include "renderer_frame_buffer_impl.h"

namespace EB
{

    Shared<FrameBuffer> FrameBuffer::create(const FrameBufferSpecification& specification)
    {
        return createShared<FrameBuffer>(specification);
    }

    FrameBuffer::FrameBuffer(const FrameBufferSpecification& specification)
    {
        EB_IMPL() = createScoped<FrameBufferImpl>(specification);
    }

    FrameBuffer::~FrameBuffer()
    {
        EB_IMPL().reset();
    }

    const EB::FrameBufferSpecification& FrameBuffer::specification() const
    {
        return EB_IMPL()->specification();
    }

    void FrameBuffer::bind() const
    {
        EB_IMPL()->bind();
    }

    void FrameBuffer::unbind() const
    {
        EB_IMPL()->unbind();
    }

    void FrameBuffer::onResize(unsigned int width, unsigned int height)
    {
        EB_IMPL()->onResize(width, height);
    }

    int FrameBuffer::pixel(unsigned int attachmentIdx, int x, int y) const
    {
        return EB_IMPL()->pixel(attachmentIdx, x, y);
    }

    unsigned int FrameBuffer::colorAttachmentRendererId(unsigned int index /*= 0*/) const
    {
        return EB_IMPL()->colorAttachmentRendererId(index);
    }

    void FrameBuffer::clearAttachment(unsigned int attachmentIdx, int value)
    {
        EB_IMPL()->clearAttachment(attachmentIdx, value);
    }

}