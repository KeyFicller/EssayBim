#pragma once

#include "renderer_frame_buffer.h"

namespace EB
{
    class FrameBufferImpl
    {
    public:
        FrameBufferImpl(const FrameBufferSpecification& specification);
        ~FrameBufferImpl();
    public:
        const FrameBufferSpecification& specification() const;
        void bind() const;
        void unbind() const;
        void onResize(unsigned int width, unsigned int height);
        int pixel(unsigned int attachmentIdx, int x, int y, eSamplerPrecision precision) const;
        unsigned int colorAttachmentRendererId(unsigned int index = 0) const;
        void clearAttachment(unsigned int attachmentIdx, int value);

    private:
        void invalidate();

    protected:
        unsigned int m_RendererId = 0;
        FrameBufferSpecification m_Specification;
        std::vector<eFrameBufferTextureFormat> m_ColorAttachmentSpecifications;
        eFrameBufferTextureFormat m_DepthAttachmentSpecification = eFrameBufferTextureFormat::kNone;
        std::vector<unsigned int> m_ColorAttachments;
        unsigned int m_DepthAttachment = 0;
    };
}