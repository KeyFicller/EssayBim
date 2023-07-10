#include "renderer_batch_render_impl.h"

#include "renderer_buffer_layout.h"
#include "renderer_entry.h"
#include "renderer_index_buffer.h"
#include "renderer_shader.h"
#include "renderer_uniform_buffer.h"
#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_texture.h"

#include "basic_file_server.h"
#include "basic_color_defines.h"
#include "geometry_arithmetic.h"
#include "geometry_circle_3d.h"

#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

#define EB_BATCH_RENDER_DEFAULT_COLOR             EB_WHITE_3
#define EB_BATCH_RENDER_DEFAULT_NORMAL            Vec3f(1.0f, 0.0f, 0.0f)
#define EB_BATCH_RENDER_DEFAULT_TEXTURE_COORD     Vec2f(0.5f, 0.5f)
#define EB_BATCH_RENDER_DEFAULT_OBJECT_ID         (-1)
#define EB_BATCH_RENDER_DEFAULT_TEXTURE_ID        0

namespace EB
{
    namespace
    {
        Shared<Texture2D> g_WhiteTexture;
        int g_Sampler2D[32] = {
             0,  1,  2,  3,  4,  5,  6,  7,
             8,  9, 10, 11, 12, 13, 14, 15,
            16, 17, 18, 19, 20, 21, 22, 23,
            24, 25, 26, 27, 28, 29, 30, 31
        };
    }


    BatchRenderImpl::BatchRenderImpl()
    {
        init();
        reset();
    }

    BatchRenderImpl::~BatchRenderImpl()
    {
        terminate();
    }

    void BatchRenderImpl::start(const Mat4& viewprojectionMatrix)
    {
        reset();
        m_CameraData.ViewProjectionMatrix = viewprojectionMatrix;
        m_CameraBuffer->setData(&m_CameraData.ViewProjectionMatrix, sizeof(CameraData), 0);
    }

    void BatchRenderImpl::end()
    {
        {
            auto bufferSize = reinterpret_cast<uint8_t*>(m_MeshDataPatches.pCurrent) - reinterpret_cast<uint8_t*>(m_MeshDataPatches.pBase);
            m_MeshDataPatches.VBOPerBatch->setData(m_MeshDataPatches.pBase, (unsigned int)bufferSize);
        }
        {
            auto bufferSize = reinterpret_cast<uint8_t*>(m_MeshDataWireFrames.pCurrent) - reinterpret_cast<uint8_t*>(m_MeshDataWireFrames.pBase);
            m_MeshDataWireFrames.VBOPerBatch->setData(m_MeshDataWireFrames.pBase, (unsigned int)bufferSize);
        }

        flush();
    }

    void BatchRenderImpl::pushColor(const Vec3f& color)
    {
        m_ColorStack.push(color);
    }

    void BatchRenderImpl::popColor()
    {
        if (m_ColorStack.size()) {
            m_ColorStack.pop();
        }
    }

    Vec3f BatchRenderImpl::currentColor()
    {
        return m_ColorStack.size() ? m_ColorStack.top() : EB_BATCH_RENDER_DEFAULT_COLOR;
    }

    void BatchRenderImpl::flush()
    {
        if (unsigned int indexCount = m_MeshDataPatches.IndicesPerBatch.size()) {
            Shared<IndexBuffer> indexBuffer = IndexBuffer::create(m_MeshDataPatches.IndicesPerBatch.data(), m_MeshDataPatches.IndicesPerBatch.size());
            m_MeshDataPatches.VAOPerBatch->setIndexBuffer(indexBuffer);
            m_MeshDataPatches.ShaderPerBatch->bind();
            g_WhiteTexture->bind(0);
            for (unsigned int i = 0; i < m_Textures.size(); i++) {
                m_Textures[i + 1]->bind(i + 1);
            }
            RendererEntry::instance().mesh(m_MeshDataPatches.VAOPerBatch.get());
            m_Statistic.RenderCall += 1;
        }

        if (unsigned int indexCount = m_MeshDataWireFrames.IndicesPerBatch.size()) {
            Shared<IndexBuffer> indexBuffer = IndexBuffer::create(m_MeshDataWireFrames.IndicesPerBatch.data(), m_MeshDataWireFrames.IndicesPerBatch.size());
            m_MeshDataWireFrames.VAOPerBatch->setIndexBuffer(indexBuffer);
            m_MeshDataWireFrames.ShaderPerBatch->bind();
            RendererEntry::instance().line(m_MeshDataWireFrames.VAOPerBatch.get());
            m_Statistic.RenderCall += 1;
        }
    }

    void BatchRenderImpl::flushAndReset()
    {
        end();
        reset();
    }

    void BatchRenderImpl::init()
    {
        m_MeshDataPatches.VAOPerBatch = VertexArray::create();
        m_MeshDataPatches.VBOPerBatch = VertexBuffer::create(
            MeshBatchData_Patches::MaxVerticesPerBatch * sizeof(MeshVertexInfo_Patches)
        );
        BufferLayout layoutPatches = {
            {"aPos", eShaderDataType::kFloat3},
            {"aColor", eShaderDataType::kFloat3},
            {"aNormal", eShaderDataType::kFloat3},
            {"aTexCoord", eShaderDataType::kFloat2},

            {"aObjectId", eShaderDataType::kInt},
            {"aTexId", eShaderDataType::kInt}
        };
        m_MeshDataPatches.VBOPerBatch->setLayout(layoutPatches);
        m_MeshDataPatches.VAOPerBatch->addVertexBuffer(m_MeshDataPatches.VBOPerBatch);
        m_MeshDataPatches.pBase = new MeshVertexInfo_Patches[MeshBatchData_Patches::MaxVerticesPerBatch];
        m_MeshDataPatches.pCurrent = m_MeshDataPatches.pBase;
        m_MeshDataPatches.ShaderPerBatch = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp.glsl");
        m_MeshDataPatches.ShaderPerBatch->bind();
        m_MeshDataPatches.ShaderPerBatch->setIntArray("uTextures", 32, g_Sampler2D);
        m_MeshDataPatches.ShaderPerBatch->unbind();

        m_MeshDataWireFrames.VAOPerBatch = VertexArray::create();
        m_MeshDataWireFrames.VBOPerBatch = VertexBuffer::create(
            MeshBatchData_WireFrames::MaxVerticesPerBatch * sizeof(MeshVertexInfo_WireFrames)
        );
        BufferLayout layoutWireFrames = {
            {"aPos", eShaderDataType::kFloat3},
            {"aColor", eShaderDataType::kFloat3},

            {"aObjectId", eShaderDataType::kInt}
        };
        m_MeshDataWireFrames.VBOPerBatch->setLayout(layoutWireFrames);
        m_MeshDataWireFrames.VAOPerBatch->addVertexBuffer(std::shared_ptr<VertexBuffer>(m_MeshDataWireFrames.VBOPerBatch));
        m_MeshDataWireFrames.pBase = new MeshVertexInfo_WireFrames[MeshBatchData_WireFrames::MaxVerticesPerBatch];
        m_MeshDataWireFrames.pCurrent = m_MeshDataWireFrames.pBase;
        m_MeshDataWireFrames.ShaderPerBatch = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp_2.glsl");
        m_MeshDataWireFrames.ShaderPerBatch->unbind();

        m_CameraBuffer = UniformBuffer::create(sizeof(CameraData), 0);

        unsigned int white = 0xffffffff;
        g_WhiteTexture = Texture2D::create("flat_white", 1, 1);
        g_WhiteTexture->setData(&white, sizeof(unsigned int));
    }

    void BatchRenderImpl::terminate()
    {
        g_WhiteTexture.reset();
    }

    void BatchRenderImpl::reset()
    {
        m_MeshDataPatches.IndicesPerBatch.clear();
        m_MeshDataPatches.pCurrent = m_MeshDataPatches.pBase;
        m_MeshDataPatches.VertexCount = 0;
        m_MeshDataPatches.VertexIndexUsed = 0;

        m_MeshDataWireFrames.IndicesPerBatch.clear();
        m_MeshDataWireFrames.pCurrent = m_MeshDataWireFrames.pBase;
        m_MeshDataWireFrames.VertexCount = 0;
        m_MeshDataWireFrames.VertexIndexUsed = 0;

        m_Statistic = BatchRenderStatistic();
    }

    const BatchRenderStatistic& BatchRenderImpl::statistic() const
    {
        return m_Statistic;
    }

    void BatchRenderImpl::line(const Vec3f& start, const Vec3f& end)
    {
        if (m_MeshDataWireFrames.VertexCount + 2 >= m_MeshDataWireFrames.MaxVerticesPerBatch ||
            m_MeshDataWireFrames.IndicesPerBatch.size() + 2 >= m_MeshDataWireFrames.MaxIndicesPerBatch) {
            flushAndReset();
        }

        *m_MeshDataWireFrames.pCurrent = MeshVertexInfo_WireFrames{
            start,
            currentColor(),
            EB_BATCH_RENDER_DEFAULT_OBJECT_ID
        };
        m_MeshDataWireFrames.pCurrent++;
        *m_MeshDataWireFrames.pCurrent = MeshVertexInfo_WireFrames{
            end,
            currentColor(),
            EB_BATCH_RENDER_DEFAULT_OBJECT_ID
        };
        m_MeshDataWireFrames.pCurrent++;

        m_MeshDataWireFrames.IndicesPerBatch.emplace_back(m_MeshDataWireFrames.VertexIndexUsed + 0);
        m_MeshDataWireFrames.IndicesPerBatch.emplace_back(m_MeshDataWireFrames.VertexIndexUsed + 1);

        m_MeshDataWireFrames.VertexCount += 2;
        m_MeshDataWireFrames.VertexIndexUsed += 2;   // for now

        m_Statistic.ElementCount += 1;
        m_Statistic.VertexCount += 2;
    }

    void BatchRenderImpl::circle(const Vec3f& center, float radius, const Vec3f& normal)
    {
        GeCircle3d circle(center, radius, normal);
        auto pts = circle.sampler(0.02f);
        std::vector<Vec3f> vertices;
        for (auto pt : pts) {
            vertices.emplace_back(Vec3f(pt));
        }
        polyline(vertices);
    }

    void BatchRenderImpl::polyline(const std::vector<Vec3f>& vertices)
    {
        EB_CORE_ASSERT(vertices.size());
        if (m_MeshDataWireFrames.VertexCount + vertices.size() >= m_MeshDataWireFrames.MaxVerticesPerBatch ||
            m_MeshDataWireFrames.IndicesPerBatch.size() + (vertices.size() - 1) * 2 >= m_MeshDataWireFrames.MaxIndicesPerBatch) {
            flushAndReset();
        }
        for (unsigned int i = 0; i < vertices.size(); i++) {
            *m_MeshDataWireFrames.pCurrent = MeshVertexInfo_WireFrames{
                vertices[i],
                currentColor(),
                EB_BATCH_RENDER_DEFAULT_OBJECT_ID
            };
            m_MeshDataWireFrames.pCurrent++;
        }
        for (unsigned int i = 0; i < vertices.size() - 1; i++) {
            m_MeshDataWireFrames.IndicesPerBatch.emplace_back(i + m_MeshDataWireFrames.VertexIndexUsed);
            m_MeshDataWireFrames.IndicesPerBatch.emplace_back(i + 1 + m_MeshDataWireFrames.VertexIndexUsed);
        }

        m_MeshDataWireFrames.VertexCount += vertices.size();
        m_MeshDataWireFrames.VertexIndexUsed += vertices.size();   // for now

        m_Statistic.ElementCount += vertices.size() - 1;
        m_Statistic.VertexCount += vertices.size() - 1;
    }

    void BatchRenderImpl::frame(const std::vector<Vec3f>& vertices, const std::vector<Vec2i>& indices)
    {
        if (m_MeshDataWireFrames.VertexCount + vertices.size() >= m_MeshDataWireFrames.MaxVerticesPerBatch ||
            m_MeshDataWireFrames.IndicesPerBatch.size() + indices.size() * 2 >= m_MeshDataWireFrames.MaxIndicesPerBatch) {
            flushAndReset();
        }
        for (unsigned int i = 0; i < vertices.size(); i++) {
            *m_MeshDataWireFrames.pCurrent = MeshVertexInfo_WireFrames{
                vertices[i],
                currentColor(),
                EB_BATCH_RENDER_DEFAULT_OBJECT_ID
            };
            m_MeshDataWireFrames.pCurrent++;
        }

        for (unsigned int i = 0; i < indices.size(); i++) {
            for (unsigned int j = 0; j < 2; j++) {
                m_MeshDataWireFrames.IndicesPerBatch.emplace_back(indices[i][j] + m_MeshDataWireFrames.VertexIndexUsed);
            }
        }

        m_MeshDataWireFrames.VertexCount += vertices.size();
        m_MeshDataWireFrames.VertexIndexUsed += vertices.size();   // for now

        m_Statistic.ElementCount += indices.size();
        m_Statistic.VertexCount += vertices.size();
    }

    void BatchRenderImpl::mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals)
    {
        EB_CORE_ASSERT(vertices.size() == normals.size());
        if (m_MeshDataPatches.VertexCount + vertices.size() >= m_MeshDataPatches.MaxVerticesPerBatch ||
            m_MeshDataPatches.IndicesPerBatch.size() + indices.size() * 3 >= m_MeshDataPatches.MaxIndicesPerBatch) {
            flushAndReset();
        }

        for (unsigned int i = 0; i < vertices.size(); i++) {
            *m_MeshDataPatches.pCurrent = MeshVertexInfo_Patches{
                vertices[i],
                currentColor(),
                EB_BATCH_RENDER_DEFAULT_NORMAL,         // TODO: 
                EB_BATCH_RENDER_DEFAULT_TEXTURE_COORD,

                EB_BATCH_RENDER_DEFAULT_OBJECT_ID,
                EB_BATCH_RENDER_DEFAULT_TEXTURE_ID
            };
            m_MeshDataPatches.pCurrent++;
        }

        for (unsigned int i = 0; i < indices.size(); i++) {
            for (unsigned int j = 0; j < 3; j++) {
                m_MeshDataPatches.IndicesPerBatch.emplace_back(indices[i][j] + m_MeshDataPatches.VertexIndexUsed);
            }
        }

        m_MeshDataPatches.VertexCount += vertices.size();
        m_MeshDataPatches.VertexIndexUsed += vertices.size();   // for now

        m_Statistic.ElementCount += indices.size();
        m_Statistic.VertexCount += vertices.size();
    }

    void BatchRenderImpl::quad(const Vec3f& center, const Vec3f& xDir, const Vec3f& yDir)
    {
        if (m_MeshDataPatches.VertexCount + 4 >= m_MeshDataPatches.MaxVerticesPerBatch ||
            m_MeshDataPatches.IndicesPerBatch.size() + 6 >= m_MeshDataPatches.MaxIndicesPerBatch) {
            flushAndReset();
        }
        for (int i = 0; i < 4; i++) {
            *m_MeshDataPatches.pCurrent = MeshVertexInfo_Patches{
                GePoint3d(center) + ((i == 1 || i == 2) ? 1.f : -1.f) * GeVector3d(xDir) + ((i == 2 || i == 3) ? 1.f : -1.f) * GeVector3d(yDir),
                currentColor(),
                EB_BATCH_RENDER_DEFAULT_NORMAL,         // TODO: 
                EB_BATCH_RENDER_DEFAULT_TEXTURE_COORD,

                EB_BATCH_RENDER_DEFAULT_OBJECT_ID,
                EB_BATCH_RENDER_DEFAULT_TEXTURE_ID
            };
            m_MeshDataPatches.pCurrent++;
        }

        m_MeshDataPatches.IndicesPerBatch.push_back(0 + m_MeshDataPatches.VertexIndexUsed);
        m_MeshDataPatches.IndicesPerBatch.push_back(1 + m_MeshDataPatches.VertexIndexUsed);
        m_MeshDataPatches.IndicesPerBatch.push_back(2 + m_MeshDataPatches.VertexIndexUsed);
        m_MeshDataPatches.IndicesPerBatch.push_back(2 + m_MeshDataPatches.VertexIndexUsed);
        m_MeshDataPatches.IndicesPerBatch.push_back(3 + m_MeshDataPatches.VertexIndexUsed);
        m_MeshDataPatches.IndicesPerBatch.push_back(0 + m_MeshDataPatches.VertexIndexUsed);

        m_MeshDataPatches.VertexCount += 4;
        m_MeshDataPatches.VertexIndexUsed += 4;   // for now

        m_Statistic.ElementCount += 6;
        m_Statistic.VertexCount += 6;
    }

    MeshBatchData_Patches::~MeshBatchData_Patches()
    {
        EB_SAFE_ARRAY_DELETE(pBase);
    }

    MeshBatchData_WireFrames::~MeshBatchData_WireFrames()
    {
        EB_SAFE_ARRAY_DELETE(pBase);
    }

}