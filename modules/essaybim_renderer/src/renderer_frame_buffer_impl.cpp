#include "renderer_frame_buffer_impl.h"

#include "renderer_gl_debugger.h"

#include "basic_assert.h"

#include <glad/glad.h>

namespace EB
{
    namespace {
        bool isDepthFormat(eFrameBufferTextureFormat format)
        {
            switch (format)
            {
            case EB::eFrameBufferTextureFormat::kDepth:
                return true;
            case EB::eFrameBufferTextureFormat::kNone:
            case EB::eFrameBufferTextureFormat::kRGBA8:
            case EB::eFrameBufferTextureFormat::kRedInteger:
            default:
                return false;
            }
        }

        GLenum targetTexture(bool multiSampled)
        {
            return multiSampled ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
        }

        void attachColorTexture(unsigned int id, const FrameBufferSpecification& spec, GLenum internalFormat, GLenum format, int index)
        {
            EB_GL_AUTO_TRACE();
            bool multiSampled = spec.Samples > 1;
            if (multiSampled) {
                glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, spec.Samples, internalFormat, spec.Width, spec.Height, GL_FALSE);
            }
            else {
                glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, spec.Width, spec.Height, 0, format, GL_UNSIGNED_BYTE, nullptr);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, targetTexture(multiSampled), id, 0);
        }

        void attachDepthTexture(unsigned int id, const FrameBufferSpecification& spec, GLenum format, GLenum attachmentType)
        {
            EB_GL_AUTO_TRACE();
            bool multiSampled = spec.Samples > 1;
            if (multiSampled) {
                glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, spec.Samples, format, spec.Width, spec.Height, GL_FALSE);
            }
            else {
                glTexStorage2D(GL_TEXTURE_2D, 1, format, spec.Width, spec.Height);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }
            glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, targetTexture(multiSampled), id, 0);
        }

        GLenum formatEnumToGLenum(eFrameBufferTextureFormat format)
        {
            switch (format)
            {
            case eFrameBufferTextureFormat::kNone:
                return GL_NONE;
            case eFrameBufferTextureFormat::kRGBA8:
                return GL_RGBA8;
            case EB::eFrameBufferTextureFormat::kRedInteger:
                return GL_RED_INTEGER;
            case EB::eFrameBufferTextureFormat::kDepth:
            default:
                return GL_NONE;
            }
        }
    }


    FrameBufferImpl::FrameBufferImpl(const FrameBufferSpecification& specification)
        : m_Specification(specification)
    {
        for (auto& attach : m_Specification.Attachments) {
            if (isDepthFormat(attach)) {
                m_DepthAttachmentSpecification = attach;
            }
            else {
                m_ColorAttachmentSpecifications.push_back(attach);
            }
        }
        invalidate();
    }

    FrameBufferImpl::~FrameBufferImpl()
    {
        EB_GL_AUTO_TRACE();
        glDeleteFramebuffers(1, &m_RendererId);
        glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
        glDeleteTextures(1, &m_DepthAttachment);
    }

    const EB::FrameBufferSpecification& FrameBufferImpl::specification() const
    {
        return m_Specification;
    }

    void FrameBufferImpl::bind() const
    {
        EB_GL_AUTO_TRACE();
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererId);
        glViewport(0, 0, m_Specification.Width, m_Specification.Height);
    }

    void FrameBufferImpl::unbind() const
    {
        EB_GL_AUTO_TRACE();
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void FrameBufferImpl::onResize(unsigned int width, unsigned int height)
    {
        static unsigned maximumFramebufferSize = 4096;
        if (width == 0 || width >= maximumFramebufferSize || height == 0 || height >= maximumFramebufferSize) {
            EB_CORE_WARN("Attempt to resize frame buffer at (%d, %d)", width, height);
            return;
        }
        m_Specification.Width = width;
        m_Specification.Height = height;
        invalidate();
    }

    int FrameBufferImpl::pixel(unsigned int attachmentIdx, int x, int y) const
    {
        EB_GL_AUTO_TRACE();
        EB_CORE_ASSERT(attachmentIdx < m_ColorAttachments.size());
        glReadBuffer(GL_COLOR_ATTACHMENT0 + attachmentIdx);
        int pixelData = -1;
        glReadPixels(x, y, 1, 1, GL_RED_INTEGER, GL_INT, &pixelData);
        return pixelData;
    }

    unsigned int FrameBufferImpl::colorAttachmentRendererId(unsigned int index /*= 0*/) const
    {
        EB_CORE_ASSERT(index < m_ColorAttachments.size());
        return m_ColorAttachments[index];
    }

    void FrameBufferImpl::clearAttachment(unsigned int attachmentIdx, int value)
    {
        EB_GL_AUTO_TRACE();
        EB_CORE_ASSERT(attachmentIdx < m_ColorAttachments.size());
        auto& spec = m_ColorAttachmentSpecifications[attachmentIdx];
        glClearTexImage(m_ColorAttachments[attachmentIdx], 0, formatEnumToGLenum(spec), GL_INT, &value);
    }

    void FrameBufferImpl::invalidate()
    {
        EB_GL_AUTO_TRACE();
        if (m_RendererId) {
            glDeleteFramebuffers(1, &m_RendererId);
            glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
            glDeleteTextures(1, &m_DepthAttachment);
            m_ColorAttachments.clear();
            m_DepthAttachment = 0;
        }

        glCreateFramebuffers(1, &m_RendererId);
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererId);

        bool multiSampled = m_Specification.Samples > 1;
        if (m_ColorAttachmentSpecifications.size()) {
            m_ColorAttachments.resize(m_ColorAttachmentSpecifications.size());
            glCreateTextures(targetTexture(multiSampled), m_ColorAttachments.size(), m_ColorAttachments.data());
            for (unsigned int i = 0; i < m_ColorAttachments.size(); i++) {
                glBindTexture(targetTexture(multiSampled), m_ColorAttachments[i]);
                switch (m_ColorAttachmentSpecifications[i])
                {
                case eFrameBufferTextureFormat::kRGBA8:
                    attachColorTexture(m_ColorAttachments[i], m_Specification, GL_RGBA8, GL_RGBA, i);
                    break;
                case eFrameBufferTextureFormat::kRedInteger:
                    attachColorTexture(m_ColorAttachments[i], m_Specification, GL_R32I, GL_RED_INTEGER, i);
                    break;
                }
            }
        }

        if (m_DepthAttachmentSpecification != eFrameBufferTextureFormat::kNone) {
            glCreateTextures(targetTexture(multiSampled), 1, &m_DepthAttachment);
            glBindTexture(targetTexture(multiSampled), m_DepthAttachment);
            switch (m_DepthAttachmentSpecification)
            {
            case eFrameBufferTextureFormat::kDepth:
                attachDepthTexture(m_DepthAttachment, m_Specification, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT);
                break;
            }
        }

        if (m_ColorAttachments.size() > 1) {
            EB_CORE_ASSERT(m_ColorAttachments.size() <= 4, "More than 4 attachments.");
            GLenum buffers[4] = {
                GL_COLOR_ATTACHMENT0,
                GL_COLOR_ATTACHMENT1,
                GL_COLOR_ATTACHMENT2,
                GL_COLOR_ATTACHMENT3
            };
            glDrawBuffers(4, buffers);
        }
        else {
            glDrawBuffer(GL_NONE);
        }

        EB_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

}