#pragma once

#include "renderer_batch_render.h"

#include "basic_vector.h"

#include <stack>

namespace EB
{
    class VertexArray;
    class VertexBuffer;
    class Shader;
    class UniformBuffer;
    class Texture2D;
    class Handle;

    struct MeshVertexInfo_Patches
    {
        Vec3f Position;
        Vec3f FlatColor;
        float Transparency = 1.0f;
        Vec3f Normal;
        Vec2f TextureCoord;

        int ObjectId = -1;
        int TextureId = 0;
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
        Vec3f FlatColor;
        float Transparency = 1.0f;

        int ObjectId = -1;
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

        void pushColor(const Vec3f& color);
        void popColor();
        Vec3f currentColor() const;

        void pushTransparency(float alpha);
        void popTransparency();
        float currentTransparency() const;

        void pushObjectId(const Handle& hdl);
        void popObjectId();
        int currentObjectId() const;

        int addTexture(const Shared<Texture2D>& texture);
        void removeTexture(int allocatedIdx);
        void removeAllTextures();
        void pushTextureId(int texId);
        void popTextureId();
        int currentTextureId() const;

    protected:
        void flush();
        void flushAndReset();
        void init();
        void terminate();
        void reset();
        const BatchRenderStatistic& statistic() const;

    protected:
        void line(const Vec3f& start, const Vec3f& end);
        void circle(const Vec3f& center, float radius, const Vec3f& normal);
        void polyline(const std::vector<Vec3f>& vertices);
        void frame(const std::vector<Vec3f>& vertices, const std::vector<Vec2i>& indices);
        void mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals);
        void quad(const Vec3f& center, const Vec3f& xDir, const Vec3f& yDir);

    protected:
        MeshBatchData_Patches m_MeshDataPatches;
        MeshBatchData_WireFrames m_MeshDataWireFrames;
        CameraData m_CameraData;
        Shared<UniformBuffer> m_CameraBuffer;
        BatchRenderStatistic m_Statistic;
        std::stack<Vec3f> m_ColorStack;
        std::vector<Shared<Texture2D>> m_Textures;
        std::stack<float> m_TransparencyStack;
        std::stack<int> m_ObjectIdStack;
        std::stack<int> m_TextureIdStack;
    };
}