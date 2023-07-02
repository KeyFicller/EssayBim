#include "renderer_batch_render_impl.h"

#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_buffer_layout.h"
#include "renderer_shader.h"
#include "renderer_uniform_buffer.h"
#include "renderer_index_buffer.h"
#include "renderer_entry.h"

#include "basic_file_server.h"

#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

namespace EB
{

    BatchRenderImpl::BatchRenderImpl()
    {
        init();
        reset();
    }

    BatchRenderImpl::~BatchRenderImpl()
    {
        delete[] m_MeshData.pBase;
    }

    void BatchRenderImpl::start(const Mat4& viewprojectionMatrix)
    {
        reset();
        m_CameraData.ViewProjectionMatrix = viewprojectionMatrix;
        m_CameraBuffer->setData(&m_CameraData.ViewProjectionMatrix, sizeof(CameraData), 0);
    }

    void BatchRenderImpl::end()
    {
        auto bufferSize = reinterpret_cast<uint8_t*>(m_MeshData.pCurrent) - reinterpret_cast<uint8_t*>(m_MeshData.pBase);
        m_MeshData.VBOPerBatch->setData(m_MeshData.pBase, (unsigned int)bufferSize);
        flush();
    }

    void BatchRenderImpl::flush()
    {
        if (unsigned int indexCount = m_MeshData.IndicesPerBatch.size()) {
            Shared<IndexBuffer> indexBuffer = IndexBuffer::create(m_MeshData.IndicesPerBatch.data(), m_MeshData.IndicesPerBatch.size());
            m_MeshData.VAOPerBatch->setIndexBuffer(indexBuffer);
            m_MeshData.ShaderPerBatch->bind();
            RendererEntry::instance().mesh(m_MeshData.VAOPerBatch);
        }
    }

    void BatchRenderImpl::flushAndReset()
    {
        end();
        reset();
    }

    void BatchRenderImpl::init()
    {
        m_MeshData.VAOPerBatch = createShared<VertexArray>();
        m_MeshData.VBOPerBatch = createShared<VertexBuffer>(
            MeshBatchData::MaxVerticesPerBatch * sizeof(MeshVertexInfo)
        );
        BufferLayout layout = {
            {"aPos", eShaderDataType::kFloat3}
        };
        m_MeshData.VBOPerBatch->setLayout(layout);
        m_MeshData.VAOPerBatch->addVertexBuffer(std::shared_ptr<VertexBuffer>(m_MeshData.VBOPerBatch.get()));
        m_MeshData.pBase = new MeshVertexInfo[MeshBatchData::MaxVerticesPerBatch];
        m_MeshData.pCurrent = m_MeshData.pBase;
        m_MeshData.ShaderPerBatch = createShared<Shader>(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp.glsl");
        m_MeshData.ShaderPerBatch->unbind();

        m_CameraBuffer = new UniformBuffer(sizeof(CameraData), 0);
    }

    void BatchRenderImpl::reset()
    {
        m_MeshData.IndicesPerBatch.clear();
        m_MeshData.pCurrent = m_MeshData.pBase;
        m_MeshData.VertexCount = 0;
        m_MeshData.VertexIndexUsed = 0;
    }

    void BatchRenderImpl::line(const Vec3f& start, const Vec3f& end)
    {
        if (m_MeshData.VertexCount + 2 >= m_MeshData.MaxVerticesPerBatch ||
            m_MeshData.IndicesPerBatch.size() + 2 >= m_MeshData.MaxIndicesPerBatch) {
            flushAndReset();
        }

        EB_CORE_ASSERT(false, "not implment yet");
    }

    void BatchRenderImpl::mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals)
    {
        EB_CORE_ASSERT(vertices.size() == normals.size());
        if (m_MeshData.VertexCount + vertices.size() >= m_MeshData.MaxVerticesPerBatch ||
            m_MeshData.IndicesPerBatch.size() + indices.size() >= m_MeshData.MaxIndicesPerBatch) {
            flushAndReset();
        }
        for (unsigned int i = 0; i < vertices.size(); i++) {
            *m_MeshData.pCurrent = MeshVertexInfo{
                vertices[i]
            };
            m_MeshData.pCurrent++;
        }

        for (unsigned int i = 0; i < indices.size(); i++) {
            for (unsigned int j = 0; j < 3; j++) {
                m_MeshData.IndicesPerBatch.emplace_back(indices[i][j] + m_MeshData.VertexIndexUsed);
            }
        }

        m_MeshData.VertexCount += vertices.size();
        m_MeshData.VertexIndexUsed += vertices.size();   // for now
    }

}