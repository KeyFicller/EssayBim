#pragma once

#include "renderer_batch_render.h"

#include "basic_vector.h"

namespace EB
{
    class VertexArray;
    class VertexBuffer;
    class Shader;
    class UniformBuffer;

    struct MeshVertexInfo_Patches
    {
        Vec3f Position;
        //Vec4f FlatColor;
        //Vec3f Normal;
    };

    struct MeshBatchData_Patches
    {
        static const unsigned int MaxVerticesPerBatch = 4000;
        static const unsigned int MaxIndicesPerBatch = 2000;

        Shared<VertexArray> VAOPerBatch;
        Shared<VertexBuffer> VBOPerBatch;
        Shared<Shader> ShaderPerBatch;
        std::vector<unsigned int> IndicesPerBatch;
        unsigned int VertexCount;
        unsigned int VertexIndexUsed;

        MeshVertexInfo_Patches* pBase = nullptr;
        MeshVertexInfo_Patches* pCurrent = nullptr;

        ~MeshBatchData_Patches();
    };

    struct MeshVertexInfo_WireFrames
    {
        Vec3f Position;
    };

    struct MeshBatchData_WireFrames
    {
        static const unsigned int MaxVerticesPerBatch = 4000;
        static const unsigned int MaxIndicesPerBatch = 2000;

        Shared<VertexArray> VAOPerBatch;
        Shared<VertexBuffer> VBOPerBatch;
        Shared<Shader> ShaderPerBatch;
        std::vector<unsigned int> IndicesPerBatch;
        unsigned int VertexCount;
        unsigned int VertexIndexUsed;

        MeshVertexInfo_WireFrames* pBase = nullptr;
        MeshVertexInfo_WireFrames* pCurrent = nullptr;

        ~MeshBatchData_WireFrames();
    };

    struct CameraData
    {
        Mat4 ViewProjectionMatrix;
    };

    class BatchRenderImpl
    {
        friend class BatchRender;
    public:
        BatchRenderImpl();
        ~BatchRenderImpl();

    protected:
        void start(const Mat4& viewprojectionMatrix);
        void end();

    protected:
        void flush();
        void flushAndReset();
        void init();
        void reset();
        const BatchRenderStatistic& statistic() const;

    protected:
        void line(const Vec3f& start, const Vec3f& end);
        void circle(const Vec3f& center, float radius, const Vec3f& normal);
        void polyline(const std::vector<Vec3f>& vertices);
        void frame(const std::vector<Vec3f>& vertices, const std::vector<Vec2i>& indices);
        void mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals);

    protected:
        MeshBatchData_Patches m_MeshDataPatches;
        MeshBatchData_WireFrames m_MeshDataWireFrames;
        CameraData m_CameraData;
        Shared<UniformBuffer> m_CameraBuffer;
        BatchRenderStatistic m_Statistic;
    };
}