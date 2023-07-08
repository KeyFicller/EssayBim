#include "renderer_vertex_array_impl.h"

#include "renderer_buffer_layout.h"
#include "renderer_gl_debugger.h"
#include "renderer_index_buffer.h"
#include "renderer_utils.h"
#include "renderer_vertex_buffer.h"

#include "basic_assert.h"

#include <glad/glad.h>

namespace EB
{

    VertexArrayImpl::VertexArrayImpl()
    {
        EB_GL_AUTO_TRACE();
        glCreateVertexArrays(1, &m_RendererId);
    }

    VertexArrayImpl::~VertexArrayImpl()
    {
        EB_GL_AUTO_TRACE();
        glDeleteVertexArrays(1, &m_RendererId);
    }

    void VertexArrayImpl::bind() const
    {
        EB_GL_AUTO_TRACE();
        glBindVertexArray(m_RendererId);
    }

    void VertexArrayImpl::unbind() const
    {
        EB_GL_AUTO_TRACE();
        glBindVertexArray(0);
    }

    void VertexArrayImpl::addVertexBuffer(const Shared<VertexBuffer>& vertexBuffer)
    {
        EB_GL_AUTO_TRACE();

        EB_CORE_ASSERT(vertexBuffer->layout().elements().size(), "vertex buffer has no layout.");
        glBindVertexArray(m_RendererId);
        vertexBuffer->bind();

        for (const auto& element : vertexBuffer->layout().elements()) {
            GLenum glType = Utils_Renderer::glTypeOfShaderType(element.Type);
            switch (element.Type) {
                case EB::eShaderDataType::kBool:
                case EB::eShaderDataType::kInt:
                case EB::eShaderDataType::kInt2:
                case EB::eShaderDataType::kInt3:
                case EB::eShaderDataType::kInt4:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribIPointer(m_VertexBufferIndex, element.Component, glType,
                        vertexBuffer->layout().stride(), reinterpret_cast<const void*>((intptr_t)element.Offset));
                    m_VertexBufferIndex++;
                    break;
                }
                case EB::eShaderDataType::kFloat:
                case EB::eShaderDataType::kFloat2:
                case EB::eShaderDataType::kFloat3:
                case EB::eShaderDataType::kFloat4:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribPointer(m_VertexBufferIndex, element.Component, glType, element.Normalized ? GL_TRUE : GL_FALSE,
                        vertexBuffer->layout().stride(), reinterpret_cast<const void*>((intptr_t)element.Offset));
                    m_VertexBufferIndex++;
                    break;
                }
                case EB::eShaderDataType::kMat2:
                case EB::eShaderDataType::kMat3:
                case EB::eShaderDataType::kMat4:
                {
                    unsigned int count = element.Component;
                    for (unsigned int i = 0; i < count; i++) {
                        glVertexAttribPointer(m_VertexBufferIndex, count, glType,
                            element.Normalized ? GL_TRUE : GL_FALSE, vertexBuffer->layout().stride(),
                            reinterpret_cast<const void*>((intptr_t)element.Offset + i * sizeof(GL_FLOAT) * count));
                        glVertexAttribDivisor(m_VertexBufferIndex, 1);
                        m_VertexBufferIndex++;
                    }
                    break;
                }
                default:
                {
                    EB_CORE_ASSERT(false, "unknown shader data type.");
                    break;
                }
            }
        }

        m_VertexBuffers.push_back(vertexBuffer);
    }

    void VertexArrayImpl::setIndexBuffer(const Shared<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererId);
        indexBuffer->bind();
        m_IndexBuffer = indexBuffer;
    }

    const std::vector<EB::Shared<EB::VertexBuffer>>& VertexArrayImpl::vertexBuffers() const
    {
        return m_VertexBuffers;
    }

    const EB::Shared<EB::IndexBuffer>& VertexArrayImpl::indexBuffer() const
    {
        return m_IndexBuffer;
    }

}