#pragma once

#include "renderer_batch_render.h"

#include "basic_vector.h"

namespace EB
{
    class VertexArray;
    class VertexBuffer;
    class Shader;
    class UniformBuffer;

    struct MeshVertexInfo
    {
        Vec3f Position;
        //Vec4f FlatColor;
        //Vec3f Normal;
    };

    struct MeshBatchData
    {
        static const unsigned int MaxVerticesPerBatch = 4000;
        static const unsigned int MaxIndicesPerBatch = 2000;

        Shared<VertexArray> VAOPerBatch;
        Shared<VertexBuffer> VBOPerBatch;
        Shared<Shader> ShaderPerBatch;
        std::vector<unsigned int> IndicesPerBatch;
        unsigned int VertexCount;
        unsigned int VertexIndexUsed;

        MeshVertexInfo* pBase = nullptr;
        MeshVertexInfo* pCurrent = nullptr;
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

    protected:
        void line(const Vec3f& start, const Vec3f& end);
        void mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals);

    protected:
        MeshBatchData m_MeshData;
        CameraData m_CameraData;
        UniformBuffer* m_CameraBuffer = nullptr;
    };
}